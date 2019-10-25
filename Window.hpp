/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:35:03 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/22 22:50:28 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Creating separate window classes for displaying ->
//      --Start Menu
//      --Game
//      --Game Over Screen

//Very useful link by Casual Coder - NCurses Refreshes, When and Why
//https://www.youtube.com/watch?v=U82JXzJoCL4

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <ncurses.h>

class Window {

    private:
        int _windowWidth;
        int _windowHeight;
        WINDOW* _win;
        

    public:
        Window( int width, int height );
        Window( Window const & window );
        Window& operator=( Window const & window );
        ~Window( void );
        void setup( void );
        void drawBorder( void );
        void updateWindow( void );
        

};

#endif