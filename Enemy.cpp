/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:06:21 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 17:12:10 by vrabaib          ###   ########.fr       */
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

void Enemy::draw( void ) {
    move( this->_y, this->_x );
    addch( ( this->_symbol ) );
}

void Enemy::fly( int screenWidth, int screenHeight ) {
    this->_x -= 1;
    if ( this->_x <= 0 ) {
        this->_x = screenWidth;
        this->_y = rand() % screenHeight;
    }
    draw();
}