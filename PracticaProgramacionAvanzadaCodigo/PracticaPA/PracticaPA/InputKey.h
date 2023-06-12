#pragma once

class InputKey
{
public:

	InputKey();
	InputKey(unsigned char lowercase, unsigned char uppercase);
	InputKey(int special);
	InputKey(bool newSpecial, unsigned char lowercase, unsigned char uppercase, int special);

	void setKey(unsigned char lowercase, unsigned char uppercase);
	void setKey(int special);

	inline bool const getIsSpecial() const { return this->isSpecial; }
	inline unsigned char const getLowercaseKey() const { return this->keyLowercase; }
	inline unsigned char const getUppercaseKey() const { return this->keyUppercase; }
	inline int const getSpecialKey() const { return this->specialKey; }

	inline bool const keyEquals(unsigned char key) const { return !this->isSpecial && (key == this->keyLowercase || key == this->keyUppercase); }
	inline bool const keyEquals(int val) const { return this->isSpecial && specialKey == val; }
	
	inline bool const getIsPressed() const { return this->isPressed; }
	inline void setIsPressed(bool val) { this->isPressed = val; }

private:
	bool isSpecial, isPressed;
	unsigned char keyLowercase, keyUppercase;
	int specialKey;
};