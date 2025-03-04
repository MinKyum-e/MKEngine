#pragma once
#include "Commoninclude.h"

namespace mk
{
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		LEFT,RIGHT, UP, DOWN,
		END
	};
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	class Input
	{
	public:

		struct Key
		{
			eKeyCode keyCode;
			eKeyState keyState;
			bool isPressed;
		};

		static bool GetKeyPressed(eKeyCode e) { return keyVector[(UINT)e].keyState == eKeyState::Pressed; }
		static bool GetKeyDown(eKeyCode e) { return keyVector[(UINT)e].keyState == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode e) { return keyVector[(UINT)e].keyState == eKeyState::Up; }



		

		static void Initialize();
		static void Update();
		static void LateUpdate();


		

	private:
		
		static void createKeys();
		static void updateKeys();
		static bool isKeyDown(eKeyCode e);
		static void updateKey(Key& key);
		static void updateKeyDown(Key& key);
		static void updateKeyUp(Key& key);

	private:
		static std::vector<Key> keyVector;


	};

}

