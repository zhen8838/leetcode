cmake_minimum_required(VERSION 3.9)
project(cpp_learn)
 
 
#设定编译参数
set(CMAKE_CXX_STANDARD 20)
 
#设定源码列表.cpp
# aux_source_directory(${CMAKE_SOURCE_DIR} DIR)
# set(SOURCE_FILES "${CMAKE_SOURCE_DIR}/test.cpp")
# set(SOURCE_FILES "${CMAKE_SOURCE_DIR}/test_varg.cpp  ${SOURCE_FILES}")
#比如:aux_source_directory(${CMAKE_SOURCE_DIR} DIR)  

 
#设定头文件路径
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)
#include_directories("路径1"  “路径2”...)
 
 
#设定链接库的路径（一般使用第三方非系统目录下的库）
# link_directories(../build/)
#link_directories("路径1"  “路径2”...)
 
 
#添加子目录,作用相当于进入子目录里面，展开子目录的CMakeLists.txt
#同时执行，子目录中的CMakeLists.txt一般是编译成一个库，作为一个模块
#在父目录中可以直接引用子目录生成的库
#add_subdirectory(math)
 
 
#生成动/静态库
#add_library(动/静态链接库名称  SHARED/STATIC(可选，默认STATIC)  源码列表)
#可以单独生成多个模块
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
 
# find_package(xtensor REQUIRED)
find_library(ACCELERATE_FRAMEWORK Accelerate REQUIRED)
add_compile_options(-Wno-unused-value -Wno-deprecated-anon-enum-enum-conversion -Wno-deprecated-declarations)

#生成可执行文件
# message(${SOURCE_FILES})

macro(add_test name)
  add_executable(${name} ${name}.cpp)
  target_include_directories(${name} PRIVATE ${xtensor_INCLUDE_DIRS})
  target_link_libraries(${name} PRIVATE gtest_main ${ACCELERATE_FRAMEWORK})
endmacro(add_test)

file(GLOB TEST_NAMES CONFIGURE_DEPENDS test_*.cpp)

foreach(test_name ${TEST_NAMES}) 
    get_filename_component(tname ${test_name} NAME_WE)
    add_test(${tname})
endforeach()

add_subdirectory(meta_program)
add_subdirectory(meta_pratice)
#比如：add_executable(hello_world    ${SOURCE_FILES})

 
# target_link_libraries(cpp_test gtest_main)#就是g++ 编译选项中-l后的内容，不要有多余空格
# ADD_CUSTOM_COMMAND( #执行shell命令
#           TARGET myLevelDB 
#           POST_BUILD #在目标文件myLevelDBbuild之后，执行下面的拷贝命令，还可以选择PRE_BUILD命令将
# 会在其他依赖项执行前执行  PRE_LINK命令将会在其他依赖项执行完后执行  POST_BUILD命令将会在目# 标构建完后执行。
#           COMMAND cp ./myLevelDB  ../
# )