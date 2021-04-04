cmake_minimum_required (VERSION 3.5)

project (demo2)

# 添加 -std=c++11 选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量   
# aux_source_directory(<dir> <variable>) 使用${}方式获取值
aux_source_directory(. DIR_SRCS)

# 命令表示生成项目的名称是 main
add_executable(main ${DIR_SRCS})