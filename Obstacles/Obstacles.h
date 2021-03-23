#ifndef Obstacles_H
#define Obstacles_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"


/** My Obstacles Class
* @brief This class is responsible for all of the information regarding the different obstacles of the game
* @author Jacob M Horgan
* @date May, 2018
**/






class Obstacles {
    
    public:
    
    /** Constructor */
    Obstacles();
    
    /** Destructor */
    ~Obstacles();
    
    
    
    
    
    
    /** 
     * 
     * @brief  Function that initialses the position of the rock.
     * 
     */
    void initRock();
    
    
    
    /** 
     * 
     * @brief  Function that draws the rock to the LCD.
     * 
     */
    void drawRock(N5110 &lcd);
    
    
    
    /** 
     * 
     * @brief  Function to return the X Y coordinates of the rock.
     * 
     * @return Returns the X Y coordinates of the rock.
     */
    Vector2D get_rockPos();
    
    
    
    private:
    
    int rockPosX;
    int rockPosY;
    
    
};

#endif