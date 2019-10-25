/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:06:27 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/22 21:32:35 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <ncurses.h>

class Enemy {

    private:
        int _x;
        int _y;
        char _symbol;
    
    public:
        Enemy( int x, int y, char character );
        Enemy( Enemy const & enemy );
        Enemy& operator=( Enemy const & enemy );
        ~Enemy( void );
        void draw( void );
        
};


#endif