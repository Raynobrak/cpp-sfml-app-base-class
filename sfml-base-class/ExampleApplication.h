#pragma once

#include "SFMLApplicationBase.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class ExampleApplication : public SFMLApplicationBase {
public:
	ExampleApplication();

private:
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void customRender() override;

	std::vector<sf::CircleShape> circles_;
	sf::RectangleShape shape_;
	sf::Vector2f velocity_;
};

