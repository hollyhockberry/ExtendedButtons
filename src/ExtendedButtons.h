// Copyright (c) 2023 Inaba (@hollyhockberry)
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#ifndef EXTENDEDBUTTONS_H_
#define EXTENDEDBUTTONS_H_

#include <map>
#include <utility/Button_Class.hpp>

namespace hollyhockberry {

class ExtendedButtons {
  std::map<uint8_t, m5::Button_Class*> _buttons;
 public:
  static ExtendedButtons& Instance();
  void begin();
  void update();
  bool add(uint8_t pin);
  const m5::Button_Class& Button(uint8_t pin);
 private:
  ExtendedButtons() : _buttons() {}
  ExtendedButtons(const ExtendedButtons&) = delete;
  ExtendedButtons& operator=(const ExtendedButtons&) = delete;
};

inline ExtendedButtons& Buttons() {
  return ExtendedButtons::Instance();
}

}

#endif  // EXTENDEDBUTTONS_H_