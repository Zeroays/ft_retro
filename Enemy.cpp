/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:53:57 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 22:30:10 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( void ) { return ; }

Enemy::Enemy( int x, int y, char character ) : _x(x), _y(y), _symbol(character)
{ return ; }

Enemy::Enemy( Enemy const & Enemy ) {
    *this = Enemy;
}

Enemy& Enemy::operator=( Enemy const & Enemy ) {
    if ( this != &Enemy ) {
        this->_x = Enemy._x;
        this->_y = Enemy._y;
        this->_symbol = Enemy._symbol;
    }
    return *this;
}

Enemy::~Enemy( void ) { return ; }

int Enemy::getX( void ) {
    return this->_x; 
}

int Enemy::getY( void ) {
    return this->_y;
}

void Enemy::setX( int x ) {
    this->_x = x;
}

void Enemy::setY( int y ) {
    this->_y = y;
}

void Enemy::draw( void ) {
    init_pair( 2, COLOR_RED, COLOR_BLACK );
    attron( COLOR_PAIR(2) );
    move( this->_y, this->_x );
    addch( ( this->_symbol ) );
    attroff( COLOR_PAIR(2) );
}

void Enemy::fly( int screenWidth, int screenHeight ) {
    this->_x -= 1;
    if ( this->_x <= 0 ) {
        this->_x = screenWidth;
        this->_y = rand() % screenHeight;
    }
    draw();
}