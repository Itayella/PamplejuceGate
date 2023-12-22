/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once


#include "juce_audio_processors/juce_audio_processors.h"
#include "DSP/GateSC.h"
//==============================================================================
/**
*/
class GateAudioProcessor  : public juce::AudioProcessor, juce::AudioProcessorValueTreeState::Listener
{
public:
    //==============================================================================
    GateAudioProcessor();
    ~GateAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;
    void processBlockBypassed (juce::AudioBuffer<float>& buffer,
                               juce::MidiBuffer& midiMessages)override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;
    void parameterChanged (const juce::String& parameterID, float newValue) override;
    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
   
    
    juce::AudioProcessorValueTreeState valueTreeState;
    
private:
    bool scListen;
 
    ItayMod::NoiseGate<float> gateProcess;
    juce::dsp::StateVariableTPTFilter<float> bandFilter;
    juce::dsp::DryWetMixer<float> dryWetMixer;

    const juce::StringArray parameterID {
           "Attack",
           "Release",
           "Threshold",
           "Ratio",
            "SC Listen",
            "SC",
            "Freq",
            "Mix"
        };
       
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GateAudioProcessor)
};
