// Copyright (c) 2023 Inaba (@hollyhockberry)
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <M5Unified.h>
#include <ExtendedButtons.h>

// Connect tactSW to SDA and SDL on port A

using hollyhockberry::Buttons;

uint8_t sda, scl;

void setup() {
  M5.begin();
  Buttons().begin();

  sda = M5.getPin(m5::pin_name_t::port_a_sda);
  scl = M5.getPin(m5::pin_name_t::port_a_scl);

  Buttons().add(sda);
  Buttons().add(scl);
}

void loop() {
  Buttons().update();

  if (Buttons().Button(sda).wasPressed()) {
    M5.Speaker.tone(8000, 100);
  }
  if (Buttons().Button(scl).wasPressed()) {
    M5.Speaker.tone(4000, 100);
  }
}