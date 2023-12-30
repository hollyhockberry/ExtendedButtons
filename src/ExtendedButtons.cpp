// Copyright (c) 2023 Inaba (@hollyhockberry)
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <ExtendedButtons.h>
#include <M5Unified.h>

namespace {

m5::Button_Class _dummy;

template<class T>
bool hasKey(std::map<uint8_t, T*> m, int key) {
  return m.find(key) != m.end();
}

}

namespace hollyhockberry {

ExtendedButtons& ExtendedButtons::Instance() {
  static ExtendedButtons o;
  return o;
}

void ExtendedButtons::begin() {
  //TODO: 
  if (_buttons.size() > 0) {
    M5_LOGE("re-initialization..");
  }
}

void ExtendedButtons::update() {
  for (auto itr = _buttons.begin(); itr != _buttons.end(); ++itr) {
    const auto pin = itr->first;
    itr->second->setRawState(m5gfx::millis(), ::digitalRead(pin) == LOW);
  }
}

bool ExtendedButtons::add(uint8_t pin) {
  if (hasKey(_buttons, pin)) {
    return false;
  }
  ::pinMode(pin, INPUT_PULLUP);
  _buttons[pin] = new m5::Button_Class;
  if (_buttons.size() > 5) {
    M5_LOGW("Currently %d registrations", _buttons.size());    
  }
  return true;
}

const m5::Button_Class& ExtendedButtons::Button(uint8_t pin) {
  return hasKey(_buttons, pin) ? *_buttons[pin] : _dummy;
}

} // namespace hollyhockberry