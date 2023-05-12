# cmake_minimum_required(VERSION 3.20)
# set(CMAKE_CXX_STANDARD 17)

# set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../lib")
# 遍历当前目录和子目录
# file(GLOB_RECURSE SRC_DIR_LIST "./*.cpp")

# 只遍历当前目录
# file(GLOB  SRC_DIR_LIST "./*.cpp")

file(GLOB_RECURSE SRC_DIR_LIST "./*.cpp")
message(" build server ")


add_executable(
    chat_server
    ${SRC_DIR_LIST}	
)


# # 指定链接库
target_link_libraries(
    chat_server PUBLIC
    net 
  ) 

# add_subdirectory (tests) # 指定 编译子目录


