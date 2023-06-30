cmake_minimum_required(VERSION 3.5)

project(list LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable( list

    main.cpp

    list.h

    test.cpp
    test.h
)

install(TARGETS list
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
