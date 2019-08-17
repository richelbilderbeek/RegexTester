include(../RibiLibraries/Boost.pri)

include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)
include(../RibiClasses/CppQtAboutDialog/CppQtAboutDialog.pri)
include(../RibiClasses/CppQtHideAndShowDialog/CppQtHideAndShowDialog.pri)

#Specific, console
include(../RibiClasses/CppRibiRegex/CppRibiRegex.pri)

#Specific, desktop
include(../RegexTester/RegexTesterDesktop.pri)

SOURCES += qtmain.cpp

QMAKE_CXXFLAGS += -Wall -Wextra -Werror

# Debug and release mode
CONFIG += debug_and_release
CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

# Qt5
QT += core gui widgets
