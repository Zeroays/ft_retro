/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swarm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:41:18 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 23:02:39 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Swarm.hpp"
#include <sstream>
Swarm::Swarm( int screenWidth, int screenHeight, Player *player, Screen* screen ) : 
_screenWidth(screenWidth), _screenHeight(screenHeight), _player(player), _screen(screen)
{
    srand(time(NULL));
    for (int i = 0; i < _N; i++)
        _swarm[i] = Enemy( rand() % (100) + screenWidth , rand() % screenHeight, '<' );
}

Swarm::Swarm( void ) {
    return ;
}

Swarm::Swarm( Swarm const & swarm ) {
    *this = swarm;
}

Swarm& Swarm::operator=( Swarm const & swarm ) {
    if ( this != &swarm ) {
        this->_screenHeight = swarm._screenHeight;
        this->_screenWidth = swarm._screenWidth;
        this->_player = swarm._player;
        this->_screen = swarm._screen;
    }
    return *this;
}

Swarm::~Swarm( void ) {
    return ;
}

void Swarm::drawSwarm( void ) {
    for (int i = 0; i < _N; i++)
        _swarm[i].fly( _screenWidth, _screenHeight );
}

void Swarm::playerHit( void ) {
    for (int i = 0; i < _N; i++) {
        if ( _player->getX() == _swarm[i].getX() && _player->getY() == _swarm[i].getY() )
            _screen->setDone();
    }
}

void Swarm::bulletHit( void ) {
    int i = 0, j = 0;
    Bullet* tmp;
    Bullet* bullets = _player->getAmmo();

    while ( i < _player->getAmmoAmt() ) {
        tmp = bullets;
        while ( j < _N ) {
            if ( (*tmp).getX() == _swarm[j].getX() && (*tmp).getY() == _swarm[j].getY() )
                _screen->setDone();
            tmp++;
            j++;
            // std::stringstream total;
            // std::stringstream enemy;
            // total << "X: " << std::to_string( (*bullets).getX() ) << ", Y: " << std::to_string( (*bullets).getY() );
            // enemy << "X: " << std::to_string( _swarm[j].getX() ) << ", Y: " << std::to_string( _swarm[j].getY() );
            // mvaddstr( 25, 80,  total.str().c_str() );
            // mvaddstr( 40, 80,  enemy.str().c_str() );


        }
        i++;
    }
}
