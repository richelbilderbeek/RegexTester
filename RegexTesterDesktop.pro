include(../RibiLibraries/DesktopApplication.pri)
include(../RibiLibraries/Boost.pri)

include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)

#Specific, console
include(../RibiClasses/CppRibiRegex/CppRibiRegex.pri)

#Specific, desktop
include(../RegexTester/RegexTesterDesktop.pri)

SOURCES += qtmain.cpp
