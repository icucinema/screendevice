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

#ifndef DEVICEMODELCREATOR_H
#define DEVICEMODELCREATOR_H

#include <HUpnpCore/HDeviceModelCreator>

class HardwareController;

class DeviceModelCreator : public Herqq::Upnp::HDeviceModelCreator {

public:
    explicit DeviceModelCreator(HardwareController *hardwareController);

    virtual Herqq::Upnp::HServerDevice *createDevice(const Herqq::Upnp::HDeviceInfo &info) const;
    virtual Herqq::Upnp::HServerService *createService(const Herqq::Upnp::HServiceInfo &info,
                                                       const Herqq::Upnp::HDeviceInfo &parentDeviceInfo) const;

private:
    virtual DeviceModelCreator *newInstance() const;
    
    HardwareController *m_hardwareController;

};

#endif


