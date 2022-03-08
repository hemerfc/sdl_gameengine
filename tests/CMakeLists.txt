# Testing library
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)
# Adds Catch2::Catch2

# Tests need to be added as executables first
add_executable(testlib testlib.cpp)

# I'm using C++17 in the test
target_compile_features(testlib PRIVATE cxx_std_17)

target_include_directories(testlib PUBLIC "${sdl_games_SOURCE_DIR}/engine/include")
target_include_directories(testlib PUBLIC "${sdl_games_SOURCE_DIR}/tests")
 
set(SDL2_INCLUDE_DIR "C:/hemerson/Projetos/games/SDL2/include")
set(SDL2_LIBRARY "C:/hemerson/Projetos/games/SDL2/lib/x64")

target_link_directories(testlib PUBLIC ${SDL2_LIBRARY})
target_include_directories(testlib PRIVATE ${SDL2_INCLUDE_DIR})

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(testlib PRIVATE engine_lib Catch2::Catch2 SDL2main SDL2 SDL2_image)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME testlibtest COMMAND testlib) # Command can be a target