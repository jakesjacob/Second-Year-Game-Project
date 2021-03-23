#ifndef Player_TESTS_H
#define Player_TESTS_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"


/** My Player-tests file
* @brief This file is responsible for all of the information regarding the player-test functions.
* @author Jacob M Horgan
* @date May, 2018
**/




int playerGetPositionTest() {                                                   //checks to see if the get_playerPos function is working correctly
    
    printf("playerGetPositionTest running.\n");
    
    bool successFlag = false;
    
    Player player;
    
    player.initPlayer();
    
    Vector2D playerPos = player.get_playerPos();
    
    if ((playerPos.x == player.playerPosX + 1) && (playerPos.y == player.playerPosY + 4)) {
        successFlag = true;
    }
    return successFlag;
}





int playerHealthTest() {                                                        //checks to see if the player health functions are working correctly
    
    printf("playerHealthTest running.\n");
    
    bool successFlag = false;
    
    Player player;
    
    player.startHealth();
    
    player.playerLife();
    
    player.playerHit();
    player.playerHit();
    player.playerHit();
    
    player.playerLife();
    
    if (player.pHealth == 4) {
        successFlag = true;
    }
    printf("player lifes = %d.\n", player.pHealth);
    return successFlag;
}
    
    
    
    
    
int playerStatusTest() {                                                        //checks to see if the return playerStatus works correctly
    
    printf("playerStatusTest running.\n");
    
    bool successFlag = false;
    bool successFlag1 = false;
    bool successFlag2 = false;
    
    Player player;
    Gamepad gamepad;
    
    player.startHealth();
    
    player.playerLife();
    
    player.playerHit();
    player.playerHit();
    player.playerHit();
    
    player.playerLife();
    
    if (!player.getPlayerStatus()) {
        successFlag1 = true;
    }
    printf("player lifes = %d .\n", player.pHealth);
    printf("successFlag1 = %d .\n", successFlag1);
    
    player.playerHit();
    player.playerHit();
    player.playerHit();
    player.playerHit();
    
    player.playerHealth(gamepad);
    
    if (player.getPlayerStatus()) {
        successFlag2 = true;
    }
    printf("player lifes = %d .\n", player.pHealth);
    printf("successFlag2 = %d .\n", successFlag2);
    
    if ((successFlag1) && (successFlag2)) {
        successFlag = true;
    }
    printf("successFlag = %d .\n", successFlag);
    return successFlag;
}
    
    
    
    

#endif  
    
    