#include "build.h"

Build::Build() {
    m_partList;
    m_price = 0.0;
    m_chosenList = new std::string[10];
    // set all values in choosen list to false
    for(int i=0; i<10; i++) {
        m_chosenList[i] = "Empty";
    }
}

Build::~Build() {
    m_price = 0.0;
    delete[] m_chosenList;
}

int Build::getPartTypeChoice() { 
    int userChoice;
    
    do {
        std::cout << "Which part would you like to start with?" << std::endl;
        std::cout 
                << " 1. " << std::setw(14) << "CPU"          << " | " << m_chosenList[0] << std::endl
                << " 2. " << std::setw(14) << "Cooler"       << " | " << m_chosenList[1] << std::endl
                << " 3. " << std::setw(14) << "Motherboard"  << " | " << m_chosenList[2] << std::endl
                << " 4. " << std::setw(14) << "Memory"       << " | " << m_chosenList[3] << std::endl
                << " 5. " << std::setw(14) << "Boot Storage" << " | " << m_chosenList[4] << std::endl
                << " 6. " << std::setw(14) << "Game Storage" << " | " << m_chosenList[5] << std::endl
                << " 7. " << std::setw(14) << "GPU"          << " | " << m_chosenList[6] << std::endl
                << " 8. " << std::setw(14) << "Chassis"      << " | " << m_chosenList[7] << std::endl
                << " 9. " << std::setw(14) << "PSU"          << " | " << m_chosenList[8] << std::endl
                << " 10. " << std::setw(13) << "Case Fans"   << " | " << m_chosenList[9] << std::endl;
        
        std::cout << "Enter part number: ";
        std::cin >> userChoice;
        std::cout << std::endl;

        bool inRange;

        // validate user input
        if ( userChoice >= 1 && userChoice <= 10 ) { inRange = true; }
        else { inRange = false; }

        if ( !std::cin.fail() && inRange == true && m_chosenList[userChoice-1] == "Empty" ) { break; }
        else if ( std::cin.fail() ) {
            std::cerr << "Invalid Input" << std::endl;
            std::cin.clear();

            char nChar;
            do { nChar = std::cin.get(); } while ( nChar != '\n' ); // prevent inf loop
        } 
        else if ( inRange == false ) {
            std::cerr << "Input out of range" << std::endl;
            std::cin.clear();
        }
        else if ( m_chosenList[userChoice-1] == "Chosen" ) {
            std::cerr << "Part already chosen" << std::endl;
            std::cin.clear();
        }


        
    } while ( true );

    // set corresponding part to true
    m_chosenList[userChoice-1] = "Chosen";

    return userChoice;
}

int Build::getPartModel(const int NUM_PARTS) const {
    int choice;
    do {
        std::cout << "Enter part ID: "; 
        std::cin >> choice;
        std::cout << std::endl;

        bool inRange;
        
        // validate user input
        if ( choice >= 1 && choice <= NUM_PARTS ) { inRange = true; }
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

Part* Build::createPart(int partChoice) {
    // Creat new Part object
    Part* newPart;

    // set part to child part depending on user input
    if ( partChoice == 1 ) { newPart = new CPU; }
    else if ( partChoice == 2 ) { newPart = new Cooler; }
    else if ( partChoice == 3 ) { newPart = new Motherboard; }
    else if ( partChoice == 4 ) { newPart = new Memory; }
    else if ( partChoice == 5 ) { newPart = new Storage("Boot Storage", 5); }
    else if ( partChoice == 6 ) { newPart = new Storage("Game Storage", 6); }
    else if ( partChoice == 7 ) { newPart = new GPU; }
    else if ( partChoice == 8 ) { newPart = new Chassis; }
    else if ( partChoice == 9 ) { newPart = new PSU; }
    else if ( partChoice == 10 ) { newPart = new Fans; }

    return newPart;
}



void Build::addPart(Part* partToAdd) {
    m_partList.push_back(partToAdd);
}


void Build::printBuildSpecs() {

    std::cout << "Build Specs: " << std::endl;
    
    // print name/price part and get total price
    std::cout 
                << " 1. " << std::right << std::setw(12) << "CPU" << " | " 
                << std::right << std::setw(24) << m_partList.at(0)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(0)->getPrice() << std::endl

                << " 2. " << std::right << std::setw(12) << "Cooler" << " | " 
                << std::right << std::setw(24) << m_partList.at(1)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(1)->getPrice() << std::endl

                << " 3. " << std::right << std::setw(12) << "Motherboard" << " | " 
                << std::right << std::setw(24) << m_partList.at(2)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(2)->getPrice() << std::endl

                << " 4. " << std::right << std::setw(12) << "Memory" << " | " 
                << std::right << std::setw(24) << m_partList.at(3)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(3)->getPrice() << std::endl

                << " 5. " << std::right << std::right << std::setw(12) << "Boot Storage" << " | " 
                << std::right << std::setw(24) << m_partList.at(4)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(4)->getPrice() << std::endl

                << " 6. " << std::right << std::setw(12) << "Game Storage" << " | " 
                << std::right << std::setw(24) << m_partList.at(5)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(5)->getPrice() << std::endl
                  
                << " 7. " << std::right << std::setw(12) << "GPU" << " | " 
                << std::right << std::setw(24) << m_partList.at(6)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(6)->getPrice() << std::endl

                << " 8. " << std::right << std::setw(12) << "Chassis" << " | " 
                << std::right << std::setw(24) << m_partList.at(7)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(7)->getPrice() << std::endl

                << " 9. " << std::right << std::setw(12) << "PSU" << " | " 
                << std::right << std::setw(24) << m_partList.at(8)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(8)->getPrice() << std::endl

                << " 10. " << std::right << std::setw(11) << "Case Fans" << " | " 
                << std::right << std::setw(24) << m_partList.at(9)->getName() << " | $" 
                << std::left << std::setw(8) << m_partList.at(9)->getPrice() << std::endl;

    std::cout << "Total Price: $" << getPrice() << std::endl << std::endl;

    
}

float Build::getPrice() {

    m_price = 0;
    // add up price for each part in list
    for(unsigned int i=0; i < m_partList.size(); i++) {
        m_price += m_partList.at(i)->getPrice();
    }

    return m_price;
}

void Build::saveBuild() {

    // promt user to send to file for printing
    int choice;
    do {

        std::cout << "Would you like to send your part list to a file for printing?" << std::endl;
        std::cout << "Enter 1 or 2: ";
        std::cin >> choice;

        bool inRange;

        // in range check
        if ( choice >= 1 && choice <= 2 ) { inRange = true; }
        else { inRange == false; }

        // if valid and in range
        if ( ~!std::cin.fail() && inRange == true ) { break; }
        // if non integer input
        else if ( std::cin.fail() ) { 
            std::cerr << "Invalid Input" << std::endl;
            std::cin.clear();

            char nChar;
            do { nChar = std::cin.get(); } while ( nChar != '\n' ); // prevent inf loop
        }
        else {
            std::cerr << "Input out of range" << std::endl;
            std::cin.clear();
        }
    } while (true);

    if ( choice == 1 ) {
        // prompt for name
        std::cout << "Enter build name: ";
        std::cin.ignore();
        std::getline(std::cin, m_name);

        // open output file stream
        std::ofstream partFile;
        partFile.open("SavedBuilds/" + m_name + ".txt");

        if ( partFile.fail() ) { std::cerr << "File failed to open" << std::endl; }

        while ( !partFile.is_open() ) {
            std::cout << "File failed to open or Build already exists" << std::endl;
            std::cout << "Enter build name: ";
            std::cin >> m_name;
            partFile.open("SavedBuild/" + m_name + ".txt");
        }

        saveBuild(partFile);

        partFile.close();
    }
    else {
        std::cout << std::endl;
        std::cout << "Thank you using this program.";
    }

    

    
}

void Build::saveBuild(std::ofstream& partFile) {

    // sort parts
    sortPartList();
    
    // perfrom file writting here
    
    partFile << "Build Name: " << m_name << std::endl;
    partFile << "--------------------------------------------" << std::endl;
    partFile << "Total Price: $" << m_price << std::endl << std::endl;


    for(unsigned int i=0; i < m_partList.size(); i++) {
        partFile << m_partList.at(i)->getType() << ": " << std::endl;
        m_partList.at(i)->save_part_specs(partFile);
        partFile << std::endl;
    }

    std::cout << std::endl;
    std::cout << "File can be found in the 'Saved Builds' folder." << std::endl;
    std::cout << "Thank you using this program.";
}

int Build::getSize() const {
    return m_partList.size();
}

void Build::changePart() {

    int choice;
    do {
        std::cout << "Would you like to change any parts?" << std::endl;
        std::cout << "Enter 1 or 2: ";
        std::cin >> choice;
        

        // add input validation for choice
        bool inRange;

        // in range check
        if ( choice >= 1 && choice <= 2 ) { inRange = true; }
        else { inRange == false; }

        // if valid and in range
        if ( ~!std::cin.fail() && inRange == true ) { break; }
        // if non integer input
        else if ( std::cin.fail() ) { 
            std::cerr << "Invalid Input" << std::endl;
            std::cin.clear();

            char nChar;
            do { nChar = std::cin.get(); } while ( nChar != '\n' ); // prevent inf loop
        }
        else {
            std::cerr << "Input out of range" << std::endl;
            std::cin.clear();
        }
    } while (true);

    int partToChange;
    
    while ( choice == 1 ) {
        partToChange = getPartTypeChange();
        changePart(partToChange);

    
        do {
            std::cout << "Would you like to change another part?: " << std::endl;
            std::cout << "Enter 1 or 2: ";
            std::cin >> choice;
            

            // add input validation for choice
            bool inRange;

            // in range check
            if ( choice >= 1 && choice <= 2 ) { inRange = true; }
            else { inRange == false; }

            // if valid and in range
            if ( ~!std::cin.fail() && inRange == true ) { break; }
            // if non integer input
            else if ( std::cin.fail() ) { 
                std::cerr << "Invalid Input" << std::endl;
                std::cin.clear();

                char nChar;
                do { nChar = std::cin.get(); } while ( nChar != '\n' ); // prevent inf loop
            }
            else {
                std::cerr << "Input out of range" << std::endl;
                std::cin.clear();
            }
        } while (true);
    }

}

void Build::changePart(int userChoice) {

    // sort
    sortPartList();

    // file streams
    std::ifstream tempDataFile;
    std::ifstream dataFile;
    std::string fileName = m_partList.at(userChoice-1)->getFileName( userChoice );

    // std::cout << fileName << std::endl;

    tempDataFile.open( fileName );
    dataFile.open ( fileName );

    if ( tempDataFile.fail() ) { std::cout << "File failed to open" << std::endl; }
    if ( dataFile.fail() ) { std::cout << "File failed to open" << std::endl; }

    // get number of part options
    int numParts = m_partList.at(userChoice-1)->print_part_options( tempDataFile );

    // get part choice
    int partChoice = getPartModel( numParts );
        
    // write part data to chosen part
    m_partList.at(userChoice-1)->write_part_data( partChoice, dataFile );

    // print specs
    printBuildSpecs();

    // close file streams
    tempDataFile.close();
    dataFile.close();

}

int Build::getPartTypeChange() { 
    int userChoice;
    
    // sort part list
    sortPartList();

    do {
        std::cout << "Which part would you like to change?" << std::endl;
        
        // print specs
        printBuildSpecs();
        
        std::cout << "Enter part number: ";
        std::cin >> userChoice;
        std::cout << std::endl;

        bool inRange;

        // validate user input
        if ( userChoice >= 1 && userChoice <= 10 ) { inRange = true; }
        else { inRange = false; }

        if ( !std::cin.fail() && inRange == true ) { break; }
        else if ( std::cin.fail() ) {
            std::cerr << "Invalid Input" << std::endl;
            std::cin.clear();

            char nChar;
            do { nChar = std::cin.get(); } while ( nChar != '\n' ); // prevent inf loop
        } 
        else if ( inRange == false ) {
            std::cerr << "Input out of range" << std::endl;
            std::cin.clear();
        }


        
    } while ( true );


    return userChoice;
}

void Build::sortPartList() {

    // sort list in order of part index
    for(int k=1; k<m_partList.size(); k++) {
        Part* temp = m_partList.at(k);
        int j = k-1;
        while ( j >=0 && temp->getIndex() <= m_partList.at(j)->getIndex() ) {
            m_partList.at(j+1) = m_partList.at(j);
            j = j-1;
        }
        m_partList.at(j+1) = temp;
    }
    
}

