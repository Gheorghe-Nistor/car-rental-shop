cmake_minimum_required(VERSION 3.21)
project(Marire_POO)

set(CMAKE_CXX_STANDARD 14)

add_executable(Marire_POO main.cpp Customer.h IOInterface.h RentalShop.h MyException.h Car.h Electric.h Gasoline.h Hybrid.h Warehouse.h InteractiveMenu.h)
