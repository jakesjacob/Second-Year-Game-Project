#ifndef TESTS_H
#define TESTS_H

#include "Player-tests.h"
#include "Monsters-tests.h"






/**
 * @brief Run all the tests for this program
 *
 * @returns The number of tests that failed
 */
int runAllTests() {
    
    int numTestsFailed = 0;
    
    bool test1Passed = playerGetPositionTest();                                 //bool value for test 1. Will be true if test is passed.
    
    bool test2Passed = playerHealthTest();                                      //bool value for test 2. Will be true if test is passed.
    
    bool test3Passed = monsterSmallPositionTest();                              //bool value for test 3. Will be true if test is passed.
    
    bool test4Passed = monsterBigPositionTest();                                //bool value for test 4. Will be true if test is passed.
    
    bool test5Passed = monsterSmallHealthTest();                                //bool value for test 5. Will be true if test is passed.
    
    bool test6Passed = monsterBigHealthTest();                                  //bool value for test 6. Will be true if test is passed.
    
    bool test7Passed = monsterSmallStatusTest();                                //bool value for test 7. Will be true if test is passed.
    
    bool test8Passed = monsterBigStatusTest();                                  //bool value for test 8. Will be true if test is passed.
    
    
    
    
    
    if (test1Passed) {                                                          
        printf ("Test 1 passed.\n");
    }
    else {
        printf ("Test 1 failed.\n");
        numTestsFailed ++;
    }
    
    if (test2Passed) {
        printf ("Test 2 passed.\n");
    }
    else {
        printf ("Test 2 failed.\n");
        numTestsFailed ++;
    }
    
    if (test3Passed) {
        printf ("Test 3 passed.\n");
    }
    else {
        numTestsFailed ++;
    }
    
    if (test4Passed) {
        printf ("Test 4 passed.\n");
    }
    else {
        printf ("Test 4 failed.\n");
        numTestsFailed ++;
    }
    
    if (test5Passed) {
        printf ("Test 5 passed.\n");
    }
    else {
        printf ("Test 5 failed.\n");
        numTestsFailed ++;
    }
    
    if (test6Passed) {
        printf ("Test 6 passed.\n");
    }
    else {
        printf ("Test 6 failed.\n");
        numTestsFailed ++;
    }
    
    if (test7Passed) {
        printf ("Test 7 passed.\n");
    }
    else {
        printf ("Test 7 failed.\n");
        numTestsFailed ++;
    }
    
    if (test8Passed) {
        printf ("Test 8 passed.\n");
    }
    else {
        printf ("Test 8 failed.\n");
        numTestsFailed ++;
    }
    

    
    
    
    
    
    
    
    
    if (numTestsFailed > 0) {                                                   //checks if any of the tests have failed
        printf("%d tests FAILED!\n", numTestsFailed);
    }
    else {
        printf("All tests passed!\n");
    }

    return numTestsFailed;                                                      //returns how many test have failed.
}
    
    
    
    

#endif
    
    
    
    
