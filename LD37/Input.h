#pragma once
class Input
{
public:
	Input();
	~Input();

	bool IsPressed(const sf::Keyboard::Key & aKey) const;
	bool IsDown(const sf::Keyboard::Key & aKey) const;
	bool IsReleased(const sf::Keyboard::Key & aKey) const;

	bool IsPressed(const sf::Mouse::Button & aButton) const;
	bool IsDown(const sf::Mouse::Button & aButton) const;
	bool IsReleased(const sf::Mouse::Button & aButton) const;

	void Update();

	void Press(const sf::Keyboard::Key & aKey);
	void Release(const sf::Keyboard::Key & aKey);
	void Press(const sf::Mouse::Button & aButton);
	void Release(const sf::Mouse::Button & aButton);

	void SetMousePosition(const sf::Vector2i & aMousePosition);
	const sf::Vector2f & GetMousePosition() const;

private:
	std::unordered_set<sf::Keyboard::Key> myKeyStates;
	std::unordered_set<sf::Keyboard::Key> myPreviousKeyStates;

	std::unordered_set<sf::Mouse::Button> myButtonStates;
	std::unordered_set<sf::Mouse::Button> myPreviousButtonStates;

	sf::Vector2f myMousePosition;
};

