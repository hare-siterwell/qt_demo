# Set CMake minimum required version and project name
cmake_minimum_required(VERSION 3.15)
project(qt_demo VERSION 1.0.0 LANGUAGES CXX)

# Options
option(DEBUG_INFO "Show debugging information" ON)

# Generate config.h based on config.h.in
configure_file(
  ${CMAKE_SOURCE_DIR}/include/config.h.in
  ${CMAKE_SOURCE_DIR}/include/config.h
  @ONLY
)

# Generate executable file
add_executable(${PROJECT_NAME})

# Introduce external dependencies
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# Set sources
file(GLOB SOURCES CONFIGURE_DEPENDS
  src/*
  include/*
)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# Set include directories
target_include_directories(${PROJECT_NAME} PRIVATE
  include
)

# Set compile definitions
target_compile_options(${PROJECT_NAME} PRIVATE)
target_compile_definitions(${PROJECT_NAME} PRIVATE)

# Set link libraries
target_link_options(${PROJECT_NAME} PRIVATE)
target_link_directories(${PROJECT_NAME} PRIVATE)
target_link_libraries(${PROJECT_NAME} PRIVATE
  Qt${QT_VERSION_MAJOR}::Widgets
)

# Set target properties
set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF

  # Set output
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
  DEBUG_POSTFIX "_${PROJECT_VERSION_MAJOR}_${PROJECT_VERSION_MINOR}_debug"
  RELEASE_POSTFIX "_${PROJECT_VERSION_MAJOR}_${PROJECT_VERSION_MINOR}"

  # QT Compiler
  AUTOMOC ON
  AUTOUIC ON
  AUTORCC ON
)

# Exclude debugging information
if(!DEBUG_INFO)
  set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
  )
endif()
