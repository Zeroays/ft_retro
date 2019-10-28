/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:45:13 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 17:11:01 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

#include <iostream>

Player::Player( void ) {
    return ;
}

Player::Player( int x, int y, char character, int screenWidth, int screenHeight ) : 
_x(x), _y(y), _symbol(character), _screenWidth(screenWidth), _screenHeight(screenHeight), _ammoIndex(0) { 
    for (int i = 0; i < 3; i++)
        _ammo[i] = Bullet( x + 1, y, '-' );
}

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
    move( this->_y, this->_x );
    addch( ( this->_symbol ) );
}

void Player::controls( int keypress ) {
    if ( keypress == 'w' ) 
        moveUp();
    else if ( keypress == 's' )
        moveDown();
    else if ( keypress == ' ' )
        shoot();
}

void Player::moveUp( void ) {
    if ( this->_y <= 3 )
        this->_y = 3;
    this->_y -= 1;
}

void Player::moveDown( void ) {
    if ( this->_y >= this->_screenHeight - 3 )
        this->_y = this->_screenHeight - 3;
        this->_y += 1;
}

void Player::drawBullets( void ) {
    for (int i = 0; i < 3; i++) {
        _ammo[i].travel( _screenWidth );
    }
}

int Player::getX( void ) {
    return this->_x;
}

int Player::getY( void ) {
    return this->_y;
}

void Player::shoot( void ) {
    _ammoIndex += 1;
    if ( _ammoIndex == 3 )
        _ammoIndex = 0;
    if ( !_ammo[_ammoIndex].getActive() ) {
        _ammo[_ammoIndex].setX( this->_y );
        _ammo[_ammoIndex].setY( this->_x );
        _ammo[_ammoIndex].setActive( true );
        
    }
}