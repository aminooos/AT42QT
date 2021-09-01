// ----------------------------------------------------------------------------
// AT42QT1060.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "../AT42QT1060.h"


AT42QT1060::Status AT42QT1060::getStatus()
{
  Status status;
  read(RegisterAddresses::AT42QT1060::DETECTION_STATUS,status.bytes);
  return status;
}

bool AT42QT1060::calibrating()
{
  Status status = getStatus();
  return status.calibrating;
}