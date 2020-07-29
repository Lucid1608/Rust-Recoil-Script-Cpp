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
	* Simple function to modify the animation time
	*/
	double SmoothPercentage(double animation, double repeat_delay, float percentage = 1.0f);

	/*
	* The basic conversion for the weapons recoil angles to pixels, excluding the scope and weapon FoV
	*/
	Vector2 AngleConversion(Vector2 angles);

	/*
	* Useless function but its there for people to see, Normalizes the vector
	*/
	double AnimationConversion(Vector2 angles);
}

#endif // !_RUST_RECOIL_HPP
