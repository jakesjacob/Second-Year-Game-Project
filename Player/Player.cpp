/** My Player Class
* @brief This class is responsible for all of the information regarding the player character of the game
* @author Jacob M Horgan
* @date March, 2018
**/


#include "Player.h"




// nothing doing in the constructor and destructor
Player::Player()
{

}

Player::~Player()
{

}








const int playerRight[7][4] =   {                                               //sprite for player facing right
    { 0,1,1,1 },
    { 0,1,0,0 },
    { 1,1,1,0 },
    { 1,0,1,0 },
    { 1,1,1,0 },
    { 0,1,0,0 },
    { 0,1,1,1 },
    };
    
const int playerLeft[7][4] =   {                                                //sprite for player facing left
    { 1,1,1,0 },
    { 0,0,1,0 },
    { 0,1,1,1 },
    { 0,1,0,1 },
    { 0,1,1,1 },
    { 0,0,1,0 },
    { 1,1,1,0 },
    };

const int playerUp[4][7] =   {                                                  //sprite for player facing up
    { 1,0,0,0,0,0,1 },
    { 1,0,1,1,1,0,1 },
    { 1,1,1,0,1,1,1 },
    { 0,0,1,1,1,0,0 },
    };
    
const int playerDown[4][7] =   {                                                //sprite for player facing down
    { 0,0,1,1,1,0,0 },
    { 1,1,1,0,1,1,1 },
    { 1,0,1,1,1,0,1 },
    { 1,0,0,0,0,0,1 },
    };










                                                                                //NAME: initPlayer
                                                                                //INFO: Function to initiate the starting characteristics of the player
void Player::initPlayer(){
    
    // Test message 
    //printf("initPlayer function initiated.\n");

    playerPosX = 3;                                                             //sets the players inital x coord
    playerPosY = 22;                                                            //sets the players inital Y coord
    playerFacing = 2;                                                           //sets the players inital DIRECTION (RIGHT)
    playerDead = false;                                                         //sets the players dead flag to false
}
// End






                                                                                //NAME: drawPlayer
                                                                                //INFO: Function to draw the image of the player
void Player::drawPlayer(N5110 &lcd){
     
    // Test message 
    //printf("drawPlayer function initiated.\n");

    if(playerFacing == 1) {
    lcd.drawSprite(playerPosX,playerPosY,4,7,(int *)playerUp);                  //draws player facing up 
    }
    if(playerFacing == 2) {
    lcd.drawSprite(playerPosX,playerPosY,7,4,(int *)playerRight);               //draws player facing right
    }
    if(playerFacing == 3) {
    lcd.drawSprite(playerPosX,playerPosY,4,7,(int *)playerDown);                //draws player facing down
    }
    if(playerFacing == 4) {
    lcd.drawSprite(playerPosX,playerPosY,7,4,(int *)playerLeft);                //draws player facing left
    }
     
    lcd.refresh();
  
}
// End






                                                                                //NAME: updatePlayer
                                                                                //INFO: Function to update all the information about the player
void Player::updatePlayer(Direction d,float mag){
    
    // Test message 
    //printf("updatePlayer function initiated.\n");

    _speed = int(mag*3.0f);                                                     //scales the magnitude of the joystick to a reasonable value for the pixel movement

    if (d == N) {                                                               //moves the player in the North direction
        playerPosY -= _speed;
    }
    else if (d == NW) {                                                         //moves the player in the North-West direction
        playerPosX -= _speed;
        playerPosY -= _speed;
    }
    else if (d == NE) {                                                         //moves the player in the North-East direction
        playerPosX += _speed;
        playerPosY -= _speed;
    }
    else if (d == S) {                                                          //moves the player in the South direction
        playerPosY += _speed;
    }
    else if (d == SW) {                                                         //moves the player in the South-West direction
        playerPosX -= _speed;
        playerPosY += _speed;
    }
    else if (d == SE) {                                                         //moves the player in the South-East direction
        playerPosX += _speed;
        playerPosY += _speed;
    }
    else if (d == E) {                                                          //moves the player in the East direction
        playerPosX += _speed;
    }
    else if (d == W) {                                                          //moves the player in the West direction
        playerPosX -= _speed;
    }

    if(playerPosX < 3){                                                         //check to ensure that the Character doesn't go off screen. Left side
        playerPosX = 3;
    }
    if(playerPosX +4 > WIDTH - 3){                                              //check to ensure that the Character doesn't go off screen. Right side
        playerPosX = WIDTH - 7;
    }
    if (playerPosY < 3){                                                        //check to ensure that the Character doesn't go off screen. Top
        playerPosY = 3;
    }
    if (playerPosY +6 > HEIGHT - 3){                                            // check to ensure that the Character doesn't go off screen. Bottom
        playerPosY = HEIGHT - 10;
    }  
}
// End





                                                                                //NAME: playerHealth
                                                                                //INFO: Function to keep track and display the players health, via LEDs
void Player::playerHealth(Gamepad &gamepad) {
    
    // Test message 
    //printf("playerHealth function initiated.\n");

    if (pHealth == 6) {                                                         //displays 6 LEDs on if player has 6 lives
        gamepad.led(1,1), gamepad.led(2,1), gamepad.led(3,1);
        gamepad.led(4,1), gamepad.led(5,1), gamepad.led(6,1);
    }
    if (pHealth == 5) {                                                         //displays 5 LEDs on if player has 5 lives
        gamepad.led(1,1), gamepad.led(2,1), gamepad.led(3,1);
        gamepad.led(4,1), gamepad.led(5,1), gamepad.led(6,0);
    }
    if (pHealth == 4) {                                                         //displays 4 LEDs on if player has 4 lives
        gamepad.led(1,1), gamepad.led(2,1), gamepad.led(3,1);
        gamepad.led(4,1), gamepad.led(5,0), gamepad.led(6,0);
    }
    if (pHealth == 3) {                                                         //displays 3 LEDs on if player has 3 lives
        gamepad.led(1,1), gamepad.led(2,1), gamepad.led(3,1);
        gamepad.led(4,0), gamepad.led(5,0), gamepad.led(6,0);
    }
    if (pHealth == 2) {                                                         //displays 2 LEDs on if player has 2 lives
        gamepad.led(1,1), gamepad.led(2,1), gamepad.led(3,0);
        gamepad.led(4,0), gamepad.led(5,0), gamepad.led(6,0);
    }
    if (pHealth == 1) {                                                         //displays 1 LEDs on if player has 1 lives
        gamepad.led(1,1), gamepad.led(2,0), gamepad.led(3,0);
        gamepad.led(4,0), gamepad.led(5,0), gamepad.led(6,0);
    }
    if (pHealth <= 0) {                                                         //displays 0 LEDs on if player has 0 lives
        gamepad.led(1,0), gamepad.led(2,0), gamepad.led(3,0);
        gamepad.led(4,0), gamepad.led(5,0), gamepad.led(6,0);
        
        playerDead = true;                                                         //sets the player dead flag to true
    }
}
// End



                                                                                //NAME: checkRotation
                                                                                //INFO: Function to check if the player has been asked to rotate
void Player::checkRotation(Gamepad &gamepad) {
    
    if(gamepad.check_event(Gamepad::R_PRESSED)) {                               //checks if the R button has been pressed
        playerFacing = playerFacing + 1;                                        //changes the playerFacing variable (turns clockwise)
    }
    if(gamepad.check_event(Gamepad::L_PRESSED)) {                               //checks if the L button has been pressed
        playerFacing = playerFacing - 1;                                        //changes the playerFacing variable (turns anti clockwise)
    }
    if (playerFacing > 4) {                                                     //loops the variable through 1 - 4
        playerFacing = 1;
    }
}
// End





                                                                                //NAME: startHealth
                                                                                //INFO: Function to remove a life from players health
void Player::startHealth() {
    pHealth = 6;                                                                //sets the players health back to full
}
// End




                                                                                //NAME: playerHit
                                                                                //INFO: Function to remove a life from players health
void Player::playerHit() {
    pHealth --;
}
// End



                                                                                //NAME: playerLife
                                                                                //INFO: Function to add a life to players health
void Player::playerLife() {
    pHealth ++;
    
    if (pHealth > 6) {                                                          //stops the players health from going above 6 lives (from heart pick ups)
        pHealth = 6;
    }
}
// End




                                                                                //NAME: getPlayerStatus
                                                                                //INFO: Function to return the bool playerDead status
bool Player::getPlayerStatus() {
    return playerDead;
}
// End




                                                                                //NAME: getPlayerFacing
                                                                                //INFO: Function to return the variable corresponding to the players direction
int Player::getPlayerFacing() {
    return playerFacing;
}
// End


                                                                                //NAME: get_playerPos
                                                                                //INFO: Function to create a 2D vector of player position and return it
Vector2D Player::get_playerPos() {
    Vector2D pp = {playerPosX+1,playerPosY+4};
    return pp;
}
// End

