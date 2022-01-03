#include <iostream>
#include <ctime>

                       
                                                                                            
                                                                                            
                                                                                            
                                                                       
                                                                                              
                                                                                              

void PrintIntroduction ()
{
    std::cout << std::endl;
    std::cout << " ________                   __  __               __     __                     __    __     \n";
    std::cout << "/        |                 /  |/  |             /  |   /  |                   /  |  /  |    \n";
    std::cout << "$$$$$$$$/______    ______  $$ |$$/_______       $$ |   $$ | ______   __    __ $$ | _$$ |_   \n";
    std::cout << "$$ |__  /      (  /      ( $$ |$//       |      $$ |   $$ |/      ( /  |  /  |$$ |/ $$   |  \n";
    std::cout << "$$    |/$$$$$$  |/$$$$$$  |$$ | /$$$$$$$/       $$  ( /$$/ $$$$$$  |$$ |  $$ |$$ |$$$$$$/   \n";
    std::cout << "$$$$$/ $$ |  $$ |$$ |  $$ |$$ | $$      (        $$  /$$/  /    $$ |$$ |  $$ |$$ |  $$ | __ \n";
    std::cout << "$$ |   $$ |__$$ |$$ |__$$ |$$ |  $$$$$$  |        $$ $$/  /$$$$$$$ |$$ (__$$ |$$ |  $$ |/  |\n";
    std::cout << "$$ |   $$    $$/ $$    $$/ $$ | /     $$/          $$$/   $$    $$ |$$    $$/ $$ |  $$  $$/ \n";
    std::cout << "$$/     $$$$$$/   $$$$$$/  $$/  $$$$$$$/            $/     $$$$$$$/  $$$$$$/  $$/    $$$$/  \n\n";
    std::cout <<"Welcome to the Fool's Vault, you are a theif and \n" ;
    std::cout <<"you are already inside a bank, vault insight - in the dead of night.\n" ;
    std::cout <<"Unlock the Vault and leave with its riches\n" ;
    std::cout <<"It is protected by a 3-combination code that changes everytime you make a mistake...Goodluck!\n" ;
}

bool PlayGame(int Difficulty)
{
    
    std::cout <<"\n\nUnlock the vault now and bathe in its riches\n" ;
    std::cout <<"Enter the correct code to continue...\n\n";

    const int CodeA = rand () %Difficulty+Difficulty;
    const int CodeB = rand () %Difficulty+Difficulty;
    const int CodeC = rand () %Difficulty+Difficulty;

    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;
    

    std::cout << "Protected by a 3 combination code that follows an algorithm as follows;\n";
    std::cout << "The codes when addedd together gives: " <<CodeSum<< " and \n";
    std::cout << "The codes when multiplied produces: " <<CodeProduct<< std::endl;

    int GuessA;
    int GuessB;
    int GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;
   
    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;

    std::cout << "You've entered the code: " <<GuessA<< " " <<GuessB<< " and " << GuessC << std::endl;
    std::cout << "Which when added together is " <<GuessSum <<  std::endl;
    std::cout << "And when multiplied gives " <<GuessProduct << std::endl;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nCongratulations, you've unlocked the vault!...... oh wait another vault\n";
        return true;
    }
    else
    {
        std::cout << "\nWrong codes, Try Again!\n";
        return false;
    }

}

int main()
    
{
    srand(time(NULL));  //create new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    PrintIntroduction();
    
    while (LevelDifficulty <= MaxLevel) //loop game until levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();   //clears any errors
        std::cin.ignore();  //discards the buffers

        if (bLevelComplete)
        {
           ++LevelDifficulty;   //increase the level difficulty
        }
    }

    std::cout << "Congrtulations Thief! you've successfully unlocked 5 vaults,\n";
    std::cout << "but the police are here too and you got nothing\n";
    std::cout << "Thank you for Playing!\n";
    return 0;
}