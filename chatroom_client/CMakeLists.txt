cmake_minimum_required(VERSION 3.24)
project(chatroom_client)

set(CMAKE_CXX_STANDARD 17)
link_directories(${PROJECT_SOURCE_DIR}/lib)
add_executable(chatroom_client main.cpp Connecting.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32.dll -pthread)
