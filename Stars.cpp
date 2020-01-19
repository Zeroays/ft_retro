/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:50:02 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 22:27:42 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stars.hpp"

Star::Star( void ) {
    srand(time(NULL));
    return ;
}

Star::Star( int x, int y, char character ) : 
_x(x), _y(y), _symbol(character) {
    return ;
}

Star::Star( Star const & star ) {
    *this = star;
}

Star& Star::operator=( Star const & star ) {
    if ( this != &star ) {
        this->_x = star._x;
        this->_y = star._y;
        this->_symbol = star._symbol;
    }
    return *this;
}

Star::~Star( void ) {
    return ;
}

int Star::getX( void ) {
    return this->_x;
}

int Star::getY( void ) {
    return this->_y;
}

void Star::setx( int x ) {
    this->_x = x;
}

void Star::sety( int y ) {
    this->_y = y;
}

void Star::draw( void ) {
    init_pair( 1, COLOR_YELLOW, COLOR_BLACK ); 
    attron( COLOR_PAIR(1) );
    move( this->_y, this->_x );
    addch( ( this->_symbol ) );
    attroff( COLOR_PAIR(1) );
}

void Star::fly( int screenWidth, int screenHeight ) {
    this->_x -= 1;
    if ( this->_x <= 0 ) {
        this->_x = screenWidth;
        this->_y = rand() % screenHeight;
    }
    draw();
}