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

#include "DeviceModelCreator.h"

#include "RetractingScreenDevice.h"
#include "RetractingScreenService.h"

#include <HUpnpCore/HDeviceInfo>
#include <HUpnpCore/HResourceType>
#include <HUpnpCore/HServiceInfo>

using namespace Herqq::Upnp;

HServerDevice *DeviceModelCreator::createDevice(const HDeviceInfo &info) const
{
    if (info.deviceType().toString() == 
            QLatin1String("urn:schemas-icucinema-co-uk:device:RetractingScreen:1")) {
        return new RetractingScreenDevice();
    }

    return 0;
}

HServerService *DeviceModelCreator::createService(const HServiceInfo &info,
                                                  const HDeviceInfo &parentDeviceInfo) const
{
    if (info.serviceType().toString() == 
            QLatin1String("urn:schemas-icucinema-co-uk:service:RetractingScreen:1")) {
        return new RetractingScreenService();
    }

    return 0;
}

DeviceModelCreator *DeviceModelCreator::newInstance() const
{
    return new DeviceModelCreator();
}


