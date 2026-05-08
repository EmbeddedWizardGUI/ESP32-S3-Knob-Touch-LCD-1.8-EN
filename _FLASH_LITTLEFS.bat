@echo off
setlocal enabledelayedexpansion

REM ================================================================
REM   USER CONFIGURATION
REM ----------------------------------------------------------------
REM   Set DEFAULT_ESP_ROOT to YOUR 'esp' folder -- the directory
REM   that contains BOTH:
REM       <esp>\v5.5.2\esp-idf\
REM       <esp>\.espressif\
REM   This is the only line you should normally need to edit.
REM
REM   You can also override this from your environment by setting
REM   EW_ESP_ROOT (or by running ESP-IDF's export.bat which sets
REM   IDF_PATH).  Either of those takes priority over the value
REM   below, so leaving this filled in is harmless.
REM ================================================================

set "DEFAULT_ESP_ROOT=C:\Users\timzi\esp"

REM ================================================================
REM   END OF USER CONFIGURATION  -  no need to edit below this line
REM ================================================================

set SCRIPT_DIR=%~dp0
set "LITTLEFS_BIN=%SCRIPT_DIR%littlefs.bin"
set "LITTLEFS_OFFSET=0x810000"

echo ============================================================
echo   ESP32-S3 Knob - LittleFS image flasher
echo ============================================================
echo.
echo This script ONLY flashes littlefs.bin to the device at
echo offset %LITTLEFS_OFFSET% (the 'littlefs' data partition).
echo.
echo It does NOT build or flash the firmware. Use 'idf.py flash'
echo (or the Espressif IDF VSCode extension's flame button) for
echo the firmware. Run _GENERATE_LITTLEFS.bat first if you have
echo changed anything under littlefs_data\.
echo.

if not exist "%LITTLEFS_BIN%" (
    echo ERROR: littlefs.bin not found at:
    echo     %LITTLEFS_BIN%
    echo.
    echo Run _GENERATE_LITTLEFS.bat first to create it.
    pause
    exit /b 1
)

REM ----------------------------------------------------------------
REM Locate ESP-IDF v5.5.2 (for esptool.py and its Python).
REM
REM Resolution order:
REM   1. IDF_PATH env var (set by ESP-IDF's export.bat)
REM   2. EW_ESP_ROOT env var (parent 'esp' folder)
REM   3. DEFAULT_ESP_ROOT from the USER CONFIGURATION block above
REM ----------------------------------------------------------------

set "ESP_ROOT_CHOSEN="
if defined EW_ESP_ROOT       set "ESP_ROOT_CHOSEN=%EW_ESP_ROOT%"
if not defined ESP_ROOT_CHOSEN if defined DEFAULT_ESP_ROOT set "ESP_ROOT_CHOSEN=%DEFAULT_ESP_ROOT%"

if not defined IDF_PATH (
    if defined ESP_ROOT_CHOSEN set "IDF_PATH=%ESP_ROOT_CHOSEN%\v5.5.2\esp-idf"
)
if not defined IDF_PATH goto :no_idf

if not defined IDF_PYTHON (
    if defined ESP_ROOT_CHOSEN (
        set "IDF_PYTHON=%ESP_ROOT_CHOSEN%\.espressif\python_env\idf5.5_py3.11_env\Scripts\python.exe"
    )
)
if not defined IDF_PYTHON call :derive_python_from_idf_path
if not defined IDF_PYTHON goto :no_idf
if not exist "%IDF_PYTHON%" goto :python_missing

set "ESPTOOL_PY=%IDF_PATH%\components\esptool_py\esptool\esptool.py"
if not exist "%ESPTOOL_PY%" (
    echo ERROR: esptool.py not found at:
    echo     %ESPTOOL_PY%
    echo Please check your ESP-IDF installation.
    pause
    exit /b 1
)

echo Using IDF_PATH:   %IDF_PATH%
echo Using IDF_PYTHON: %IDF_PYTHON%
echo.

REM ----------------------------------------------------------------
REM COM port selection: argument > auto-detect > prompt
REM ----------------------------------------------------------------

if not "%~1"=="" (
    set "PORT=%~1"
    goto :flash
)

set "PS_SCRIPT=%TEMP%\list_com_ports.ps1"
>"%PS_SCRIPT%" echo $ports = Get-CimInstance -ClassName Win32_PnPEntity -Filter "Name like '%%(COM%%)'"
>>"%PS_SCRIPT%" echo foreach ($p in $ports) {
>>"%PS_SCRIPT%" echo     if ($p.Name -match '\((COM\d+)\)') {
>>"%PS_SCRIPT%" echo         $com = $Matches[1]
>>"%PS_SCRIPT%" echo         Write-Output "$com|$($p.Name)"
>>"%PS_SCRIPT%" echo     }
>>"%PS_SCRIPT%" echo }

echo ============================================
echo   Scanning COM ports...
echo ============================================
echo.

set PORTCOUNT=0
for /f "usebackq tokens=1,2 delims=|" %%a in (`powershell -NoProfile -ExecutionPolicy Bypass -File "%PS_SCRIPT%"`) do (
    set /a PORTCOUNT+=1
    set "COMPORT_!PORTCOUNT!=%%a"
    set "COMDEVICE_!PORTCOUNT!=%%b"
)

del "%PS_SCRIPT%" >nul 2>nul

if %PORTCOUNT%==0 (
    echo   No COM ports found. Is the device connected?
    echo.
    pause
    exit /b 1
)

echo   Available COM ports:
echo   -------------------------------------------
for /l %%i in (1,1,%PORTCOUNT%) do (
    echo     [%%i] !COMDEVICE_%%i!
)
echo   -------------------------------------------
echo.

if %PORTCOUNT%==1 (
    set CHOICE=1
    echo   Only one port found, selecting !COMPORT_1!
) else (
    set /p "CHOICE=  Select port [1-%PORTCOUNT%]: "
)

if not defined CHOICE (
    echo   ERROR: No selection made.
    pause
    exit /b 1
)
if %CHOICE% LSS 1 (
    echo   ERROR: Invalid selection.
    pause
    exit /b 1
)
if %CHOICE% GTR %PORTCOUNT% (
    echo   ERROR: Invalid selection.
    pause
    exit /b 1
)

set "PORT=!COMPORT_%CHOICE%!"

:flash
echo.
echo ============================================
echo   ESP32-S3 LittleFS Flash Tool
echo ============================================
echo   Port:       %PORT%
echo   Image:      %LITTLEFS_BIN%
echo   Offset:     %LITTLEFS_OFFSET%
echo ============================================
echo.

"%IDF_PYTHON%" "%ESPTOOL_PY%" -p %PORT% -b 460800 --before default_reset --after hard_reset --chip esp32s3 write_flash %LITTLEFS_OFFSET% "%LITTLEFS_BIN%"

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ERROR: LittleFS flashing failed!
    pause
    exit /b 1
)

echo.
echo ============================================
echo   LittleFS flashed successfully
echo ============================================
pause
exit /b 0


REM ===== helpers =====================================================

:derive_python_from_idf_path
for %%I in ("%IDF_PATH%\..\..") do set "ESP_FOLDER=%%~fI"
if not defined ESP_FOLDER goto :eof
set "IDF_PYTHON=%ESP_FOLDER%\.espressif\python_env\idf5.5_py3.11_env\Scripts\python.exe"
goto :eof


:no_idf
echo.
echo ERROR: Could not locate ESP-IDF v5.5.2.
echo.
echo --------------------------------------------------------------
echo   QUICKEST FIX:
echo --------------------------------------------------------------
echo Open this batch file in any text editor and update the line
echo near the top:
echo.
echo     set "DEFAULT_ESP_ROOT=C:\path\to\your\esp"
echo.
echo Point it at your 'esp' folder (the directory containing
echo 'v5.5.2\esp-idf' and '.espressif').
echo.
echo --------------------------------------------------------------
echo   ALTERNATIVES (do not edit the script):
echo --------------------------------------------------------------
echo   * setx EW_ESP_ROOT "C:\path\to\your\esp"
echo     ...then open a NEW Command Prompt and re-run.
echo.
echo   * call "C:\path\to\esp\v5.5.2\esp-idf\export.bat"
echo     ...in your current Command Prompt, then re-run this batch.
echo.
pause
exit /b 1


:python_missing
echo.
echo ERROR: Python interpreter not found at the expected location:
echo     %IDF_PYTHON%
echo.
echo This is usually because the ESP-IDF v5.5.2 install script did
echo not finish creating the Python virtualenv.  Open a Command
echo Prompt, change into your esp-idf folder, and run:
echo.
echo     install.bat
echo.
echo Then re-run this script.
pause
exit /b 1
