set (${PROJECT_NAME}_UPNP_DESCRIPTIONS
     RetractingScreenDevice.xml
     RetractingScreenService.xml
)

install(FILES ${${PROJECT_NAME}_UPNP_DESCRIPTIONS}
        DESTINATION ${UPNP_DESCRIPTIONS_INSTALL_DIR})


