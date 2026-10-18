@echo off
setlocal

echo Building C data-structure modules...
gcc -std=c11 -Wall -Wextra -pedantic -c priority_queue.c -o priority_queue.o
if errorlevel 1 goto failed

gcc -std=c11 -Wall -Wextra -pedantic -c fine_bst.c -o fine_bst.o
if errorlevel 1 goto failed

echo Building C++ application...
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp Vehicle.cpp Parking.cpp ReservationManager.cpp FineAlert.cpp priority_queue.o fine_bst.o -o CampusParkingResolver.exe
if errorlevel 1 goto failed

echo.
echo Build successful. Run CampusParkingResolver.exe
goto end

:failed
echo.
echo Build failed. Check the compiler messages above.
exit /b 1

:end
endlocal
