/** My Game Engine Class
* @brief This class is responsible for most of the main functions of the game, it is very useful for integrating different objects of different classes with each other.
* @author Jacob M Horgan
* @date March, 2018
**/


#include "GEngine.h"
#include <ctime>




// nothing doing in the constructor and destructor
Game::Game()
{
   
}

Game::~Game()
{

}






    


    
const int gameOverSprite[8][42] =   {                                           // Sprite to display the image of GAME OVER 

    { 1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1 },        
    { 1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1 },
    { 1,0,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,0,1,1,1,1 },
    { 1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,0 },
    { 1,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    };
    
    




                                                                                //NAME: initGame
                                                                                //INFO: Functon to intiailize parameters special to the start of a new game
void Game::initGame() {
    
    // Test message 
    //printf("initGame function initiated.\n");
    
    clock_t start1 = std::clock();                                              //starts the clock timer

    player.initPlayer();                                                        //initialises the parameters of the object player
    room.initRoom();                                                            //initialises the parameters of the object room
    numRocks = room.rocksIn();                                                  //sets the variable numRocks = to how many rocks are in that particular room
    numSmallMons = room.getNumSmallMons();                                      //sets the variable numSmallMons = to how many small monsters are in that particular room
    numBigMons = room.getNumBigMons();                                          //sets the variable numBigMons = to how many big monsters are in that particular room
    
    bulletFlag = -1;                                                            //sets the bulletFLag variable to minus 1 at the start, -1 because of the way that entering arrays work
    numBullets = 0;                                                             //sets the variable numBullets to 0 at the start of every room
    gameOverFlag = false;                                                       //sets the gameoverflag to false at the start of the game
    allSmallDead = false;                                                       //sets the allsmalldead to false at the start of each room
    allBigDead = false;                                                         //sets the allbigdead to false at the start of each room

    for(int i=0;i<numSmallMons;i++) {                                           //loops through every object of small mosnsters
        monsters[i].initMonsterSmall();                                         //initialses all parameters of the monster
    }
    for(int i=0;i<numBigMons;i++) {                                             //loops through every object of big mosnsters
        monstersBig[i].initMonsterBig();                                        //initialses all parameters of the monster
    }
    for(int i=0;i<numRocks;i++) {                                               //loops through every object of rocks
        rocks[i].initRock();                                                    //initialses all parameters of the rock
    }
    
    clock_t stop1 = std::clock();                                               //ends the clock timer
    float duration1 = (stop1 - start1)/CLOCKS_PER_SEC;                          //math to determine the time passed
    //printf ("Duration of initGame = %f s\n", duration1);                      //prints how long this function took
    
}   
// End








                                                                                //NAME: readInput
                                                                                //INFO: Function to read the inputs of the gamepad (joystick etc.)
void Game::readInput(Gamepad &gamepad) {
    
    // Test message 
    //printf("readInput function initiated.\n");
    
    _d = gamepad.get_direction();                                               //sets _d as the direction valuer of the joystick
    _mag = gamepad.get_mag();                                                   //sets _mag as the magnitude value of the joystick
    player.checkRotation(gamepad);                                              //checks to see if player has been asked to rotate
    checkForShot(gamepad);                                                      //checks to see if a shot has been fired
    
}
// End







                                                                                //NAME: updateGame
                                                                                //INFO: Function to update all aspects of the game, positions, health etc.
void Game::updateGame(N5110 &lcd, Gamepad &gamepad) {
    
    // Test message
    //printf("updateGame function initiated.\n");
    
    player.updatePlayer(_d,_mag);                                               //updates the players position. sends across arguments _d and _mag, whcih are determined in 'read input'
    checkPlayerMonsterCollisions(gamepad);                                      //checks to see if any collisions with player and monsters
    checkBulletMonsterCollisions(gamepad);                                      //checks to see if any collisions with bullets and monsters
    checkBulletBigMonsterCollisions(gamepad);                                   //checks to see if any collisions with bullets and big monsters
    checkChestOpen(gamepad);                                                    //checks to see if chest is being opened
    checkHeartGot(gamepad);                                                     //checks to see if the heart has been picked up by player
    checkPlayerRocksCollision();                                                //checks to see if the player has collided with any of the rocks
    checkMonsterRocksCollision();                                               //checks to see if any of the small monsters have collided with any of the rocks
    checkBigMonsterRocksCollision();                                            //checks to see if any of the big monsters have collided with any of the rocks
    checkBulletRocksCollision();                                                //checks to see if any of the bullets have collided with any of the rocks
    Vector2D player_pos_mons = player.get_playerPos();                          //gets player xy coords


    for(int i=0;i<numBullets;i++) {
        bullets[i].moveBullet();                                                //updates position of every object of bullets from class Bullets
    }
    
    
    for(int i=0;i<numSmallMons;i++) {                                           //*****SMALL MONSTER UPDATES****
        monsters[i].monsterMoveSmall();                                         //updates the current iterations monsters movement
        monsters[i].monsterHealthCheck();                                       //checks the current iterations monsters health
    }
    checkSmallDead();                                                           //checks to see if all of the small monsters in the room are dead
    
    
    for(int i=0;i<numBigMons;i++) {                                             //*****BIG MONSTER UPDATES*****  
        monstersBig[i].monsterMoveBig(player_pos_mons);                         //updates the current iterations monsters movement
        monstersBig[i].monsterBigHealthCheck();                                 //checks the current iterations monsters health
    }
    checkBigDead();                                                             //checks to see if all of the big monsters in the room are dead
    
    
    player.playerHealth(gamepad);                                               //monitors the players health
    checkForDead(lcd, gamepad);                                                 //checks if the player is dead
    checkAllDead(gamepad);                                                      //checks if all the monsters are dead
    
}
// End




                                                                                //NAME: drawRender
                                                                                //INFO: Function to draw the game
void Game::drawRender(N5110 &lcd, Gamepad &gamepad) {
    
    // Test message 
    //printf("drawRoom function initiated.\n");
    
    room.drawRoom(lcd);                                                         //draws the current room
    player.drawPlayer(lcd);                                                     //draws the player at its current position
    room.drawHeart(lcd);
    
    for(int i=0;i<numSmallMons;i++) {       
        monsters[i].drawMonsterSmall(lcd);                                      //draws every object of monsters from class Monsters (small monsters)
    }
    for(int i=0;i<numBigMons;i++) {
        monstersBig[i].drawMonsterBig(lcd);                                     //draws every object of the big monsters from class Monsters
    }
    for(int i=0;i<numBullets;i++) {
        bullets[i].drawBullet(lcd);                                             //draws every object of bullets from class Bullets
    }
    for(int i=0;i<numRocks;i++) {
            rocks[i].drawRock(lcd);                                             //draws every object of rocks from class Obstacles
    }
}
// End








                                                                                //NAME: checkPlayerMonsterCollisions
                                                                                //INFO: Function to check if the player has collided with a monster
void Game::checkPlayerMonsterCollisions(Gamepad &gamepad) {
    
    // Test message 
    //printf("checkPlayerMonsterCollisions function initiated.\n");
                                                                                //****SMALL MONSTER CHECK****
    Vector2D player_pos = player.get_playerPos();                               //gets the players current x,y coord directly from the class
    
    for(int i=0;i<numSmallMons;i++) {                                           //loops through every object of the small monsters
    Vector2D monster_pos = monsters[i].get_monsterPos();                        //gets the current monsters position relevant to which iteration of the for loop
    
    if (!monsters[i].getSmallMonsterStatus()){                                  //only does the next part of code if current monster is alive

    if (
        (player_pos.x <= monster_pos.x + 7) &&                                  //checks to see if the player and monster have collided
        (player_pos.x + 4 >= monster_pos.x) && 
        (player_pos.y <= monster_pos.y + 5) && 
        (player_pos.y + 2 >= monster_pos.y)  
    ) 
    {
        gamepad.tone(1000.0,0.1);                                             //makes a sound
        player.playerPosX = player.playerPosX - 5;                              //pushes player back by 5 pixels
        monsters[i].monsterPosX = monsters[i].monsterPosX + 5;                  //pushes monster back by 5 pixels (stops constant damage done to player) 
        player.playerHit();                                                     //alters the players health
        //printf("player collided with small monster.\n");
    }
    }
    }
    
    
                                                                                //****BIG MONSTER CHECK****
    for(int i=0;i<numBigMons;i++) {                                             //loops through every object of the small monsters
    Vector2D monster_pos = monstersBig[i].get_monsterBigPos();                  //gets the current monsters position relevant to which iteration of the for loop
    
    if (!monstersBig[i].getBigMonsterStatus()) {                                //only does the next part of code if current monster is alive

    if (
        (player_pos.x <= monster_pos.x + 8) &&                                  //checks to see if the player and monster have collided
        (player_pos.x + 4 >= monster_pos.x) &&
        (player_pos.y <= monster_pos.y + 9) && 
        (player_pos.y + 2 >= monster_pos.y)
    ) 
    {
        gamepad.tone(1000.0,0.1);                                             //makes a sound
        player.playerPosX = player.playerPosX - 5;                              //pushes player back by 5 pixels
        monstersBig[i].monsterBigPosX = monstersBig[i].monsterBigPosX + 5;      //pushes monster back by 5 pixels (stops constant damage done to player) 
        player.playerHit();                                                     //alters the players health
        //printf("player collided with big monster.\n");
    }
    }
    }
}
// End




                                                                                //NAME: checkBulletMonsterCollisions
                                                                                //INFO: Function to check if a bullet has collided with a small monster
void Game::checkBulletMonsterCollisions(Gamepad &gamepad) {
    
    // Test message 
    //printf("checkBulletMonsterCollisions function initiated.\n");
    
    for(int j=numBullets;j>=0;j--) {                                            //loops through every object of the bullets
    Vector2D bullet_pos = bullets[j].get_bulletPos();                           //gets the current bullets position relevant to which iteration of the for loop
    
    for(int i=0;i<numSmallMons;i++) {                                           //loops through every object of the small monsters
    Vector2D monster_pos = monsters[i].get_monsterPos();                        //gets the current monsters position relevant to which iteration of the for loop
    
    
    if (!monsters[i].getSmallMonsterStatus() && bullets[j].getBulletStatus()){  //only does the next part of code if current monster is alive &&&&& the current bullet exists

    if (
        (bullet_pos.x <= monster_pos.x + 7) &&                                  //checks to see if the bullet and monster have collided
        (bullet_pos.x >= monster_pos.x) && 
        (bullet_pos.y <= monster_pos.y + 5) && 
        (bullet_pos.y >= monster_pos.y)  
    ) 
    {
        gamepad.tone(1000.0,0.1);
        bullets[j].bulletGone();                                                //runs function to remove the bullet from game
        monsters[i].monsterSmallHit();                                          //runs the function of a monster taking damage
        //printf("small mons health = %d.\n",monsters[i].mHealth);
        //printf("small hit.\n");
    }
    }
    }
    }
}   
// End    
    


                                                                                //NAME: checkBulletBigMonsterCollisions
                                                                                //INFO: Function to check if a bullet has collided with a big monster
void Game::checkBulletBigMonsterCollisions(Gamepad &gamepad) {   

    for(int j=numBullets;j>=0;j--) {                                            //loops through every object of the bullets
    Vector2D bullet_pos2 = bullets[j].get_bulletPos();                          //gets the current bullets position relevant to which iteration of the for loop
    
    for(int i=0;i<numBigMons;i++) {                                             //loops through every object of the small monsters
    Vector2D monsterBig_pos = monstersBig[i].get_monsterBigPos();               //gets the current monsters position relevant to which iteration of the for loop
    
    if ((!monstersBig[i].getBigMonsterStatus()) && 
        (bullets[j].getBulletStatus())) {                                       //only does the next part of code if current monster is alive &&&&& the current bullet exists
    

    if (
        (bullet_pos2.x <= monsterBig_pos.x + 8) &&                              //checks to see if the bullet and monster have collided
        (bullet_pos2.x >= monsterBig_pos.x) &&
        (bullet_pos2.y <= monsterBig_pos.y + 9) &&
        (bullet_pos2.y >= monsterBig_pos.y)  
    ) 
    {
        gamepad.tone(1000.0,0.1);
        bullets[j].bulletGone();                                                //runs function to remove the bullet from game
        monstersBig[i].monsterBigHit();                                         //runs the function of a monster taking damage
        //printf("big mons health = %d.\n",monstersBig[i].mBigHealth);
        //printf("big hit.\n");
    }
    }
    }
    }
}
// End





                                                                                //NAME: checkPlayerRockCollision
                                                                                //INFO: Function to check if the player has collided with a rock
void Game::checkPlayerRocksCollision() {
    
    Vector2D player_pos = player.get_playerPos();                               //gets players xy coords
    
    for(int i=0;i<numRocks;i++) {                                               //loops through every object of rocks
        Vector2D rock_pos = rocks[i].get_rockPos();                             //gets each rocks coords on each iteration of loop
        
        if (
        (player_pos.x <= rock_pos.x + 8) &&                                     //checks to see if the player and monster have collided
        (player_pos.x + 4 >= rock_pos.x) && 
        (player_pos.y <= rock_pos.y + 9) && 
        (player_pos.y >= rock_pos.y)  
        )
        {
            player.playerPosX = player_pos.x;                                   //sets the players xy coords back to what they were before collision
            player.playerPosY = player_pos.y;
                
            if ((player_pos.y <= rock_pos.y + 2) &&                             //sets the player higher if colliding from the top (needed because of sprite sizes) (stops player travelling through rock)
                (player_pos.y >= rock_pos.y -9)) {
                    
                    player.playerPosY = player_pos.y - 8;
            }
        }
    }
}        
// End




                                                                                //NAME: checkMonsterRockCollision
                                                                                //INFO: Function to check if any of the small monsters have collided with a rock
void Game::checkMonsterRocksCollision() {
    
    for(int j=0;j<numSmallMons;j++) {                                           //loops through every object of the small monsters
    Vector2D monster_pos = monsters[j].get_monsterPos();                        //gets the current monsters position relevant to which iteration of the for loop 
    
    for(int i=0;i<numRocks;i++) {                                               //loops through every object of rocks
        Vector2D rock_pos = rocks[i].get_rockPos();                             //gets the current rocks position relevant to which iteration of the for loop 
        
        if (
        (monster_pos.x <= rock_pos.x + 8) &&                                    //checks to see if the monster and monster have collided
        (monster_pos.x + 4 >= rock_pos.x) && 
        (monster_pos.y <= rock_pos.y + 9) && 
        (monster_pos.y >= rock_pos.y)  
        )
        {
            monsters[j].monsterPosX = monster_pos.x;                            //sets the monsters xy coords back to what they were before collision
            monsters[j].monsterPosY = monster_pos.y;
                
            if ((monster_pos.y <= rock_pos.y + 2) &&                            //sets the monster higher if colliding from the top (needed because of sprite sizes) (stops monster travelling through rock)
                (monster_pos.y >= rock_pos.y -9)) {
                    
                    monsters[j].monsterPosY = monster_pos.y - 8;
            }
        }
    }
    }
}        
// End



                                                                                //NAME: checkBigMonsterRockCollision
                                                                                //INFO: Function to check if any of the big monsters have collided with a rock
void Game::checkBigMonsterRocksCollision() {
    
    for(int j=0;j<numBigMons;j++) {                                             //loops through every object of the big monsters
    Vector2D monster_pos = monstersBig[j].get_monsterBigPos();                  //gets the current monsters position relevant to which iteration of the for loop 
    
    for(int i=0;i<numRocks;i++) {                                               //loops through every object of rocks
        Vector2D rock_pos = rocks[i].get_rockPos();                             //gets the current rocks position relevant to which iteration of the for loop 
        
        if (
        (monster_pos.x <= rock_pos.x + 9) &&                                    //checks to see if the player and monster have collided
        (monster_pos.x + 9 >= rock_pos.x) &&
        (monster_pos.y <= rock_pos.y + 9) && 
        (monster_pos.y >= rock_pos.y)
        )
        {
            monstersBig[j].monsterBigPosX = monster_pos.x;                      //sets the monsters xy coords back to what they were before collision
            monstersBig[j].monsterBigPosY = monster_pos.y;
            //printf("collision.\n");
                
            if ((monster_pos.x - 2 >= rock_pos.x + 6) &&                        //sets the monster higher if colliding from the top (needed because of sprite sizes) (stops monster travelling through rock)
                (monster_pos.x <= rock_pos.x +18)) {
                    
                    monstersBig[j].monsterBigPosX = monster_pos.x + 6;
                    //printf("collision.\n");
            }

        }
    }
    }
}        
// End





                                                                                //NAME: checkBulletRockCollision
                                                                                //INFO: Function to check if any of the bullets have collided with a rock
void Game::checkBulletRocksCollision() {
    
    for(int j=numBullets;j>=0;j--) {                                            //loops through every object of the bullets
    Vector2D bullet_pos2 = bullets[j].get_bulletPos();                          //gets the current bullets position relevant to which iteration of the for loopvant to which iteration of the for loop 
    
    for(int i=0;i<numRocks;i++) {                                               //loops through every object of rocks
        Vector2D rock_pos = rocks[i].get_rockPos();                             //gets the current rocks position relevant to which iteration of the for loop 
        
        if (
        (bullet_pos2.x <= rock_pos.x + 8) &&                                    //checks to see if the player and monster have collided
        (bullet_pos2.x + 4 >= rock_pos.x) && 
        (bullet_pos2.y <= rock_pos.y + 9) && 
        (bullet_pos2.y >= rock_pos.y) 
        )
        {
            bullets[j].bulletGone();                                            //calls the function that makes the bullet not exist
            //printf("bullet hit rock.\n");
        }
    }
    }
}        
// End






    
                                                                                //NAME: checkForShot
                                                                                //INFO: Function to detyermine if a shot has been fired and create a bullet for it 
void Game::checkForShot(Gamepad &gamepad){
    
    if(gamepad.check_event(Gamepad::A_PRESSED)) {                               //checks to see if the button A has been presses
        numBullets ++;                                                          //adds another 1 to the numBullets variable, used in the for loops of the bullets
        initBull();                                                             //runs the initBull frunction if a shot has been fired
        //printf("num_bullets = %d.\n", numBullets);
        //printf("shot fired.\n");
    }
}   
// End





                                                                                //NAME: checkSmallDead
                                                                                //INFO: Function to run the code that checks if all small monsters in room are dead
void Game::checkSmallDead() {
    
    for (int i=0;i<numSmallMons;i++) {                                          //loops through every small monster (depends on varaible numSmallMons)
        
        if (numSmallMons == 2) {                                                //if room starts with 2 small monsters, this checks to see if all are dead.
            if (monsters[i].getSmallMonsterStatus() && monsters[i+1].getSmallMonsterStatus()){
                allSmallDead = true;
            }
        }
        if (numSmallMons == 3) {                                                //if room starts with 3 small monsters, this checks to see if all are dead.
            if (monsters[i].getSmallMonsterStatus() && monsters[i+1].getSmallMonsterStatus() && monsters[i+2].getSmallMonsterStatus()){
                allSmallDead = true;
            }
        }
        if (numSmallMons == 4) {                                                //if room starts with 4 small monsters, this checks to see if all are dead.
            if (monsters[i].getSmallMonsterStatus() && monsters[i+1].getSmallMonsterStatus() && monsters[i+2].getSmallMonsterStatus() && monsters[i+3].getSmallMonsterStatus()){
                allSmallDead = true;
            }
        }
        if (numSmallMons == 5) {                                                //if room starts with 5 small monsters, this checks to see if all are dead.
            if (monsters[i].getSmallMonsterStatus() && monsters[i+1].getSmallMonsterStatus() && monsters[i+2].getSmallMonsterStatus() && monsters[i+3].getSmallMonsterStatus() && monsters[i+4].getSmallMonsterStatus()){
                allSmallDead = true;
            }
        }
        if (numSmallMons == 6) {                                                //if room starts with 6 small monsters, this checks to see if all are dead.
            if (monsters[i].getSmallMonsterStatus() && monsters[i+1].getSmallMonsterStatus() && monsters[i+2].getSmallMonsterStatus() && monsters[i+3].getSmallMonsterStatus() && monsters[i+4].getSmallMonsterStatus() && monsters[i+5].getSmallMonsterStatus()){
                allSmallDead = true;
            }
        }
        if (numSmallMons == 7) {                                                //if room starts with 7 small monsters, this checks to see if all are dead.
            if (monsters[i].getSmallMonsterStatus() && monsters[i+1].getSmallMonsterStatus() && monsters[i+2].getSmallMonsterStatus() && monsters[i+3].getSmallMonsterStatus() && monsters[i+4].getSmallMonsterStatus() && monsters[i+5].getSmallMonsterStatus() && monsters[i+6].getSmallMonsterStatus()){
                allSmallDead = true;
            }
        }
    }
}
// End






                                                                                //NAME: checkBigDead
                                                                                //INFO: Function to run the code that checks if all big monsters in room are dead
void Game::checkBigDead() {
    
    for (int i=0;i<numBigMons;i++) {                                            //loops through every big monster (depends on varaible numBigMons)
        
        if (numBigMons == 1) {                                                  //if room starts with 1 big monsters, this checks to see if all are dead.
            if (monstersBig[i].getBigMonsterStatus()){
                allBigDead = true;
            }
        }
        if (numBigMons == 2) {                                                  //if room starts with 2 big monsters, this checks to see if all are dead.
            if((monstersBig[i].getBigMonsterStatus()) && 
            (monstersBig[i+1].getBigMonsterStatus())){
                allBigDead = true;
            }
        }
    }
}
// End







                                                                                //NAME: checkAllDead
                                                                                //INFO: Function to determine if all monsters in the room have been killed
void Game::checkAllDead(Gamepad &gamepad) {
    
    Vector2D player_pos = player.get_playerPos();                               //gets the players xy coords and stores in a 2D vector
    
    if (numBigMons > 0 && allSmallDead == true && allBigDead == true){          //if small and big monsters both start in room and all of them are dead then run this:
            room.doorOpen();                                                    //runs the door open function in room
            
            if ((player_pos.y + 7 >= 20) &&                                     //checks to see if player has collided with area of the new open door
                (player_pos.y <= 30) && 
                (player_pos.x + 3 >= 81)) 
                {
                    plus_50_Score();                                            //adds 50 points the score variable if the player "enters a new room" by colliding with door
                    initGame();                                                 //inits the game again (a new room)
                    gamepad.tone(2000.0,0.5);
                    wait(0.5);
                    gamepad.tone(4000.0,0.5); 
            }   
    }
    
    if (numBigMons == 0){                                                       //if just small monsters start in the room and all dead ru7n this
        if (allSmallDead == true){
            room.doorOpen();                                                    //runs the door open function in room
            
            if ((player_pos.y + 7 >= 20) &&                                     //checks to see if player has collided with area of the new open door
                (player_pos.y <= 30) && //bottom
                (player_pos.x + 3 >= 81)) //left
                {
                    plus_50_Score();                                            //adds 50 points the score variable if the player "enters a new room" by colliding with door
                    initGame();                                                 //inits the game again (a new room) 
                    gamepad.tone(2000.0,0.5);
                    wait(0.5);
                    gamepad.tone(4000.0,0.5); 
            }   
        }
    }
}
// End






                                                                                //NAME: checkChestOpen
                                                                                //INFO: Function to check if the chest is to be opened
void Game::checkChestOpen(Gamepad &gamepad) {
    
    // Test message 
    //printf("checkChestOpen function initiated.\n");
    
    Vector2D player_pos = player.get_playerPos();                               //gets the players xy coords
    
    //gamepad.reset_event();
    
    if (!room.getChestStatus() && gamepad.check_event(gamepad.X_PRESSED)) {     //checks to see if X button has been pressed & that the chest is false (closed)
          while((player_pos.y >= 15) &&                                         //if X pressed whilst player is in this area then do code:
                (player_pos.y <= 35) && 
                (player_pos.x >= 32) &&
                (player_pos.x <= 43)
                )
                {
                    //printf("player in.\n");
                    gamepad.tone(3000.0,0.1);                                   //makes sound
                    room.chestOpen();                                           //calls the function that is responsible for opening the chest in the room class
                    room.heartStatusChange();                                   //swaps the status of the heart (in this case makes it appear)
                    break;                                                      //breaks out of the loop if this has happened
                }
                
        }
}
// End







                                                                                //NAME: checkheartGot
                                                                                //INFO: Function to check if the heart has been picked up
void Game::checkHeartGot(Gamepad &gamepad) {
    
    // Test message 
    //printf("checkChestOpen function initiated.\n");
    
    Vector2D player_pos = player.get_playerPos();                               //gets the players xy coords
    
    if (room.getHeartStatus()) {                                                //checks to see if X button has been pressed
          while((player_pos.y >= 7) &&                                          //if X pressed whilst player is in this area then do code:
                (player_pos.y <= 15) && 
                (player_pos.x >= 39) && 
                (player_pos.x <= 46)
                )
                {
                    //printf("player in.\n");
                    gamepad.tone(3000.0,0.1);                                   //makes sound
                    room.heartStatusChange();                                   //swaps the status of the heart (in this case makes it dissappear)
                    player.playerLife();                                        //calls the player function that adds 1 life
                    break;                                                      //breaks out of the loop if this has happened                                                      
                }
                
        }
}
// End

    


                                                                                //NAME: checkForDead
                                                                                //INFO: Function to check to see if the player has died 
void Game::checkForDead(N5110 &lcd, Gamepad &gamepad) {
    
    // Test message 
    //printf("checkForDead function initiated.\n");
    
    if (player.getPlayerStatus()) {                                             //checks to see if the player is alive or dead
        //gamepad.tone(3000.0,2);
        gameOver(lcd, gamepad);                                                 //runs the game over function
    }
}
// End








                                                                                //NAME: gameOver
                                                                                //INFO: Function to initiate the game over screen  and start the loop back to the main menu
void Game::gameOver(N5110 &lcd, Gamepad &gamepad) {
    
    // Test message 
    //printf("gameOver function initiated.\n");
    
    lcd.clear();                                                                //clear the screen of the game images
    gamepad.reset_event();                                                      //resets any unwanted button presses
    
    lcd.drawSprite(20,8,8,42,(int *)gameOverSprite);                            //display "game over" text on screen
    lcd.printString(" Press Back ",8,5);                                        //display the press back message 
        
    char buffer[14];                                                            //max screen witdth is 14
    sprintf(buffer," Score =%d",score);                                         //print message to buffer
    lcd.printString(buffer,8,3);                                                //print to screen (x pixel, line number)
    lcd.refresh();                                                              //refreshes the screen with these new images
    
    gamepad.tone(300.0,0.5);
    wait(0.5);
    gamepad.tone(150.0,0.5);
    wait(0.5);
    gamepad.tone(50.0,1);
    
    while (gamepad.check_event(Gamepad::BACK_PRESSED) == false){                //loops in this loop until back is pressed

    }
    
    gameOverFlag = true;                                                           //sets the game over flag so that it leaves the new game loop and gioes back to menu (in main file)
    
}
// End









                                                                                //NAME: initBull
                                                                                //INFO: Function to create a new bullet
void Game::initBull() {
    
    bulletFlag ++;                                                              //used as a pointer to the next value of the bullet object array
    
    bullets[bulletFlag].initBullet(player.get_playerPos(),player.getPlayerFacing());        //initalises a new bullet with player position and direction parameters
    minus_1_Score();                                                                        //removes value of 1 from the score every time a bullet is fired
    
}    
// End








 
                                                                                //NAME: startScore
                                                                                //INFO: Function used to set the score at 0 at the start of a new game. called from main
void Game::startScore() {
    score = 0;                                                                  //sets the variable score to 0
}
// End



                                                                                //NAME: startPlayersHealth
                                                                                //INFO: Function used to start the plasyers health at 6. called from main. calls a function from the player class.
void Game::startPlayersHealth() {
    player.startHealth();
}
// End



                                                                                //NAME: plus_50_Score
                                                                                //INFO: Function used to add a value of 50 to the variable score
void Game::plus_50_Score() {
    score = score + 50;
    //printf("50 added to score.\n");
}
// End



                                                                                //NAME: minus_1_Score
                                                                                //INFO: Function used to remove a value of 1 from variable score
void Game::minus_1_Score() {
    score = score - 1;
    if (score < 0) {
        score = 0;
    }
}
// End






