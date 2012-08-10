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

#include "DeviceModelCreator.h"

#include "config.h"

#include <HUpnpCore/HDeviceHost>
#include <HUpnpCore/HDeviceHostConfiguration>

#include <QtCore/QDebug>

using namespace Herqq::Upnp;

AppLogic::AppLogic(QObject *parent)
    : QObject(parent),
      m_deviceHost(0)
{
    qDebug() << "AppLogic Constructed.";
}

AppLogic::~AppLogic()
{
    qDebug() << "AppLogic Destroyed.";
}

void AppLogic::init()
{
    // Initialise the UPnp Device Host
    HDeviceHostConfiguration hostConf;
    hostConf.setDeviceModelCreator(DeviceModelCreator());

    HDeviceConfiguration deviceConf;
    QString xmlpath = UPNP_DESCRIPTION_DIR+QLatin1String("/RetractingScreenDevice.xml");
    qDebug() << xmlpath;
    deviceConf.setPathToDeviceDescription(xmlpath);

    hostConf.add(deviceConf);

    m_deviceHost = new HDeviceHost();
    if (!m_deviceHost->init(hostConf)) {
        qWarning() << "*** Failed to initialise deviceHost.";
        qWarning() << "*** " << m_deviceHost->error();
        qWarning() << "*** " << m_deviceHost->errorDescription();
    }
}


