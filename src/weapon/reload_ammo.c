#include "weapon.h"

void	reload_ammo(t_weapon *weapon)
{
	if (weapon->max_ammo > weapon->total_ammo)
	{
		weapon->ammo = weapon->total_ammo;
		weapon->total_ammo = 0;
	}
	else
	{
		weapon->ammo = weapon->max_ammo;
		weapon->total_ammo -= weapon->max_ammo;
	}
	log_info("Reload ammo");
}
