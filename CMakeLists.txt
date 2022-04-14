# Set CMake minimum required version and project name
cmake_minimum_required(VERSION 3.15)
project(main VERSION 1.0.0 LANGUAGES CXX)

# Generate config.h based on config.h.in
configure_file(
  ${CMAKE_SOURCE_DIR}/include/config.h.in
  ${CMAKE_SOURCE_DIR}/include/config.h
  @ONLY
)

# Generate executable file
add_executable(${PROJECT_NAME})

# Set sources
file(GLOB SOURCES CONFIGURE_DEPENDS
  src/*
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

# Introduce external dependencies
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# Set target properties
set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF

  # Set output directory
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin

  # QT Compiler
  AUTOMOC ON
  AUTOUIC ON
  AUTORCC ON
)

# Exclude debugging information when release type
if(CMAKE_BUILD_TYPE MATCHES Release)
  set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
  )
endif()
