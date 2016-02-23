#ifndef APOCLI_TOOLS_H__
#define APOCLI_TOOLS_H__

namespace Tools {
	namespace Location {
		int	getX(const int nX, const int nD),
			getY(const int nY, const int nD),
			/* "Rosetta stone" functions */
			rosX(const int nX, const int nD),
			rosY(const int nX, const int nD);
	}
	namespace UI {
		const char
			*rtPane(const int yCount);
	}
}

#endif
