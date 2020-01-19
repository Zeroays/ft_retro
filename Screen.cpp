/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:54:39 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 21:54:47 by vrabaib          ###   ########.fr       */
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

    //MUST TURN OFF "Disable session-initiated window resizing"
    //IN iTerm2->Preferences->Profile->Terminal
    std::cout << "\e[8;" << this->_screenHeight << ";" 
    << this->_screenWidth << "t;";
    //Initializes Standard Screen
    resizeterm(this->_screenWidth, this->_screenHeight);
    
    initscr();
    //Enable colors for terminal
    start_color();
    raw();
    //Register key presses on Standard Screen - stdscr
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    //Remove white cursor
    curs_set(0);

    //Initialize stars array
    for (int i = 0; i < _starAmt; i++)
        _stars[i] = Star( rand() % _screenWidth + 10, rand() % _screenHeight, '*' );
}

void Screen::drawStars( void ) {
    for (int i = 0; i < _starAmt; i++)
        _stars[i].fly( _screenWidth, _screenHeight );
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

void Screen::setDone( void ) {
    quit();
}

bool Screen::isDone( void ) const {
    return this->_done;
}

void Screen::quit( void ) {
    this->_done = true;
}