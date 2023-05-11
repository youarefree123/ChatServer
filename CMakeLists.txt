cmake_minimum_required(VERSION 3.20)

set( PROJECT_NAME "ChatServer" )
set(CMAKE_CXX_STANDARD 17)

# 设置优化等, 还有 -fPIC 的问题
# set( CXX_FLAG... )
# debug模式S
set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g )

project(${PROJECT_NAME})

# 执行文件输出目录和lib 输出目录

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
message(message : LIBRARY_OUTPUT_PATH =  ${LIBRARY_OUTPUT_PATH} )


# 指定头文件搜索目录
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)



# target_include_directories (
#   ${PROJECT_NAME} PUBLIC 
#   ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog/include
#   ${CMAKE_CURRENT_SOURCE_DIR}/include
# )



# 指定头文件搜索路径（）
# target_include_directories (${CMAKE_CURRENT_SOURCE_DIR}/base  )

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog )


# set(base_DIR ${CMAKE_CURRENT_SOURCE_DIR}/base)
# find_package(base REQUIRED)

# set(spdlog_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog)
# find_package(spdlog REQUIRED)



add_subdirectory ("src") # 加载子目录


# add_subdirectory ("net") # 指定 编译子目录
add_subdirectory ("example") # 指定 编译子目录




# # 指定可执行文件名及源码
# add_executable(${PROJECT_NAME}  main.cpp)


# # 指定头文件
# target_include_directories (
#   ${PROJECT_NAME} PUBLIC 
#   ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog/include
#   # ${CMAKE_CURRENT_SOURCE_DIR}/base/include
  
# )


# 指定链接库
# 没有写包未找到的逻辑
# target_link_libraries(
#   ${PROJECT_NAME} PUBLIC 
#   net 
#   ) 
  
# target_link_libraries(
#   ${PROJECT_NAME} PUBLIC 
#   base 
#   ) 
