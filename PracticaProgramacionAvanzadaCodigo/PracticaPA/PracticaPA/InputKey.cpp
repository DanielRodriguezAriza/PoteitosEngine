#include "InputKey.h"

InputKey::InputKey()
:isSpecial{ false }, keyLowercase{ 0 }, keyUppercase{ 0 }, specialKey{ 0 }, isPressed{false}
{}

InputKey::InputKey(unsigned char lowercase, unsigned char uppercase)
:isSpecial{false},keyLowercase{lowercase},keyUppercase{uppercase},specialKey{0},isPressed{false}
{}

InputKey::InputKey(int special)
:isSpecial{true},keyLowercase{0},keyUppercase{0},specialKey{special},isPressed{false}
{}

InputKey::InputKey(bool newSpecial, unsigned char lowercase, unsigned char uppercase, int special)
:isSpecial{newSpecial}, keyLowercase{lowercase}, keyUppercase{uppercase}, specialKey{special}, isPressed{false}
{}

void InputKey::setKey(unsigned char lowercase, unsigned char uppercase)
{
	this->keyLowercase = lowercase;
	this->keyUppercase = uppercase;
	this->isSpecial = false;
}

void InputKey::setKey(int special)
{
	this->specialKey = special;
	this->isSpecial = true;
}