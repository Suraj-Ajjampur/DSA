#include <stdio.h>
#include <stdlib.h>

// Define the width and height of the Bayer pattern image
#define WIDTH 4
#define HEIGHT 4

// Function to convert Bayer pattern to RGB
void convertBayerToRGB(const unsigned char *bayer, unsigned char *rgb, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the index in the RGB array
            int rgbIndex = (y * width + x) * 3;

            // Red component
            if (y % 2 == 0 && x % 2 == 0) {
                rgb[rgbIndex] = bayer[y * width + x]; // R
                rgb[rgbIndex + 1] = (bayer[y * width + (x + 1)] + bayer[(y + 1) * width + x]) / 2; // G
                rgb[rgbIndex + 2] = bayer[(y + 1) * width + (x + 1)]; // B
            }
            // Green component on a red row
            else if (y % 2 == 0 && x % 2 != 0) {
                rgb[rgbIndex] = bayer[y * width + (x - 1)]; // R
                rgb[rgbIndex + 1] = bayer[y * width + x]; // G
                rgb[rgbIndex + 2] = bayer[(y + 1) * width + x]; // B
            }
            // Green component on a blue row
            else if (y % 2 != 0 && x % 2 == 0) {
                rgb[rgbIndex] = bayer[y * width + x]; // R
                rgb[rgbIndex + 1] = bayer[y * width + (x + 1)]; // G
                rgb[rgbIndex + 2] = bayer[(y - 1) * width + x]; // B
            }
            // Blue component
            else {
                rgb[rgbIndex] = bayer[(y - 1) * width + (x - 1)]; // R
                rgb[rgbIndex + 1] = (bayer[(y - 1) * width + x] + bayer[y * width + (x - 1)]) / 2; // G
                rgb[rgbIndex + 2] = bayer[y * width + x]; // B
            }
        }
    }
}

int main() {
    // Example Bayer data (2x2 pattern repeated for simplicity)
    unsigned char bayer[WIDTH * HEIGHT] = {
        10, 20, 10, 20,
        30, 40, 30, 40,
        10, 20, 10, 20,
        30, 40, 30, 40
    };
    unsigned char rgb[WIDTH * HEIGHT * 3];

    // Convert Bayer to RGB
    convertBayerToRGB(bayer, rgb, WIDTH, HEIGHT);

    // Output the RGB values for demonstration purposes
    for (int i = 0; i < WIDTH * HEIGHT * 3; i += 3) {
        printf("R: %3d G: %3d B: %3d\n", rgb[i], rgb[i + 1], rgb[i + 2]);
    }

    return 0;
}
