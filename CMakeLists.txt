# CMakeLists.txt - інструкція для Visual Studio (і не лише), що саме збирати.
cmake_minimum_required(VERSION 3.15)
project(LogReaderAndGenerator CXX)

set(CMAKE_CXX_STANDARD 17)

# Файли в UTF-8: без цього MSVC може зіпсувати кирилицю в рядках
if(MSVC)
    add_compile_options(/utf-8)
endif()

# Дві окремі програми: кожна має свій main()
add_executable(generator generator.cpp)
add_executable(reader reader.cpp)
