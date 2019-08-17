include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)
include(../RibiClasses/CppRibiRegex/CppRibiRegex.pri)
include(../RegexTester/RegexTesterConsole.pri)

SOURCES += main.cpp

QMAKE_CXXFLAGS += -Wall -Wextra -Werror

# Debug and release mode
CONFIG += debug_and_release
CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

# Boost.Program_options
LIBS += -lboost_program_options
