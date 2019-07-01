project(
    'data_structures',
    'cpp',
    default_options: [
        'cpp_std=c++17',
        'warning_level=3',
    ],
)

catch2_proj = subproject('catch2')
catch2_dep = catch2_proj.get_variable('catch2_dep')

data_structures_lib = library(
    'data_structures library',
)

data_structures_test = executable(
    'test_data_structures',
    sources: [
        'test'/'test_main.cpp',
        'test'/'test_list.cpp',
        'test'/'test_stack.cpp',
        'test'/'test_queue.cpp',
        'test'/'test_queue2.cpp',
        'test'/'test_heap.cpp',
        'test'/'test_binary_tree.cpp',
        'test'/'test_graph.cpp',
    ],
    link_with: data_structures_lib,
    dependencies: catch2_dep,
)

test(
    'tests for data_structures library',
    data_structures_test,
)
