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

# C++14
QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
# Qt does not go well with -Weffc++
QMAKE_CXXFLAGS += -Wall -Wextra -Werror -std=c++14


# Debug and release mode
CONFIG += debug_and_release
CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

# Qt5
QT += core gui widgets
