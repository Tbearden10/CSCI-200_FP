#ifndef BUILD_H
#define BUILD_H

#include "part.h"

#include <vector>

class Build {
    public:

        /**
         * @brief Construct a new Build object
         * 
         */
        Build();

        /**
         * @brief Destroy the Build object
         * 
         */
        ~Build();

        /**
         * @brief Prompts the user with a list of parts and returns the choice
         * Handles input validation
         * 
         * @return int 
         */
        int getPartTypeChoice();

        /**
         * @brief Gets the users choice for which part model they would like.
         * Handles input validation
         * 
         * @param NUM_PARTS max number of parts
         * @return int 
         */
        int getPartModel(const int NUM_PARTS) const;

        /**
         * @brief Creates a part object that corresponds to the given input. 
         * Returns a new part object
         * 
         * @param partChoice 
         * @return Part* 
         */
        Part* createPart(int partChoice);

        /**
         * @brief Appends the part object to the list of parts
         * 
         * @param partToAdd 
         */
        void addPart(Part* partToAdd);

        /**
         * @brief Prints the Name and Price of each part in the part list
         * 
         */
        void printBuildSpecs();

        /**
         * @brief Calculates the total build price and returns it
         * 
         * @return float 
         */
        float getPrice();
        
        /**
         * @brief Writes the data from each part in the part list to a data file
         * 
         */
        void saveBuild();

        /**
         * @brief Returns the number of parts in the part list
         * 
         * @return int 
         */
        int getSize() const;

        /**
         * @brief Promts the user with the option to change a part of desired.
         * Handles input validation
         * 
         */
        void changePart();

    private:
        
        /**
         * @brief List of part points to store the parts
         * 
         */
        std::vector<Part*> m_partList;

        /**
         * @brief List of strings to check if a part is chosen or not
         * 
         */
        std::string* m_chosenList;

        /**
         * @brief Total Price of the build
         * 
         */
        float m_price;       

        /**
         * @brief Name of the build
         * 
         */
        std::string m_name;

        /**
         * @brief Helper function for saveBuild()
         * Handles the logic for saving the build 
         * 
         * @param partFile 
         */
        void saveBuild(std::ofstream& partFile);
        
        /**
         * @brief Helper function for changePart(). Behaves similar to getPartTypeChoice()
         * 
         * 
         * @return int 
         */
        int getPartTypeChange();
        
        /**
         * @brief Helper function for changePart(); Behaves similar to writePartData()
         * 
         * @param userChoice 
         */
        void changePart(int userChoice);

        /**
         * @brief Sorts the list of parts based on their index. Sorted order is the same
         * as the order when parts are prompted
         * 
         */
        void sortPartList();
};

#endif
