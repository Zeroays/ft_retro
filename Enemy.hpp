/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:54:03 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 20:54:04 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <ncurses.h>
#include <iostream>

class Enemy {

    private:
        int _x;
        int _y;
        char _symbol;
    
    public:
        Enemy( void );
        Enemy( int x, int y, char character );
        Enemy( Enemy const & enemy );
        Enemy& operator=( Enemy const & enemy );
        ~Enemy( void );
        int getX( void );
        int getY( void );
        void setX( int x );
        void setY( int y );
        void draw( void );
        void fly( int screenWidth, int screenHeight );
        
};


#endif