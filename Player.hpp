/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:45:18 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/22 21:25:41 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>

class Player {

    private:
        int _x;
        int _y;
        char _symbol;

    public:
        Player( int x, int y, char character );
        Player( Player const & player );
        Player& operator=( Player const & player );
        ~Player( void );
        void draw( void );
        void controls( int keypress );
        void moveLeft( void );
        void moveRight( void );
        void moveUp( void );
        void moveDown( void );
        void shoot( void );

};

#endif