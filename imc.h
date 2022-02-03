#ifndef IMC_H
#define IMC_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

#include "controlador.h"


QT_BEGIN_NAMESPACE
namespace Ui { class IMC; }
QT_END_NAMESPACE

class IMC : public QMainWindow
{
    Q_OBJECT

public:
    IMC(QWidget *parent = nullptr);
    ~IMC();

private slots:
    void on_btnCalcular_clicked();



    void on_btnAgregar_clicked();

private:
    Ui::IMC *ui;
    Controlador *m_controlador;
    QList<double>pesos;
    void guardar();
    void calcular();
};
#endif // IMC_H
