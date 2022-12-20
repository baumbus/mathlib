project(math)

add_library(
    math
    coordinates.hpp
    vector.hpp
)

set_target_properties(math PROPERTIES LINKER_LANGUAGE CXX)