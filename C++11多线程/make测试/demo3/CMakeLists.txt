cmake_minimum_required (VERSION 3.5)

project (demo3)

# 添加 -std=c++11 选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量   
# aux_source_directory(<dir> <variable>) 使用${}方式获取值
aux_source_directory(. DIR_SRCS)

# 添加 hello 子目录
add_subdirectory(hello)

# 命令表示生成项目的名称是 main
add_executable(main ${DIR_SRCS})

# 添加动态库
target_link_libraries(main hello)