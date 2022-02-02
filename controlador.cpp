#include "controlador.h"

Controlador::Controlador(QObject *parent) : QObject(parent)
{
    this->m_usuario=nullptr;
}

bool Controlador::ingresoDatos(QString fecha, double peso, double altura)
{
    this->m_usuario=new Usuario(fecha,peso,altura);
    return true;
}

bool Controlador::calcularIMC()
{
    if(this->m_usuario==nullptr){
        return false;}
    double imc;

    imc=(m_usuario->peso()/(m_usuario->altura()*m_usuario->altura()))*10000;

    m_usuario->setImc(imc);

    return true;

}

Usuario *Controlador::usuario() const
{
    return m_usuario;
}
