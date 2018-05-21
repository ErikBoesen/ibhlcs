#include <Magick++.h>
#include <iostream>
#include <complex>

#define SCALE 100
#define WIDTH 3*SCALE
#define HEIGHT 2*SCALE

#define RE_START -2
#define RE_END 1
#define IM_START -1
#define IM_END 1

#define MAX_ITER 70

using namespace Magick;

/*int mandelbrot(std::complex<int> c) {
    int z = 0,
        n = 0;
    while (abs(z) <= 2 && n < MAX_ITER) {
        z = z*z + c.real();
        n += 1;
    }
    return n;
}*/

int main(int argc, char *argv[]) {
    //Magick::InitializeMagick(*argv);

    Image image("100x100", "white");
    //image.size(Magick::Geometry(WIDTH, HEIGHT));
}
