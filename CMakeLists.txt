# BEGIN: Boilerplate
cmake_minimum_required(VERSION 2.8.8)
# END: Boilerplate

set(PROJECT_NAME screendevice)

# BEGIN: Boilerplate
project(${PROJECT_NAME})

find_package(ECM 0.0.4 REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(KF5 5.0.0 REQUIRED MODULE COMPONENTS CMake Compiler InstallDirs)

include(ECMQtFramework)
find_package(Qt5Transitional REQUIRED Core)

find_package(HUpnp REQUIRED)

include_directories(
    ${QT_INCLUDES}
    ${HUPNP_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(UPNP_DESCRIPTIONS_INSTALL_DIR "${DATA_INSTALL_DIR}/icucinema/hardnet/${PROJECT_NAME}/upnp")
# END: Boilerplate

add_subdirectory(src)
add_subdirectory(xml)


