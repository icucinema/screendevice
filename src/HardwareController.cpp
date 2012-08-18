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

#include "HardwareController.h"

#include <QtCore/QDebug>
#include <QtCore/QTimer>

#include <wiringPi.h>

HardwareController::HardwareController(QObject *parent)
    : QObject(parent),
      m_failsafeTimer(0),
      m_position(PositionTop),
      m_status(StatusStopped)
{
    qDebug() << "Hardware Controller Constructed.";

    // Initialise failsafe timer.
    m_failsafeTimer = new QTimer(this);
    m_failsafeTimer->setInterval(500);

    connect(m_failsafeTimer, SIGNAL(timeout()), this, SLOT(onFailsafeTimerTimeout()));

    // Setup the wiringPi library for GPIO access
    wiringPiSetupGpio();
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);

    qDebug() << "*** HC: Hardware initialisation completed.";
}

HardwareController::~HardwareController()
{
    qDebug() << "HardwareController Destroyed.";
}

void HardwareController::lowerScreen()
{
    // We shouldn't proceed with a lowerScreen if the screen is currently raising.
    if (m_status == StatusRaising) {
        qWarning() << "+++ HC: Received LowerScreen.  Ignoring, due to current raising status.";
        return;
    }
    
    // Check if we have already reached the bottom.
    if (m_position == PositionBottom) {
        qWarning() << "+++ HC: Received LowerScreen.  Ignoring, due to already at bottom.";
        return;
    }

    // Reset timer and issue lower command.
    m_failsafeTimer->start();
    
    if (m_status != StatusLowering) {
        m_status = StatusLowering;
        Q_EMIT statusChanged(m_status);

        qDebug() << "*** HC: Setting Pin.";
        digitalWrite(7, HIGH);
    }

    // If we aren't reporting the screen in the middle, then do so.
    if (m_position != PositionMiddle) {
        m_position = PositionMiddle;
        Q_EMIT positionChanged(m_position);
    }
}

void HardwareController::raiseScreen()
{
    // We shouldn't proceed with a raiseScreen if the screen is currently lowering
    if (m_status == StatusLowering) {
        qWarning() << "+++ HC: Received RaiseScreen.  Ignoring, due to current lowering status.";
        return;
    }
    
    // Check if we have already reached the top
    if (m_position == PositionTop) {
        qWarning() << "+++ HC: Received RaiseScreen.  Ignoring, due to already at top.";
        return;
    }

    // Reset timer and issue raise command.
    m_failsafeTimer->start();
    
    if (m_status != StatusRaising) {
        m_status = StatusRaising;
        Q_EMIT statusChanged(m_status);

        qDebug() << "*** HC: Setting Pin.";
        digitalWrite(8, HIGH);
    }

    // If we aren't reporting the screen in the middle, then do so.
    if (m_position != PositionMiddle) {
        m_position = PositionMiddle;
        Q_EMIT positionChanged(m_position);
    }
}

void HardwareController::onFailsafeTimerTimeout()
{
    m_status = StatusStopped;
    Q_EMIT statusChanged(m_status);

    qDebug() << "*** HC: Failsafe Timer Timeout Out. Stopping Screen.";
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);

    // Stop the FailSafe timer so it doesn't timeout while we are waiting for the next command.
    m_failsafeTimer->stop();
}

void HardwareController::onBottomReached()
{
    if (m_position == PositionBottom) {
        return;
    }

    m_position = PositionBottom;
    Q_EMIT positionChanged(m_position);

    // TODO: Find a way to have the hardware invoke this slot when the screen reaches the bottom.
}

void HardwareController::onTopReached()
{
    if (m_position == PositionTop) {
        return;
    }

    m_position = PositionTop;
    Q_EMIT positionChanged(m_position);
    
    // TODO: Find a way to have the hardware invoke this slot when the screen reaches the top.
}


