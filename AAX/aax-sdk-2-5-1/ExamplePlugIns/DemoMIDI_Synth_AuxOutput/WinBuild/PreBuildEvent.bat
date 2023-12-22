REM        Copyright 2016, 2023 Avid Technology, Inc.
REM All rights reserved.
REM 
REM CONFIDENTIAL: this document contains confidential information of Avid. Do
REM not disclose to any third party. Use of the information contained in this
REM document is subject to an Avid SDK license.

set OutDir=%1

CALL ..\..\..\..\Utilities\CreatePackage.bat %OutDir% ..\..\..\..\Utilities\PlugIn.ico

echo Copy "DemoSynthPages.xml"
copy /Y ..\..\Source\DemoSynthPages.xml %OutDir%\..\..\Contents\Resources\ > NUL

