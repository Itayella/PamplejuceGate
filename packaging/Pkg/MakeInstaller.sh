#!/bin/bash
clear
      
NAME="Gate"
NAME2="Gate"
NAME3="Gate_Installer"

echo "Creating installer for ${NAME}"

rm -rf "./AAX/"
rm -rf "./AU/"
rm -rf "./VST3/"

find "./Signed" -type f -name "*.pkg" -exec rm {} +

mkdir -p "./AU/"
mkdir -p "./AAX/"
mkdir -p "./VST3/"

cd ../build-xcode

# clear old aax and build xcode project
rm -rf "/Library/Application Support/Avid/Audio/Plug-Ins/${NAME}.aaxplugin"
xcodebuild -scheme "${NAME2}_AAX" -destination 'platform=macOS' -configuration Release
                                                                                                          
#/Applications/PACEAntiPiracy/Eden/Fusion/Current/bin/wraptool sign --verbose --account noamlev5 --wcguid 867CDD30-76F1-11EE-849E-005056928F3B --signid "Developer ID Installer: Itay Ella (8V43W798AG)" --in "/Library/Application Support/Avid/Audio/Plug-Ins/${NAME}.aaxplugin" --out "../Installer/AAX/${NAME}.aaxplugin" --autoinstall on


AU="/Users/mac/Library/Audio/Plug-Ins/Components/${NAME}.component"
VST3="/Users/mac/Library/Audio/Plug-Ins/VST3/${NAME}.vst3"


rm -rf "${VST3}"
xcodebuild -scheme "${NAME2}_VST3" -destination 'platform=macOS' -configuration Release

rm -rf "${AU}"
xcodebuild -scheme "${NAME2}_AU" -destination 'platform=macOS' -configuration Release

cd ../Installer

cp -r "${AU}" "./AU/"
cp -r "${VST3}" "./VST3/"
 
codesign --deep --force --verify --verbose --sign "Developer ID Installer: Itay Ella (8V43W798AG)" "AU/${NAME}.component/" --timestamp --options runtime
codesign --deep --force --verify --verbose --sign "Developer ID Installer: Itay Ella (8V43W798AG)" "VST3/${NAME}.vst3" --timestamp --options runtime 


pkgbuild --identifier "com.ShizanaRecords.${NAME2}.vst3.pkg" --root VST3 --install-location /Library/Audio/Plug-Ins/VST3 "com.ShizanaRecords.${NAME2}.vst3.pkg"
pkgbuild --identifier "com.ShizanaRecords.${NAME2}.component.pkg" --root AU --install-location /Library/Audio/Plug-Ins/Components "com.ShizanaRecords.${NAME2}.component.pkg"

productsign --sign "8V43W798AG" "com.ShizanaRecords.${NAME2}.vst3.pkg" "signed/com.ShizanaRecords.${NAME2}.vst3.pkg"
productsign --sign "8V43W798AG" "com.ShizanaRecords.${NAME2}.component.pkg" "signed/com.ShizanaRecords.${NAME2}.component.pkg" 
 
rm "com.ShizanaRecords.${NAME2}.component.pkg"
rm "com.ShizanaRecords.${NAME2}.vst3.pkg"

productbuild --distribution "./Signed/distribution.xml" --resources ./Signed/Res/ --package-path "./Signed/" "${NAME3}.pkg"
productsign --sign "8V43W798AG" "${NAME3}.pkg" "./Signed/${NAME3}.pkg"

rm ${NAME3}.pkg

xcrun notarytool submit "./Signed/${NAME3}.pkg" --apple-id "itay.ella@gmail.com" --password "ktyu-ikjx-fqfx-jzuf" --team-id "8V43W798AG" --wait 
xcrun stapler staple "./Signed/${NAME3}.pkg"

echo "...finished" 



 
