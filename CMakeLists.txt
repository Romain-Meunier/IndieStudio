CMAKE_MINIMUM_REQUIRED(VERSION 3.11)
project(indie)				# Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)		# Enable c++14 standard

if (NOT raylib_FOUND)
  INCLUDE(FetchContent)

  FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/master.tar.gz)
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    SET(raylib_FOUND TRUE)
  endif()
endif()

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES  test.cpp PlayersItems/InteractionManager.cpp PlayersItems/Item.cpp PlayersItems/MapManagement.cpp PlayersItems/Player.cpp PlayersItems/Items/Bomb.cpp PlayersItems/Items/BombUp.cpp PlayersItems/Items/Fire.cpp PlayersItems/Items/FireUp.cpp PlayersItems/Items/SpeedUp.cpp PlayersItems/Items/WallPass.cpp raylib_window.cpp raylib_main.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(bomberman ${SOURCE_FILES})
