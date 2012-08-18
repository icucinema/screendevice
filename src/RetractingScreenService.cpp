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

#include "RetractingScreenService.h"

#include "HardwareController.h"

#include <QtCore/QDebug>

using namespace Herqq::Upnp;

RetractingScreenService::RetractingScreenService(HardwareController *hardwareController)
    : m_hardwareController(hardwareController)
{

}

RetractingScreenService::~RetractingScreenService()
{

}

qint32 RetractingScreenService::RaiseScreen(const HActionArguments &inArgs,
                                            HActionArguments *outArgs)
{
    m_hardwareController->raiseScreen();

    return UpnpSuccess;
}

qint32 RetractingScreenService::LowerScreen(const HActionArguments &inArgs,
                                            HActionArguments *outArgs)
{
    m_hardwareController->lowerScreen();

    return UpnpSuccess;
}

qint32 RetractingScreenService::GetRetractingStatus(const HActionArguments &inArgs,
                                                   HActionArguments *outArgs)
{
    return UpnpSuccess;
}

qint32 RetractingScreenService::GetPosition(const HActionArguments &inArgs,
                                            HActionArguments *outArgs)
{
    return UpnpSuccess;
}


