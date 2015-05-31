#ifndef	APO_OBJECTS_HPP
#define	APO_OBJECTS_HPP

/*	objects.hpp: header file for apostle's objects */

/* enumerator that defines object types */
enum	object_t {
	/* entities */
	OBJECT_LIVING,		// living entities (actors, npcs, zombies...)
	/* openables */
	OBJECT_DOOR,		// objects that can be opened to be passed through (doors, windows...)
	OBJECT_CONTAINER,	// objects that can contain other objects (chests, safes...)
	/* consumables */
	OBJECT_FOOD,		// objects that can be consumed for health and hunger (edibles, soups...)
	OBJECT_WATER,		// objects that can be consumed for health and thirst (water, soda...)
	OBJECT_MEDICINE,	// objects that can be consumed for health and sickness (pills, vaccines...)
	/* usables */
	OBJECT_WEAPON,		// objects that can be used to cause damage (guns, bats, knives...)
	OBJECT_USABLE,		// objects that can be used on other objects (keys, matches...)
	/* other */
	OBJECT_MISC,		// objects that have little value (decorations, blood, rocks...)
	OBJECT_UNKNWN		// an unknown object (usually in error)
};

/* main object class */
class	object {
	private:
		object_t
			type;		// the object's type

		int
			health,		// condition of the object
			strength,	// object resistance
			mass;		// combined mass of the object
	public:
		/* these functions return the variables above */
		object_t
			get_type ( void );

		int
			get_health ( void ),
			get_strength ( void ),
			get_mass ( void );

		/* these functions set the variables */
		void
			set_type ( object_t temp_type ),
			set_health ( int temp_health ),
			set_strength ( int temp_strength ),
			set_mass ( int temp_mass );
};

#endif	// APO_OBJECTS_HPP_
