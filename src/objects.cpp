#include "objects.hpp"

/* these functions return variables in the object class */
object_t object::get_type ( void )
{
    return type;
}

int object::get_health ( void )
{
    return health;
}

int object::get_strength ( void )
{
    return strength;
}

int object::get_mass ( void )
{
    return mass;
}

/* these functions set variables in the object class */
void object::set_type ( object_t temp_type )
{
    type = temp_type;
}

void object::set_health ( int temp_health )
{
    health = temp_health;
}

void object::set_strength ( int temp_strength )
{
    strength = temp_strength;
}

void object::set_mass ( int temp_mass )
{
    mass = temp_mass;
}
