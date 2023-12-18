@echo off
setlocal EnableDelayedExpansion

set base_path=%~dp0
cd %base_path%

if not exist "..\Libraries\" (mkdir "..\Libraries")

set update_lib=%~1

for %%A in ("fast_float" "") do ( 
    if "%update_lib%"==%%A (
        REM updating the fast_float library
        set lib_name="fast_float"
        set lib_path_src="!base_path!!lib_name!\"

        cd !lib_name!
        set "tag="
        for /f %%i in ('git describe --contains HEAD') do set "tag=%%i"

        cd !base_path!
        REM delete the destination library folder when updating
        RD /S /Q "..\Libraries\!lib_name!"
        set lib_path_dest="..\Libraries\!lib_name!\"
        mkdir !lib_path_dest!

        mkdir "!lib_path_dest!Include"
        copy !lib_path_src!include\!lib_name!\*.h "!lib_path_dest!Include" /Y

        echo "!tag!" >"!lib_path_dest!!lib_name!_!tag!.txt"
    )
)

for %%A in ("zlib" "") do ( 
    if "%update_lib%"==%%A (
        REM updating the zlib library
        set lib_name="zlib"
        set lib_path_src="!base_path!!lib_name!\"

        cd !lib_name!
        set "tag="
        for /f %%i in ('git describe --contains HEAD') do set "tag=%%i"

        cd !base_path!
        REM delete the destination library folder when updating
        RD /S /Q "..\Libraries\!lib_name!"
        set lib_path_dest="..\Libraries\!lib_name!\"
        mkdir !lib_path_dest!

        mkdir "!lib_path_dest!Include"
        mkdir "!lib_path_dest!Source"
        copy !lib_path_src!*.h "!lib_path_dest!Include" /Y
        copy  !lib_path_src!*.c "!lib_path_dest!Source" /Y

        echo "!tag!" >"!lib_path_dest!!lib_name!_!tag!.txt"
    )
)


REM updating the cpp-base64 library
for %%A in ("cpp-base64" "") do ( 
    if "%update_lib%"==%%A (
        set lib_name="cpp-base64"
        set lib_path_src="!base_path!!lib_name!\"

        cd !lib_name!
        set "tag="
        for /f %%i in ('git describe --contains HEAD') do set "tag=%%i"
        
        cd !base_path!
        REM delete the destination library folder when updating
        RD /S /Q "..\Libraries\!lib_name!"
        set lib_path_dest="..\Libraries\!lib_name!\"
        mkdir !lib_path_dest!

        mkdir "!lib_path_dest!Include"
        mkdir "!lib_path_dest!Source"
        copy !lib_path_src!base*.h "!lib_path_dest!Include" /Y
        copy  !lib_path_src!base*.cpp "!lib_path_dest!Source" /Y

        echo "!tag!" >"!lib_path_dest!!lib_name!_!tag!.txt"
    )
)
