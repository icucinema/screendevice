# BEGIN: Boilerplate
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_definitions(-DQT_NO_CAST_FROM_ASCII)

configure_file(config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)
# END: Boilerplate

set(${PROJECT_NAME}_SRCS
    main.cpp
    AppLogic.cpp
    DeviceModelCreator.cpp
    RetractingScreenDevice.cpp
    RetractingScreenService.cpp
)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS})

target_link_libraries(${PROJECT_NAME}
                      ${QT_QTCORE_LIBRARY}
                      ${HUPNP_LIBS}
)

install(TARGETS ${PROJECT_NAME} ${ECM_TARGET_DEFAULT_ARGS})


