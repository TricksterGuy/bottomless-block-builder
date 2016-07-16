cmake_minimum_required(VERSION 2.6)
if(CMAKE_VERSION VERSION_EQUAL 3.0 OR CMAKE_VERSION VERSION_GREATER 3.0)
    # Ignore warnings about rpath behavior on OS X
    cmake_policy(SET CMP0042 NEW)
endif()
project(bottomless-block-builder)

# Require C++11 build
if(NOT CMAKE_CXX_FLAGS MATCHES "-std=(c|gnu)\\+\\+11")
    message(STATUS "This project requires C++11. Adding -std=c++11 to CXXFLAGS.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

# Install directories
set(CMAKE_INSTALL_LIBDIR lib CACHE STRING "where to install libraries/plugins")
set(CMAKE_INSTALL_BINDIR bin CACHE STRING "where to install programs")

# Set default warning flags
set(PROJECT_WARNING_FLAGS "-Wall -Wno-deprecated -Wno-deprecated-declarations" CACHE STRING "Compiler warning flags to include")
mark_as_advanced(PROJECT_WARNING_FLAGS)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PROJECT_WARNING_FLAGS}")

# Default to release build if not specified
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif(NOT CMAKE_BUILD_TYPE)

add_definitions(-DPREFIX=${CMAKE_INSTALL_PREFIX})
add_definitions(-DSO_SUFFIX="${CMAKE_SHARED_LIBRARY_SUFFIX}")
set(wxWidgets_USE_LIBS xrc xml html adv gl net core base)
find_package(wxWidgets REQUIRED)
set(CMAKE_SKIP_RPATH TRUE)
include(${wxWidgets_USE_FILE})

if(CMAKE_HOST_UNIX)
    add_definitions(-DLINUX)
endif(CMAKE_HOST_UNIX)

if(CMAKE_HOST_WIN32)
    add_definitions(-DWINDOWS)
    # Needed for htons
    set(LIBLC3_EXTRA_LIBS ws2_32)
    # Windows doesn't set include directories correctly?
    #include_directories("C:/msys/1.0/local/lib/wx/include/msw-unicode-3.0")
    #include_directories("C:/msys/1.0/local/include/wx-3.0")
endif(CMAKE_HOST_WIN32)

set(SRC_BBB
    BBBApp.cpp
    BBBFrame.cpp
    BBBGui.cpp
    PanelDisplay.cpp
    panel_table.cpp
    solver.cpp
    logger.cpp
    wxlogger.cpp
)

set(SRC_BBBUPDATER
    BBBUpdater.cpp
    logger.cpp
    panel_table.cpp
)

add_executable(
    bottomless-block-builder
    ${SRC_BBB}
)

add_executable(
    bbb_updater
    ${SRC_BBBUPDATER}
)

target_link_libraries(
    bottomless-block-builder
    ${wxWidgets_LIBRARIES}
)


target_link_libraries(
    bbb_updater
)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/bottomless-block-builder DESTINATION ${CMAKE_INSTALL_BINDIR})
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/bbb_updater DESTINATION ${CMAKE_INSTALL_BINDIR})
