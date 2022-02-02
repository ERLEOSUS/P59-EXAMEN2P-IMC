#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>

#include "usuario.h"

class Controlador : public QObject
{
    Q_OBJECT
public:
    explicit Controlador(QObject *parent = nullptr);

    bool ingresoDatos(QString fecha,double peso,double altura);
    bool calcularIMC();




    Usuario *usuario() const;

signals:
private:
   Usuario *m_usuario;

};

#endif // CONTROLADOR_H
