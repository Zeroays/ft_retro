/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:18:07 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/22 22:49:06 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"
#include "Player.hpp"
#include "Window.hpp"

#include <iostream>

int main( void ) {
    
    const int SCREEN_WIDTH = 160;
    const int SCREEN_HEIGHT = 50;
    
    Screen standard = Screen( SCREEN_WIDTH, SCREEN_HEIGHT );
    Player p1 = Player( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, '>' );
    Window mainMenu = Window( SCREEN_WIDTH, SCREEN_HEIGHT );
    
    while ( !standard.isDone() ) {
        int keyPressed = standard.getPressed();
        p1.controls( keyPressed );
        standard.clearScreen();
        p1.draw();
        mainMenu.updateWindow();
        standard.updateScreen();
        
        
        if ( keyPressed == KEY_HOME )
            standard.quit();
    }
    return (0);

}