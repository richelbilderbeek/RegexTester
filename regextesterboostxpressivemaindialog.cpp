#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "regextesterboostxpressivemaindialog.h"

#include <boost/xpressive/xpressive.hpp>

#include <boost/xpressive/detail/dynamic/parse_charset.hpp>

#include "ribi_regex.h"
#pragma GCC diagnostic pop

ribi::RegexTesterBoostXpressiveMainDialog::RegexTesterBoostXpressiveMainDialog()
{

}


boost::shared_ptr<ribi::RegexTesterMainDialog>
  ribi::RegexTesterBoostXpressiveMainDialog::Clone() const noexcept
{
  boost::shared_ptr<RegexTesterMainDialog> d(
    new RegexTesterBoostXpressiveMainDialog);
  return d;
}

std::vector<std::string>
  ribi::RegexTesterBoostXpressiveMainDialog::GetRegexMatches(
  const std::string& s,
  const std::string& regex_str
) const noexcept
{
  if (!this->GetRegexValid(regex_str)) return std::vector<std::string>();
  return Regex().GetRegexMatchesXpressive(s,regex_str);
  //return GetRegexMatches(s,boost::xpressive::sregex::compile(r));
}

//From http://www.richelbilderbeek.nl/CppGetRegexMatches.htm
/*
std::vector<std::string>
  ribi::RegexTesterBoostXpressiveMainDialog::GetRegexMatches(
  const std::string& s,
  const boost::xpressive::sregex& r)
{
  std::vector<std::string> v;

  try
  {
    boost::xpressive::sregex_iterator cur(s.begin(),s.end(),r);
    boost::xpressive::sregex_iterator end;

    for( ; cur != end; ++cur )
    {
      const boost::xpressive::smatch& what = *cur;
      assert(!what.empty());
      v.push_back(what[0]);
    }
  }
  catch (...)
  {
    v.push_back("UNKNOWN exception");
  }
  return v;
}
*/

bool ribi::RegexTesterBoostXpressiveMainDialog::GetRegexMatchLine(
  const std::string& line,
  const std::string& regex_str
) const noexcept
{
  if (!GetRegexValid(regex_str)) return false;
  const boost::xpressive::sregex r(
    boost::xpressive::sregex::compile(regex_str));
  return boost::xpressive::regex_match(line,r);
}

std::string ribi::RegexTesterBoostXpressiveMainDialog::GetRegexReplace(
  const std::string& str,
  const std::string& regex_str,
  const std::string& format_str) const
{
  try
  {
    return boost::xpressive::regex_replace(
      str,
      boost::xpressive::sregex(boost::xpressive::sregex::compile(regex_str)),
      format_str,
      boost::xpressive::regex_constants::match_default
        | boost::xpressive::regex_constants::format_all
        | boost::xpressive::regex_constants::format_no_copy);
  }
  catch (boost::xpressive::regex_error& e)
  {
    const std::string s
      = "boost::xpressive::regex_error: " + std::string(e.what());
    return "";
  }
}

bool ribi::RegexTesterBoostXpressiveMainDialog::GetRegexValid(
  const std::string& regex_str) const noexcept
{
  return Regex().IsValidXpressive(regex_str);
  /*
  try
  {
    boost::xpressive::sregex::compile(regex_str);
  }
  catch (boost::xpressive::regex_error& e) { return false; }
  return true;
  */
}

