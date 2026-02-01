#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <limits>

//TODO: Create a function named isValidMove(). It needs to have boolean return type
//      and it needs to take two parameters: int userMove and int stones.
//      This function is to determine if the move is valid or not. If the user move
//      is less than 1, greater than 3, or if their move is greater than the number
//      of available stones, then return false. Else return true.

bool isValidMove(int userMove, int stones) {
    if (userMove < 1 || userMove > 3 || userMove > stones) {
        return false;
    }
    else {
        return true;
    }
}

//TODO: Create a function named getUserMove(). It needs to have a int return type and
//      it needs to take one parameter: int stones.
//      The purpose of the function is to get the users move. You will need to
//      do the following steps in the function:
//      1) create a a loop that will only break when a valid move is made
//      2) inside the loop ask the user how many stones they would like to take and
//         then have them input their answer
//      3) if the move is valid, return the user's move. Else print "Invalid amount."
//         (hint: use the isValidMove function to test if the move is valid)

int getUserMove(int stones) {
    int userInput;

    while (true) {
        std::cout << "How many stones would you like to remove? ";
        std::cin >> userInput;

        if (isValidMove(userInput, stones)) {
            return userInput;
        }
        else {
            std::cout << "Invalid amount.\n";
        }
    }
}

//TODO: Create a function named computerMove() that has a return type of int. It needs
//      to take one parameter: int stones.
//      The purpose of this function is to program how many stones the computer will
//      take on their move.
//      If the number of stones = 1 or 2 then return 1. If stones = 3 then return 2.
//      If stones = 4 then return 3. Else return a random number between 1 and 3.

int computerMove(int stones) {

    //INitialize random
    srand(time(0));

    switch (stones) {
    case 1 || 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    default:
        return (rand() % 3) + 1;
    }
}

//TODO: Create a function of type bool named checkWin(). It will take one parameter: int stones
//      This one should be very simple, if there are no stones left then return true else 
//      return false.

bool checkWin(int stones) {
    if (stones > 0) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    //TODO: Start the stone count at 16 and tell the user how many stones are in the 
    //      pile
    int stones = 16;
    std::cout << "There are " << stones << " stones in the pile.\n";

    //TODO: Create a loop that will only break when the game is over.
    //      Within the loop, have the user take their move then subtract
    //      the result of the user's move with the total number of stones.

    while (!checkWin(stones)) {
        // User move
        int userMove = getUserMove(stones);
        stones = stones - userMove;
        std::cout << "There are " << stones << " stones left.\n";

        //TODO: Once again print how many stones are remaining and then check the
        //      the win condition.
        if (checkWin(stones)) {
            std::cout << "You took the last stone... YOU LOSE!\n";
            break;
        }

        //TODO: Now have the computer take its turn. Subtract the computer's move
        //      from the total number of stones.
        int compMove = computerMove(stones);
        stones = stones - compMove;

        //TODO: Print the total number of stones and then check the win condition
        std::cout << "The computer took " << compMove << " stones.\n";
        std::cout << "There are " << stones << " stones left.\n";

        if (checkWin(stones)) {
            std::cout << "The computer took the last stone... YOU WIN!\n";
        }
    }

    return 0;
}
