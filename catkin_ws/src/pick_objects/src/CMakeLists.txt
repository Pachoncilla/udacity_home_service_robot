include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(pick_objects pick_objects.cpp)
target_link_libraries(pick_objects ${catkin_LIBRARIES})


