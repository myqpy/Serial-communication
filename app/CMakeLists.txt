
# aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
set(EXE_NAME main)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/ SRC_LIST_APP)
# aux_source_directory(${PROJECT_SOURCE_DIR}/jt808/ SRC_LIST_APP)
add_executable(${EXE_NAME} ${SRC_LIST_APP} )

# aux_source_directory(. DIR_SRCS) add_executable(jt808_zxiat_client
# ${DIR_SRCS})

# add_dependencies(EXE_NAME jt808)
# target_link_libraries(${EXE_NAME} pthread settings date_time_ctrl)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)