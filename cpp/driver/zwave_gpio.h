/*
 * Copyright 2018 <Admobilize>
 * MATRIX Labs  [http://creator.matrix.one]
 * This file is part of MATRIX Creator HAL
 *
 * MATRIX Creator HAL is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CPP_DRIVER_GPIO_CONTROL_H_
#define CPP_DRIVER_ZWAVE_GPIO_H_
#include <cstdint>
#include <vector>
#include "./matrix_driver.h"

namespace matrix_hal {

enum ZwaveData : uint16_t {
  CS = 0,
  SCK = 1,
  MOSI = 2,
  MISO = 3,
};

enum ZwaveControl : uint16_t {
  MODE = 0,
  NRESET = 1,
};

class ZwaveGPIO : public MatrixDriver {
 public:
  ZwaveGPIO();

  void Setup(MatrixIOBus *bus);
  bool SetControl(uint16_t pin, uint16_t value);
  bool SetData(uint16_t pin, uint16_t value);
  uint16_t GetMISO();

 private:
  uint16_t data_;
  uint16_t control_;
};

};      // namespace matrix_hal
#endif  // CPP_DRIVER_ZWAVE_GPIO_H_
