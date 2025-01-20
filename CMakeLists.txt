cmake_minimum_required(VERSION 3.24.0)
project(LearnVulkan VERSION 0.1.0 LANGUAGES C CXX)

find_package(Vulkan REQUIRED)
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Application.cpp
    src/Window.cpp
    src/Pipeline.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE SDL3::SDL3
)

target_include_directories(${PROJECT_NAME}
    PUBLIC include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

if(WIN32)
    if(TARGET SDL3::SDL3-shared)
        add_custom_command(
            TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
                $<TARGET_FILE:SDL3::SDL3-shared>
                $<TARGET_FILE_DIR:${PROJECT_NAME}>
            COMMENT "Copying SDL3 shared library to game directory"
            VERBATIM
        )
    else()
        message(FATAL_ERROR "SDL3::SDL3-shared target not found. Ensure SDL3 is correctly linked.")
    endif()
endif()
