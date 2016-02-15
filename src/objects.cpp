#include "objects.hpp"

ObjectType Object::get_type ( void )
{
    return type;
}

int Object::get_health ( void )
{
    return health;
}

int Object::get_strength ( void )
{
    return strength;
}

int Object::get_mass ( void )
{
    return mass;
}

void Object::set_type ( ObjectType temp_type )
{
    type = temp_type;
}

void Object::set_health ( int temp_health )
{
    health = temp_health;
}

void Object::set_strength ( int temp_strength )
{
    strength = temp_strength;
}

void Object::set_mass ( int temp_mass )
{
    mass = temp_mass;
}
