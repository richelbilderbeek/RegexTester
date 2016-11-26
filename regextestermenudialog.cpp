#include "regextestermenudialog.h"

#include <cassert>
#include <iostream>


int ribi::RegexTesterMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc == 1)
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }
  assert(!"TODO");
  return 1;
}

ribi::About ribi::RegexTesterMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "RegexTester",
    "regular expression tester",
    "November 21st of 2015",
    "2010-2015",
    "http://www.richelbilderbeek.nl/ToolRegexTester.htm",
    GetVersion(),
    GetVersionHistory());
  return a;
}

ribi::Help ribi::RegexTesterMenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {

    },
    {

    }
  );
}

std::string ribi::RegexTesterMenuDialog::GetVersion() const noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::RegexTesterMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2010-08-19: Version 1.3: Qt GUI application",
    "2012-01-07: Version 1.4: port to Wt and console application",
    "2012-09-24: Version 1.5: added Qt and C++11 versions",
    "2013-03-20: Version 1.6: added TR1 version, added replace",
    "2013-07-16: Version 1.7: added Boost.Xpressive",
    "2015-11-21: Version 2.0: moved to own GitHub"
  };
}

