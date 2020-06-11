/*
	This source was made out of boredom and has all the basic features required for a 'good' script, Add all the other shit yourself its not my issue I couldn't be fucked doing it myself. Have fun lel.

	DISCORD: sector#7111
*/

/* Includes for this file */
#include <Windows.h>
#include <map>
#include <thread>

#include "Structure/Struct.hpp"
#include "Input/Input.hpp"
#include "Rust Recoil/Rust Recoil.hpp"
#include "Recoil Data/Recoil Data.hpp"

/* Create a keybinding map */
std::map<int, Weapon::data> keybind_map
{
	{VK_NUMPAD1, RecoilData::assualt_rifle},
	{VK_NUMPAD2, RecoilData::lr_assault_rifle},
	{VK_NUMPAD3, RecoilData::mp5},
	{VK_NUMPAD4, RecoilData::none}
};

/* Initialize current weapon struct */
Weapon::data current;

/*
* Keybinding thread so you can have cool keybinds :o
*/
void KeyBindThread()
{
	/* Initialize an infinite loop */
	while (true)
	{
		/* iterate each weapon in the keybind map */
		for (auto& weapon : keybind_map)
		{
			/* Check if button is pressed */
			if (Input::IsPressed(weapon.first))
			{
				/* Update current with this weapon */
				current = weapon.second;

				/* Log the change in weapon */
				printf("-> Current Weapon [%s]\n", current.type.c_str());

				/* Cute little beep noise */
				Beep(600, 150);

				/* Avoid fat finger button spam */
				SleepEx(150, false);
			}
		}

		/* Keep that CPU on the down low */
		SleepEx(1, false);
	}
}

/* int main where all the goofy shit happens */
int main()
{
	/*
	* You can write your own UI so you can pick your sens & fov realtime
	*/
	{
		/* Set input.sensitivity */
		RecoilFunction::GetSet::SetSensitivity(0.5f);

		/* Set graphics.fov */
		RecoilFunction::GetSet::SetFov(90.0f);

		/* Set the current weapon as none */
		current = RecoilData::none;

		/* Put use to the get functions I wrote so you can see what to do with them */
		printf("-> Sensitivity: %f\n-> FoV: %f\n-> Current Weapon: [%s]\n", RecoilFunction::GetSet::GetSensitivity(), RecoilFunction::GetSet::GetFov(), current.type.c_str());
	}

	/* Create keybind thread */
	std::thread key_binding(KeyBindThread);
	key_binding.detach();

	/* Account for any excess time that has been created whilst calling functions */
	auto f_excess = std::chrono::high_resolution_clock::now();

	/* Create an infinte loop */
	while (true)
	{
		/* Loop while player isn't scoped or shooting */
		while (!(Input::IsPressed(VK_LBUTTON) && Input::IsPressed(VK_RBUTTON)))
		{
			/* Small sleep because this loop needs to be ready to exit */
			std::this_thread::sleep_for(std::chrono::microseconds(1));

			/* Update the excess time point so its very accurate */
			f_excess = std::chrono::high_resolution_clock::now();
		}

		/* Iterate the weapons magazine size */
		for (int bullet = 1; bullet < current.angles.size(); ++bullet)
		{
			/* Exit this loop if the player is no longer shooting */
			if (!Input::IsPressed(VK_LBUTTON)) break;

			/* Calculate this pixel position */
			Vector2 pos = RecoilFunction::angle_conversion(current.angles[bullet]);

			/* Calculate the magnitude of this currents iteration */
			double animation = RecoilFunction::animation_conversion(current.angles[bullet]);

			/* Compensate recoil */
			Input::Mouse::Lerp(pos, animation, current.repeat_delay, f_excess);

			/* Update f_excess for the next iteration so */
			f_excess = std::chrono::high_resolution_clock::now();
		}

		/* Do not continue unless the player is no longer shooting */
		while (Input::IsPressed(VK_LBUTTON))
		{
			/* Small sleep because this loop needs to be ready to exit */
			std::this_thread::sleep_for(std::chrono::microseconds(1));
		}
	}

	/* Return with success */
	return EXIT_SUCCESS;
}