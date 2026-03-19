#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_CadLivro_clicked();

    void on_pushButton_CadCliente_clicked();

    void on_pushButton_Operacoes_clicked();

    void on_pushButton_Buscar_clicked();

    void on_pushButton_Relatorios_clicked();

private:
    Ui::MainWindow *ui;
};
class ScrollableMessageBox : public QDialog {
public:
    ScrollableMessageBox(const QString& title, const QString& text, QWidget* parent = nullptr)
        : QDialog(parent) {
        setWindowTitle(title);

        QVBoxLayout* layout = new QVBoxLayout(this);
        QScrollArea* scrollArea = new QScrollArea(this);
        QLabel* label = new QLabel(text, this);
        label->setWordWrap(true);
        scrollArea->setWidget(label);
        scrollArea->setWidgetResizable(true);

        layout->addWidget(scrollArea);

        QPushButton* closeButton = new QPushButton("Fechar Relatório", this);
        connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
        closeButton->setStyleSheet("QPushButton {"
                                   "background-image: url(:/images/cinza.jpg);"
                                   "color: rgb(0, 170, 255);"
                                   "background-repeat: no-repeat;"
                                   "background-position: center;"
                                   "border: none;"
                                   "width: 24px;"
                                   "height: 24px;"
                                   "}");
        layout->addWidget(closeButton);

        setLayout(layout);
        resize(400, 300);
    }
};
#endif // MAINWINDOW_H
