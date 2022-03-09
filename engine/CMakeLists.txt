file(GLOB_RECURSE sources "${CMAKE_SOURCE_DIR}/engine/*.cpp")

# create a dinamic lib
add_library(engine STATIC ${sources})
 
# Set C++ standard.
set_target_properties(engine PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
) 

# Set compile flags.
target_compile_options(engine PRIVATE
    # Clang
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Weverything>
    # GCC
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic -fdiagnostics-color=always>
    # Visual Studio
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

# engine include folder
target_include_directories(engine PUBLIC "${CMAKE_SOURCE_DIR}/engine/include")
target_include_directories(engine PUBLIC "${CMAKE_SOURCE_DIR}/vendor/SDL/include")
target_include_directories(engine PUBLIC "${CMAKE_SOURCE_DIR}/vendor/SDL_image/include")
target_include_directories(engine PUBLIC "${CMAKE_SOURCE_DIR}/vendor/box2d/include")

target_link_libraries(engine SDL2-static SDL2_image box2d) 