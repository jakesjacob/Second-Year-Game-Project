#ifndef Player_H
#define Player_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"


/** My Player Class
* @brief This class is responsible for all of the information regarding the player character of the game
* @author Jacob M Horgan
* @date March, 2018
**/






class Player {
    
    public:
    
    /** Constructor */
    Player();
    
    /** Destructor */
    ~Player();
    
    
    
    /** 
     * 
     * @brief Initialses all parameters relevant to the player.
     * Sets the position, direction and alive status.
     * 
     */
    void initPlayer();
    
    
    
    /** 
     * 
     * @brief Draws the player on to the LCD. Will draw one of the four sprites,
     * depending on what direction the player is facing.
     * 
     */
    void drawPlayer(N5110 &lcd);
    
    
    
    /** 
     * 
     * @brief Updates the players movement and position. Takes the direction and
     * magnitude of the gamepad joystick as arguments, and uses them to dtermine
     * movement direction and speed.
     *
     * @param d - the direction from the joystick
     * @param mag - initalses the speed of the character from the magnitude of the force on the joystick
     */
    void updatePlayer(Direction d,float mag);
    
    
     
    /** 
     * 
     * @brief Function that monitors the players health. This function ensures 
     * that the correct LEDs are lit corresponding to the players health. Also,
     * lets the game know if the player is dead.
     * 
     */
    void playerHealth(Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Checks to see if the player has rotated to a new direction
     * via the Left & Right buttons.
     */
    void checkRotation(Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Sets the players health to the max (6) 
     * 
     */
    void startHealth();
    
    
    
    /** 
     * 
     * @brief Removes a value of 1 from the players health when this function
     * is ran. 
     * 
     */
    void playerHit();
    
    
    
    /** 
     * 
     * @brief Adds a value of 1 to the players health when this function
     * is ran. 
     * 
     */
    void playerLife();
    
    
    
    /** 
     * 
     * @brief A function to return the bool status of the player
     *
     * @return Returns the bool playerDead
     */
    bool getPlayerStatus();
    
    
    
    /** 
     * 
     * @brief A function to return the variable corresponding to the players
     *  direction.
     *
     * @return Returns the variable playerFacing
     */
    int getPlayerFacing();
    
    
    
    /** 
     * 
     * @brief A function to return the value of the players X Y coords in a 
     * 2D vector.
     * 
     * @return Returns the X Y coordinates of the player
     */
    Vector2D get_playerPos();
    
    
    
    
    int playerPosX;
    int playerPosY;
    int pHealth;
    

    
    private:
    
    bool playerDead;
    int playerFacing;
    int _speed;
    

    
};


#endif