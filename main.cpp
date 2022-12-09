#include "build.h"

int get_menu_choice() {
    int choice;
    do {
        // print options
        std::cout << " 1: Start \n 2: Instructions \n 3. Exit Program" << std::endl;
        
        std::cout << "What would you like to do: "; 
        std::cin >> choice;
        std::cout << std::endl;

        bool inRange;

        if ( choice >= 1 && choice <= 3 ) { inRange = true; }
        else { inRange = false; }

        if ( !std::cin.fail() && inRange==true ) { break; }
        else if ( std::cin.fail() ) {

            std::cerr << "Invalid input" << std::endl;
            std::cin.clear();

            char nChar;
            do { nChar = std::cin.get(); } while ( nChar != '\n' ); // prevent inf loop
        }
        else {
            std::cerr << "Input out of range" << std::endl;
            std::cin.clear();
        }
    } while ( true );

    return choice; 
}


void run_application() {

    // create build object
    Build* user_build = new Build;

    // loop until all parts have been chosen
    do {
        
        // get user choice
        int partTypeChoice = user_build->getPartTypeChoice();
        
        // create part from user choice
        Part* partToAdd = user_build->createPart( partTypeChoice );

        // get file name based on user choice
        std::string fileName = partToAdd->getFileName( partTypeChoice );
        
        // open file
        std::ifstream dataFile;
        dataFile.open( fileName );

        // check if file opened
        if ( dataFile.fail() ) { std::cerr << "File failed to open" << std::endl; }

        // create temp file for printing
        std::ifstream tempDataFile;
        tempDataFile.open( fileName );

        // check if temp file opened
        if ( tempDataFile.fail() ) { std::cerr << "File failed to open" << std::endl; }

        // print part options from file
        int numParts = partToAdd->print_part_options( tempDataFile );

        // get part choice 
        int partChoice = user_build->getPartModel(numParts);
        
        // write part data to the new part object
        partToAdd->write_part_data( partChoice, dataFile );

        // close file streams
        dataFile.close();
        tempDataFile.close();

        // add part to part list
        user_build->addPart(partToAdd);
            
        

    } while ( user_build->getSize() != 10 );


    // print specs 
    user_build->printBuildSpecs();

    // prompt user to change any parts
    user_build->changePart();

    // promt user to save any parts
    user_build->saveBuild();    

    // deallocate build
    delete user_build;

}

int main() {

    std::cout << " ------------------------------------------------------" << std::endl;
    std::cout << "| Welcome to the ITX PC Part Picker - Terminal Edition |" << std::endl;
    std::cout << " ------------------------------------------------------" << std::endl;

    int choice;
    do {
        choice = get_menu_choice();
        if ( choice == 1 ) 
        {
            // function to handle PC building functions
            run_application();
            break;
        } 
        else if ( choice == 2 ) 
        {
            // print instructions
            std::cout << " --------------" << std::endl;
            std::cout << "| Instructions |" << std::endl;
            std::cout << " --------------" << std::endl;

            std::cout << " Step 1:  Select 'Start' from menu \n" 
                      << " Step 2:  You will be a given the list of part for the build \n"
                      << " Step 3:  Select the part you wish to choose first \n"
                      << " Step 4:  You will then be given the avaliable options for the part \n"
                      << " Step 5:  Select your desired part \n"
                      << " Step 6:  Repeat this process until all parts have been choosen \n"
                      << " Step 7:  Once finished, you will be given the option print your part list \n"
                      << " Step 8:  Program will exit once finished \n" <<
            std::endl;

            std::cout << " ----------------------------------------" << std::endl;
            std::cout << "| ITX PC Part Picker - Terminal Editiion |" << std::endl;
            std::cout << " ----------------------------------------" << std::endl;


            continue;
        }
        else if ( choice == 3 ) 
        {
            std::cout << "Program exited" << std::endl;
            return -1;
        }
    
    }  while ( true );
    
    

    return 0;
}
