/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:34:52 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/22 22:50:17 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

Window::Window( int width, int height ) : 
_windowWidth(width), _windowHeight(height) 
{ setup(); }

Window::Window( Window const & window ) {
    *this = window;
}

Window& Window::operator=( Window const & window ) {
    if ( this != &window ) {
        this->_windowHeight = window._windowHeight;
        this->_windowWidth = window._windowWidth;
        this->_win = window._win;
    }
    return *this;
}

Window::~Window( void ) {
    delwin( this->_win );
}

void Window::setup( void ) {
    this->_win = newwin( this->_windowHeight, this->_windowWidth, 0, 0 );  
}

void Window::drawBorder( void ) {
    box( this->_win, 0, 0 );
}

void Window::updateWindow( void ) {
    wrefresh( this->_win );
}

