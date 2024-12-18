# 设置CMake的最低版本
cmake_minimum_required(VERSION 2.8)

# 设置项目的名称
project(Test)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)

# 包含头文件的目录	CMAKE_CXX_STANDARD 表示当前的目录
include_directories(${CMAKE_SOURCE_DIR})

# 添加可执行文件
add_executable(test_program test.cc)

# 可选 如果需要链接到其他的库 可以在这里添加
# target_lin_libraries(test_program <库的名字>)

