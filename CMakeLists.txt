cmake_minimum_required(VERSION 3.10)
project(GHActionsTest)

add_executable(Main main.cpp)
target_compile_options(Main PRIVATE "-sUSE_SDL=2")
target_link_options(Main PRIVATE "-sUSE_SDL=2")
set_target_properties(Main
    PROPERTIES
    OUTPUT_NAME "index"
    SUFFIX ".html"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist"
)
