cmake_minimum_required(VERSION 3.21)
project(AiSD)

set(CMAKE_CXX_STANDARD 20)

add_executable(AiSD main.cpp insert_sort.cpp table_based_sort.cpp table_based_sort.h quick_sort.cpp quick_sort.h bucket_sort.cpp bucket_sort.h merge_sort.cpp merge_sort.h merge_sort_iteracyjne.cpp merge_sort_iteracyjne.h heap_sort.cpp heap_sort.h simple_bucket_sort.cpp simple_bucket_sort.h)
