/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:30:09 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 17:10:17 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet( void ) { return ; }

Bullet::Bullet( int x, int y, char character ) : _x(x), _y(y), _symbol(character), _isActive(false) { 
    return ;
}

Bullet::Bullet( Bullet const & bullet ) {
    *this = bullet;
}

Bullet& Bullet::operator=( Bullet const & bullet ) {
    if ( this != &bullet ) {
        this->_x = bullet._x;
        this->_y = bullet._y;
        this->_symbol = bullet._symbol;
        this->_isActive = bullet._isActive;
    }
    return *this;
}

Bullet::~Bullet( void ) { 
    return ;
}

void Bullet::draw( void ) {
    move( this->_x, this->_y );
    addch( ( this->_symbol ) );
}

int Bullet::getX( void ) {
    return this->_x;
}

int Bullet::getY( void ) {
    return this->_y;
}

void Bullet::setX( int x ) {
    this->_x = x;
}

void Bullet::setY( int y ) {
    this->_y = y;
}

bool Bullet::getActive( void ) {
    return this->_isActive;
}

void Bullet::setActive( bool active ) {
    this->_isActive = active;
}

void Bullet::travel( int screenWidth ) {
    if ( _isActive ) {
        this->_y += 1;
        draw();
        if ( this->_y >= screenWidth )
            _isActive = false;
    }
}