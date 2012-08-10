# BEGIN: Boilerplate
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_definitions(-DQT_NO_CAST_FROM_ASCII)

configure_file(config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)
# END: Boilerplate

set(screendevice_SRCS
    main.cpp
    AppLogic.cpp
    DeviceModelCreator.cpp
    RetractingScreenDevice.cpp
    RetractingScreenService.cpp
)

add_executable(screendevice ${screendevice_SRCS})

target_link_libraries(screendevice
                      ${QT_QTCORE_LIBRARY}
                      ${HUPNP_LIBS}
)

install(TARGETS screendevice ${ECM_TARGET_DEFAULT_ARGS})


