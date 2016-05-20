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

unsigned long Tools::Math::ulong_pow( unsigned long base, unsigned long power )
{
    unsigned long exp = base;

    if (power == 0x00000000) {
        return 0x00000001;
    }

    if (power == 0x00000001) {
        return base;
    }

    for (int i = 0; i < power-1; i++) {
        exp *= base;
    }

    return exp;
}

unsigned long Tools::Math::hex_stage( std::string hex )
{
    unsigned short value;
    unsigned long ret = 0xFF000000;

    int j = 0;
    for (int i = 6; i >= 0; i--) {
        value = 0;
        switch( hex.at(i) )
        {
            case 'f':
            case 'F':
            value = 15;
            break;

            case 'e':
            case 'E':
            value = 14;
            break;

            case 'd':
            case 'D':
            value = 13;
            break;

            case 'c':
            case 'C':
            value = 12;
            break;

            case 'b':
            case 'B':
            value = 11;
            break;

            case 'a':
            case 'A':
            value = 10;
            break;

            case '9':
            value = 9;
            break;

            case '8':
            value = 8;
            break;

            case '7':
            value = 7;
            break;

            case '6':
            value = 6;
            break;

            case '5':
            value = 5;
            break;

            case '4':
            value = 4;
            break;

            case '3':
            value = 3;
            break;

            case '2':
            value = 2;
            break;

            case '1':
            value = 1;
            break;

            default:
            case '0':
            value = 0;
            break;
        }
        ret += static_cast<unsigned long>(value)*ulong_pow(16, j);
        j++;
    }

    return ret;
}
