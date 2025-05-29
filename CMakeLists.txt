cmake_minimum_required(VERSION 3.24)

project(chatroom_client)
set(CMAKE_CXX_STANDARD 17)
set(EGE_INC_DIR D:/C++/ege24.04/include)
set(EGE_LIB_DIR D:/C++/ege24.04/lib/mingw64/mingw-w64-gcc-8.1.0-x86_64)
include_directories(${EGE_INC_DIR})
link_directories(${EGE_LIB_DIR})
add_executable(chatroom_client chatroom_client/main.cpp chatroom_client/Connecting.h chatroom_client/Render.h)
target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32 -pthread graphics gdi32 gdiplus)
#

project(chatroom_server)
set(CMAKE_CXX_STANDARD 17)
link_directories(lib)
add_executable(chatroom_server chatroom_server/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32.dll -pthread)