#include "../SDL/include/SDL.h"

#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char* argv[]) {
	//Initialize window and renderer
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	//Create window
	window = SDL_CreateWindow("Shooting Cube Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	//Define Red Quad
	SDL_Rect RedQuad;
	RedQuad.x = 0;
	RedQuad.y = 0;
	RedQuad.w = 80;
	RedQuad.h = 80;

	//Define Green Quad
	SDL_Rect GreenQuad;
	GreenQuad.x = (RedQuad.x) + 80;
	GreenQuad.y = (RedQuad.y) + 30;
	GreenQuad.w = 30;
	GreenQuad.h = 10;

	//Print blue blackground
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	bool loop = true;

	while(loop) {
		SDL_Event e;
		if (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				loop = false;
			}
		}
			
	}

	return 0;

}