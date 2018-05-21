from PIL import Image, ImageDraw
from math import log, log2

SCALE = 2
WIDTH = 3*10**SCALE
HEIGHT = 2*10**SCALE

# Plot window
RE_START = -2
RE_END = 1
IM_START = -1
IM_END = 1

im = Image.new('HSV', (WIDTH, HEIGHT), (0, 0, 0))
draw = ImageDraw.Draw(im)

MAX_ITER = 70

def mandelbrot(c):
    z = 0
    n = 0
    while abs(z) <= 2 and n < MAX_ITER:
        z = z*z + c
        n += 1
    return n

for x in range(0, WIDTH):
    if x % 10 == 0:
        print('x = %d (out of %d)' % (x, WIDTH))
    for y in range(0, HEIGHT//2+1):
        # Convert pixel coordinate to complex number
        c = complex(RE_START + (x / WIDTH) * (RE_END - RE_START),
                    IM_START + (y / HEIGHT) * (IM_END - IM_START))
        # Compute the number of iterations
        m = mandelbrot(c)
        # The color depends on the number of iterations
        hue = int(255 * m / MAX_ITER)
        saturation = 200
        value = 255 if m < MAX_ITER else 0
        # Plot the point
        draw.point([x, y], (hue, saturation, value))
        draw.point([x, HEIGHT - y], (hue, saturation, value))

im.convert('RGB').save('output.png', 'PNG')
