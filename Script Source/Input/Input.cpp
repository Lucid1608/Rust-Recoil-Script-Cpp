/*
   DISCORD: sector#7111
*/

/* Includes for this file */
#include <Windows.h>
#include <chrono>

#include "Input.hpp"
#include "../Time/Time.hpp"
// george floyd deserved it

namespace Input
{

	/*
	* If button is pressed function
	*/
	bool IsPressed(int virtual_key)
	{
		/* Check if key is being pressed using GetAsyncKeyState */
		if (GetAsyncKeyState(virtual_key) & 0x8000) return true;

		/* Return false if the button is not being pressed */
		return false;
	}

	namespace Mouse
	{
		/*
		* Relative mouse move function
		*/
		inline bool RelaitiveMove(Vector2 pos)
		{
			INPUT input;
			input.type = INPUT_MOUSE;
			input.mi.mouseData = 0;
			input.mi.time = 0;
			input.mi.dx = static_cast<int>(pos.x);
			input.mi.dy = static_cast<int>(pos.y);
			input.mi.dwFlags = MOUSEEVENTF_MOVE;
			return SendInput(1, &input, sizeof(input));
		}

		/*
		* Simple lerp function to simulate smooth relative mouse movement
		*/
		void Lerp(Vector2 pos, double animation, double repeat_delay, std::chrono::time_point<std::chrono::steady_clock> f_excess)
		{
			/* Begin a time point to try to account for any discrepancies */
			std::chrono::time_point<std::chrono::steady_clock> excess = f_excess;

			/* Initailize values to store previous value */
			int previous_x = 0, previous_y = 0;

			/* Iterate the animation time to get '1ms' */
			for (int index = 1; index < static_cast<int>(animation); index++)
			{
				/* Create a lerped x value */
				int x = index * static_cast<int>(pos.x) / static_cast<int>(animation);

				/* Create a lerped y value */
				int y = index * static_cast<int>(pos.y) / static_cast<int>(animation);

				/* Compensate recoil */
				RelaitiveMove(Vector2{ static_cast<double>(x - previous_x), static_cast<double>(y - previous_y)});

				/* Sleep for 1ms because thats just what it is */
				Time::Sleep(1, excess);

				/* Update the excess timepoint */
				excess = std::chrono::high_resolution_clock::now();

				/* set the previous values */
				previous_x = x; previous_y = y;
			}

			/* If animation is greater than repeat delay then dont sleep its not necessary */
			if (repeat_delay - animation > 0) Time::Sleep(repeat_delay - animation, excess);
		}
	}


}