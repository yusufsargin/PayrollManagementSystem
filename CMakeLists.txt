cmake_minimum_required(VERSION 3.17)
project(PayrollManegementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(PayrollManegementSystem main.cpp Screens/Employee/Employee_Main_Screen.cpp Models/People.h Operations/Operations.cpp Models/Employee.h Models/Task.h)