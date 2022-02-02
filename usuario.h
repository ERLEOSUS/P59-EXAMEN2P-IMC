#ifndef USUARIO_H
#define USUARIO_H

#include <QObject>

class Usuario : public QObject
{
    Q_OBJECT
public:
    explicit Usuario(QObject *parent = nullptr);
    Usuario(const QString &fecha, double peso, double altura);



    double peso() const;
    void setPeso(double newPeso);

    double altura() const;
    void setAltura(double newAltura);

    const QString &fecha() const;
    void setFecha(const QString &newFecha);

    double pesoMax() const;
    void setPesoMax(double newPesoMax);
    double pesoMin() const;
    void setPesoMin(double newPesoMin);

    double imc() const;
    void setImc(double newImc);

    QString toString()const;

signals:
private:
    QString m_fecha;
    double m_peso;
    double m_altura;
    double m_pesoMax;
    double m_pesoMin;
    double m_imc;

};

#endif // USUARIO_H
