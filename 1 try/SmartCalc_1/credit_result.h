#ifndef CREDIT_RESULT_H
#define CREDIT_RESULT_H

#include <QWidget>

namespace Ui {
class credit_result;
}

class credit_result : public QWidget
{
    Q_OBJECT

public:
    explicit credit_result(QWidget *parent = nullptr);
    ~credit_result();
    void fill_table(double** result, int period);

private:
    Ui::credit_result *ui;
    void createUI(const QStringList &headers);
};

#endif // CREDIT_RESULT_H
