#pragma once
#include <string>
#include "Solid.h"

class Text : public Solid
{
public:

	Text();
	Text(std::string const &newText);
	void Render() override;

	inline std::string const& getText() const { return this->textData; }
	inline void setText(std::string const& newText) { this->textData = newText; }

	inline bool const& getIsScreenSpace() const { return this->isScreenSpace; }
	inline void setIsScreenSpace(bool newScreenSpace) { this->isScreenSpace = newScreenSpace; }

	inline bool const& getIsStroke() const { return this->isStroke; }
	inline void setIsStroke(bool newStroke) { this->isStroke = newStroke; }

private:

	std::string textData;
	bool isScreenSpace;
	bool isStroke;

};