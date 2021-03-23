#ifndef GEngine_H
#define GEngine_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Room.h"
#include "Player.h"
#include "Monsters.h"
#include "Bullet.h"
#include "Obstacles.h"

#define MAX_NUM_MONSTERS 7



/** My Game Engine Class
* @brief This class is responsible for most of the main functions of the game, it is very useful for integrating different objects of different classes with each other.
* @author Jacob M Horgan
* @date March, 2018
**/






class Game {
    
    public:
    
    /** Constructor */
    Game();
    
    /** Destructor */
    ~Game();
    
    
    Player player;                                                              //creates an object called player of class Player
    Room room;                                                                  //creates an object called room of class Room
    Monster monsters[MAX_NUM_MONSTERS];                                         //creates an array of objects called monsters from class Monster
    Monster monstersBig[MAX_NUM_MONSTERS];                                      //creates an array of objects called monstersBig from class Monster
    Bullet bullets[200];                                                        //creates an array of objects called bullets from class Bullet
    Obstacles rocks[7];                                                         //creates an array of objects called rocks from class Obstacles
    Direction _d;                                                               //creates an object called _d from class Direction
    
    
    
    
    /** 
     * 
     * @brief Initialses the games parameters. Is also used to create a new room.
     * 
     */
    void initGame();
    
    
    
    /** 
     * 
     * @brief Reads all inputs of the game.
     * 
     */
    void readInput(Gamepad &pad);
    
    
    
    /** 
     * 
     * @brief Updates the game and all relevant function/variables.
     * 
     */
    void updateGame(N5110 &lcd, Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Draws the designated room and all inside it to the LCD.
     * 
     */
    void drawRender(N5110 &lcd, Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Checks to see if the player has collided with any monster.
     * 
     */
    void checkPlayerMonsterCollisions(Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Checks to see if any bullet has collided with any small 
     * alive monster.
     * 
     */
    void checkBulletMonsterCollisions(Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Checks to see if any bullet has collided with any big 
     * alive monster.
     * 
     */
    void checkBulletBigMonsterCollisions(Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Checks to see if the player has collided with any rocks.
     * 
     */
    void checkPlayerRocksCollision();
    
    
    
    /** 
     * 
     * @brief Checks to see if any small monsters have collided with any
     * of the rocks.
     * 
     */
    void checkMonsterRocksCollision();
    
    
    
    /** 
     * 
     * @brief Checks to see if any big monsters have collided with any
     * of the rocks.
     * 
     */
    void checkBigMonsterRocksCollision();
    
    
    
    /** 
     * 
     * @brief Checks to see if any bullets have collided with any of the
     * rocks.
     * 
     */
    void checkBulletRocksCollision();
    
    
    
    /** 
     * 
     * @brief Checks to see if a shot has been fired and starts the process to
     * create a bullet.
     *  
     */
    void checkForShot(Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Checks to see if all of the small monsters in the room have died.
     * 
     */
    void checkSmallDead();
    
    
    
    /** 
     * 
     * @brief Checks to see if all of the big monsters in the room have died.
     * 
     */
    void checkBigDead();
    
    
    
    /** 
     * 
     * @brief Checks to see if all monsters have been killed in current room.
     * 
     */
    void checkAllDead(Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Checks to see if the chest needs to be opened.
     * 
     */
    void checkChestOpen(Gamepad &gamepad);
    
    
    
    /**
     * 
     * @brief Checks to see if the heart has been picked up.
     * 
     */
    void checkHeartGot(Gamepad &gamepad);
    
    

    /** 
     * 
     * @brief Checks to see if the player is dead.
     *  
     */
    void checkForDead(N5110 &lcd, Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Commences the end of the game.
     *  
     */
    void gameOver(N5110 &lcd, Gamepad &gamepad);
    
    
    
    /** 
     * 
     * @brief Initialises each new object of bullet.
     *  
     */
    void initBull();
    
    
    
    /** 
     * 
     * @brief Sets the variable score to zero. Used at the start of a new game.
     *  
     */
    void startScore();
    
    
    
    /** 
     * 
     * @brief Sets the players health to 6. Used at the start of a new game.
     *  
     */
    void startPlayersHealth();
    
    

    /** 
     * 
     * @brief Adds 50 to the variable score. Used every time player enters a 
     * new room.
     *  
     */
    void plus_50_Score();
    
    
    
    /** 
     * 
     * @brief Removes a value of 1 from variable score. Used every time player
     * fires a shot.
     *  
     */
    void minus_1_Score();
    
    

    bool gameOverFlag;
    int score;
    int highscore;

    

    
    

    
    
    
    private:
    
    int numSmallMons;
    int numBigMons;
    int numRocks;
    int numBullets;
    int bulletDir1;
    int bulletFlag;
    float _mag;
    bool allBigDead;
    bool allSmallDead;
    
    
};

#endif