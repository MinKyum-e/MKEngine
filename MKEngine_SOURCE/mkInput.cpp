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
		createKeys();
	}

	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::END; i++)
		{
			Key tKey = {};
			tKey.isPressed = false;
			tKey.keyCode = (eKeyCode)i;
			tKey.keyState = eKeyState::None;
			keyVector.push_back(tKey);
		}
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::updateKeys()
	{
		std::for_each(keyVector.begin(), keyVector.end(),
			[](Key& key)->void {
				updateKey(key);
			});
	}

	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.keyCode))
		{
			updateKeyDown(key);
		}
		else
		{
			updateKeyUp(key);
		}
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.isPressed)
		{
			key.keyState = eKeyState::Pressed;
		}
		else
		{
			key.keyState = eKeyState::Down;
		}
		key.isPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.isPressed)
		{
			key.keyState = eKeyState::Up;
		}
		else
		{
			key.keyState = eKeyState::None;
		}
		key.isPressed = false;
	}


	bool Input::isKeyDown(eKeyCode e)
	{
		return GetAsyncKeyState(ASCI[(UINT)e]) & 0x8000;
	}
	
}