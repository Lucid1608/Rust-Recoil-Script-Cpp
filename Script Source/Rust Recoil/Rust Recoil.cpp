/*
   DISCORD: sector#7111
*/

/* Includes for this file */
#include "Rust Recoil.hpp"

namespace
{
	/* Store the players sensitivity */
	float sensitivity = 0.0f;

	/* Store the players FoV */
	float fov = 90;
}

namespace RecoilFunction
{	
	namespace GetSet
	{
		/*
		* Set sensitivity value
		*/
		void SetSensitivity(float in)
		{
			sensitivity = in;
		}

		/*
		* Get sensitivity value
		*/
		float GetSensitivity()
		{
			return sensitivity;
		}

		/*
		* Set FoV value
		*/
		void SetFov(float in)
		{
			fov = in;
		}

		/*
		* Get FoV value
		*/
		float GetFov()
		{
			return fov;
		}
	}

	/* 
	* Simple function to modify the animation time
	*/
	double SmoothPercentage(double animation, double repeat_delay, float percentage)
	{
		/*
		* What is happening and why is it so autistic?
		* Basically you cannot just increase the animation time by (x) otherwise you will exceed the repeat delay causing the
		* script to become inaccurate and useless. So we get the delta between repeat and animation delay and scale it to the percentage value,
		* then we subtract the delta from the modified delta. Then add that too the animation time, Basically increasing the animation time so that
		* it isn't pulling as accurate as it should be.
		*/

		/* Calculate the difference between repeat and animation */
		double delta = repeat_delay - animation;

		/* Doing it like this instead of just returning it so I can log it too console */
		double new_animation = animation + (delta - (delta * percentage));

		printf("[original] %f [new] %f\n", animation, new_animation);

		/* Return new animation time */
		return new_animation;
	}

	/* 
	* The basic conversion for the weapons recoil angles to pixels, excluding the scope and weapon FoV 
	*/
	Vector2 AngleConversion(Vector2 angles)
	{
		/* initailize the return vector */
		Vector2 pixel_return;

		/* Convert yaw to pixels */
		pixel_return.x = angles.x / (-0.03 * static_cast<double>(sensitivity) * 3.0 * (fov / 100.0));

		/* Convert pitch to pixels */
		pixel_return.y = angles.y / (-0.03 * static_cast<double>(sensitivity) * 3.0 * (fov / 100.0));

		/* Return pixel values */
		return pixel_return;
	}

	/* 
	* Useless function but its there for people to see, Normalizes the vector 
	*/
	double AnimationConversion(Vector2 angles)
	{
		/* Calculate the magnitude of the vector then use rusts special number 20 and convert it to milliseconds */
		return (sqrt(pow(angles.x, 2) + pow(angles.y, 2))) / 20.0 * 1000.0;
	}
}