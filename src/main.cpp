/**
 * This file is part of icucinema/hardnet/screendevice.
 * 
 * Copyright 2012 George Goldberg <grundleborg@googlemail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "AppLogic.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

extern "C"
{
    #include <signal.h>
}

namespace
{
    static void signal_handler(int sig)
    {
        if (sig == SIGTERM || sig == SIGINT)
        {
            QCoreApplication * const qapp(QCoreApplication::instance());
            if (0 != qapp) {
                qapp->quit();
            }
            return;
        }
    }
}

int main (int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Install signal handlers
    if (signal(SIGTERM, signal_handler) == SIG_ERR) {
        qWarning() << "Failed to install handler for SIGTERM.";
    }
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        qWarning() << "Failed to install handler for SIGINT.";
    }

    AppLogic *appLogic = new AppLogic(&app);

    appLogic->init();

    qDebug() << "Lanuching Application.";

    app.exec();
};


