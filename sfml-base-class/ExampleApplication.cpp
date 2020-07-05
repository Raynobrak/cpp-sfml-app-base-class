#include "ExampleApplication.h"

ExampleApplication::ExampleApplication() {
	auto settings = SFMLApplicationSettings();
	settings.applicationName = "Mouse gravity";
	settings.fps = 500.f;
	initApplication(settings);

	shape_.setSize({ 40.f,40.f });
	shape_.setOrigin(shape_.getSize() / 2.f);
	shape_.setPosition(getWindowSize() / 2.f);

	sf::CircleShape baseCircle(30.f);
	baseCircle.setPosition(10.f, 10.f);
	circles_.push_back(baseCircle);
	baseCircle.setPosition(200.f, 30.f);
	circles_.push_back(baseCircle);
	baseCircle.setPosition(30.f, 150.f);
	circles_.push_back(baseCircle);

	velocity_ = { 0.f, 0.f };
}

void ExampleApplication::handleEvent(sf::Event& event) {
	switch (event.type) {
	case sf::Event::Closed:
		exitApplication();
		break;
	case sf::Event::KeyPressed:
		switch (event.key.code) {
		case sf::Keyboard::Escape:
			exitApplication();
			break;
		}
		break;
	case sf::Event::MouseButtonPressed:
		switch (event.mouseButton.button) {
		case sf::Mouse::Button::Left:
			shape_.setPosition(getMousePosOnWindow());
			break;
		}
		break;
	}
}

void ExampleApplication::update(float dt) {
	constexpr float acceleration = 100.f;

	sf::Vector2f delta = getMousePosOnWindow() - shape_.getPosition();
	float distance = sqrtf(delta.x * delta.x + delta.y * delta.y);
	if (distance > 1.f) {
		sf::Vector2f direction = delta / distance;
		velocity_ += dt * acceleration * direction;
	}
	
	shape_.move(velocity_ * dt);
}

void ExampleApplication::customRender() {
	drawOnWindow(shape_);
	for (const auto& c : circles_)
		drawOnWindow(c);
}
