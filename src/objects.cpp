#include "objects.hpp"

ObjectType Object::getType ( void )
{
    return type;
}

int Object::getHealth ( void )
{
    return health;
}

int Object::getStrength ( void )
{
    return strength;
}

int Object::getMass ( void )
{
    return mass;
}

void Object::getPosition( entity_position *x, entity_position *y )
{
    *x = this->x;
    *y = this->y;
}

void Object::setPosition( entity_position x, entity_position y )
{
    this->x = x;
    this->y = y;
}

void Object::setType ( ObjectType tempType )
{
    type = tempType;
}

void Object::setHealth ( int tempHealth )
{
    health = tempHealth;
}

void Object::setStrength ( int tempStrength )
{
    strength = tempStrength;
}

void Object::setMass ( int tempMass )
{
    mass = tempMass;
}
