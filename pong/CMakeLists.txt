add_executable(pong app.cpp)

set(SDL2_INCLUDE_DIR "C:/hemerson/Projetos/games/SDL2/include")
set(SDL2_LIBRARY "C:/hemerson/Projetos/games/SDL2/lib/x64")

target_link_directories(pong PUBLIC ${SDL2_LIBRARY})

target_include_directories(pong PRIVATE ${SDL2_INCLUDE_DIR})
target_include_directories(pong PUBLIC "${sdl_games_SOURCE_DIR}/engine/include")

target_link_libraries(pong engine_lib SDL2main SDL2 SDL2_image)

