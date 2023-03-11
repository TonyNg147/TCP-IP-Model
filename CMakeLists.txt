project(main)
file(GLOB SRC_FILES ./*cpp
                    ./Utils/*cpp)
add_definitions("-DMODE_DEBUG")
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC Utils)