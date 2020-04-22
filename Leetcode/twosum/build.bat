@echo off
REM build file for System Information C Project, Not working for some dumb reason
W:\misc\ctime -begin twosum_BuildTimes.ctm

set buildDIR=\build\
set outputDirectories=/Fd.%buildDIR% /Fe.%buildDir% /Fo.%buildDir%
set WarningFlags= -WX -wd4201 -wd4100 -wd4189 -wd4505
set Flags= -Zi -EHsc -nologo -fp:fast -Gm- -GR- -EHa- -Od %WarningFlags% %outputDirectories%

set LibsLinkedTo= user32.lib
set LinkerFlags= -incremental:no -opt:ref -NODEFAULTLIB:library %LibsLinkedTo%


IF NOT EXIST build mkdir build
REM Delete old debug information files
del %buildDIR%*.pdb

cl %Flags% twosum.cpp /link %LinkerFlags%

set LastError=%ERRORLEVEL%
W:\misc\ctime -end twosum_BuildTimes.ctm %LastError%