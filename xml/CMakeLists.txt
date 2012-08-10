set (screendevice_UPNP_DESCRIPTIONS
     RetractingScreenDevice.xml
     RetractingScreenService.xml
)

install(FILES ${screendevice_UPNP_DESCRIPTIONS}
        DESTINATION ${UPNP_DESCRIPTIONS_INSTALL_DIR})


