#include "imc.h"
#include "ui_imc.h"
#include <cstdlib>

IMC::IMC(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IMC)
{
    ui->setupUi(this);
    m_controlador=new Controlador();
}

IMC::~IMC()
{
    delete ui;
}


void IMC::on_btnCalcular_clicked()
{
    calcular();

}

void IMC::guardar()
{
    // Abrir cuadro de diálogo para seleccionar ubicación y nombre del archivo.
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar archivo",
                                                         QDir::home().absolutePath(),
                                                         "Archivos de IMC (*.slr)");

    // Crear un objeto QFile
    QFile archivo(nombreArchivo);
    // Abrirlo para escritura
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
        // Crear un 'stream' de texto
        QTextStream salida(&archivo);
        // Enviar los datos del resultado a la salida
        salida << m_controlador->usuario()->toString();

        // Mostrar 5 segundo que todo fue bien
        ui->statusbar->showMessage("Datos almacenados en " + nombreArchivo, 5000);
    }else {
        // Mensaje de error si no se puede abrir el archivo
        QMessageBox::warning(this,
                             "Guardar datos",
                             "No se pudo guardar el archivo");
    }
    // Cerrar el archivo
    archivo.close();

}

void IMC::calcular()
{

    QString fecha=ui->inFecha->text();
    double peso= ui->inPeso->value();
    double altura= ui->inAltura->value();
    double pesoMax=peso;
    double pesoMin=peso;

    m_controlador->ingresoDatos(fecha,peso,altura);
    pesos.push_back(m_controlador->usuario()->peso());
    if(pesos.size()>0){
        for(int i=0;i<pesos.size();i++){
            if(pesos.at(i)<pesoMin){
                pesoMin=pesos.at(i);
            }
            if(pesos.at(i)>pesoMax){
                pesoMax=pesos.at(i);
            }
        }
    }
    m_controlador->usuario()->setPesoMin(pesoMin);
    m_controlador->usuario()->setPesoMax(pesoMax);
    if(m_controlador->calcularIMC()){
        ui->outResultado->setText(QString::number(m_controlador->usuario()->imc()));
        ui->outPesoActual->setText(QString::number(m_controlador->usuario()->peso())+" kg");
        ui->outAltura->setText(QString::number(m_controlador->usuario()->altura())+" cm");
        ui->outPesoMin->setText(QString::number(m_controlador->usuario()->pesoMin())+" kg");
        ui->outPesoMax->setText(QString::number(m_controlador->usuario()->pesoMax())+" kg");
        ui->progressBar->setValue(m_controlador->usuario()->imc()+12);

}

}


void IMC::on_btnAgregar_clicked()
{
    guardar();

}

