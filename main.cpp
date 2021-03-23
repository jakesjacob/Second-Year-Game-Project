/*
ELEC2645 Embedded Systems Project
School of Electronic & Electrical Engineering
University of Leeds
Name: Jacob Horgan
Username: el16jh
Student ID Number: 201061845
Date: 28/02/18
*/



/*
This game is called Pixel Panic and the aim of the game is to kill all of the 
monsters in as many rooms as possible. The door to the next room will only open
once all of the monsters in the current room have been killed.

Small monsters take 2 hits and big monsters take 4 hits. Bullets are unlimited,
however the scoring system is based on how many shots are fired so use them
sparingly for higher scores. 50 points is added for every room cleared, but 1 
point is removed for every shot fired.

The player starts with 6 lives and loses a life every time they are touched by a
monster so do your best to dodge them! Extra lives can be gained by opening the
chests found in some of the rooms. This can be done by placing the player on top
of the chest and pressing the action button (X). A heart will appear that the
player can pick up. The LEDS on the gamepad correspond to the players lives.

There are 6 different possible combinations of monsters that are chosen at
random for each room. The monsters spawn points are also chosen at random. 
In each room there can also be a possible number of rocks between amount 2 and 
7, all can also be in a random X Y coordinate. This leads to a very very high 
number of possible room setups for the game, making the user feel that they are 
travelling through the rooms. Giving it a good level of re-playibility.
*/







// Libraries and modules

#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"
#include "Room.h"
#include "Player.h"
#include "GEngine.h"
#include <ctime>

#ifdef WITH_TESTING
# include "tests.h"
#endif



// Class objects

N5110 lcd(PTC9,PTC0,PTC7,PTD2,PTD1,PTC11);                                      //creating an object of class N5110 called lcd
Game game;                                                                      //creating an object of class Game called game
Gamepad gamepad;                                                                //creating an object of class Gamepad called gamepad





// Function prototypes

void init();
void startUp();
void mainMenu();
void newGame();
void instructions();
void highScores();




// CODE START


int main() {                                                    
    
    printf("Device on.\n");
    
    init();                                                                     //calls the init() function first                                                               
    startUp();                                                                  //calls the startUp() function afterwards
    mainMenu();                                                                 //then enters the main menu when mainMenu() is called by pressing start
}





                                                                                //NAME: init 
                                                                                //INFO: Function to initialize the parameters 
void init() {
    
    // Test message 
    //printf("init function initiated.\n");

    lcd.init();                                                                 //initialses all the parameters of the object lcd (the screen)
    gamepad.init();                                                             //initialses all the parameters of the object gamepad (the game controller itself)
    lcd.setContrast(0.6);                                                       //sets the screens contrast to 0.6
    game.highscore = 0;
}
// End 





                                                                                //NAME: startUp 
                                                                                //INFO: Function to display a start screen 
void startUp() {
    
    // Test message 
    //printf("startUp function initiated.\n"); 

    lcd.printString("-PIXEL PANIC-   ",3,1);                                    //displays the name of the game and also the message to press start button
    lcd.printString(" Press Start ",3,3);
    lcd.printString("   To Play ",3,4);
    lcd.refresh();
    gamepad.tone(1500.0,0.1);
    gamepad.tone(3500.0,0.5);
    gamepad.tone(5500.0,1);

    while ( gamepad.check_event(Gamepad::START_PRESSED) == false) {             //loops in this until the start button is pressed. when pressed, breaks out of loop and function
        
    }
    //gamepad.tone(1500.0,0.3);
}
// End 





                                                                                //NAME: mainMenu 
                                                                                //INFO: Function to display the main menu 
void mainMenu() {
    
    // Test message 
    //printf("mainMenu function initiated.\n");

    gamepad.reset_event();                                                      //resets the button event flags

    lcd.clear();                                                                //clears the screen of previos images
    lcd.printString("  Main Menu    ",3,0);                                     //prints the main menu title and choices
    lcd.printString("X-New Game     ",0,2);
    lcd.printString("Y-Instructions ",0,3);
    lcd.printString("B-High Score   ",0,4);
    lcd.drawLine(14,9,69,9,FILL_BLACK);                                         //draw an underline for the title
    lcd.refresh();                                                              //refreshes the new graphics to screen



    while(1) {

        if(gamepad.check_event(gamepad.X_PRESSED)) {                            //checks to see if X has been pressed
            
            // Test message 
            //printf("X button pressed.\n");

            gamepad.tone(1500.0,0.3);
            lcd.clear();                                                        //clears the screen
            lcd.refresh();                                                      //refreshes the screen
            newGame();                                                          //runs the newGame function
            break;                                                              //breaks out of the while loop
        }

        else if(gamepad.check_event(Gamepad::Y_PRESSED)) {                      //checks to see if Y has been pressed
            
            // Test message 
            //printf("Y button pressed.\n");

            gamepad.tone(1500.0,0.3);
            lcd.clear();                                                        //clears the screen
            lcd.refresh();                                                      //refreshes the screen
            instructions();                                                     //runs the instructions function
            break;                                                              //breaks out of the while loop
        }

        else if(gamepad.check_event(Gamepad::B_PRESSED)) {                      //checks to see if B has been pressed
            
            // Test message 
            //printf("B button pressed.\n");

            gamepad.tone(1500.0,0.3);
            lcd.clear();                                                        //clears the screen
            lcd.refresh();                                                      //refreshes the screen
            highScores();                                                       //runs the high score function
            break;                                                              //breaks out of the while loop
        }

        //wait(0.25);

    }
}
// End 







                                                                                //NAME: newGame
                                                                                //INFO: Function to run a new playthrough of the main game
void newGame() {
    
    // Test message 
    //printf("newGame function initiated.\n");

    gamepad.reset_event();                                                      //resets the button flags
    game.initGame();                                                            //initalises the parameters for the game to be played
    game.startPlayersHealth();                                                  //starts the players health at 6
    game.startScore();                                                          //starts the score at 0
    srand(time(NULL));                                                          //starts the random sequences from the moment in time that this function is called
    
    
    
#ifdef WITH_TESTING
    int numberOfFailures = runAllTests();
    
    //if(numberOfFailures > 0) return numberOfFailures;
#endif                



    
    while(!game.gameOverFlag) {                                                 //loops through these game functions as long as the gameOver is false

        lcd.clear();                                                            //clears the screen
        
        game.readInput(gamepad);                                                //function that reads all of the games inputs
        game.updateGame(lcd, gamepad);                                          //function that updates all of the aspects of the game (collisions, movement etc.)
        game.drawRender(lcd, gamepad);                                          //function that draws all the new aspects of the game (rooms, monsters, rocks etc.)
        
        lcd.refresh();                                                          //refreshes the screen

        wait(0.05);                                                             //reduces the frame rate slightly

    }
    mainMenu();                                                                 //goes back to the main menu once game is over
}
// End 







                                                                                //NAME: instructions
                                                                                //INFO: Function to display the instructions for the game
void instructions() {
    
    // Test message 
    //printf("instructions function initiated.\n");
    
    gamepad.reset_event();                                                      //resets the button flags
    lcd.clear();                                                                //clears the screen
    lcd.printString("INSTURCTIONS: ",3,0);                                      //prints the instruction text
    lcd.printString("Survive in the",0,2);
    lcd.printString("dungeon if you",0,3);
    lcd.printString("can. Beware of",0,4);
    lcd.printString("monsters.. (A)",0,5);
    lcd.refresh();                                                              //refreshes the screen

    while(1) {

        if(gamepad.check_event(Gamepad::A_PRESSED)) {                           //loops on screen above until A is pressed
            
            // Test message
            //printf("A button pressed.\n");

            gamepad.tone(1500.0,0.3);                                           //makes sound on button press
            lcd.clear();                                                        //clears screen
            lcd.printString("Search for the",0,1);                              //prints the instruction text
            lcd.printString("chests and use",0,2);
            lcd.printString("less bullets  ",0,3);
            lcd.printString("for a higher  ",0,4);
            lcd.printString("score..    (A)",0,5);
            lcd.refresh();                                                      //refreshes the screen
            gamepad.reset_event();                                              //resets the button flags
            break;                                                              //breaks out of the while loop
        }
    }
    
    while(1) {

        if(gamepad.check_event(Gamepad::A_PRESSED)) {                           //loops on screen above until A is pressed
            
            // Test message
            //printf("A button pressed.\n");

            gamepad.tone(1500.0,0.3);                                           //makes sound on button press
            lcd.clear();                                                        //clears screen
            lcd.printString("A  = Shoot    ",0,1);                              //prints the instruction text
            lcd.printString("X  = Action   ",0,2);
            lcd.printString("LR = Rotate   ",0,3);
            lcd.printString("JS = Movement ",0,4);
            lcd.printString("           (A)",0,5);
            lcd.refresh();                                                      //refreshes the screen
            gamepad.reset_event();                                              //resets the button flags
            break;                                                              //breaks out of the while loop
        }
    }
    
    while(1) {
        
        if(gamepad.check_event(Gamepad::A_PRESSED)) {                           //loops on screen above until A is pressed
            
            // Test message 
            //printf("B button pressed.\n");

            gamepad.tone(1500.0,0.3);
            mainMenu();                                                         //goes back to main menu after last instrcution screen
            break;                                                              //breaks out of the while loop
        }
    }
}
// End 






                                                                                //NAME: highScores
                                                                                //INFO: Function to display the high scores of the game
void highScores() {
    
    // Test message 
    //printf("highScores function initiated.\n");
    
    gamepad.reset_event();
    
    if (game.score > game.highscore) {
        game.highscore = game.score;
    }
    
    lcd.printString("  HIGH SCORE ",0,0);
    char buffer[14];                                                            //max screen witdth is 14
    sprintf(buffer,"HighScore= %d",game.highscore);                             //print message to buffer
    lcd.printString(buffer,0,3);                                                //print to screen (x pixel, line number)
    lcd.printString("           (A)",0,5);
    lcd.refresh();                                                              //refreshes the screen with these new images
    
    while(1) {

        if(gamepad.check_event(Gamepad::A_PRESSED)) {                           //loops on screen above until A is pressed
        
        gamepad.tone(1500.0,0.3);
        lcd.clear();
        lcd.refresh();
        //gamepad.reset_event();
        break;
        }
    }
    mainMenu();
}
// End 
















