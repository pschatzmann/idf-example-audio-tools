# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)

idf_component_register(SRCS ${app_sources})

# imporant defines
add_compile_definitions(-DESP32_CMAKE -DLOG_LOCAL_LEVEL=ESP_LOG_INFO )
