cmake_minimum_required( VERSION 3.0.2 )
project( shared_lib CXX )
set( SOURCE_LIB src/main.cpp src/cmdhandler/handler.cpp )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_library( kaori SHARED ${SOURCE_LIB} )
add_definitions( -std=gnu++1y -lstdc++ -fPIC)
add_custom_command(TARGET kaori POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:kaori>"
     "../serv/plugins/$<TARGET_FILE_NAME:kaori>" 
  COMMENT "Copying to output directory")
