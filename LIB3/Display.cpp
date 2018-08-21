/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:08:26 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/21 15:34:28 by mafernan         ###   ########.fr       */
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

// get player two keys
Keys	Display::getKey2(void)
{
	if (glfwGetKey(this->_window, GLFW_KEY_W) == GLFW_PRESS)
		return Keys::KEYW;
	else if (glfwGetKey(this->_window, GLFW_KEY_A) == GLFW_PRESS)
		return Keys::KEYA;
	else if (glfwGetKey(this->_window, GLFW_KEY_S) == GLFW_PRESS)
		return Keys::KEYS;
	else if (glfwGetKey(this->_window, GLFW_KEY_D) == GLFW_PRESS)
		return Keys::KEYD;
	else
		return Keys::UNKNOWN;
}

// get the key inputs
Keys	Display::getKey(void)
{
	if (glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		return Keys::ESC;
	else if (glfwGetKey(this->_window, GLFW_KEY_UP) == GLFW_PRESS)
		return Keys::UPA;
	else if (glfwGetKey(this->_window, GLFW_KEY_DOWN) == GLFW_PRESS)
		return Keys::DOWNA;
	else if (glfwGetKey(this->_window, GLFW_KEY_LEFT) == GLFW_PRESS)
		return Keys::LEFTA;
	else if (glfwGetKey(this->_window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		return Keys::RIGHTA;
	else if (glfwGetKey(this->_window, GLFW_KEY_F1) == GLFW_PRESS)
		return Keys::F1;
	else if (glfwGetKey(this->_window, GLFW_KEY_F2) == GLFW_PRESS)
		return Keys::F2;
	else if (glfwGetKey(this->_window, GLFW_KEY_F3) == GLFW_PRESS)
		return Keys::F3;
	else if (glfwGetKey(this->_window, GLFW_KEY_W) == GLFW_PRESS)
		return Keys::KEYW;
	else if (glfwGetKey(this->_window, GLFW_KEY_A) == GLFW_PRESS)
		return Keys::KEYA;
	else if (glfwGetKey(this->_window, GLFW_KEY_S) == GLFW_PRESS)
		return Keys::KEYS;
	else if (glfwGetKey(this->_window, GLFW_KEY_D) == GLFW_PRESS)
		return Keys::KEYD;
	else
		return Keys::UNKNOWN;
}

// get the events
bool	Display::PollEvents( void )
{
	if (!glfwWindowShouldClose(this->_window))
	{
		glfwPollEvents();
		return true;
	}
	else
		return false;
}

Points	Display::getPoints(int x, int y)
{
	Points	points;

	points.x0 = static_cast<float>(x * 16 - (this->_width >> 1)) / static_cast<float>(this->_width >> 1);
	points.x1 = static_cast<float>(x *16 + 16 - (this->_width >> 1)) / static_cast<float>(this->_width >> 1);
	points.y0 = static_cast<float>((this->_height >> 1) - y *16) / static_cast<float>(this->_height >> 1);
	points.y1 = static_cast<float>((this->_height >> 1) - y *16 - 16) / static_cast<float>(this->_height >> 1);
	// what the points mean on a graph
	//
	//            |
	//	 (x0, y0) | (x1, y0)
	//	          |
	//	 --------------------
	//	          |
	//	 (x0, y1) | (x1, y1)
	//            |
	//
	return (points);

}

// second player snake
void	Display::secondSnake(std::vector<Block> snake)
{
	glColor3f(0.2f, 0.5f, 0.1f);
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
}

// Render background/apple/snake/border
void	Display::Render(int foodX, int foodY, int type, std::vector<Block> snake, std::vector<Block> snake2, int set)
{
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
	if (type == 1)
		glColor3f(1.0f, 0.0f, 0.0f);
	else if (type == 2)
		glColor3f(0.9f, 0.0f, 0.0f);
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
	// ============= player two =========== //
	if (set == 2)
		secondSnake(snake2);
	// swap front and back bufferes
	glfwSwapBuffers(this->_window);
}

// initilize screen size
void	Display::Init(int width, int height)
{
	this->_width = width;
	this->_height = height;

	if (!glfwInit())
		std::cout << "Did not initilize glfw properly" << std::endl;
	this->_window = glfwCreateWindow(this->_width, this->_height, "Snake in GLFW", NULL, NULL);
	if (!this->_window)
		std::cout << "Window was not created properly in glfw" << std::endl;
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

// ====== Online stuff not coded yet for sdl ======== //

void	Display::CreateServer( void )
{
	std::cout << "does nothing for now" << std::endl;
}

void	Display::ConnectClient( void )
{
	std::cout << "does nothing for now" << std::endl;
}

Keys	Display::sendOnlineKey( void )
{
	return (Keys::KEYW);
}

Keys	Display::getOnlineKey( void )
{
	return (Keys::KEYW);
}
std::string		Display::getFood( void )
{
	return ("does nothing for now");
}

void	Display::sendFood(int x, int y)
{
	std::cout << "does nothing for now" << std::endl;
}

void	Display::setOnline(int port, std::string ip)
{
	(void)port;
	(void)ip;
	std::cout << "does nothing for now" << std::endl;
}
