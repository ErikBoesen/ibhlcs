#include <Magick++.h>
#include <iostream>
#include <complex>
#include <cmath>

#define SCALE 100
#define WIDTH SCALE
#define HEIGHT SCALE

#define RE_START -2
#define RE_END 1
#define IM_START -1
#define IM_END 1

#define MAX_ITER 70

using namespace Magick;

int mandelbrot(std::complex<int> c) {
    int z = 0,
        n = 0;
    while (abs(z) <= 2 && n < MAX_ITER) {
        z = z*z + c.real();
        n += 1;
    }
    return n;
}

int main(int argc, char *argv[]) {
    Magick::InitializeMagick(*argv);

    Magick::Image image(Magick::Geometry(100, 100), "white");
    image.colorSpace(Magick::HSVColorspace);
    image.type(Magick::TrueColorType);
    image.modifyImage();
    Magick::Pixels view(image);
    Magick::Quantum *pixels = view.get(0, 0, WIDTH, HEIGHT);
    for (int x = 0; x < WIDTH; x++) {
        if (x % 10 == 0) {
            std::cout << "x = " << x << " (out of " << WIDTH << ")" << std::endl;
        }
        for (int y = 0; y < HEIGHT; y++) {
            std::complex<int> c(RE_START + (x / WIDTH) * (RE_END - RE_START),
                                IM_START + (y / HEIGHT) * (IM_END - IM_START));

            int m = mandelbrot(c);

            int hue = 255 * m / MAX_ITER,
                saturation = 200,
                value = m < MAX_ITER ? 255 : 0;
            Magick::ColorHSL color(hue, saturation, value);
            *pixels++ = QuantumRange * color.quantumRed();
            *pixels++ = QuantumRange * color.quantumGreen();
            *pixels++ = QuantumRange * color.quantumBlue();
        }
    }
    view.sync();
    image.syncPixels();
    image.write("output.png");
}
