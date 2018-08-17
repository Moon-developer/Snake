/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:08:26 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/17 14:03:46 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"

// constructor
Display::Display(void)
{
}

// deconstructor
Display::~Display(void)
{
	glfwTerminate();
}

void	Display::CloseWindow( void )
{
	Debug::print("close window", true);
}

// get the key inputs
Keys	Display::getKey(void)
{
	//	if (this->_event.type == SDL_KEYDOWN)
	//	{
	//		int keyCode = this->_event.key.keysym.sym;
	//		if (keyCode == SDLK_UP)
	//			return Keys::UPA;
	//		else if (keyCode == SDLK_DOWN)
	//			return Keys::DOWNA;
	//		else if (keyCode == SDLK_LEFT)
	//			return Keys::LEFTA;
	//		else if (keyCode == SDLK_RIGHT)
	//			return Keys::RIGHTA;
	//		else if (keyCode == SDLK_ESCAPE)
	//			return Keys::ESC;
	//		else if (keyCode == SDLK_F1)
	//			return Keys::F1;
	//		else if (keyCode == SDLK_F2)
	//			return Keys::F2;
	//		else if (keyCode == SDLK_F3)
	//			return Keys::F3;
	//		else
	//			return Keys::UNKNOWN;
	//	}
	return Keys::UNKNOWN;
}

// get the events
bool	Display::PollEvents( void )
{
	//if (!glfwWindowShouldClose(this->_window))
	glfwPollEvents();
	return true;
}

// render the background & border
void	Display::BackGround( void )
{
	Debug::print("background", true);
}

Points	Display::getPoints(int x, int y)
{
	Points	points;
	points.x0 = static_cast<float>(x * 16 - (this->_width >> 1)) / static_cast<float>(this->_width >> 1);
	points.x1 = static_cast<float>(x *16 + 16 - (this->_width >> 1)) / static_cast<float>(this->_width >> 1);
	points.y0 = static_cast<float>((this->_height >> 1) - y *16) / static_cast<float>(this->_height >> 1);
	points.y1 = static_cast<float>((this->_height >> 1) - y *16 - 16) / static_cast<float>(this->_height >> 1);
	// (x0 y0)(x1 y0)
	// (x0 y1)(x1 y1)
	return (points);

}

// Render background/apple/snake/border
void	Display::Render(int foodX, int foodY, std::vector<Block> snake)
{
	Points	food;
	Points	body;
	Points	bg;
	// clear
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	// ============= BORDER ================= //
    glColor3f(0.3f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    bg = getPoints(0, 0);
    glVertex2f(bg.x1, bg.y1);
    bg = getPoints(this->_width / 16 -1, 0);
    glVertex2f(bg.x0, bg.y1);
    bg = getPoints(this->_width / 16 - 1, this->_height / 16 - 1);
    glVertex2f(bg.x0, bg.y0);
    bg = getPoints(0, this->_height /16 - 1);
    glVertex2f(bg.x1, bg.y0);
    glEnd();
	// ============= FOOD ============== //
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	food = getPoints(foodX,foodY);
	glVertex2f(food.x0, food.y0);
	glVertex2f(food.x1, food.y0);
	glVertex2f(food.x1, food.y1);
	glVertex2f(food.x0, food.y1);
	glEnd();
	// ============= SNAKE HEAD ============== //
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_QUADS);
	body = getPoints(snake.begin()->x, snake.begin()->y);
	glVertex2f(body.x0, body.y0);
	glVertex2f(body.x1, body.y0);
	glVertex2f(body.x1, body.y1);
	glVertex2f(body.x0, body.y1);
	glEnd();
	// ============= SNAKE BODY ============== //
	for (auto section = snake.begin() + 1; section != snake.end();++section)
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_QUADS);
		body = getPoints(section->x, section->y);
		glVertex2f(body.x0, body.y0);
		glVertex2f(body.x1, body.y0);
		glVertex2f(body.x1, body.y1);
		glVertex2f(body.x0, body.y1);
		glEnd();
	}
	// swap front and back bufferes
	glfwSwapBuffers(this->_window);
}

// initilize screen size
void	Display::Init(int width, int height)
{
	this->_width = width;
	this->_height = height;

	if (!glfwInit())
		Debug::print("Did not Initilize glfw properly", true);
	this->_window = glfwCreateWindow(this->_width, this->_height, "Snake in GLFW", NULL, NULL);
	if (!this->_window)
	{
		Debug::print("window did not create properly", true);
		glfwTerminate();
	}

	glfwMakeContextCurrent(this->_window);
	glfwGetFramebufferSize(this->_window, &this->_width, &this->_height);
	glViewport(0, 0, this->_width, this->_height);
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
