// // #include "SDL2/SDL.h"
// #include "SDL.h"
// #include <stdio.h>
// // cmake --build [D:\\dgboy\\OneDrive\\Desktop\\image to text in c]

// int main(int argc, char* argv[]) {
//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO) != 0) {
//         printf("Failed to initialize SDL: %s\n", SDL_GetError());
//         return 1;
//     }

//     // Load image
//     SDL_Surface* imgSurface = SDL_LoadBMP("image.bmp");
//     if (imgSurface == NULL) {
//         printf("Failed to load image: %s\n", SDL_GetError());
//         return 1;
//     }

//     // Convert image to text
//     char textImage[imgSurface->h][imgSurface->w];
//     for (int y = 0; y < imgSurface->h; y++) {
//         for (int x = 0; x < imgSurface->w; x++) {
//             Uint32 pixel = ((Uint32*)imgSurface->pixels)[y * imgSurface->w + x];
//             Uint8 r, g, b;
//             SDL_GetRGB(pixel, imgSurface->format, &r, &g, &b);
//             char character;
//             if ((r + g + b) / 3 > 128) {
//                 character = ' ';
//             } else {
//                 character = '#';
//             }
//             textImage[y][x] = character;
//         }
//     }

//     // Output text image
//     for (int y = 0; y < imgSurface->h; y++) {
//         for (int x = 0; x < imgSurface->w; x++) {
//             printf("%c", textImage[y][x]);
//         }
//         printf("\n");
//     }

//     // Free resources
//     SDL_FreeSurface(imgSurface);
//     SDL_Quit();

//     return 0;
// }


#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // Load image
    SDL_Surface* imgSurface = SDL_LoadBMP("image.bmp");
    if (imgSurface == NULL) {
        printf("Failed to load image: %s\n", SDL_GetError());
        return 1;
    }

    // Convert image to text
    char textImage[imgSurface->h][imgSurface->w];
    for (int y = 0; y < imgSurface->h; y++) {
        for (int x = 0; x < imgSurface->w; x++) {
            Uint32 pixel = ((Uint32*)imgSurface->pixels)[y * imgSurface->w + x];
            Uint8 r, g, b;
            SDL_GetRGB(pixel, imgSurface->format, &r, &g, &b);
            char character;
            if ((r + g + b) / 3 > 128) {
                character = ' ';
            }
            else {
                character = '#';
            }
            textImage[y][x] = character;
        }
    }

    // Output text image
    for (int y = 0; y < imgSurface->h; y++) {
        for (int x = 0; x < imgSurface->w; x++) {
            printf("%c", textImage[y][x]);
        }
        printf("\n");
    }

    // Free resources
    SDL_FreeSurface(imgSurface);

    return 0;
}

