/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:30:15 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 17:10:04 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
#define BULLET_HPP

#include <ncurses.h>

class Bullet {

    private:
        int _x;
        int _y;
        char _symbol;
        bool _isActive;
    
    public:
        Bullet();
        Bullet( int x, int y, char character );
        Bullet( Bullet const & bullet );
        Bullet& operator=( Bullet const & bullet );
        ~Bullet( void );
        int getX( void );
        int getY( void );
        void setX( int x );
        void setY( int y );
        bool getActive( void );
        void setActive( bool active );
        void draw( void );
        void travel( int screenWidth );

};


#endif