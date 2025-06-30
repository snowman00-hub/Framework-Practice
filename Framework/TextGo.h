#pragma once
#include "GameObject.h"

class TextGo : public GameObject
{
protected:
	sf::Text text;
	std::string fontId;

public:
	TextGo(const std::string& Id = "", const std::string& name = "");
	~TextGo() override = default;

	const std::string& getFontId() const { return fontId; }
	void setFontId(const std::string& Id) { fontId = Id; }
	const sf::Color& getColor() const { return text.getFillColor(); }
	void setColor(const sf::Color& color) { text.setFillColor(color); }
	int getCharSize() const { return text.getCharacterSize(); }
	void setCharSize(int size);
	const std::string& getString() const { return text.getString(); }
	void setString(const std::string& str);

	void setPosition(const sf::Vector2f& pos) override;
	void setRotation(float rot) override;
	void setScale(const sf::Vector2f& s) override;
	void setOrigin(const sf::Vector2f& o) override;
	void setOrigin(Origins preset) override;

	void init() override;
	void release() override;
	void reset() override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};
