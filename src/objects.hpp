#ifndef	APO_OBJECTS_HPP
#define	APO_OBJECTS_HPP

//	Objects.hpp: header file for apostle's Objects

// enumerator that defines Object types
enum ObjectType {
    // entities
    OBJECT_ENTITY,      // living entities
    // openables
    OBJECT_DOOR,        // Objects that can be opened to be passed through
    OBJECT_CONTAINER,   // Objects that can contain other Objects
    // consumables
    OBJECT_FOOD,        // Objects that can be consumed for health and hunger
    OBJECT_WATER,       // Objects that can be consumed for health and thirst
    OBJECT_MEDICINE,    // Objects that can be consumed for health and sickness
    // usables
    OBJECT_WEAPON,      // Objects that can be used to cause damage
    OBJECT_USABLE,      // Objects that can be used on other Objects
    // other
    OBJECT_MISC,        // Objects that have little value
    OBJECT_UNKNWN       // an unknown Object
};

// main Object class
class Object
{
private:
    ObjectType type;    // the Object's type

    int  health;        // condition of the Object
    int  strength;      // Object resistance
    int  mass;          // combined mass of the Object

public:
    // these functions return the variables above
    ObjectType get_type();

    int  get_health();
    int  get_strength();
    int  get_mass();

    // these functions set the variables
    void set_type(ObjectType temp_type);
    void set_health(int temp_health);
    void set_strength(int temp_strength);
    void set_mass(int temp_mass);
};

#endif	// APO_OBJECTS_HPP_
