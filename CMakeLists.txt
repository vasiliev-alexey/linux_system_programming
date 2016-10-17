cmake_minimum_required(VERSION 3.5)
project(linux_system_programming)


set (FILE_EXAMPLE_SOURCE
        src/ch1/Main.c
        src/ch1/FileExample.c
        )

add_executable(file_example ${FILE_EXAMPLE_SOURCE})
