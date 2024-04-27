#pragma once

enum class InputDirection {
	Up,
	Down,
	Right,
	Left,
	None
};

class Input
{

public:

	static InputDirection GetDirection();

};

