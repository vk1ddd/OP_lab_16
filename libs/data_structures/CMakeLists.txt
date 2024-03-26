add_library(data_structures
        matrix/matrix.c
        matrix/matrix.h
)

target_link_libraries(data_structures algorithms)
