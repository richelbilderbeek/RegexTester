#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "regextestermaindialog.h"
#pragma GCC diagnostic pop

std::vector<std::string> ribi::RegexTesterMainDialog::GetTestRegexes() noexcept
{
  return
  {
    //"\{d}4 [",
    "/",
    "\\",
    "{d}2",
    ""
    //"(\\2)" //Results in crash
  };
}

std::vector<std::string> ribi::RegexTesterMainDialog::GetTestStrings() noexcept
{
  return
  {
    "Test",
    ""
  };
}
