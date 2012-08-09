/**
 * This file is part of hardnet/screendevice.
 * 
 * Copyright 2012 George Goldberg <grundleborg@googlemail.com>
 *
 * License: LGPL 2.1+
 */

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

int main (int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "Lanuching Application.";

    app.exec();

};


