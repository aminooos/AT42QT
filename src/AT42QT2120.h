// ----------------------------------------------------------------------------
// AT42QT2120.h
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef AT42QT2120_H
#define AT42QT2120_H
#include <Arduino.h>
#include "AT42QT/AT42QT.h"


class AT42QT2120 : public AT42QT
{
public:
  AT42QT2120(TwoWire & wire);
private:
};

#endif