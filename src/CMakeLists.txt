cmake_minimum_required(VERSION 3.10.0)  

project(ElfLoader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

set(SOURCE_FILES elf_loader.cpp main.cpp wheelc/list.cpp)

link_directories(./lib)

add_executable(elfloader ${SOURCE_FILES})

include_directories(${PROJECT_SOURCE_DIR}/include)

target_link_libraries(elfloader dl pthread mysymlink)

