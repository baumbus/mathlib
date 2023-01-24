project(math)

add_library(
    math
    emath.hpp
)

set_target_properties(math PROPERTIES LINKER_LANGUAGE CXX)