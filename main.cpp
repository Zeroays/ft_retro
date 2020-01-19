/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:54:11 by vrabaib           #+#    #+#             */
/*   Updated: 2019/10/27 22:53:57 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Swarm.hpp"

#include <iostream>
#include <unistd.h>
#include <curses.h>

void displayScore( int score ) {
    init_pair( 3, COLOR_GREEN, COLOR_BLACK );
    attron( COLOR_PAIR(3) );
    std::string text = "Score: ";
    mvaddstr( 0, 0, text.c_str());
    mvaddstr( 0, text.length() + 1, std::to_string(score).c_str() );
    attroff( COLOR_PAIR(3) );
}

int main( void ) {
    
    srand(time(NULL));
    const int SCREEN_WIDTH = 160;
    const int SCREEN_HEIGHT = 50;
    int score = 0;
    
    Screen standard = Screen( SCREEN_WIDTH, SCREEN_HEIGHT );
    Player p1 = Player( 3, SCREEN_HEIGHT / 2, '>', SCREEN_WIDTH, SCREEN_HEIGHT );
    Swarm enemyFleet = Swarm( SCREEN_WIDTH, SCREEN_HEIGHT, &p1, &standard );
    while ( !standard.isDone() ) {
        int keyPressed = standard.getPressed();
        standard.clearScreen();
        displayScore( score );
        standard.drawStars();
        p1.draw();
        p1.drawBullets();
        p1.controls( keyPressed );
        enemyFleet.drawSwarm();
        enemyFleet.playerHit();
        enemyFleet.bulletHit();
        usleep(17500);
        standard.updateScreen();
        score += 1;
        if ( keyPressed == KEY_HOME )
            standard.quit();
    }
    return (0);

}