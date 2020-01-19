/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swarm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:41:25 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 20:48:34 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWARM_HPP
#define SWARM_HPP

#include <ncurses.h>
#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Screen.hpp"

class Swarm {

    private:
        static const int _N = 69;
        int _screenWidth;
        int _screenHeight;
        Player *_player;
        Screen *_screen;
        Enemy _swarm[_N];

    public:
        Swarm( void );
        Swarm( int screenWidth, int screenHeight, Player* player, Screen* screen );
        Swarm( Swarm const & swarm );
        Swarm& operator=( Swarm const & swarm );
        ~Swarm( void );
        void drawSwarm( void );
        void playerHit( void );
        void bulletHit( void );
        
};


#endif