#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qtregextestermaindialog.h"

#include <cassert>

#include "regextestermaindialog.h"
#include "regextestermaindialog.h"
#include "ui_qtregextestermaindialog.h"
#pragma GCC diagnostic pop

ribi::QtRegexTesterMainDialog::QtRegexTesterMainDialog(
  const boost::shared_ptr<RegexTesterMainDialog> dialog,
  QWidget *parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtRegexTesterMainDialog),
    m_dialog(dialog)
{
  ui->setupUi(this);

  QObject::connect(ui->edit_line,&QLineEdit::textEdited,this,&ribi::QtRegexTesterMainDialog::onAnyChange);
  QObject::connect(ui->edit_regex,&QLineEdit::textEdited,this,&ribi::QtRegexTesterMainDialog::onAnyChange);
  QObject::connect(ui->edit_format,&QLineEdit::textEdited,this,&ribi::QtRegexTesterMainDialog::onAnyChange);

  ui->edit_regex->setText(m_dialog->GetExampleRegex().c_str());
  ui->edit_format->setText(m_dialog->GetExampleFormat().c_str());
  this->onAnyChange();
}

ribi::QtRegexTesterMainDialog::~QtRegexTesterMainDialog() noexcept
{
  delete ui;
}

void ribi::QtRegexTesterMainDialog::onAnyChange()
{
  const std::string regex_str = ui->edit_regex->text().toStdString();
  const std::string line = ui->edit_line->text().toStdString();
  const std::string format = ui->edit_format->text().toStdString();

  const boost::shared_ptr<RegexTesterMainDialog> dialog = m_dialog->Clone();

  ui->label_regex_valid->setText(
    QString("Regex valid: ") + (dialog->GetRegexValid(regex_str) ? "yes" : "no"));

  if (dialog->GetRegexMatchLine(line,regex_str))
  {
    ui->label_regex_match->setText("Regex matches line: yes");
  }
  else
  {
    ui->label_regex_match->setText("Regex matches line: no");
  }

  if (!dialog->GetRegexMatches(line,regex_str).empty())
  {
    ui->label_regex_found->setText("Regex found in line: yes");
  }
  else
  {
    ui->label_regex_found->setText("Regex found in line: no");
  }

  ui->edit_matching_regexes->clear();

  const std::vector<std::string>& v = dialog->GetRegexMatches(line,regex_str);

  std::for_each(v.begin(),v.end(),
    [this](const std::string& s)
    {
      this->ui->edit_matching_regexes->appendPlainText(
        QString(s.c_str()));

    }
  );

  ui->edit_replaced_regexes->setPlainText( dialog->GetRegexReplace(line,regex_str,format).c_str());
}

