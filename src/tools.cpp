#include "tools.hpp"

int Tools::Location::getX(const int nX, const int nD)
{
	int rValue, tD;

	tD = nD / 2;
	rValue = nX - tD;

	return rValue;
}

int Tools::Location::getY(const int nY, const int nD)
{
	int rValue, nValue,
	    tD;

	tD = nD / 2;
	nValue = nY * 2;
	nValue = nY - nValue;
	rValue = nValue + tD;

	return rValue;
}

int Tools::Location::rosX(const int nX, const int nD)
{
	/* synopsis:
	 * problem: -5 -4 -3 -2 -1  0  1  2  3  4  5
	 *  answer:  0  1  2  3  4  5  6  7  8  9  10
	 */

	int rX, tX;

	tX = Tools::Location::getX(nD - 1, nD);
	rX = nX + tX;

	return rX;
}

int Tools::Location::rosY(const int nY, const int nD)
{
	/* synopsis:
	 * problem: -5 -4 -3 -2 -1  0  1  2  3  4  5
	 *  answer: 10  9  8  7  6  5  4  3  2  1  0
	 * basically, rosCoordinateX reversed
	 */

	int rY, mY,
	    tY;

	tY = Tools::Location::rosX(nY, nD);
	mY = nY * 2;
	rY = tY - mY;

	return rY;
}

const char * Tools::UI::rtPane(const int yCount)
{
	switch (yCount) {
		case 1:
			return "Health: ";
		default:
			return " ";
	}
}
