cmake_minimum_required(VERSION 3.14)
project(3D_TEMPLATE)
set(CMAKE_CXX_STANDARD 17)

## ~ CONFIGURE DEPENDENCIES ~
# Set versions of dependencies
set(GLFW_VERSION 3.3.9)
set(GLM_VERSION 1.0.1)

# Optionally use freetype if you want to render font 
# set(FREETYPE_VERSION 2.13.2)
# Non-needed features of freetype
# option(FT_DISABLE_ZLIB ON)
# option(FT_DISABLE_BZIP2 ON)
# option(FT_DISABLE_PNG ON)
# option(FT_DISABLE_HARFBUZZ ON)
# option(FT_DISABLE_BROTLI ON)
# option(FT_DISABLE_GZIP ON)
# option(FT_DISABLE_LZMA ON)

# Do not build other non-important things
option(GLFW_BUILD_DOCS ON)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS ON)

## ~ FETCH DEPENDENCIES ~
# Include FetchContent
include(FetchContent)

# Fetch GLFW
FetchContent_Declare(
    glfw
    URL https://github.com/glfw/glfw/archive/refs/tags/${GLFW_VERSION}.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(glfw)

# Fetch GLM
FetchContent_Declare(
    glm
    URL https://github.com/g-truc/glm/archive/refs/tags/${GLM_VERSION}.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(glm)

# Fetch Freetype
# FetchContent_Declare(
#     freetype
#     URL https://download.savannah.gnu.org/releases/freetype/freetype-${FREETYPE_VERSION}.tar.xz
#     DOWNLOAD_EXTRACT_TIMESTAMP TRUE
# )
# FetchContent_MakeAvailable(freetype)

# Fetch GLAD
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG c
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_Populate(glad)

# Include GLAD
include_directories(${glad_SOURCE_DIR}/include)

## ~ COMPILER SETTINGS ~
# Set compiler flags based on compiler
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") # Check if using GCC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
    # -Wall -Wextra -Wpedantic
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") # Check if using Clang
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

## ~ BUILD FILES ~
# Set which project you would like to build
set(B_TARGET "src")

# Set source files
file(GLOB VENDORS_SOURCES ${glad_SOURCE_DIR}/src/glad.c)
file(GLOB_RECURSE PROJECT_HEADERS ${B_TARGET}/*.h)
file(GLOB_RECURSE PROJECT_SOURCES ${B_TARGET}/*.cpp)
file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          Readme.md
                         .gitattributes
                         .gitignore
                         .gitmodules)

# Add globs to sources
source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})

# Important GLFW definitions
add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

## ~ BUILD PROJECT ~
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${PROJECT_CONFIGS}
                               ${VENDORS_SOURCES})
# Include libraries
target_link_libraries(${PROJECT_NAME} glfw glm freetype)
