@echo off
echo Compilando el proyecto...
gcc -Wall -Wextra -g3 main.c get_next_line.c get_next_line_utils.c -o main.exe
if %ERRORLEVEL% NEQ 0 (
    echo Error durante la compilacion.
    pause
    exit /b %ERRORLEVEL%
) else (
    echo Compilacion exitosa.
    pause
)
