/** My Obstacles Class
* @brief This class is responsible for all of the information regarding the different obstacles of the game
* @author Jacob M Horgan
* @date May, 2018
**/


#include "Obstacles.h"




// nothing doing in the constructor and destructor
Obstacles::Obstacles()
{

}

Obstacles::~Obstacles()
{

}







const int bigRock[8][8] =   {                                                   //sprite to display the image of a rock
    { 0,0,1,1,1,1,0,0 },
    { 0,1,0,1,0,0,1,0 },
    { 1,0,0,0,0,0,0,1 },
    { 1,0,0,1,0,0,1,1 },
    { 1,1,0,0,0,0,0,1 },
    { 1,0,0,0,0,1,0,1 },
    { 0,1,0,0,1,0,1,0 },
    { 0,0,1,1,1,1,0,0 },

    };






                                                                                //NAME: initRock
                                                                                //INFO: Function to initiate the parameters of the rock
void Obstacles::initRock () {
    
    rockPosX = rand() % (73 - 10) + 10;                                         //sets the rocks X coord randomly between 10 and 73
    rockPosY = rand() % (37 - 3) + 3;                                           //sets the rocks Y coord randomly between 3 and 37
}                                                  
// End





                                                                                //NAME: drawRock
                                                                                //INFO: Function to draw the rock
void Obstacles::drawRock(N5110 &lcd) {
    
    lcd.drawSprite(rockPosX,rockPosY,8,8,(int *)bigRock);                       //draws the rock sprite onto the LCD
}
// End




                                                                                //NAME: get_rockPos
                                                                                //INFO: Function to create a 2D vector of the rocks position
Vector2D Obstacles::get_rockPos() {
    Vector2D rr = {rockPosX,rockPosY};
    return rr;
}
// End
    



