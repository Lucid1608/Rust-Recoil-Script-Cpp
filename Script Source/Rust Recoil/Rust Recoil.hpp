/*
   DISCORD: sector#7111
*/

#ifndef _RUST_RECOIL_HPP
#define _RUST_RECOIL_HPP

#include "../Structure/Struct.hpp"

namespace RecoilFunction
{
	namespace GetSet
	{
		/*
		* Set sensitivity value
		*/
		void SetSensitivity(float in);

		/*
		* Get sensitivity value
		*/
		float GetSensitivity();

		/*
		* Set FoV value
		*/
		void SetFov(float in);

		/*
		* Get FoV value
		*/
		float GetFov();
	}

	/*
	* The basic conversion for the weapons recoil angles to pixels, excluding the scope and weapon FoV
	*/
	Vector2 angle_conversion(Vector2 angles);

	/*
	* Useless function but its there for people to see, Normalizes the vector
	*/
	double animation_conversion(Vector2 angles);
}

#endif // !_RUST_RECOIL_HPP
