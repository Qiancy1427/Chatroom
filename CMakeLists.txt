cmake_minimum_required(VERSION 3.24)

project(chatroom_client)
set(CMAKE_CXX_STANDARD 17)
link_directories(lib)
add_executable(chatroom_client chatroom_client/main.cpp chatroom_client/Connecting.cpp chatroom_client/Render.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32.dll -pthread)

project(chatroom_server)
set(CMAKE_CXX_STANDARD 17)
link_directories(lib)
add_executable(chatroom_server chatroom_server/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32.dll -pthread)