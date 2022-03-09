cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME GameEngine)
project(${PROJECT_NAME} LANGUAGES CXX)

# Set build type to debug by default.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Let's nicely support folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS})
#FILE(
#    GLOB src "src/*.h" "src/*.hpp" "src/*.c" "src/*.cpp"
#)
# Copy resource files
#FILE(COPY "${CMAKE_CURRENT_SOURCE_DIR}/res/" DESTINATION "${CMAKE_BINARY_DIR}/res/")

# Add third party libraries.
add_subdirectory(vendor)

# Add engine
add_subdirectory(engine)

# Add games folder
add_subdirectory(games)
