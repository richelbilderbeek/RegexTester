#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "regextesterqtmaindialog.h"

#include <sstream>
#include <stdexcept>

#include <QRegExp>

#pragma GCC diagnostic pop

boost::shared_ptr<ribi::RegexTesterMainDialog> ribi::RegexTesterQtMainDialog::Clone() const noexcept
{
  boost::shared_ptr<RegexTesterMainDialog> d(
    new RegexTesterQtMainDialog);
  return d;
}

std::vector<std::string> ribi::RegexTesterQtMainDialog::GetRegexMatches(
  const std::string& s,
  const std::string& r) const
{
  if (!this->GetRegexValid(r)) return std::vector<std::string>();

  return GetRegexMatches(s,QRegExp(r.c_str()));
}

///Obtain all regex matches in a std::string
//From http://www.richelbilderbeek.nl/CppGetRegexMatches.htm
std::vector<std::string> ribi::RegexTesterQtMainDialog::GetRegexMatches(
  const std::string& s,
  const QRegExp& r_original)
{
  QRegExp r = r_original;
  r.setMinimal(true); //QRegExp must be non-greedy
  std::vector<std::string> v;
  int pos = 0;
  while ((pos = r.indexIn(s.c_str(), pos)) != -1)
  {
    const QString q = r.cap(1);
    if (q.isEmpty()) break;
    v.push_back(q.toStdString());
    pos += r.matchedLength();
  }

  return v;
}

bool ribi::RegexTesterQtMainDialog::GetRegexMatchLine(
  const std::string& /* line */,
  const std::string& /* regex_str */) const
{
  std::stringstream msg;
  msg << __func__ << ": Qt does not have a regex match algorithm";
  throw std::logic_error(msg.str());
}

std::string ribi::RegexTesterQtMainDialog::GetRegexReplace(
  const std::string& /* str */,
  const std::string& /* regex_str */,
  const std::string& /* format_str */) const
{
  std::stringstream msg;
  msg << __func__ << ": Qt does not have a regex replace algorithm";
  throw std::logic_error(msg.str());
}


bool ribi::RegexTesterQtMainDialog::GetRegexValid(
  const std::string& /* regex_str */) const
{
  std::stringstream msg;
  msg << __func__ << ": TODO";
  throw std::logic_error(msg.str());
}
