#ifndef Bullet_H
#define Bullet_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"



/** My Bullet Class
* @brief This class is responsible for all of the information regarding the bullets of the game
* @author Jacob M Horgan
* @date March, 2018
**/





class Bullet {

    public:
    
    /** Constructor */
    Bullet();
    
    /** Destructor */
    ~Bullet();
    
    
    
    
    
    /** 
     * 
     * @brief Initialises all parameters of the bullet.
     * 
     * @param player_pos_mons2 - stores the 2D location i.e. the (x,y) co-ordinate of the cetre point of the character on the screen
     * @param bulletDir1 - stores the value that corresponds to the direction of the player when shot fired
     */
    void initBullet(Vector2D player_pos_mons2, int bulletDir1);
    
    
    
    /** 
     * 
     * @brief Moves the bullet in the required direction depending on the 
     * direction acquired in initBullet.
     * 
     */
    void moveBullet();
    
    
    
    /** 
     * 
     * @brief Draws the bullet to the LCD if it exists.
     * 
     */
    void drawBullet(N5110 &lcd);
    
    
    
    /** 
     * 
     * @brief Changes the bullet exist bool to false.
     * 
     */
    void bulletGone();
    
    
    
    /** 
     * 
     * @brief A function to return the X Y coordinates of the bullet.
     *
     * @return Returns the bullets X Y coordinates. 
     */
    Vector2D get_bulletPos();
    
    
    
    /** 
     * 
     * @brief A function to return the exist status of the bullet.
     *
     * @return Returns the status of the bullet. 
     */
    int getBulletStatus();
    
    
    
    int BulletPosX;
    int BulletPosY;
    
    
    
    
    private:
    
    int bulletDir;
    bool bulletExist;





};








#endif