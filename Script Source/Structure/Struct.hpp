/*
   DISCORD: sector#7111
*/

#ifndef _STRUCT_HPP
#define _STRUCT_HPP

/* Includes for this file */
#include <string>
#include <vector>

/* Simple struct for vector2 */
struct Vector2
{
	double x;
	double y;
};

namespace Weapon
{
	/* Weapon information structure */
	struct data
	{
		/* Weapon name */
		std::string type;

		/* Weapon yaw / pitch recoil values */
		std::vector<Vector2> angles;

		/* Weapons repeat delay */
		double repeat_delay;
	};
}

#endif // !_STRUCT_HPP
