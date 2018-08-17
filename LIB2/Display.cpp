/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:08:26 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 12:38:52 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"
#include "sdl_check.hpp"

// constructor
Display::Display(void)
{
}

// deconstructor
Display::~Display(void)
{
	SDL_DestroyRenderer(this->_render);
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
}

void	Display::CloseWindow( void )
{
	Debug::print("close window", true);
}

// get the key inputs
Keys	Display::getKey(void)
{
	if (this->_event.type == SDL_KEYDOWN)
	{
		int keyCode = this->_event.key.keysym.sym;
		if (keyCode == SDLK_UP)
			return Keys::UPA;
		else if (keyCode == SDLK_DOWN)
			return Keys::DOWNA;
		else if (keyCode == SDLK_LEFT)
			return Keys::LEFTA;
		else if (keyCode == SDLK_RIGHT)
			return Keys::RIGHTA;
		else if (keyCode == SDLK_ESCAPE)
			return Keys::ESC;
		else if (keyCode == SDLK_F1)
			return Keys::F1;
		else if (keyCode == SDLK_F2)
			return Keys::F2;
		else if (keyCode == SDLK_F3)
			return Keys::F3;
		else
			return Keys::UNKNOWN;
	}
	return Keys::UNKNOWN;
}

// get the events
bool	Display::PollEvents( void )
{
	if (SDL_PollEvent(&this->_event))
	{
		if (this->_event.type == SDL_QUIT)
			return false;
	}
	return true;
}

// render the background & border
void	Display::BackGround( void )
{
	Debug::print("background", true);
}

// Render background/apple/snake/border
void	Display::Render(int foodX, int foodY, std::vector<Block> snake)
{
	SDL_Rect rect;
	SDL_RenderClear(this->_render);
	// =========== Border ========== //
	SDL_SetRenderDrawColor(this->_render, 255,0,0,0);
	rect.x = 16;
	rect.y = 16;
	rect.h = this->_height - 32;
	rect.w = this->_width - 32;
	// =========== head ============ //
	SDL_SetRenderDrawColor(this->_render, 0,0,255,0);
	SDL_RenderFillRect(this->_render, &rect);
	rect.h = 16;
	rect.w = 16;
	auto head = snake.begin();
	SDL_SetRenderDrawColor(this->_render, 0,255,0,0);
	rect.x = this->_le + 16 * head->x;
	rect.y = this->_te + 16 * head->y;
	SDL_RenderFillRect(this->_render, &rect);
	// ================= body ========== //
	SDL_SetRenderDrawColor(this->_render, 255,0,0,0);
	for (auto section = snake.begin() + 1; section != snake.end(); ++section)
	{
		rect.x = this->_le + 16 * section->x;
		rect.y = this->_te + 16 * section->y;
		SDL_RenderFillRect(this->_render, &rect);
	}
	// =============== FOOD ================ //
	rect.x = this->_le + 16 * foodX;
	rect.y = this->_te + 16 * foodY;
	SDL_RenderFillRect(this->_render, &rect);
	// =============== Render everthing ==== //
	SDL_RenderPresent(this->_render);
	
}

// initilize screen size
void	Display::Init(int width, int height)
{
	this->_width = width;
	this->_height = height;
	// divided by block size
	this->_rows = height / 16;
	this->_cols = width / 16;
	auto res = SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2
	SDL_CHECK(res == 0, "SDL_Init");
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &this->_window, &this->_render);
	SDL_CHECK(this->_window, "SDL_CreateWindowAndRenderer");
	SDL_CHECK(this->_render, "SDL_CreateWindowAndRenderer");
	SDL_SetWindowTitle(this->_window, "Nibbler SDL");
	SDL_SetWindowPosition(this->_window, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);
	auto surface = SDL_LoadBMP("sprites/sdl_sprites.bmp");
	SDL_CHECK(surface, "SDL_LOADBMP(\"sprites.bmp\")");
	this->_sprites = SDL_CreateTextureFromSurface(this->_render, surface);
	SDL_CHECK(this->_sprites, "SDL_CreateTextureFromSurface");
	SDL_FreeSurface(surface);

	// create the correct rows/cols according to blocksize... set to 16 default
	if (this->_width % 16 != 0)
		this->_le = (this->_width % 16) > 1;
	else
		this->_le = 0;
	if (this->_height % 16 != 0)
		this->_te = (this->_height % 16) > 1;
	else
		this->_te = 0;
}

// return instance of display object.
Interface * CreateDisplay( void )
{
	return new Display;
}
// delete new instance of it
void	DeleteDisplay(Display * display)
{
	delete display;
}
