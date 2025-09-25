cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME vis)
project(${PROJECT_NAME})

set(SFML_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} main.cpp renderer.cpp tools.cpp sorts.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} 
    ${SFML_LIB_DIR}/libsfml-system.so
    ${SFML_LIB_DIR}/libsfml-graphics.so
    ${SFML_LIB_DIR}/libsfml-window.so
)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/build/vis DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin/)