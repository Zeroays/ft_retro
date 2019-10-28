/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:18:07 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 17:12:23 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

#include <iostream>
#include <unistd.h>

int main( void ) {
    
    srand(time(NULL));
    const int SCREEN_WIDTH = 160;
    const int SCREEN_HEIGHT = 50;
    int enemyAmt = 5;
    
    Screen standard = Screen( SCREEN_WIDTH, SCREEN_HEIGHT );
    Player p1 = Player( 3, SCREEN_HEIGHT / 2, '>', SCREEN_WIDTH, SCREEN_HEIGHT );
    Enemy swarm[enemyAmt];
    for (int i = 0; i < enemyAmt; i++)
        swarm[i] = Enemy( SCREEN_WIDTH, rand() % SCREEN_HEIGHT, '<' );
    Enemy e1 = Enemy( SCREEN_WIDTH, rand() % SCREEN_HEIGHT, '<' );
    //Window gameWindow = Window( SCREEN_WIDTH, SCREEN_HEIGHT );
    while ( !standard.isDone() ) {
        int keyPressed = standard.getPressed();
        standard.clearScreen();
        p1.draw();
        p1.drawBullets();
        p1.controls( keyPressed );
        for (int i = 0; i < enemyAmt; i++)
            swarm[i].fly( SCREEN_WIDTH, SCREEN_HEIGHT );
        usleep(17500);
        standard.updateScreen();
        //gameWindow.updateWindow();
        
        if ( keyPressed == KEY_HOME )
            standard.quit();
    }
    return (0);

}