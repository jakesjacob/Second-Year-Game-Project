/** My Room Class
* @brief This class is responsible for all of the information regarding the different rooms of the game
* @author Jacob M Horgan
* @date March, 2018
**/


#include "Room.h"
#include <ctime>




// nothing doing in the constructor and destructor
Room::Room()
{

}

Room::~Room()
{

}









const int doorClosed[12][3] =   {                                               //Sprite of the door closed image
    { 1,1,1 },
    { 1,0,1 },
    { 1,0,1 },
    { 1,0,1 },
    { 1,0,1 },
    { 1,0,1 },
    { 1,0,1 },
    { 1,0,1 },
    { 1,0,1 },
    { 1,0,1 },
    { 1,0,1 },
    { 1,1,1 },
    };



const int doorO[12][3] =   {                                                    //Sprite of the door open image
    { 1,1,1 },
    { 0,0,0 },
    { 0,0,0 },
    { 0,0,0 },
    { 0,0,0 },
    { 0,0,0 },
    { 0,0,0 },
    { 0,0,0 },
    { 0,0,0 },
    { 0,0,0 },
    { 0,0,0 },
    { 1,1,1 },
    };



const int chest[8][9] =   {                                                     //Sprite to display the image of the chest closed 
    { 0,1,1,1,1,1,1,1,0 },
    { 1,0,0,0,0,0,0,0,1 },
    { 1,0,0,1,1,1,0,0,1 },
    { 1,1,1,1,1,1,1,1,1 },
    { 1,0,0,0,0,0,0,0,1 },
    { 1,0,1,0,0,0,1,0,1 },
    { 1,0,0,0,0,0,0,0,1 },
    { 1,1,1,1,1,1,1,1,1 },
    };
    

    
const int chestO[10][9] =   {                                                   //Sprite to display the image of the chest open 
    { 0,1,1,1,1,1,1,1,0 },
    { 1,0,0,0,0,0,0,0,1 },
    { 1,0,0,1,1,1,0,0,1 },
    { 1,1,1,1,1,1,1,1,1 },
    { 0,1,0,0,0,0,0,1,0 },
    { 1,1,1,1,1,1,1,1,1 },
    { 1,0,0,0,0,0,0,0,1 },
    { 1,0,1,0,0,0,1,0,1 },
    { 1,0,0,0,0,0,0,0,1 },
    { 1,1,1,1,1,1,1,1,1 },
    };



const int heart[7][7] =   {                                                     //Sprite to display the image of the heart
    { 0,1,1,0,1,1,0 },
    { 1,0,0,1,0,0,1 },
    { 1,0,0,0,0,0,1 },
    { 1,0,0,0,0,0,1 },
    { 0,1,0,0,0,1,0 },
    { 0,0,1,0,1,0,0 },
    { 0,0,0,1,0,0,0 },
    };






                                                                                //NAME: roomSelect
                                                                                //INFO: Function to randomly choose which room will be drawn next
void Room::initRoom() {
   
   roomDone = false;                                                            //sets the room done flag to false (means the room is still active)
   chestFlag = false;                                                           //sets the chestFlag to false (means its closed)
   heartThere = false;                                                          //sets the heartThere flaf to false (means the heart is not out of the chest yet)
   rocksThere = false;                                                          //sets the rocksthere flag to false (means the rocks will only be drawn in rooms that change this)
   amountRocks = 0;                                                             //sets the amount of rocks to zero, so it doesnt add up with every room iteration
   roomSelect();                                                                //calls the roomSelect function so that a random room will be chosen
}






                                                                                //NAME: roomSelect
                                                                                //INFO: Function to randomly choose which room will be drawn next
void Room::roomSelect() {
     
    // Test message 
    //printf("roomSelect function initiated.\n");
    
    int state = rand() % 6;                                                     //randomly chooses a value between 0 - 5 and this corresponds to which state the room select chooses
    
    switch(state) {
            case 0:
                selection = 1;
                numSmallMons = 2;                                               //sets the amount of small monsters in this room
                numBigMons = 2;                                                 //sets the amount of big monsters in this room
                break;
            case 1:
                selection = 2;
                numSmallMons = 3;                                               //sets the amount of small monsters in this room
                numBigMons = 2;                                                 //sets the amount of big monsters in this room
                rocksThere = true;                                              //sets the rocks there flag to true
                howManyRocks();                                                 //calls the function that determines how many rocks to draw
                break;
            case 2:
                selection = 3;
                numSmallMons = 4;                                               //sets the amount of small monsters in this room
                numBigMons = 1;                                                 //sets the amount of big monsters in this room
                break;
            case 3:
                selection = 4;
                numSmallMons = 5;                                               //sets the amount of small monsters in this room
                numBigMons = 0;                                                 //sets the amount of big monsters in this room
                rocksThere = true;                                              //sets the rocks there flag to true
                howManyRocks();                                                 //calls the function that determines how many rocks to draw
                break;
            case 4:
                selection = 5;
                numSmallMons = 6;                                               //sets the amount of small monsters in this room
                numBigMons = 0;                                                 //sets the amount of big monsters in this room
                rocksThere = true;                                              //sets the rocks there flag to true
                howManyRocks();                                                 //calls the function that determines how many rocks to draw
                break;
            case 5:
                selection = 6;
                numSmallMons = 7;                                               //sets the amount of small monsters in this room
                numBigMons = 0;                                                 //sets the amount of big monsters in this room
                rocksThere = true;                                              //sets the rocks there flag to true
                howManyRocks();                                                 //calls the function that determines how many rocks to draw
                break;
    }
    //printf("selection = %d.\n", selection);
}
// End





                                                                                //NAME: drawRoom
                                                                                //INFO: Function to draw one of the six possible rooms, randomly chosen
void Room::drawRoom(N5110 &lcd) {
    
    // Test message 
    //printf("drawRoom function initiated.\n");
    //printf("num dead = %d.\n", numDead);
    
    if (selection == 1){                                                        //draws a different set of functions depending on whcih room selection
        drawBasics(lcd);                                                        //draws the basic images of the room
        drawChest(lcd);
    }
    if (selection == 2){
        drawBasics(lcd);                                                        //draws the basic images of the room
        //drawChest(lcd);
    }
    if (selection == 3){
        drawBasics(lcd);                                                        //draws the basic images of the room
        drawChest(lcd);                                                         //draws the chest in the room
    }
    if (selection == 4){
        drawBasics(lcd);                                                        //draws the basic images of the room
        //drawChest(lcd);
    }
    if (selection == 5){
        drawBasics(lcd);                                                        //draws the basic images of the room
        //drawChest(lcd); 
    }
    if (selection == 6){
        drawBasics(lcd);                                                        //draws the basic images of the room
        //drawChest(lcd);                                                         //draws the chest in the room
    }
}
// End





                                                                                //NAME: drawChest
                                                                                //INFO: Function to draw the chest in the room, uses flag to decide if open or closed
void Room::drawChest(N5110 &lcd) {
    
    // Test message 
    //printf("drawChest function initiated.\n");
    
    if (chestFlag == true) {
        lcd.drawSprite(38,18,10,9,(int *)chestO);                               //drasws chest open if flag is true, flag is changed when player presses X at the same time as colliding with chest. GameEngine.
        lcd.refresh();
    }
    else {   
        lcd.drawSprite(38,20,8,9,(int *)chest);                                 //draws chest closed otherwise
        lcd.refresh();
    }
}
// End






                                                                                //NAME: drawBasics
                                                                                //INFO: Function to draw the basic images of each room
void Room::drawBasics(N5110 &lcd) {
    
        lcd.clear();
        lcd.drawRect(0,0,84,48,FILL_TRANSPARENT);                               //draws the walls of the game
        lcd.drawRect(2,2,80,44,FILL_TRANSPARENT);                               //draws the walls of the game
        lcd.drawLine(0,21,0,30,0);                                              //draws the walls of the game
        lcd.setPixel(1,20);                                                     //draws the walls of the game
        lcd.setPixel(1,31);                                                     //draws the walls of the game
        
        if (roomDone == false) {
            lcd.drawSprite(81,20,12,3,(int *)doorClosed);                       //keeps the door drawn closed whilst the room is still in use
        }
        else {
            lcd.drawSprite(81,20,12,3,(int *)doorO);                            //draws the door open if roomDone = true. This flag is changed when all monsters are killed and roomDone function is ran.
        }
        
        lcd.refresh();

}
// End





                                                                                //NAME: drawHeart
                                                                                //INFO: Function to draw the heart if it exists
void Room::drawHeart(N5110 &lcd) {
    
    if (heartThere == true) {
        lcd.drawSprite(39,7,7,7,(int *)heart);                                  //draws the heart above the chest if the flag = true. this flag is changed when the chest is opened. GameEngine.
    }
}
// End





                                                                                //NAME: howManyRocks
                                                                                //INFO: Function to randomly determine how many rocks will be in a room
void Room::howManyRocks(){
    
    if (rocksThere == true) {
        amountRocks = rand() % (7 -2) + 2;                                      //sets the variable amountRocks to a random number between 2 - 7. Only if rocksThere = true. this is set in room selction
        
        //printf("numbver of rocks = %d\n",amountRocks);
    }
}
// End   





                                                                                //NAME: rocksIn
                                                                                //INFO: Function to return the variable amountRocks
int Room::rocksIn() {
    return amountRocks;                                                         // returns the value of amountRocks
}
// End





                                                                                //NAME: doorOpen
                                                                                //INFO: Function to change the value of roomDone
void Room::doorOpen() {
    roomDone = true;                                                            //sets roomDone = true. called from game engine when all monsters in a room are dead
    //printf("door open.\n");
}
// End




                                                                                //NAME: chestOpen
                                                                                //INFO: Function to set chestFlag to true
void Room::chestOpen() {
    chestFlag = true;
}




                                                                                //NAME: heartStatusChange
                                                                                //INFO: Function to change the status of heartThere
void Room::heartStatusChange() {
    heartThere = !heartThere;
}




                                                                                //NAME: getChestStatus
                                                                                //INFO: Function to return the status of chestFlag
int Room::getChestStatus() {
    return chestFlag;
}




                                                                                //NAME: getHeartStatus
                                                                                //INFO: Function to return the status of heartThere
int Room::getHeartStatus() {
    return heartThere;
}




                                                                                //NAME: getNumSmallMons
                                                                                //INFO: Function to return the number of small monsters
int Room::getNumSmallMons() {
    return numSmallMons;
}




                                                                                //NAME: getNumBigMons
                                                                                //INFO: Function to return the number of big monsters
int Room::getNumBigMons() {
    return numBigMons;
}
