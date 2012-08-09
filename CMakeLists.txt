# BEGIN: Boilerplate
cmake_minimum_required(VERSION 2.8.8)
# END: Boilerplate

project(screendevice)

# BEGIN: Boilerplate
find_package(ECM 0.0.4 REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR/cmake})

find_package(KF5 5.0.0 REQUIRED MODULE COMPONENTS CMake Compiler InstallDirs)

include(ECMQtFramework)
find_package(Qt5Transitional REQUIRED Core)

include_directories(
    ${QT_INCLUDES}
    ${CMAKE_CURRENT_BINARY_DIR}
)
# END: Boilerplate

add_subdirectory(src)
