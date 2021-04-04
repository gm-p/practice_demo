cmake_minimum_required (VERSION 3.5)

# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量   
# aux_source_directory(<dir> <variable>) 使用${}方式获取值
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library(hello ${DIR_LIB_SRCS})