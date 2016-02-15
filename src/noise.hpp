#ifndef APO_NOISE_HPP__
#define APO_NOISE_HPP__

class WhiteNoise
{
private:
    float **noise;
    int width;
    int height;

public:
     WhiteNoise( int width, int height, int seed );
    ~WhiteNoise();

    float getValue( int x, int y );

    int getWidth();
    int getHeight();
};

#endif // APO_NOISE_HPP__
