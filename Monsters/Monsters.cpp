/** My Monsters Class
* @brief This class is responsible for all of the information regarding the monsters of the game
* @author Jacob M Horgan
* @date March, 2018
**/


#include "Monsters.h"
#include <ctime>




// nothing doing in the constructor and destructor
Monster::Monster()
{

}

Monster::~Monster()
{

}







                                                                                // Sprite to display the image of the small monster 
const int monsterSmall[5][7] =   {
    { 0,0,1,1,1,0,0 },
    { 0,1,0,0,0,1,0 },
    { 1,1,1,1,1,1,1 },
    { 1,0,1,0,1,0,1 },
    { 1,0,1,0,1,0,1 },

    };
  
                                                                                // Sprite to display the image of the big monster   
const int monsterBig[9][8] =   {
    { 1,1,1,0,0,1,1,1 },
    { 0,0,1,1,1,1,0,0 },
    { 0,1,1,0,0,1,1,0 },
    { 1,1,0,0,0,0,1,1 },
    { 1,0,0,1,1,0,0,1 },
    { 1,1,0,0,0,0,1,1 },
    { 0,1,1,0,0,1,1,0 },
    { 0,0,1,1,1,1,0,0 },
    { 1,1,1,0,0,1,1,1 },

    };






                                                                                //NAME: initMonster
                                                                                //INFO: Function to initiate the positions of the monster
void Monster::initMonsterSmall(){
    
    // Test message 
    //printf("initMonster function initiated.\n");

    monsterPosX = rand() % (80 - 15) + 15;                                      //sets the monsters X coord randomly between 15 and 80
    monsterPosY = rand() % 44;                                                  //sets the monsters Y coord randomly between 0 and 44
    
    mHealth = 2;                                                                //sets the small monsters health to 2
    monsterDead = false;                                                        //initialses the monster as alive
    
}
// End





                                                                                //NAME: initMonster
                                                                                //INFO: Function to initiate the positions of the monster
void Monster::initMonsterBig(){
    
    // Test message 
    //printf("initMonster function initiated.\n");

    monsterBigPosX = rand() % (80 - 60) + 60;                                   //sets the monsters X coord randomly between 60 and 80
    monsterBigPosY = rand() % 44;                                               //sets the monsters Y coord randomly between 0 and 44
    
    mBigHealth = 4;                                                             //sets the big monsters health to 4
    monsterBigDead = false;                                                     //initialses the monster as alive
    
}
// End





                                                                                //NAME: drawMonsterSmall
                                                                                //INFO: Function to draw the monster (small)
void Monster::drawMonsterSmall(N5110 &lcd) {
    
    // Test message 
    //printf("drawMonster function initiated.\n");

    if (!monsterDead) {                                                         //if monster alive, draw
        lcd.drawSprite(monsterPosX,monsterPosY,5,7,(int *)monsterSmall);
    }
        
}
// End




                                                                                //NAME: drawMonsterBig
                                                                                //INFO: Function to draw the big monster 
void Monster::drawMonsterBig(N5110 &lcd) {
    
    // Test message 
    //printf("drawMonsterBig function initiated.\n");

    if (!monsterBigDead) {                                                      //if big monster alive, then draw big monster sprite
        lcd.drawSprite(monsterBigPosX,monsterBigPosY,9,8,(int *)monsterBig);
    }
        
}
// End






                                                                                //NAME: monsterMove
                                                                                //INFO: Function to give the monsters random sporadic movement
void Monster::monsterMoveSmall() {
    
    // Test message 
    //printf("monsterMove function initiated.\n");

    int mDirection = rand() % 4;                                                //sets the variable mDirection to a random number between 0 and 4 (corresponding to up,down,left,right)
    
    if (mDirection == 0) {                                                      //if 0 monster moves up by 2 pixels
        monsterPosY -= 2;
    } 
    else if (mDirection == 1) {                                                 //if 1 monster moves left by 2 pixels
        monsterPosX -= 2;
    }
    else if (mDirection == 2) {                                                 //if 2 monster moves down by 2 pixels
        monsterPosY += 2;
    }
    else if (mDirection == 3) {                                                 //if 3 monster moves right by 2 pixels
        monsterPosX += 2;
    }
                                                                                       
    if(monsterPosX < 3){                                                        //sets the boundarys for the monster to edges of the screen. left
        monsterPosX = 3;
    }
    if(monsterPosX+4>WIDTH-3){                                                  //sets the boundarys for the monster to edges of the screen. right
        monsterPosX = WIDTH -7;
    }
    if (monsterPosY < 3){                                                       //sets the boundarys for the monster to edges of the screen. top
        monsterPosY = 3;
    }
    if (monsterPosY+6 > HEIGHT - 3) {                                           //sets the boundarys for the monster to edges of the screen. bottom
        monsterPosY = HEIGHT-10;
    }
    wait(0.005);
}
// End



                                                                                //NAME: monsterMoveBig
                                                                                //INFO: Function to give the monsters random sporadic movement towards player
void Monster::monsterMoveBig(Vector2D player_pos_mons) {
    
    // Test message 
    //printf("monsterMove function initiated.\n");

    if (monsterBigPosY > player_pos_mons.y + 3){                                //uses the players xy coords (from argument) to move the monster closer towards player
        monsterBigPosY -= 1;
    }
    if (monsterBigPosY < player_pos_mons.y - 3){                                //uses the players xy coords (from argument) to move the monster closer towards player
        monsterBigPosY += 1;
    }
    if (monsterBigPosX > player_pos_mons.x + 3){                                //uses the players xy coords (from argument) to move the monster closer towards player
        monsterBigPosX -= 1;
    }
    if (monsterBigPosX < player_pos_mons.x - 3){                                //uses the players xy coords (from argument) to move the monster closer towards player
        monsterBigPosX += 1;
    }
    
    int mDirection = rand() % 4;                                                //sets the variable mDirection to a random number between 0 and 4 (corresponding to up,down,left,right)
    
    if (mDirection == 0) {                                                      //if 0 monster moves up by 1 pixels
        monsterBigPosY -= 1;
    }
    else if (mDirection == 1) {                                                 //if 1 monster moves left by 1 pixels
        monsterBigPosX -= 1;
    }
    else if (mDirection == 2) {                                                 //if 2 monster moves down by 1 pixels
        monsterBigPosY += 1;
    }
    else if (mDirection == 3) {                                                 //if 3 monster moves right by 1 pixels
        monsterBigPosX += 1;
    }
                                                                                   
    if(monsterBigPosX < 3){                                                     //sets the boundarys for the monster to edges of the screen. left
        monsterBigPosX = 3;
    }
    if(monsterBigPosX+4>WIDTH-3){                                               //sets the boundarys for the monster to edges of the screen. right
        monsterBigPosX = WIDTH -7;
    }
    if (monsterBigPosY < 3){                                                    //sets the boundarys for the monster to edges of the screen. top
        monsterBigPosY = 3;
    }
    if (monsterBigPosY+6 > HEIGHT - 3) {                                        //sets the boundarys for the monster to edges of the screen. bottom
        monsterBigPosY = HEIGHT-10;
    }
    wait(0.005);
}
// End




                                                                                //NAME: monsterHealthCheck
                                                                                //INFO: Function to check if monster should be dead
void Monster::monsterHealthCheck() {
    
    if (monsterDead == false && mHealth <= 0) {                                 //check if the monster is alive and if it should be dead
        monsterDead = true;                                                     //sets the monster to dead
    }
}
// End



                                                                                //NAME: monsterBigHealthCheck
                                                                                //INFO: Function to check if big monster should be dead
void Monster::monsterBigHealthCheck() {
    
    if (monsterBigDead == false && mBigHealth <= 0) {                           //check if the big monster is alive and if it should be dead
        monsterBigDead = true;                                                  //sets the big monster to dead
    }
}
// End




                                                                                //NAME: monsterSmallHit
                                                                                //INFO: Function to take 1 away from small monsters health
void Monster::monsterSmallHit() {
    mHealth --;
}
// End






                                                                                //NAME: monsterBigHit
                                                                                //INFO: Function to take 1 away from big monsters health
void Monster::monsterBigHit() {
    mBigHealth --;
}
// End
  
    



                                                                                //NAME: get_monsterPos
                                                                                //INFO: Function to create a 2D vector of the monsters position
Vector2D Monster::get_monsterPos() {
    
    // Test message 
    //printf("get_monsterPos function initiated.\n");

    Vector2D pp = {monsterPosX,monsterPosY};
    return pp;
}
// End






                                                                                //NAME: get_monsterBigPos
                                                                                //INFO: Function to create a 2D vector of the big monsters position
Vector2D Monster::get_monsterBigPos() {
    
    // Test message 
    //printf("get_monsterPos function initiated.\n");

    Vector2D pp = {monsterBigPosX,monsterBigPosY};
    return pp;
}
// End



                                                                                //NAME: getSmallMonsterStatus
                                                                                //INFO: Function to return the status of monsterDead
int Monster::getSmallMonsterStatus() {
    return monsterDead;
}
// End




                                                                                //NAME: getBigMonsterStatus
                                                                                //INFO: Function to return the status of monsterBigDead
int Monster::getBigMonsterStatus() {
    return monsterBigDead;
}
// End