#include "imc.h"
#include "usuario.h"
#include "controlador.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMC w;
    w.show();

   Controlador *objus=new Controlador();
   objus->ingresoDatos("1/1/2022",85,170);
   if(objus->calcularIMC()){
       qDebug()<<objus->usuario()->toString();}
   else{
   qDebug()<<"EROOORRR";
   }
    return a.exec();
}
