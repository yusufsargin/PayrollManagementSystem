cmake_minimum_required(VERSION 3.17)
project(PayrollManegementSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(PayrollManegementSystem main.cpp Screens/Employee/Employee_Main_Screen.cpp Screens/Manager/Manager_Main_Screen.cpp Models/ScreenType.h Models/Storage.cpp Models/HumanResources.h Screens/HumanResources/HumanResources_Main_Screen.cpp Models/Departmans.h Models/People.h Models/Account.h Models/Manager.cpp Models/Team.cpp Operations/Operations.cpp Models/Employee.cpp Models/Task.h Models/Manager.cpp Models/Team.cpp)