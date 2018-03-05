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
	SDL_Rect GreenQuad[5];
	for (int a = 0; a < 5; a++) {
		GreenQuad[a].x = NULL;
		GreenQuad[a].y = NULL;
		GreenQuad[a].w = NULL;
		GreenQuad[a].h = NULL;
	}
	

	//Print blue blackground
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 122, 255, 255);
	SDL_RenderClear(renderer);

	int numBullet = 0;
	bool loop = true;
	bool BulletExist = false;
	bool moveUp = false;
	bool moveDown = false;
	bool moveRight = false;
	bool moveLeft = false;

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
						BulletExist = true;
						//5 Bullets
						switch (numBullet) {
						case 0:
							GreenQuad[0].x = (RedQuad.x) + 80;
							GreenQuad[0].y = (RedQuad.y) + 30;
							GreenQuad[0].w = 30;
							GreenQuad[0].h = 10;
							numBullet++;
							break;
						case 1:
							GreenQuad[1].x = (RedQuad.x) + 80;
							GreenQuad[1].y = (RedQuad.y) + 30;
							GreenQuad[1].w = 30;
							GreenQuad[1].h = 10;
							numBullet++;
							break;
						case 2:
							GreenQuad[2].x = (RedQuad.x) + 80;
							GreenQuad[2].y = (RedQuad.y) + 30;
							GreenQuad[2].w = 30;
							GreenQuad[2].h = 10;
							numBullet++;
							break;
						case 3:
							GreenQuad[3].x = (RedQuad.x) + 80;
							GreenQuad[3].y = (RedQuad.y) + 30;
							GreenQuad[3].w = 30;
							GreenQuad[3].h = 10;
							numBullet++;
							break;
						case 4:
							GreenQuad[4].x = (RedQuad.x) + 80;
							GreenQuad[4].y = (RedQuad.y) + 30;
							GreenQuad[4].w = 30;
							GreenQuad[4].h = 10;
							numBullet = 0;
							break;
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
		if (RedQuad.x == 570) {
			RedQuad.x = 560;
		}
		if (RedQuad.y < 0) {
			RedQuad.y = 0;
		}
		if (RedQuad.y > 400) {
			RedQuad.y = 400;
		}

		//Print Red Quad
		SDL_SetRenderDrawColor(renderer, 255, 10, 50, 255);
		SDL_RenderFillRect(renderer, &RedQuad);

		//Print Green Quad
		if (BulletExist) {
			for (int a = 0; a < 5; a++) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 51, 255);
				SDL_RenderFillRect(renderer, &GreenQuad[a]);
				GreenQuad[a].x += 10;
			}
			SDL_Delay(10);
		}

		//Movement
		if (moveUp == true) {
			RedQuad.y -= 1;
		}
		if (moveDown == true) {
			RedQuad.y += 1;
		}
		if (moveLeft == true) {
			RedQuad.x -= 1;
		}
		if (moveRight == true) {
			RedQuad.x += 1;
		}

		SDL_RenderPresent(renderer);

		//Clean Screen
		SDL_SetRenderDrawColor(renderer, 0, 122, 255, 255);
		SDL_RenderClear(renderer);


	}

	SDL_DestroyWindow(window);
	return 0;

}
