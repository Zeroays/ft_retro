/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:50:07 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 21:55:48 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARS_HPP
#define STARS_HPP

#include <iostream>
#include <curses.h>
#include <ncurses.h>

class Star {

    private:
        int _x;
        int _y;
        int _symbol;
    
    public:
        Star( void );
        Star( int x, int y, char character );
        Star( Star const & star );
        Star& operator=( Star const & star );
        ~Star( void );
        int getX( void );
        int getY( void );
        void setx( int x );
        void sety( int y );
        void draw( void );
        void fly( int screenWidth, int screenHeight );
        
};

#endif