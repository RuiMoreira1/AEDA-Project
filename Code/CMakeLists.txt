cmake_minimum_required(VERSION 3.15)
project(AEDAPROJECT)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(AEDAPROJECT main.cpp Vehicle.cpp Vehicle.h Client.cpp Client.h TollBooth.cpp TollBooth.h FileManager.cpp FileManager.h Workers.cpp Workers.h Exceptions.cpp Exceptions.h ProgramLoop.cpp ProgramLoop.h utils.cpp utils.h BST.cpp BST.h priority_queue.cpp priority_queue.h hash_table.cpp hash_table.h menu.cpp menu.h technician.cpp technician.h intervention.cpp intervention.h)