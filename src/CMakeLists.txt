add_library(library "")

target_sources(
        library
        PRIVATE
        sort.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/sort.h
)

target_include_directories(
        library
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)