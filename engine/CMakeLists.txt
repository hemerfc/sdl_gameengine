file(GLOB_RECURSE sources "${sdl_games_SOURCE_DIR}/engine/*.cpp")

# create a dinamic lib
add_library(engine_lib ${sources} ${includes})
 
set(SDL2_INCLUDE_DIR "C:/hemerson/Projetos/games/SDL2/include")
set(SDL2_LIBRARY "C:/hemerson/Projetos/games/SDL2/lib/x64")

target_link_directories(engine_lib PUBLIC ${SDL2_LIBRARY})
target_include_directories(engine_lib PRIVATE ${SDL2_INCLUDE_DIR})

# engine include folder
target_include_directories(engine_lib PUBLIC "${sdl_games_SOURCE_DIR}/engine/include")

target_link_libraries(engine_lib SDL2main SDL2 SDL2_image)
