#ifndef	APO_OBJECTS_HPP
#define	APO_OBJECTS_HPP

/*	Objects.hpp: header file for apostle's Objects */

/* enumerator that defines Object types */
enum ObjectType {
    /* entities */
    OBJECT_LIVING,      /* living entities (actors, npcs, zombies...) */
    /* openables */
    OBJECT_DOOR,        /* Objects that can be opened to be passed through (doors, windows...) */
    OBJECT_CONTAINER,   /* Objects that can contain other Objects (chests, safes...) */
    /* consumables */
    OBJECT_FOOD,        /* Objects that can be consumed for health and hunger (edibles, soups...) */
    OBJECT_WATER,       /* Objects that can be consumed for health and thirst (water, soda...) */
    OBJECT_MEDICINE,    /* Objects that can be consumed for health and sickness (pills, vaccines...) */
    /* usables */
    OBJECT_WEAPON,      /* Objects that can be used to cause damage (guns, bats, knives...) */
    OBJECT_USABLE,      /* Objects that can be used on other Objects (keys, matches...) */
    /* other */
    OBJECT_MISC,        /* Objects that have little value (decorations, blood, rocks...) */
    OBJECT_UNKNWN       /* an unknown Object (usually in error) */
};

/* main Object class */
class Object
{
private:
    ObjectType type;    /* the Object's type */

    int  health;        /* condition of the Object */
    int  strength;      /* Object resistance */
    int  mass;          /* combined mass of the Object */

public:
    /* these functions return the variables above */
    ObjectType get_type();

    int  get_health();
    int  get_strength();
    int  get_mass();

    /* these functions set the variables */
    void set_type(ObjectType temp_type);
    void set_health(int temp_health);
    void set_strength(int temp_strength);
    void set_mass(int temp_mass);
};

#endif	// APO_OBJECTS_HPP_
