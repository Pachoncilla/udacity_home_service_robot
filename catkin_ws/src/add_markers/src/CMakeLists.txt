add_executable(add_markers add_markers.cpp)
target_link_libraries(add_markers ${catkin_LIBRARIES})
add_dependencies(add_markers ${catkin_EXPORTED_TARGETS})