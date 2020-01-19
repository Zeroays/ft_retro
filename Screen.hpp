/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:54:46 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 21:26:02 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <ncurses.h>
#include "Stars.hpp"

class Screen {

    private:
        int _screenWidth;
        int _screenHeight;
        bool    _done;
        static const int _starAmt = 20;
        Star _stars[_starAmt];

    public:
        Screen( void );
        Screen( int width, int height );
        Screen( Screen const & screen );
        Screen& operator=( Screen const & screen );
        ~Screen( void );
        bool isDone( void ) const;
        int  getPressed( void );
        void drawStars( void );
        void setup( void );
        void setDone( void );
        void clearScreen( void );
        void updateScreen( void );
        void quit( void );

};


#endif