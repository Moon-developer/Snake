/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 09:08:00 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/06 17:25:43 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <iostream>

extern "C" void test(int width, int height)
{
	SDL_Window *window;                    // Declare a pointer
	SDL_Renderer *ren;

    SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        width,                               // width, in pixels
        height,                               // height, in pixels
        0                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
		std::cout << "Could not create window" << std::endl;
    }
	ren = SDL_CreateRenderer(window, -1, 0);
    // The window is open: could enter program loop here (see SDL_PollEvent())

	std::cout << "wait 3 seconds" << std::endl;
    //SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
	while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }
		SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
        SDL_RenderClear(ren);
        //SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
        SDL_RenderPresent(ren);
    }
    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}
