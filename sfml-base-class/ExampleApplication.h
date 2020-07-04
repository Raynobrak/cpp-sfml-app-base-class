#pragma once

#include "SFMLApplicationBase.h"

#include <SFML/Graphics/RectangleShape.hpp>

class ExampleApplication : public SFMLApplicationBase {
public:
	ExampleApplication();

private:
	void handleEvent(sf::Event& event) override;
	void update(float dt) override;
	void customRender() override;

	sf::RectangleShape shape_;
	sf::Vector2f velocity_;
};

