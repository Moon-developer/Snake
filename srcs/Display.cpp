/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 07:38:11 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/22 10:44:32 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"

Display::Display(void)
{
	this->_time = 0;
	this->_score = 0;
	this->_lives = 0;
}

Display::~Display(void)
{
	endwin();
}


Display::Display(Display const & src) {
	*this = src;	
}

Display & Display::operator=(Display const & src) {
	if (this != &src)
    {
	*this = src;
    }
	return (*this);
}

void	Display::print(void)
{
	clear();
	mvprintw(1, 0, "=====================================================");
	mvprintw(5, 5, "NIBBLER LIVE UPDATE!!!");
	mvprintw(7, 5, "SCORE : %d", this->_score);
	mvprintw(9, 5, "LIVES : %d", this->_lives);
	mvprintw(11, 5, "CLOCK : %d", this->_time);
	mvprintw(15, 0, "=====================================================");
}

void	Display::update(int score, int lives)
{
	this->_score = score;
	this->_lives = lives;
	this->_time += 1;
}

int	barmenu(const char **array, const int row,
		const int col, const int arraylength,
		const int width, int menulength, int selection) {
	int	counter;
	int	offset = 0;
	int	ky = 0;
	char	formatstring[7];
	curs_set(0);

	if (arraylength < menulength)
		menulength = arraylength;
	if (selection > menulength)
		offset = selection - menulength + 1;
	sprintf(formatstring, "%%-%ds", width); //remove - sign to right justifiy the menu items

	while (ky != 27)
	{
		for (counter = 0; counter < menulength; counter++)
		{
			if (counter + offset == selection)
				attron(A_REVERSE);
			mvprintw(row + counter, col, formatstring, array[counter + offset]);
			attroff(A_REVERSE);
		}

		ky = getch();

		switch(ky)
		{
			case KEY_UP:
				if (selection)
				{
					selection--;
					if (selection < offset)
						offset--;
				}
				break;
			case KEY_DOWN:
				if (selection < arraylength - 1)
				{
					selection++;
					if (selection > offset + menulength - 1)
						offset++;
				}
				break;
			case KEY_HOME:
				selection = 0;
				offset = 0;
				break;
			case KEY_END:
				selection = arraylength - 1;
				offset = arraylength - menulength;
				break;
			case KEY_PPAGE:
				selection -= menulength;
				if (selection < 0)
					selection = 0;
				offset -= menulength;
				if (offset < 0)
					offset = 0;
				break;
			case KEY_NPAGE:
				selection += menulength;
				if (selection > arraylength - 1)
					selection = arraylength + 1;
				offset += menulength;
				if (offset > arraylength - menulength)
					offset = arraylength - menulength;
				break;
			case 10: // enter button
				return selection;
				break;
			case KEY_F(1): // F1
				return (-1);
			case 27: // esc key
				ky = getch();
				if (ky == 27)
				{
					curs_set(0);
					mvaddstr(9, 77, "    ");
					return (-1);
				}
				else
					if (ky == '[')
					{
						getch();
						getch();
					}
					else
						ungetch(ky);
		}

	}
	return (-1);

}

void	Display::resolution( void )
{
	int 	set = -1;
	const char *WidthOptions[] = {"Default","640x480", "800x600", "1280x960", "1920x1080"};

	clear();
	mvprintw(1, 0, "=====================================================");
	mvprintw(5, 5, "SELECT A RESOLUTION");
	mvprintw(15, 0, "=====================================================");
	set = barmenu(WidthOptions, 7, 4, 5, this->_width, 5,3);
	if (set == 1)
	{
		this->_screenWidth = 640;
		this->_screenHeight = 480;
	}
	else if (set == 2)
	{
		this->_screenWidth = 800;
		this->_screenHeight = 600;
	}
	else if (set == 3)
	{
		this->_screenWidth = 1280;
		this->_screenHeight = 960;
	}
	else if (set == 4)
	{
		this->_screenWidth = 1920;
		this->_screenHeight = 1080;
	}
	clear();
}

void	Display::lives(void)
{
	const char *options[] = {"3", "6", "9", "max"};
	int	set = -1;

	clear();
	mvprintw(1, 0, "=====================================================");
	mvprintw(5, 5, "SELECT AMOUNT OF LIVES");
	mvprintw(15, 0, "=====================================================");
	set = barmenu(options, 7, 4, 4, this->_width, 4,3);
	if (set == 0)
		this->_lives = 3;
	else if (set == 1)
		this->_lives = 6;
	else if (set == 2)
		this->_lives = 9;
	else if (set == 3)
		this->_lives = 999;
	clear();
}

void	Display::difficulty(void)
{
	const char *settings[] = {"easy", "medium", "hard", "nightmare"};
	int	set = -1;

	clear();
	mvprintw(1, 0, "=====================================================");
	mvprintw(5, 5, "SELECT A DIFFICULTY");
	mvprintw(15, 0, "=====================================================");
	set = barmenu(settings, 7, 4, 4, this->_width, 4,3);
	if (set == 0)
		this->_level = 1;
	else if (set == 1)
		this->_level = 2;
	else if (set == 2)
		this->_level = 3;
	else if (set == 3)
		this->_level = 4;
	clear();
}

void	Display::library(void)
{
	const char *options[] = {"sfml", "sdl", "glfw"};
	int	set = -1;
	
	clear();
	mvprintw(1, 0, "=====================================================");
	mvprintw(5, 5, "SELLECT A GRAPHICS LIBRARY");
	mvprintw(15, 0, "=====================================================");
	set = barmenu(options, 7, 4, 3, this->_width, 3,3);
	if (set == 0)
		this->_library = 5;
	else if (set == 1)
		this->_library = 6;
	else if (set == 2)
		this->_library = 7;
	clear();
}

void		Display::setOnline(void)
{
	const char *options[] = {"set IP", "set PORT", "back"};
	int		set = 1;

	clear();
	while (set != 2)
	{
		mvprintw(1, 0, "=====================================================");
		mvprintw(4, 5, "using IP: %s", _ip.c_str());
		mvprintw(5, 5, "using PORT: %d", _port);
		mvprintw(15, 0, "=====================================================");
		set = barmenu(options, 7, 5, 3, this->_width, 3,3);
		if (set == 0)
			break ;
		if (set == 1)
			break ;
	}
	clear();
}

int		Display::online(void)
{
	const char *options[] = {"Run as server", "Connect as client", "back"};
	int			set = 1;

	clear();
	while (set != 2)
	{
		mvprintw(1, 0, "=====================================================");
		mvprintw(4, 5, "Server will use host IP");
		mvprintw(5, 5, "PORT number is: %d", _port);
		mvprintw(15, 0, "=====================================================");
		set = barmenu(options, 7, 5, 3, this->_width, 3,3);
		if (set == 0)
		{
			clear();
			return (3);
		}
		if (set == 1)
		{
			clear();
			return (4);
		}
	}
	clear();
	return (9);
}

void	Display::settings(void)
{
	const char *settings[] = {"resolution", "lives", "difficulty", "library","online","back"};
	int  set = -1;


	clear();
	while (set != 5)
	{
		mvprintw(1, 0, "=====================================================");
		mvprintw(5, 5, "SETTINGS MENU");
		mvprintw(15, 0, "=====================================================");
		set = barmenu(settings, 7, 4, 6, this->_width, 6,3);
		if (set == 0)
			resolution();
		if (set == 1)
			lives();
		if (set == 2)
			difficulty();
		if (set == 3)
			library();
		if (set == 4)
			setOnline();
	}
	clear();
}

int	Display::menu( void )
{

	initscr();
	noecho();	
	keypad(stdscr, TRUE);

	const char *menu[] = {"play","multiplayer", "online","settings","exit"};
	int	set = -1;
	int	temp = 0;

	while (set != 4)
	{
		mvprintw(1, 0, "=====================================================");
		mvprintw(3, 10, "NIBBLER GAME!!!");
		mvprintw(5, 5, "please selection an option");
		mvprintw(15, 0, "=====================================================");
		set = barmenu(menu, 7, 5, 5, this->_width, 5,3);
		if (set == 0)
			return (1);
		if (set == 1)
			return (2);
		if (set == 2)
		{
			temp = online();
			if (temp == 3)
				return (3);
			else if (temp == 4)
				return (4);
		}
		if (set == 3)
			settings();
	}
	refresh();
	return (0);
}

// ============ return functions ================ //

int		Display::screenHeight( void )
{
	return (this->_screenHeight);
}

int		Display::screenWidth( void )
{
	return (this->_screenWidth);
}

int		Display::getLibrary( void )
{
	return (this->_library);
}

int		Display::getLives( void )
{
	return (this->_lives);
}

std::string		Display::getIP( void )
{
	return (this->_ip);
}

int		Display::getPORT( void )
{
	return (this->_port);
}

int		Display::getLevel( void )
{
	return (this->_level);
}

// ============================================== //

void	Display::reset( void )
{
	refresh();
}
