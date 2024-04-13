cmake_minimum_required(VERSION 2.8.11)
project(Algorithm_Note)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 子目录
add_subdirectory("${PROJECT_SOURCE_DIR}/数组")
add_subdirectory("${PROJECT_SOURCE_DIR}/字符串")
add_subdirectory("${PROJECT_SOURCE_DIR}/经典设计")
add_subdirectory("${PROJECT_SOURCE_DIR}/排序")
add_subdirectory("${PROJECT_SOURCE_DIR}/树")
add_subdirectory("${PROJECT_SOURCE_DIR}/栈和队列")
add_subdirectory("${PROJECT_SOURCE_DIR}/链表")
add_subdirectory("${PROJECT_SOURCE_DIR}/其他")
add_subdirectory("${PROJECT_SOURCE_DIR}/动态规划")



