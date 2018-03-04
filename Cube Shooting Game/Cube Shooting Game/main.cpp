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
	SDL_SetRenderDrawColor(renderer, 0, 122, 255, 255);
	SDL_RenderClear(renderer);

	bool loop = true;
	bool BulletExist = false;

	while (loop) {
		SDL_Event e;
		if (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT: //Quit program
				loop = false;
				break;
			case SDL_KEYDOWN: //Movement & Attack
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					RedQuad.y -= 10;
					break;
				case SDLK_DOWN:
					RedQuad.y += 10;
					break;
				case SDLK_LEFT:
					RedQuad.x -= 10;
					break;
				case SDLK_RIGHT:
					RedQuad.x += 10;
					break;
				case SDLK_SPACE:
					BulletExist = true;
					GreenQuad.x = (RedQuad.x) + 80;
					GreenQuad.y = (RedQuad.y) + 30;
					break;
				case SDLK_ESCAPE:
					loop = false;
					break;
				}
				break;
			}
		}

		//Set Borders
		if (RedQuad.x < 0) {
			RedQuad.x = 0;
		}
		if (RedQuad.x == 570) {
			RedQuad.x = 560;
		}
		if (RedQuad.y < 0) {
			RedQuad.y = 0;
		}
		if (RedQuad.y == 410) {
			RedQuad.y = 400;
		}

		//Print Red Quad
		SDL_SetRenderDrawColor(renderer, 255, 10, 50, 255);
		SDL_RenderFillRect(renderer, &RedQuad);

		//Print Green Quad
		if (BulletExist) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 51, 255);
			SDL_RenderFillRect(renderer, &GreenQuad);
			GreenQuad.x += 10;
			SDL_Delay(10);
			if (GreenQuad.x > 630) {
				BulletExist = false;
			}
		}

		SDL_RenderPresent(renderer);

		//Clean Screen
		SDL_SetRenderDrawColor(renderer, 0, 122, 255, 255);
		SDL_RenderClear(renderer);


	}

	SDL_DestroyWindow(window);
	return 0;

}
