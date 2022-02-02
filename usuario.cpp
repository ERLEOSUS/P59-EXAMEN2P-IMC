#include "usuario.h"

Usuario::Usuario(QObject *parent) : QObject(parent)
{
    this->m_peso=0;
    this->m_altura=0;
    this->m_fecha=" ";
}

double Usuario::peso() const
{
    return m_peso;
}

void Usuario::setPeso(double newPeso)
{
    m_peso = newPeso;
}

double Usuario::altura() const
{
    return m_altura;
}

void Usuario::setAltura(double newAltura)
{
    m_altura = newAltura;
}

const QString &Usuario::fecha() const
{
    return m_fecha;
}

void Usuario::setFecha(const QString &newFecha)
{
    m_fecha = newFecha;
}

double Usuario::pesoMax() const
{
    return m_pesoMax;
}

void Usuario::setPesoMax(double newPesoMax)
{
    m_pesoMax = newPesoMax;
}

double Usuario::pesoMin() const
{
    return m_pesoMin;
}

void Usuario::setPesoMin(double newPesoMin)
{
    m_pesoMin = newPesoMin;
}

double Usuario::imc() const
{
    return m_imc;
}

void Usuario::setImc(double newImc)
{
    m_imc = newImc;
}

QString Usuario::toString() const
{
    QString str="";
    str.append(m_fecha+" ");
    str.append(QString::number(m_peso)+" kg ");
    str.append(QString::number(m_altura)+" m ");
    str.append(QString::number(m_imc));
    return str;

}

Usuario::Usuario(const QString &fecha, double peso, double altura) : m_fecha(fecha),
    m_peso(peso),
    m_altura(altura)
{}
