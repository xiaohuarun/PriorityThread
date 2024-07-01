cmake_minimum_required(VERSION 3.5)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)

# 添加调试信息
#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 添加可执行文件，并包含源文件 main.cpp 和 global.cpp
add_executable(main main.cpp global.cpp PriorityThread.cpp)

# 将当前源文件目录添加到 main 可执行文件的包含路径中
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 查找并链接线程库
find_package(Threads REQUIRED)
target_link_libraries(main PRIVATE Threads::Threads)

# 添加额外的编译选项，比如 -fpermissive
target_compile_options(main PRIVATE -fpermissive)

