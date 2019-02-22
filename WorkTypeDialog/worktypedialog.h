#ifndef WORKTYPEDIALOG_H
#define WORKTYPEDIALOG_H

#include <QDialog>

namespace Ui {
class WorkTypeDialog;
}

class WorkTypeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorkTypeDialog(QWidget *parent = nullptr);
    ~WorkTypeDialog();

private:
    Ui::WorkTypeDialog *ui;
};

#endif // WORKTYPEDIALOG_H
