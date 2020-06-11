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
	* The basic conversion for the weapons recoil angles to pixels, excluding the scope and weapon FoV 
	*/
	Vector2 angle_conversion(Vector2 angles)
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
	double animation_conversion(Vector2 angles)
	{
		/* Calculate the magnitude of the vector then use rusts special number 20 and convert it to milliseconds */
		return (sqrt(pow(angles.x, 2) + pow(angles.y, 2))) / 20.0 * 1000.0;
	}
}