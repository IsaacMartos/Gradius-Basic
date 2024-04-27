#include "Input.h"
#include <Windows.h>


InputDirection Input::GetDirection()
{
	if (GetKeyState(VK_UP) & 0x8000)
		return InputDirection::Up;
	else if (GetKeyState(VK_DOWN) & 0x8000)
		return InputDirection::Down;
	else if (GetKeyState(VK_RIGHT) & 0x8000)
		return InputDirection::Right;
	else if (GetKeyState(VK_LEFT) & 0x8000)
		return InputDirection::Left;
	else
		return InputDirection::None;
}
