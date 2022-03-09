file(GLOB_RECURSE sources "${CMAKE_SOURCE_DIR}/games/pong/*.cpp")
 
add_executable(pong ${sources})

#set(SDL2_INCLUDE_DIR "C:/hemerson/Projetos/games/SDL2/include")
#set(SDL2_LIBRARY "C:/hemerson/Projetos/games/SDL2/lib/x64")

target_link_directories(pong PUBLIC ${SDL2_LIBRARY})

# include folder
target_include_directories(pong PUBLIC "${CMAKE_SOURCE_DIR}/games/pong/include")
target_include_directories(pong PUBLIC "${CMAKE_SOURCE_DIR}/engine/include")
target_include_directories(pong PUBLIC "${CMAKE_SOURCE_DIR}/vendor/SDL/include")
target_include_directories(pong PUBLIC "${CMAKE_SOURCE_DIR}/vendor/SDL_image/include")
target_include_directories(pong PUBLIC "${CMAKE_SOURCE_DIR}/vendor/box2d/include")

target_link_libraries(pong engine SDL2main SDL2-static SDL2_image box2d)

