@echo off
setlocal

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

echo ============================================================
echo   ESP32-S3 Knob - LittleFS image generator
echo ============================================================
echo.
echo This script ONLY (re)generates the LittleFS filesystem image
echo (littlefs.bin) from the contents of littlefs_data\.
echo.
echo It does NOT flash the device. Use 'idf.py flash' (or the
echo Espressif IDF VSCode extension's flash button) to flash the
echo firmware. Run this generator before your FIRST flash so a
echo valid littlefs.bin exists at the project root.
echo.

REM ----------------------------------------------------------------
REM Locate ESP-IDF v5.5.2's Python interpreter (which has the
REM 'littlefs' package preinstalled).
REM
REM Resolution order:
REM   1. IDF_PATH env var (set by ESP-IDF's export.bat)
REM   2. EW_ESP_ROOT env var (parent 'esp' folder)
REM   3. DEFAULT_ESP_ROOT from the USER CONFIGURATION block above
REM ----------------------------------------------------------------

REM Pick which 'esp' root to use (env var beats the in-file default).
set "ESP_ROOT_CHOSEN="
if defined EW_ESP_ROOT       set "ESP_ROOT_CHOSEN=%EW_ESP_ROOT%"
if not defined ESP_ROOT_CHOSEN if defined DEFAULT_ESP_ROOT set "ESP_ROOT_CHOSEN=%DEFAULT_ESP_ROOT%"

REM Derive IDF_PATH if not already set in the environment.
if not defined IDF_PATH (
    if defined ESP_ROOT_CHOSEN set "IDF_PATH=%ESP_ROOT_CHOSEN%\v5.5.2\esp-idf"
)
if not defined IDF_PATH goto :no_idf

REM Derive IDF_PYTHON if not already set in the environment.
if not defined IDF_PYTHON (
    if defined ESP_ROOT_CHOSEN (
        set "IDF_PYTHON=%ESP_ROOT_CHOSEN%\.espressif\python_env\idf5.5_py3.11_env\Scripts\python.exe"
    )
)
if not defined IDF_PYTHON call :derive_python_from_idf_path
if not defined IDF_PYTHON goto :no_idf
if not exist "%IDF_PYTHON%" goto :python_missing

echo Using IDF_PATH:   %IDF_PATH%
echo Using IDF_PYTHON: %IDF_PYTHON%
echo.

"%IDF_PYTHON%" "%SCRIPT_DIR%littlefs_gen.py" 0x700000 "%SCRIPT_DIR%littlefs_data" "%SCRIPT_DIR%littlefs.bin"
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ERROR: LittleFS image generation failed.
    pause
    exit /b 1
)

echo.
echo ============================================================
echo   littlefs.bin generated successfully
echo ============================================================
echo.
echo Next: flash the device with idf.py (or VSCode's flame icon).
pause
exit /b 0


REM ===== helpers =====================================================

:derive_python_from_idf_path
REM IDF_PATH usually looks like  ...\esp\v5.5.2\esp-idf
REM The Python venv lives at     ...\esp\.espressif\python_env\idf5.5_py3.11_env
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
