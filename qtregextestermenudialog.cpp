#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qtregextestermenudialog.h"

#include <cassert>
#include <string>

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include <QIcon>

#include "qtaboutdialog.h"
#include "qtregextestermaindialog.h"
#include "regextesterboostregexmaindialog.h"
#include "regextesterboostxpressivemaindialog.h"
#include "regextestercpp11maindialog.h"
#include "regextestermaindialog.h"
#include "regextestermenudialog.h"
#include "regextesterqtmaindialog.h"
#include "ui_qtregextestermenudialog.h"
#pragma GCC diagnostic pop

ribi::QtRegexTesterMenuDialog::QtRegexTesterMenuDialog(QWidget *parent) :
    QtHideAndShowDialog(parent),
    ui(new Ui::QtRegexTesterMenuDialog)
{
  ui->setupUi(this);
}

ribi::QtRegexTesterMenuDialog::~QtRegexTesterMenuDialog() noexcept
{
  delete ui;
}

void ribi::QtRegexTesterMenuDialog::on_button_about_clicked()
{
  const About a = RegexTesterMenuDialog().GetAbout();
  QtAboutDialog d(a);
  d.setStyleSheet(this->styleSheet());
  this->ShowChild(&d);
}

void ribi::QtRegexTesterMenuDialog::on_button_quit_clicked()
{
  close();
}


void ribi::QtRegexTesterMenuDialog::on_button_cpp11_clicked()
{
  boost::shared_ptr<RegexTesterMainDialog> d(new RegexTesterCpp11MainDialog);
  QtRegexTesterMainDialog qd(d);
  qd.setWindowIcon(QIcon(QPixmap(":/images/PicCpp11.png")));
  this->ShowChild(&qd);
}

void ribi::QtRegexTesterMenuDialog::on_button_qt_clicked()
{
  boost::shared_ptr<RegexTesterMainDialog> d(new RegexTesterQtMainDialog);
  QtRegexTesterMainDialog qd(d);
  qd.setWindowIcon(QIcon(QPixmap(":/images/PicQt.png")));
  this->ShowChild(&qd);
}

void ribi::QtRegexTesterMenuDialog::on_button_boost_regex_clicked()
{
  #ifdef TOOLREGEXTESTER_ADD_BOOST_REGEX
  boost::shared_ptr<RegexTesterMainDialog> d(new RegexTesterBoostRegexMainDialog);
  QtRegexTesterMainDialog qd(d);
  qd.setWindowIcon(QIcon(QPixmap(":/images/PicBoost.png")));
  this->ShowChild(&qd);
  #else
  ui->button_boost_regex->setText("Boost.Regex omitted from (cross)compile");
  #endif
}

void ribi::QtRegexTesterMenuDialog::on_button_boost_xpressive_clicked()
{
  boost::shared_ptr<RegexTesterMainDialog> d(new RegexTesterBoostXpressiveMainDialog);
  QtRegexTesterMainDialog qd(d);
  qd.setWindowIcon(QIcon(QPixmap(":/images/PicBoost.png")));
  this->ShowChild(&qd);
}
