add_library(xpsdk INTERFACE)

target_include_directories(xpsdk INTERFACE CHeaders/XPLM CHeaders/Widgets)
target_compile_definitions(xpsdk INTERFACE XPLM200=1 XPLM210=1 XPLM300=1 XPLM301=1 XPLM302=1 XPLM303=1)

if (WIN32)
    target_compile_definitions(xpsdk INTERFACE APL=0 IBM=1 LIN=0)
    target_link_libraries(xpsdk INTERFACE Libraries/Win/XPLM_64.lib Libraries/Win/XPWidgets_64.lib)
elseif (APPLE)
    target_compile_definitions(xpsdk INTERFACE APL=1 IBM=0 LIN=0)
    # TODO link
elseif (UNIX)
    target_compile_definitions(xpsdk INTERFACE APL=0 IBM=0 LIN=1)
endif()
