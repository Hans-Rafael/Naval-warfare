cmake_minimum_required(VERSION 3.10)
project(BatallaNaval CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(juego
    "src/main.cpp"
    "src/funciones.cpp"
)
