// ----------------------------------------------------------------------------
// AT42QT.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef AT42QT_H
#define AT42QT_H
#include <Wire.h>


template<typename RegisterAddress>
class AT42QT
{
public:
  AT42QT(uint8_t device_address,
    uint8_t chip_id,
    TwoWire & wire=Wire,
    int8_t change_pin=-1,
    int8_t reset_pin=-1);

  void begin();
  void hardReset();
  uint8_t getChipId();
  bool communicating();

  typedef void (*Callback)();
  void attachChangeCallback(const Callback callback);

  void triggerCalibration();
  void reset();

private:
  const uint8_t device_address_;
  const uint8_t chip_id_;
  TwoWire * const wire_ptr_;
  const int8_t change_pin_;
  const int8_t reset_pin_;

  const static uint8_t BITS_PER_BYTE = 8;
  const static uint8_t BYTE_MAX = 0xFF;

protected:
  static const uint8_t NONZERO_VALUE = 1;

  template<typename Data>
  void write(RegisterAddress register_address,
    const Data & data);

  template<typename Data>
  void read(RegisterAddress register_address,
    Data & data);
};
#include "AT42QT/AT42QTDefinitions.h"
#endif