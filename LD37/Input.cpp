#include "stdafx.h"
#include "Input.h"


Input::Input()
{
}

bool Input::IsPressed(const sf::Keyboard::Key& aKey) const
{
	return myKeyStates.find(aKey) != myKeyStates.end() &&
		myPreviousKeyStates.find(aKey) == myPreviousKeyStates.end();
}

bool Input::IsDown(const sf::Keyboard::Key& aKey) const
{
	return myKeyStates.find(aKey) != myKeyStates.end();
}

bool Input::IsReleased(const sf::Keyboard::Key& aKey) const
{
	return myKeyStates.find(aKey) == myKeyStates.end() &&
		myPreviousKeyStates.find(aKey) != myPreviousKeyStates.end();
}

bool Input::IsPressed(const sf::Mouse::Button& aButton) const
{
	return myButtonStates.find(aButton) != myButtonStates.end() &&
		myPreviousButtonStates.find(aButton) == myPreviousButtonStates.end();
}

bool Input::IsDown(const sf::Mouse::Button& aButton) const
{
	return myButtonStates.find(aButton) != myButtonStates.end();
}

bool Input::IsReleased(const sf::Mouse::Button& aButton) const
{
	return myButtonStates.find(aButton) == myButtonStates.end() &&
		myPreviousButtonStates.find(aButton) != myPreviousButtonStates.end();
}

void Input::Update()
{
	myPreviousKeyStates = myKeyStates;
	myPreviousButtonStates = myButtonStates;
}

void Input::Press(const sf::Keyboard::Key& aKey)
{
	myKeyStates.emplace(aKey);
}

void Input::Release(const sf::Keyboard::Key& aKey)
{
	auto && it = myKeyStates.find(aKey);
	if (it != myKeyStates.end())
	{
		myKeyStates.erase(it);
	}
}

void Input::Press(const sf::Mouse::Button& aButton)
{
	myButtonStates.emplace(aButton);
}

void Input::Release(const sf::Mouse::Button& aButton)
{
	auto && it = myButtonStates.find(aButton);
	if (it != myButtonStates.end())
	{
		myButtonStates.erase(it);
	}
}

void Input::SetMousePosition(const sf::Vector2i& aMousePosition)
{
	myMousePosition.x = static_cast<float>(aMousePosition.x);
	myMousePosition.y = static_cast<float>(aMousePosition.y);
}

const sf::Vector2f& Input::GetMousePosition() const
{
	return myMousePosition;
}

Input::~Input()
{
}
