/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:45:18 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 16:59:06 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>
#include "Bullet.hpp"

class Player {

    private:
        int _x;
        int _y;
        char _symbol;
        int _screenWidth;
        int _screenHeight;
        int _ammoIndex;
        Bullet _ammo[3];

    public:
        Player( void );
        Player( int x, int y, char character, int screenWidth, int screenHeight );
        Player( Player const & player );
        Player& operator=( Player const & player );
        ~Player( void );
        int getX( void );
        int getY( void );
        void draw( void );
        void controls( int keypress );
        void moveUp( void );
        void moveDown( void );
        void shoot( void );
        void drawBullets( void );

};

#endif