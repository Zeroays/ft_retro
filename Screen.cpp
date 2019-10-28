/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:18:49 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 16:36:21 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"
#include <iostream>

Screen::Screen( int width, int height ) : 
_screenWidth(width), _screenHeight(height), _done(false) 
{ setup(); }

Screen::~Screen( void ) { endwin(); }

void Screen::setup( void ) {
    //Resize Terminal Screen by sending XTerm Control Sequence
    // to cout
    //https://apple.stackexchange.com/questions/33736/can-a-terminal-window-be-resized-with-a-terminal-command
    std::cout << "\e[8;" << this->_screenHeight << ";" 
    << this->_screenWidth << "t;";
    //Initializes Standard Screen
    resizeterm(this->_screenWidth, this->_screenHeight);
    
    initscr();
    raw();
    //Register key presses on Standard Screen - stdscr
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    //Remove white cursor
    curs_set(0);
}

int     Screen::getPressed( void ) {
    return getch();
}

void    Screen::clearScreen( void ) {
    clear();
}

void    Screen::updateScreen( void ) {
    refresh();
}

bool Screen::isDone( void ) const {
    return this->_done;
}

void Screen::quit( void ) {
    this->_done = true;
}