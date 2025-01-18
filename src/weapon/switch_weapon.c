#include "weapon.h"

void	switch_weapon(t_toolbar *toolbar, t_type type)
{
	toolbar->current_weapon = &toolbar->weapons[type];
}
