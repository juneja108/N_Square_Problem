@echo off
setlocal

g++ -std=c++26 -fmodules-ts -x c++ -c node.cpp -o node.o
if errorlevel 1 exit /b 1

g++ -std=c++26 -fmodules-ts -x c++ -c S.cpp -o S.o
if errorlevel 1 exit /b 1

g++ -std=c++26 -fmodules-ts -x c++ -c grid.cpp -o grid.o
if errorlevel 1 exit /b 1

g++ -std=c++26 -fmodules-ts -c main.cpp -o main.o
if errorlevel 1 exit /b 1

g++ main.o node.o S.o grid.o -lstdc++exp -o a.exe
if errorlevel 1 exit /b 1

a.exe