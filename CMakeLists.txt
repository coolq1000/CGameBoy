cmake_minimum_required ( VERSION 3.8.2 )

PROJECT(main C CXX)

set( VERSION_MAJOR 1 )
set( VERSION_MINOR 0 )

# cpp
set ( main_cpp "${PROJECT_SOURCE_DIR}/main.cpp" )
set ( cpu_cpp "${PROJECT_SOURCE_DIR}/src/cpu/cpu.cpp" )

# hpp
set ( main_hpp "${PROJECT_BINARY_DIR}/main.hpp" )
set ( cpu_hpp "${PROJECT_BINARY_DIR}/src/cpu/cpu.hpp" )

# Dirs
set ( main_dir "${PROJECT_BINARY_DIR}" )
set ( cpu_dir "${PROJECT_BINARY_DIR}/src/cpu" )


# STATUS MESSAGES
message( STATUS "main_hpp: ${main_hpp}")
message( STATUS "cpu_hpp: ${cpu_hpp}")


configure_file (
    "${PROJECT_SOURCE_DIR}/src/main/main.hpp.in"
    ${main_hpp}
)

configure_file (
    "${PROJECT_SOURCE_DIR}/src/cpu/cpu.hpp.in"
    ${cpu_hpp}
)

include_directories (
    ${main_dir}
    ${cpu_dir}
    #${EXTERNAL_INSTALL_LOCATION}/include
)

link_directories (
    #${EXTERNAL_INSTALL_LOCATION}/lib
)

add_library( cpu ${cpu_cpp} ${cpu_hpp} )
add_executable( main ${PROJECT_SOURCE_DIR}/src/main/main.cpp ${main_hpp} ${cpu_hpp} )
target_link_libraries( main cpu )



