cmake_minimum_required(VERSION 3.11)
cmake_policy(SET CMP0076 NEW)

project(pract_test C)

set(MYLIB functions)
set (SRC sieve.c point.c circle.c bb.c)
set (HEADERS sieve.h point.h circle.h bb.h)
add_library(${MYLIB})
target_sources(${MYLIB} PRIVATE ${SRC} ${HEADERS}) 
target_link_libraries(${MYLIB} INTERFACE m)

target_compile_options(${MYLIB} PUBLIC "--coverage")
target_link_options(${MYLIB} PUBLIC "--coverage")

set(TEST_PROJECT1 test_pract1)
add_executable(${TEST_PROJECT1})
target_sources(${TEST_PROJECT1} PUBLIC cunit_tests.c)
target_link_libraries(${TEST_PROJECT1} PUBLIC ${MYLIB} cunit)


# CTEST (use test -v to visualize)
enable_testing()
add_test(NAME "MyCunitTest" COMMAND ${TEST_PROJECT1} )


## COVERAGE
add_custom_target(cover
COMMAND cmake --build  . --target test
COMMAND gcovr -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${TEST_PROJECT1}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(cover_html
COMMAND cmake --build . --target test
COMMAND gcovr --html --html-detail -o index.html -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${TEST_PROJECT1}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})








# EXPR GENERATOR
#target_compile_definitions(${PROJECT1} PUBLIC "$<$<CONFIG:Release>:OPTIMIZED=1>")


# V.2
# set(PROJECT2 pract2)
# add_subdirectory(practLib2)
# add_executable(${PROJECT2} main2.c )
# target_link_libraries(${PROJECT2} PUBLIC pract_lib2)


# install(TARGETS pract2)


#find_package(SDL2 REQUIRED)

# find_program(GIT "git")
# message(${GIT})
# find_program(NINJA "ninja")
# message(${NINJA})

# add_custom_target(T1)
# add_custom_command(TARGET T1 
#     COMMAND ${GIT} clone https:://fake.org/fake.git)

## FUNCTION
# function(mytest l)
# message(WARNING "TEST FUNCTION " ${l})
#   foreach(v ${l})
#     message("Loop " ${v})
#   endforeach()
# endfunction()

# mytest("riri;fifi;loulou")

# list (APPEND X "riri")
# message( "append " ${X} )
# list (APPEND X "fifi")
# message( "append " ${X} )
# list (APPEND X "loulou")
# message( "append " ${X} )

# list (REVERSE X )
# message( "append " ${X} )