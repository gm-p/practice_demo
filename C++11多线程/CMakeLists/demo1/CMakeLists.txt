# 指定运行此配置文件所需的 CMake 的最低版本
cmake_minimum_required (VERSION 3.5)

# 命令表示项目的名称是 demo1
project (demo1)

# 添加 -std=c++11 选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 命令表示生成项目的名称是 test
add_executable(test1 test.cpp)


# https://mp.weixin.qq.com/s/K7JRpuu0KDr19jL_qZ7SSg