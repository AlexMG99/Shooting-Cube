#include "../SDL/include/SDL.h"
#include "../SDL_Image/include/SDL_image.h"
#include <iostream>

#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")
#pragma comment(lib, "../SDL_Image/libx86/SDL2_image.lib")

//Define

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* background;
SDL_Texture* ship;
SDL_Texture* bullet;

//Texture Function
SDL_Texture* loadTexture(std::string path) {
	//Create Texture
	SDL_Texture* newTexture;
	//Surface where it loads
	SDL_Surface* loadSurface = IMG_Load(path.c_str());
	newTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
	SDL_FreeSurface(loadSurface);
	return newTexture;
}

int main(int argc, char* argv[]) {
	
	int numBullet = 0;
	bool loop = true;
	bool moveUp = false;
	bool moveDown = false;
	bool moveRight = false;
	bool moveLeft = false;
	bool bulletExist = false;


	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	//Create window & Renderer
	window = SDL_CreateWindow("Shooting Cube Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	//Define Player Surface
	SDL_Rect* RedQuad = new SDL_Rect;
	RedQuad->x = 0;
	RedQuad->y = 0;
	RedQuad->w = 123;
	RedQuad->h = 60;

	//Define Bullet Surface
	SDL_Rect * Bullet[5];
	for (int a = 0; a < 5; a++) {
		Bullet[a] = new SDL_Rect;
		Bullet[a]->x;
		Bullet[a]->y;
		Bullet[a]->w = 30;
		Bullet[a]->h = 30;
	}

	//Load Textures
	background = loadTexture("Background.png");
	ship = loadTexture("ship.png");
	bullet = loadTexture("bullet.png");

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
							Bullet[numBullet]->x = (RedQuad->x) + (RedQuad->w);
							Bullet[numBullet]->y = (RedQuad->y)+((RedQuad->h)/2 - Bullet[1]->h);
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
		if (RedQuad->x < 0) {
			RedQuad->x = 0;
		}
		if (RedQuad->x > WINDOW_WIDTH-RedQuad->w ) {
			RedQuad->x = WINDOW_WIDTH - RedQuad->w;
		}
		if (RedQuad->y < 0) {
			RedQuad->y = 0;
		}
		if (RedQuad->y > WINDOW_HEIGHT-RedQuad->h) {
			RedQuad->y = WINDOW_HEIGHT - RedQuad->h;
		}

		SDL_RenderCopy(renderer, background, 0, 0);
		SDL_RenderCopy(renderer, ship, 0, RedQuad);

		

		//Print Green Quad
		for (int a = 0; a < 5; a++) {
			SDL_RenderCopy(renderer, bullet, 0, Bullet[a]);
			Bullet[a]->x += 10;
		}

		//Movement
		if (moveUp == true) {
			RedQuad->y -= 5;
		}
		if (moveDown == true) {
			RedQuad->y += 5;
		}
		if (moveLeft == true) {
			RedQuad->x -= 5;
		}
		if (moveRight == true) {
			RedQuad->x += 5;
		}

	
		
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	return 0;

}
