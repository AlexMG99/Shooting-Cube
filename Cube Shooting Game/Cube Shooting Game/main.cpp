#include "../SDL/include/SDL.h"
#include "../SDL_Image/include/SDL_image.h"

#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")
#pragma comment(lib, "../SDL_Image/libx86/SDL2_image.lib")

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char* argv[]) {
	//Initialize window and renderer
	SDL_Window* window;
	SDL_Renderer* renderer;

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
	SDL_Rect Bullet[5];
	for (int a = 0; a < 5; a++) {
		Bullet[a].x;
		Bullet[a].y;
		Bullet[a].w = 30;
		Bullet[a].h = 10;
	}
	

	//Print blue blackground
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 122, 255, 255);
	SDL_RenderClear(renderer);

	int numBullet = 0;
	bool loop = true;
	bool moveUp = false;
	bool moveDown = false;
	bool moveRight = false;
	bool moveLeft = false;
	bool bulletExist = false;

	while (loop) {
		SDL_Event e;
		if (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT){ //Quit program
					loop = false;
				}
				if (e.type == SDL_KEYDOWN) {//Movement & Attack
					if (e.key.keysym.sym == SDLK_UP) {
						moveUp = true;
					}
					if (e.key.keysym.sym == SDLK_DOWN) {
						moveDown = true;
					}
					if (e.key.keysym.sym == SDLK_LEFT) {
						moveLeft = true;
					}
					if (e.key.keysym.sym == SDLK_RIGHT) {
						moveRight = true;
					}
					if (e.key.keysym.sym == SDLK_SPACE) {
							Bullet[numBullet].x = (RedQuad.x) + (RedQuad.w);
							Bullet[numBullet].y = (RedQuad.y)+((RedQuad.h)/2-Bullet->h);
							numBullet++;
							if (numBullet == 5) {
								numBullet = 0;
							}
					}
						if (e.key.keysym.sym == SDLK_ESCAPE) {
							loop = false;
						}
					}
				if (e.type == SDL_KEYUP) {
					if (e.key.keysym.sym == SDLK_UP) {
						moveUp = false;
					}
					if (e.key.keysym.sym == SDLK_DOWN) {
						moveDown = false;
					}
					if (e.key.keysym.sym == SDLK_LEFT) {
						moveLeft = false;
					}
					if (e.key.keysym.sym == SDLK_RIGHT) {
						moveRight = false;
					}
				}
				}
				
		

		//Set Borders
		if (RedQuad.x < 0) {
			RedQuad.x = 0;
		}
		if (RedQuad.x > WINDOW_WIDTH-RedQuad.w ) {
			RedQuad.x = WINDOW_WIDTH - RedQuad.w;
		}
		if (RedQuad.y < 0) {
			RedQuad.y = 0;
		}
		if (RedQuad.y > WINDOW_HEIGHT-RedQuad.h) {
			RedQuad.y = WINDOW_HEIGHT - RedQuad.h;
		}

		//Print Red Quad
		SDL_SetRenderDrawColor(renderer, 255, 10, 50, 255);
		SDL_RenderFillRect(renderer, &RedQuad);

		//Print Green Quad
		for (int a = 0; a < 5; a++) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 51, 255);
			SDL_RenderFillRect(renderer, &Bullet[a]);
			Bullet[a].x += 10;
		}

		//Movement
		if (moveUp == true) {
			RedQuad.y -= 5;
		}
		if (moveDown == true) {
			RedQuad.y += 5;
		}
		if (moveLeft == true) {
			RedQuad.x -= 5;
		}
		if (moveRight == true) {
			RedQuad.x += 5;
		}

		SDL_RenderPresent(renderer);

		//Clean Screen
		SDL_SetRenderDrawColor(renderer, 0, 122, 255, 255);
		SDL_RenderClear(renderer);

		SDL_Delay(10);
	}

	SDL_DestroyWindow(window);
	return 0;

}
