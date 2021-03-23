#ifndef Monsters_H
#define Monsters_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Room.h"
#include "Player.h"



/** My Monsters Class
* @brief This class is responsible for all of the information regarding the monsters of the game
* @author Jacob M Horgan
* @date March, 2018
**/







class Monster {
    
    public:
    
    /** Constructor */
    Monster();
    
    /** Destructor */
    ~Monster();
    
    
    
    
    
    /** 
     * 
     * @brief  Function to initialses all of the parameters regarding the small
     * monsters in the game. Position, health and dead flag.
     * 
     */
    void initMonsterSmall();
    
    
    
    /** 
     * 
     * @brief Function to initialses all of the parameters regarding the big
     * monsters in the game. Position, health and dead flag.
     * 
     */
    void initMonsterBig();
    
    
    
    /** 
     * 
     * @brief Function to draw the image of the small monster to screen, but
     * only if that monster is "alive".
     * 
     */  
    void drawMonsterSmall(N5110 &lcd);
    
    
    
    /** 
     * 
     * @brief Function to draw the image of the big monster to screen, but
     * only if that monster is "alive".
     * 
     */
    void drawMonsterBig(N5110 &lcd);
    
    
    
    /** 
     * 
     * @brief Function to give the small monsters a random sporadic movement,
     * that is limited to inside the room due to boundary code.
     * 
     */
    void monsterMoveSmall();
    
    
    
    /** 
     * 
     * @brief Function to give the big monsters a random sporadic movement and,
     * also a homing movement towards ther players position.
     * Also limited to inside the room due to boundary code.
     *
     * @param player_pos_mons - X Y coords of the player 
     */
    void monsterMoveBig(Vector2D player_pos_mons);
    
    
    
    /** 
     * 
     * @brief Function to check if the current alive monsters should be dead.
     * Due to health being 0 or lower. Sets that monster to dead if so.
     * 
     */
    void monsterHealthCheck();
    
    
    
    /** 
     * 
     * @brief Function to check if the current alive big monsters should be dead.
     * Due to health being 0 or lower. Sets that monster to dead if so.
     * 
     */
    void monsterBigHealthCheck();
    
    
    
    /**
     * 
     * @brief Function to remove a value of 1 health from small monster.
     * 
     */
    void monsterSmallHit();
    
    
    
    /** 
     * 
     * @brief Function to remove a value of 1 health from big monster.
     * 
     */
    void monsterBigHit();
    
    
    
    /** 
     * 
     * @brief A function to return the value of the small monsters X Y coords 
     * in a 2D vector.
     * 
     * @return Returns the X Y coordinates of the small monster.
     */
    Vector2D get_monsterPos();
    
    
    
    /** 
     * 
     * @brief A function to return the value of the big monsters X Y coords in a 
     * 2D vector.
     * 
     * @return Returns the X Y coordinates of the big monster.
     */
    Vector2D get_monsterBigPos();
    
    
    /** 
     * 
     * @brief A function to return the status of the bool monsterDead.
     * 
     * @return Returns the status of bool monsterDead.
     */
    int getSmallMonsterStatus();
    
    
    
    /** 
     * 
     * @brief A function to return the status of the bool monsterBigDead.
     * 
     * @return Returns the status of bool monsterBigDead.
     */
    int getBigMonsterStatus();
    
    
    
    int monsterPosX;
    int monsterPosY;
    int monsterBigPosX;
    int monsterBigPosY;
    int mHealth;
    int mBigHealth;
    
    
    
    private:
    
    bool monsterDead;
    bool monsterBigDead;

    
};


#endif