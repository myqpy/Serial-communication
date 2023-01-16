cmake_minimum_required(VERSION 3.1)

project(STM32_RK3399)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

option(BUILD_APP "Build  STM32_RK3399 app" OFF)
set(BUILD_APP "Build  STM32_RK3399 app" ON)

# set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O2 -Wall -g -ggdb")
# set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wfatal-errors")

SET(CMAKE_C_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_INCLUDE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/include)

set(STM32_RK3399_include_dirs ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM ${STM32_RK3399_include_dirs})

include_directories(${PROJECT_SOURCE_DIR}/include/)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 配置文件设置静态库
# aux_source_directory(src/settings/ SRC_LIST_SETTINGS)
# add_library(settings ${SRC_LIST_SETTINGS})

# jt808客户端静态库
# aux_source_directory(src/jt808/ DIR_SRCS)
# add_library(${PROJECT_NAME} ${DIR_SRCS})

# 添加依赖
# add_dependencies(${PROJECT_NAME} bcd)
# target_link_libraries(${PROJECT_NAME} bcd)

# set_target_properties(${PROJECT_NAME} PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${proTemp_include_dirs})

if(BUILD_APP)
  add_subdirectory(app)
endif(BUILD_APP)
