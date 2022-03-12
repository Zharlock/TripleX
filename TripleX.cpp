#include <iostream>
#include <ctime>
#include <cstdio>

void PrintIntrodution(int Difficulty)
{
     // Print start of the story
    std::cout << "      __...--~~~~~-._   _.-~~~~~--...__ \n \
    //               `V'               \\ \n \
   //                 |                 \\ \n \
  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\ \n \
 //__.....----~~~~._\\ | /_.~~~~----.....__\\\n \
====================\\|//====================";
    std::cout << "\n\nYou are a Rogue sneaking in to the Demon Lords Castle to steal it's treasure\n";
    std::cout << "You need to enter the right combination to pass this level " << Difficulty;
    std::cout << " door...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntrodution(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the lock";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to: " << CodeProduct << std::endl;

    // Store Player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    /* Use == to compare, use = to assign value
       Use && for "and"
       Check if the player guess is correct */
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        if (Difficulty <= 4)
        std::cout << "\nGood Job! You passed the door. On to the next room! \n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        return true;
    }
    else
    {
        std::cout << "\nYou heard some steps and had to hide. Try again! \n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // randomizes the game

    int LevelDifficulty = 1;
    int const MaxDifficulty = 2;

    while (LevelDifficulty <= MaxDifficulty) //loop game until the game is completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }

    }
    
    std::cout << "  .     '     ,\n \
    _________ \n \
 _ /_|_____|_\ _ \n \
   '. \   / .' \n \
     '.\ /.' \n \
       '.' \n \ ";
    std::cout << "\nCongratulations you stolen the Demon Lords treasure";

    std::getchar();

    return 0;
}