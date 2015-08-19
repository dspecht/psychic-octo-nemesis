@echo off
REM build file for System Information C Project, Not working for some dumb reason

IF NOT EXIST build mkdir build
pushd build
REM Delete old debug information files
del *.pdb > NUL 2> NUL

cl -nologo -Od -Zi ..\getSysInfo.cpp
popd
