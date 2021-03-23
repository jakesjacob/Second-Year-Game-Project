/** My Bullet Class
* @brief This class is responsible for all of the information regarding the bullets of the game
* @author Jacob M Horgan
* @date March, 2018
**/


#include "Bullet.h"




// nothing doing in the constructor and destructor
Bullet::Bullet()
{
    
}

Bullet::~Bullet() 
{
    
}







                                                                                //NAME: initBullet(
                                                                                //INFO: Function to initiate the positions of the monster
void Bullet::initBullet(Vector2D player_pos_mons2, int bulletDir1){
    
    // Test message
    //printf("initBullet function initiated.\n");
    
    BulletPosX = player_pos_mons2.x;                                            //sets the bullets X coord as the same X coord of the player at time of shot
    BulletPosY = player_pos_mons2.y;                                            //sets the bullets Y coord as the same Y coord of the player at time of shot
    bulletDir = bulletDir1;                                                     //sets the bullets direction of travel as the same direction the player is facing at time of shot
    bulletExist = true;                                                         //sets the bullets status to exist
    
}
// End




                                                                                //NAME: bulletGone
                                                                                //INFO: Function to make the bullet not exist
void Bullet::bulletGone() {
    bulletExist = false;                                                        //makes the bullet not exist
}
// End




                                                                                //NAME: drawBullet
                                                                                //INFO: Function to draw the bullet
void Bullet::drawBullet(N5110 &lcd) {
    
    // Test message
    //printf("drawBullet function initiated.\n");

    if (bulletExist) {
    lcd.setPixel(BulletPosX, BulletPosY);                                       //draws the bullet as a single pixel if it exist
    }
    else if(!bulletExist) {
    lcd.clearPixel(BulletPosX, BulletPosY);                                     //clears that same pixel if the bullet doesnt exist
    }
}
// End




                                                                                //NAME: moveBullet
                                                                                //INFO: Function to initiate the positions of the monster
void Bullet::moveBullet() {
    
    // Test message
    //printf("moveBullet function initiated.\n");

    if(bulletDir == 1) {
        BulletPosY -= 4;                                                        //moves the bullet upwards if direction is 1 (up)
    }
    if(bulletDir == 2) {
        BulletPosX += 4;                                                        //moves the bullet right if direction is 2 (right)
    }
    if(bulletDir == 3) {
        BulletPosY += 4;                                                        //moves the bullet downwards if direction is 3 (down)
    }
    if(bulletDir == 4) {
        BulletPosX -= 4;                                                        //moves the bullet left if direction is 4 (left)
    }
}
// End




                                                                                //NAME: get_bulletPos
                                                                                //INFO: Function to create a 2D vector of player position
Vector2D Bullet::get_bulletPos() {
    Vector2D bb = {BulletPosX,BulletPosY};
    return bb;
}
// End




                                                                                //NAME: getBulletStaus
                                                                                //INFO: Function to return the status of the bullet
int Bullet::getBulletStatus() {
    return bulletExist;
}
// End