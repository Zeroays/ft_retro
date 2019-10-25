/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:45:13 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/22 21:18:42 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player( int x, int y, char character ) : _x(x), _y(y), _symbol(character) 
{ return ; }

Player::Player( Player const & player ) {
    *this = player;
}

Player& Player::operator=( Player const & player ) {
    if ( this != &player ) {
        this->_x = player._x;
        this->_y = player._y;
        this->_symbol = player._symbol;
    }
    return *this;
}

Player::~Player( void ) { return ; }

void Player::draw( void ) {
    mvprintw( this->_y, this->_x, &(this->_symbol) );
}

void Player::controls( int keypress ) {
    if ( keypress == 'a' )
        moveLeft();
    else if ( keypress == 'd' )
        moveRight();
    else if ( keypress == 'w' ) 
        moveUp();
    else if ( keypress == 's' )
        moveDown();
}

void Player::moveLeft( void ) {
    this->_x -= 1;
}

void Player::moveRight( void ) {
    this->_x += 1;
}

void Player::moveUp( void ) {
    this->_y -= 1;
}

void Player::moveDown( void ) {
    this->_y += 1;
}