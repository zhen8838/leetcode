cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 20)
file(GLOB TEST_NAMES CONFIGURE_DEPENDS test_*.cpp)

foreach(test_name ${TEST_NAMES}) 
    get_filename_component(tname ${test_name} NAME_WE)
    add_test(${tname})
endforeach()