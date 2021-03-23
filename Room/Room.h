#ifndef Room_H
#define Room_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"


/** My Room Class
* @brief This class is responsible for all of the information regarding the different rooms of the game
* @author Jacob M Horgan
* @date March, 2018
**/






class Room {
    
    public:
    
    /** Constructor */
    Room();
    
    /** Destructor */
    ~Room();
    
    //Monster *monsters;
    
    
    
    
    
    /** 
     * 
     * @brief Initialises all parameters of the new room. Starts the room select
     * function.
     * 
     */
    void initRoom();
    
    
    /** 
     * 
     * @brief Randomly selects whcih room will be next out of 6 choices. These 
     * rooms all have different monsters etc.
     * 
     */
    void roomSelect();
    
    
    /** 
     * 
     * @brief Draws the current room to the LCD. Different rooms will have 
     * different draw functions inside them.
     * 
     */
    void drawRoom(N5110 &lcd);
    
    
    
    /** 
     * 
     * @brief Function to draw the chest in the middle of the screen. Only in
     * certain rooms and will change to open if chestFlag = true.
     * 
     */
    void drawChest(N5110 &lcd);
    
    
    
    /** 
     * 
     * @brief Function to draw the basic images of each room, left door and
     * perimeter walls.
     * 
     */
    void drawBasics(N5110 &lcd);
    
    
    
    /**
     * 
     * @brief Function to draw the image of the heart sprite above the chest if
     * the chest is opened. Dissapears if player picks it up.
     * 
     */
    void drawHeart(N5110 &lcd);
    
    
    
    /** 
     * 
     * @brief Function to randomly determine how many rocks should be in the
     * room, if that room is to have rocks.
     * 
     */
    void howManyRocks();
    
    
    
    /** 
     * 
     * @brief Function to return the number of rocks that are in a room.
     *
     * @return Returns the number of rocks in particular room
     */
    int rocksIn();
    
    
    
    /** 
     * 
     * @brief Function to open the door of the room, only happens when all 
     * monsters are dead.
     * 
     */
    void doorOpen();
    
    
    
    /** 
     * 
     * @brief Function to change the chestFlag to true.
     * 
     */
    void chestOpen();
    
    
    
    /** 
     * 
     * @brief Function to change the heartThere to true.
     * 
     */
    void heartStatusChange();
    
    
    
    /** 
     * 
     * @brief Function to return the status of the chestFlag.
     *
     * @return Returns the status of chestFlag.
     */
    int getChestStatus();
    
    
    
    /** 
     * 
     * @brief Function to return the status of the heartThere.
     *
     * @return Returns the status of heartThere.
     */
    int getHeartStatus();
    
    
    
    /** 
     * 
     * @brief Function to return the number of small monsters in room.
     *
     * @return Returns the value of numSmallMons.
     */
    int getNumSmallMons();
    
    
    
    /** 
     * 
     * @brief Function to return the number of Big monsters in room.
     *
     * @return Returns the value of numBigMons.
     */
    int getNumBigMons();
    
    

    
    
    private:
    
    int selection;
    int amountRocks;
    int numSmallMons;
    int numBigMons;
    bool roomDone;
    bool chestFlag;
    bool heartThere;
    bool rocksThere;
    
};

#endif
    
    