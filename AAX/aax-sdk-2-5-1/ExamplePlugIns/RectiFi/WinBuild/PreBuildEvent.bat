REM        Copyright 2019, 2023 Avid Technology, Inc.
REM All rights reserved.
REM 
REM CONFIDENTIAL: this document contains confidential information of Avid. Do
REM not disclose to any third party. Use of the information contained in this
REM document is subject to an Avid SDK license.

set OutDir=%1

echo Copy Resources and Create Folder Icon

CALL ..\..\..\..\Utilities\CreatePackage.bat %OutDir% ..\..\..\..\Utilities\PlugIn.ico

echo Copy XML files
copy /Y ..\..\*.xml %OutDir%\..\..\Contents\Resources\ > NUL
