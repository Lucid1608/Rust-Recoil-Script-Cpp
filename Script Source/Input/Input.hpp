/*
   DISCORD: sector#7111
*/

#ifndef _INPUT_HPP
#define _INPUT_HPP

/* Includes for this file */
#include "../Structure/Struct.hpp"

namespace Input
{
	/*
	* If button is pressed function
	*/
	bool IsPressed(int virtual_key);

	namespace Mouse
	{
		/*
		* Simple lerp function to simulate smooth mouse movement
		*/
		void Lerp(Vector2 pos, double animation, double repeat_delay,std::chrono::time_point<std::chrono::steady_clock> f_excess);
	}
}


#endif // !_INPUT_HPP
