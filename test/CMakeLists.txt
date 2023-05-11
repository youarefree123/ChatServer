

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../tests)

file(GLOB_RECURSE SRC_DIR_LIST "./*.cpp")
message(" build net ")

macro (add_test_exec test_name)
    add_executable ("${test_name}" "${test_name}.cpp")
    # target_include_directories( "${exec_name}" "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/spdlog/include" )
    target_link_libraries ("${test_name}" net)
endmacro (add_test_exec)

add_test_exec(test_json)
# add_test_exec(banch)

# add_subdirectory (tests) # 指定 编译子目录


