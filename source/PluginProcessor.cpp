/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GateAudioProcessor::GateAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
, valueTreeState(*this, nullptr, juce::Identifier("Parameters"),
                {
    std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("Attack", 1),  "Attack",juce::NormalisableRange<float>(0.1f, 500.f, 0.1f, 1.0f), 1.f),
    std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("Release", 1), "Release",juce::NormalisableRange<float>(0.1f, 500.f, 0.1f, 1.0f), 1.f),
    std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("Threshold", 1),   "Thershold",juce::NormalisableRange<float>(-120.0f, 0.0f, 0.01f, 1.f), 0.f),
    std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("Ratio", 1),   "Ratio",juce::NormalisableRange<float>(1.0f, 50.0f, 0.5f, 1.f), 1.f),
    std::make_unique<juce::AudioParameterBool>(juce::ParameterID("SC Listen", 1), "SC Listen", 0),
    std::make_unique<juce::AudioParameterBool>(juce::ParameterID("SC", 1), "SC", 0),
    std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("Freq", 1),   "Freq",juce::NormalisableRange<float>(40.0f, 15000.0f, 1.0f, 0.3f), 2000.f),
    std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("Mix", 1),   "Mix",juce::NormalisableRange<float>(0.0f, 1.0f, 0.001f, 1.f), 1.f)
                }
            )
{
    for (auto parameters : parameterID)
        {
            valueTreeState.addParameterListener(parameters, this);
        }
    
}

GateAudioProcessor::~GateAudioProcessor()
{
    for(auto parameters : parameterID)
       {
           valueTreeState.removeParameterListener(parameters, this);
       }
}

//==============================================================================
const juce::String GateAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool GateAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool GateAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool GateAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double GateAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int GateAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int GateAudioProcessor::getCurrentProgram()
{
    return 0;
}

void GateAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String GateAudioProcessor::getProgramName (int index)
{
    return {};
}

void GateAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void GateAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::dsp::ProcessSpec spec;
    
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumInputChannels();
    
    bandFilter.prepare(spec);
    bandFilter.setType(juce::dsp::StateVariableTPTFilterType::bandpass);
    bandFilter.setResonance(0.7f);
    
    gateProcess.prepare(spec);
    dryWetMixer.prepare(spec);
}

void GateAudioProcessor::releaseResources()
{
    dryWetMixer.reset();
    gateProcess.reset();
    bandFilter.reset();
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GateAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void GateAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    juce::dsp::AudioBlock<float> block(buffer);
    dryWetMixer.pushDrySamples(block);
    juce::dsp::ProcessContextReplacing<float> ctx(block);
    juce::AudioBuffer<float> scBuffer;
    scBuffer.makeCopyOf(buffer);
    scBuffer.applyGain(juce::Decibels::decibelsToGain(12.f));
    juce::dsp::AudioBlock<float> scBlock(scBuffer);
    juce::dsp::ProcessContextReplacing<float> scCtx(scBlock);
    if (scListen)
    {
        bandFilter.process(ctx);
  
    }
    else if(*valueTreeState.getRawParameterValue("SC"))
    {
        bandFilter.process(scCtx);
        gateProcess.process(ctx, scCtx);
    }
    else
    {
        gateProcess.process(ctx, ctx);
    }
    dryWetMixer.mixWetSamples(block);
    
}

void GateAudioProcessor::processBlockBypassed (juce::AudioBuffer<float>& buffer,
                                   juce::MidiBuffer& midiMessages)
{
    
}

//==============================================================================
bool GateAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* GateAudioProcessor::createEditor()
{
   // return new GateAudioProcessorEditor (*this);
    return new juce::GenericAudioProcessorEditor(*this);
}

void GateAudioProcessor::parameterChanged(const juce::String &parameterID, float newValue)
{
    
        if (parameterID == "Attack")
        {
            gateProcess.setAttack(newValue);
        }
    
        if (parameterID == "Release")
        {
            gateProcess.setRelease(newValue);
        }
    
        if (parameterID == "Threshold")
        {
            gateProcess.setThreshold(newValue);
        }
    
        if (parameterID == "Ratio")
        {
            gateProcess.setRatio(newValue);
        }
       
        if (parameterID == "SC Listen")
        {
            scListen = newValue;
        }
    
        if (parameterID == "SC")
        {
            gateProcess.setSideChain(newValue);
        }
    
        if (parameterID == "Freq")
        {
            bandFilter.setCutoffFrequency(newValue);
        }
    
        if (parameterID == "Mix")
        {
            dryWetMixer.setWetMixProportion(newValue);
        }
}
//==============================================================================
void GateAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void GateAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}
//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GateAudioProcessor();
}
