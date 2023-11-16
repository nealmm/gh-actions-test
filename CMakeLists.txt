cmake_minimum_required(VERSION 3.10)

project(GHActionsTest)

add_executable(exec main.cpp)
set_target_properties(exec PROPERTIES OUTPUT_NAME "index" SUFFIX ".html")
