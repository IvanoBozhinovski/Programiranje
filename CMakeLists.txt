cmake_minimum_required(VERSION 3.16)
project(Programiranje_Ivano_Bozhinovski)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE ALL_CPP_FILES CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/*.cpp"
)

foreach(CPP_FILE IN LISTS ALL_CPP_FILES)
    get_filename_component(TARGET_NAME "${CPP_FILE}" NAME_WE)
    add_executable("${TARGET_NAME}" "${CPP_FILE}")
endforeach()