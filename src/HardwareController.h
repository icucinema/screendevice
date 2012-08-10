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

#ifndef HARDWARECONTROLLER_H
#define HARDWARECONTROLLER_H

#include <QtCore/QObject>

class QTimer;

class HardwareController : public QObject {

    Q_OBJECT

public:
    enum Position {
        PositionUnknown,
        PositionTop,
        PositionMiddle,
        PositionBottom,
    };
    
    enum Status {
        StatusUnknown,
        StatusLowering,
        StatusStopped,
        StatusRaising,
    };

    explicit HardwareController(QObject *parent = 0);
    virtual ~HardwareController();

    void lowerScreen();
    void raiseScreen();

Q_SIGNALS:
    void positionChanged(HardwareController::Position);
    void statusChanged(HardwareController::Status);

private Q_SLOTS:
    void onFailsafeTimerTimeout();
    void onBottomReached();
    void onTopReached();

private:
    QTimer *m_failsafeTimer;
    Position m_position;
    Status m_status;

};

#endif


