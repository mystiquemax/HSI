@echo off
set /p userInput=Type 'yes' to continue: 
if /i "%userInput%"=="yes" (
    echo Script begin.
    "C:\Program Files\rti_connext_dds-7.2.0\bin\rtiddsgen.bat" "%~dp0\..\..\..\InformationModel\HSI_Standard_topics.xml" -inputXml -ppDisable -d %~dp0 -language C++11 -create typefiles
) else (
    echo Script execution cancelled.
    pause
)
