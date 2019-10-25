/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:18:12 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/22 22:12:52 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <ncurses.h>

#define ESC 27

class Screen {

    private:
        int _screenWidth;
        int _screenHeight;
        bool    _done;

    public:
        Screen( int width, int height );
        ~Screen( void );
        bool isDone( void ) const;
        int  getPressed( void );
        void setup( void );
        void clearScreen( void );
        void updateScreen( void );
        void quit( void );

};


#endif