#pragma once

#include"SFML\Graphics.hpp"
#include"Constants.h"

namespace ui {

static enum CornerTypes {
	TOP_RIGHT,
	TOP_LEFT,
	BOTTOM_RIGHT,
	BOTTOM_LEFT,
};

class TextLabel {
public:
	////////////////////////////////////////////////////////////
	///
	/// \brief Creates an empty text label
	/// 
	////////////////////////////////////////////////////////////
	TextLabel();

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a empty text label with a font loaded
	///
	////////////////////////////////////////////////////////////
	TextLabel(const sf::Font& p_font);

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a text with font loaded, a string to draw and a size
	///
	////////////////////////////////////////////////////////////
	TextLabel(const sf::Font& p_font, const std::string& p_text, unsigned int p_fontSize);

	~TextLabel(){}

public:

	// Class methods

	void draw(sf::RenderTarget &target);

	////////////////////////////////////////////////////////////
	///
	/// \brief Returns m_text
	///
	////////////////////////////////////////////////////////////
	const std::string &getText() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets m_text's display string   to a_text
	///
	////////////////////////////////////////////////////////////
	void setText(std::string a_text);

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets m_text's display color to a_color
	///
	////////////////////////////////////////////////////////////
	void setColor(sf::Color a_color);

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets m_text's character size so a_size
	///
	////////////////////////////////////////////////////////////
	void setFontSize(unsigned int a_size);

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets m_text's world postion to a_pos
	///
	////////////////////////////////////////////////////////////
	void setPosition(sf::Vector2f a_pos);

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets m_text's font to a_font
	///
	////////////////////////////////////////////////////////////
	void setFont(sf::Font const &a_font);

	////////////////////////////////////////////////////////////
	///
	/// \brief Centers m_text in the middle of a_screenWidth and a_screenHeight
	///
	////////////////////////////////////////////////////////////
	void centerText(sf::RenderWindow &a_window);

	////////////////////////////////////////////////////////////
	///
	/// \brief Puts m_text at specified corner, look at CornerTypes for available corners
	///
	////////////////////////////////////////////////////////////
	void setCornerPosition(ui::CornerTypes a_corner);

	////////////////////////////////////////////////////////////
	///
	/// \brief Returns m_text's position 
	///
	////////////////////////////////////////////////////////////
	sf::Vector2f getPosition() { return m_text.getPosition(); }

	////////////////////////////////////////////////////////////
	///
	/// \brief Returns an actual reference to the sfml text object used in TextLabel.h
	///
	////////////////////////////////////////////////////////////
	sf::Text &getActualText() { return m_text; }

private:
	sf::Text m_text;
	sf::Font m_font;
};
}