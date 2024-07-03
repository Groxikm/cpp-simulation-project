@echo off
REM Navigate to the C++ project directory
cd Y:\Work-projects\cpp-simulation-project\tests

REM Build the C++ project using CMake
echo Building the C++ project...
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release

REM Check if the build was successful
IF %ERRORLEVEL% NEQ 0 (
    echo Compilation failed!
    pause
    exit /b %ERRORLEVEL%
)

REM Run the compiled executable
echo Running the C++ executable...
build\your_executable.exe

REM Check if the executable ran successfully
IF %ERRORLEVEL% NEQ 0 (
    echo C++ program execution failed!
    pause
    exit /b %ERRORLEVEL%
)

REM Navigate to the Python script directory
cd Y:\Work-projects\cpp-simulation-project\tests

REM Run the Python script with the output CSV file as argument
echo Running the Python script...
python parse_and_visualize_csv.py ..\cpp-project\output.csv

REM Check if the Python script ran successfully
IF %ERRORLEVEL% NEQ 0 (
    echo Python script execution failed!
    pause
    exit /b %ERRORLEVEL%
)

REM Wait for user input before closing the command prompt window
echo Process completed successfully!
pause