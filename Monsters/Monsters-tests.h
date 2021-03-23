#ifndef Monsters_TESTS_H
#define Monsters_TESTS_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Room.h"
#include "Player.h"



/** My Monsters-tests file
* @brief This file is responsible for all of the information regarding the monsters-test functions.
* @author Jacob M Horgan
* @date March, 2018
**/








int monsterSmallPositionTest() {                                                //checks if the movement of the monster, and also the get_monsterPos function works correctly
    
    printf("monsterSmallPositionTest running.\n");
    
    bool successFlag = false;
    
    Monster monsterSmall;
    
    monsterSmall.initMonsterSmall();
    
    monsterSmall.monsterMoveSmall();
    
    Vector2D monsterSmallPos = monsterSmall.get_monsterPos();
    
    if ((monsterSmallPos.x == monsterSmall.monsterPosX) && (monsterSmallPos.y == monsterSmall.monsterPosY)) {
        successFlag = true;
    }
    return successFlag;
}




int monsterBigPositionTest() {                                                  //checks if the movement of the big monster, and also the get_monsterPos function works correctly
    
    printf("monsterBigPositionTest running.\n");
    
    bool successFlag = false;
    
    Monster monsterBig;
    Player player;
    
    monsterBig.initMonsterBig();
    
    Vector2D playerPos = player.get_playerPos();
    
    monsterBig.monsterMoveBig(playerPos);
    
    Vector2D monsterBigPos = monsterBig.get_monsterBigPos();
    
    if ((monsterBigPos.x == monsterBig.monsterBigPosX) && (monsterBigPos.y == monsterBig.monsterBigPosY)) {
        successFlag = true;
    }
    return successFlag;
}




int monsterSmallHealthTest() {                                                  //checks to see if the monster health functions are working correctly
    
    printf("monsterSmallHealthTest running.\n");
    
    bool successFlag = false;
    
    Monster monsterSmall;
    
    monsterSmall.initMonsterSmall();
    printf("Monster lifes = %d.\n", monsterSmall.mHealth);
    
    monsterSmall.monsterSmallHit();
    printf("Monster lifes = %d.\n", monsterSmall.mHealth);
    
    if (monsterSmall.mHealth == 1) {
        successFlag = true;
    }
    return successFlag;
}





int monsterBigHealthTest() {                                                    //checks to see if the big monster health functions are working correctly
    
    printf("monsterBigHealthTest running.\n");
    
    bool successFlag = false;
    
    Monster monsterBig;
    
    monsterBig.initMonsterBig();
    printf("Big monster lifes = %d.\n", monsterBig.mBigHealth);
    
    monsterBig.monsterBigHit();
    printf("Big monster lifes = %d.\n", monsterBig.mBigHealth);
    
    if (monsterBig.mBigHealth == 3) {
        successFlag = true;
    }
    return successFlag;
}

    
    
    

int monsterSmallStatusTest() {                                                  //checks to see if the return small monster status function is working correctly
    
    printf("monsterSmallStatusTest running.\n");
    
    bool successFlag = false;
    
    Monster monsterSmall;
    
    monsterSmall.initMonsterSmall();
    
    monsterSmall.monsterSmallHit();
    monsterSmall.monsterSmallHit();
    
    monsterSmall.monsterHealthCheck();
    
    if (monsterSmall.getSmallMonsterStatus()) {
        successFlag = true;
    }
    return successFlag;
}
    
    



int monsterBigStatusTest() {                                                    //checks to see if the return big monster status function is working correctly
    
    printf("monsterBigStatusTest running.\n");
    
    bool successFlag = false;
    
    Monster monsterBig;
    
    monsterBig.initMonsterBig();
    
    monsterBig.monsterBigHit();
    monsterBig.monsterBigHit();
    monsterBig.monsterBigHit();
    monsterBig.monsterBigHit();
    
    monsterBig.monsterBigHealthCheck();
    
    if (monsterBig.getBigMonsterStatus()) {
        successFlag = true;
    }
    return successFlag;
}






#endif


  
    
    
    
    
    
    
    
