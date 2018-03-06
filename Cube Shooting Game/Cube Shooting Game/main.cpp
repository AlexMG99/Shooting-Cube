#include "../SDL/include/SDL.h"
#include "../SDL_Image/include/SDL_image.h"
#include "../SDL_Mixer/include/SDL_mixer.h"
#include <iostream>

#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")
#pragma comment(lib, "../SDL_Image/libx86/SDL2_image.lib")
#pragma comment(lib, "../SDL_Mixer/libx86/SDL2_mixer.lib")

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
	SDL_Rect* Ship_Surface = new SDL_Rect;
	Ship_Surface->x = 0;
	Ship_Surface->y = 0;
	Ship_Surface->w = 123;
	Ship_Surface->h = 60;

	//Define Bullet Surface
	SDL_Rect * Bullet_Surface[5];
	for (int a = 0; a < 5; a++) {
		Bullet_Surface[a] = new SDL_Rect;
		Bullet_Surface[a]->x;
		Bullet_Surface[a]->y;
		Bullet_Surface[a]->w = 30;
		Bullet_Surface[a]->h = 30;
	}

	//Load Textures
	background = loadTexture("Background.png");
	ship = loadTexture("ship.png");
	bullet = loadTexture("bullet.png");

	while (loop) {
		SDL_Event e;
		if (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) { //Quit program
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
					bulletExist = true;
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
				if (e.key.keysym.sym == SDLK_SPACE) {
					bulletExist = false;
				}
			}
		}
				
		

		//Set Borders
		if (Ship_Surface->x < 0) {
			Ship_Surface->x = 0;
		}
		if (Ship_Surface->x > WINDOW_WIDTH - Ship_Surface->w ) {
			Ship_Surface->x = WINDOW_WIDTH - Ship_Surface->w;
		}
		if (Ship_Surface->y < 0) {
			Ship_Surface->y = 0;
		}
		if (Ship_Surface->y > WINDOW_HEIGHT-Ship_Surface->h) {
			Ship_Surface->y = WINDOW_HEIGHT - Ship_Surface->h;
		}

		SDL_RenderCopy(renderer, background, 0, 0);
		SDL_RenderCopy(renderer, ship, 0, Ship_Surface);

		

		//Print Bullet
		for (int a = 0; a < 5; a++) {
			SDL_RenderCopy(renderer, bullet, 0, Bullet_Surface[a]);
			Bullet_Surface[a]->x += 10;
		}

		//Bullet 
		if (bulletExist) {
			Bullet_Surface[numBullet]->x = (Ship_Surface->x) + (Ship_Surface->w);
			Bullet_Surface[numBullet]->y = (Ship_Surface->y) + ((Ship_Surface->h) / 2 - Bullet_Surface[1]->h);
			numBullet++;
			if (numBullet == 5) {
				numBullet = 0;
			}
			bulletExist = false;
		}

		//Movement
		if (moveUp == true) {
			Ship_Surface->y -= 5;
		}
		if (moveDown == true) {
			Ship_Surface->y += 5;
		}
		if (moveLeft == true) {
			Ship_Surface->x -= 5;
		}
		if (moveRight == true) {
			Ship_Surface->x += 5;
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	SDL_DestroyTexture(background);
	SDL_DestroyTexture(bullet);
	SDL_DestroyTexture(ship);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	return 0;
}
