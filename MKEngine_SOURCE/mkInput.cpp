#include "mkInput.h"

namespace mk
{
	int ASCI[(UINT)eKeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};
	
	std::vector<Input::Key> Input::keyVector = {};
	
	void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::END; i++)
		{
			Key tKey = {};
			tKey.isPressed = false;
			tKey.keyPad = (eKeyCode)i;
			tKey.keyState = eKeyState::None;
			keyVector.push_back(tKey);
		}
	}
	void Input::Update()
	{
		for (int i = 0; i < keyVector.size(); i++)
		{
			if (GetAsyncKeyState(ASCI[i]) & 0x8000)
			{
				if (keyVector[i].isPressed)
				{
					keyVector[i].keyState = eKeyState::Pressed;
				}
				else
				{
					keyVector[i].keyState = eKeyState::Down;
				}
				keyVector[i].isPressed = true;
			}
			else
			{
				if (keyVector[i].isPressed)
				{
					keyVector[i].keyState = eKeyState::Up;
				}
				else
				{
					keyVector[i].keyState = eKeyState::None;
				}
				keyVector[i].isPressed = false;
			}
		}
	}

	
}