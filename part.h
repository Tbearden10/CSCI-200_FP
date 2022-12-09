#ifndef PART_H
#define PART_H

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>

class Part {
    public:

        /**
         * @brief Construct a new Part object
         * 
         */
        Part();

        /**
         * @brief Destroy the Part object
         * 
         */
        ~Part();

        /**
         * @brief Returns part name
         * 
         * @return std::string 
         */
        std::string getName() const;

        /**
         * @brief Returns part type
         * 
         * @return std::string 
         */
        std::string getType() const;

        /**
         * @brief Returns the file name for corresponding part based on user input. 
         * 
         * @param PART_TYPE_CHOICE 
         * @return std::string 
         */
        std::string getFileName( const int PART_TYPE_CHOICE ) const;

        /**
         * @brief Returns the part index
         * 
         * @return int 
         */
        int getIndex() const;

        /**
         * @brief Returns the part price
         * 
         * @return float 
         */
        float getPrice() const;

        /**
         * @brief Prints the name and price of the part
         * 
         */
        void print_name_price();

        /**
         * @brief Prints the option(s) for each part.
         * 
         * @param partDataFile 
         * @return int 
         */
        virtual int print_part_options(std::ifstream& partDataFile) = 0;

        /**
         * @brief Writes part data to the part object
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        virtual void write_part_data(int partChoice, std::ifstream& partDataFile) = 0;

        /**
         * @brief Writes the part data to an output file
         * 
         * @param partDataFile 
         */
        virtual void save_part_specs(std::ofstream& partDataFile) = 0;
    protected:

        /**
         * @brief Part name
         * 
         */
        std::string m_name;  

        /**
         * @brief Part type
         * 
         */
        std::string m_type;

        /**
         * @brief Part price
         * 
         */
        float m_price;      

        /**
         * @brief Part number
         * 
         */
        int m_partNumber;     

        /**
         * @brief Part index
         * 
         */
        int m_index;
};

class CPU final : public Part {
    public:

        /**
         * @brief Construct a new CPU object
         * 
         */
        CPU();

        /**
         * @brief Print CPU option from given file
         * 
         * @param partDataFile 
         * @return int 
         */
        int print_part_options(std::ifstream& partDataFile) override;

        /**
         * @brief Write data to CPU object from file. Reads the file line by line,
         * until partChoice is reached. 
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        void write_part_data(int partChoice, std::ifstream& partDataFile) override;

        /**
         * @brief Write CPU object data to given output file
         * 
         * @param partDataFile 
         */
        void save_part_specs(std::ofstream& partDataFile) override;
    private: 
        int m_cpu_powerDraw;      // CPU TDP
        int m_cpu_cores;          // Number of cores in CPU
        float m_cpu_coreClock;    // CPU Core Clock Speed in GHz
        float m_cpu_boostClock;   // CPU Boost Clock Speed in GHz
        std::string m_cpu_socket; // CPU Socket
};

class Cooler final : public Part {
    public:

        /**
         * @brief Construct a new Cooler object
         * 
         */
        Cooler();

        /**
         * @brief Print COOLER options from given file
         * 
         * @param partDataFile 
         * @return int 
         */
        int print_part_options(std::ifstream& partDataFile) override;

        /**
         * @brief Writes data to COOLER object from file. Reads the file line by line,
         * until partChoice is reached. 
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        void write_part_data(int partChoice, std::ifstream& partDataFile) override;

        /**
         * @brief Writes COOLER object data to given output file
         * 
         * @param partDataFile 
         */
        void save_part_specs(std::ofstream& partDataFile) override;
    private:
        std::string m_cooler_type;  // Type of cooler ( Fin stack or AIO )
        std::string m_cooler_color; // Cooler color
        int m_cooler_height;        // Clearance height
        int m_cooler_radSize;       // Fan size ( 120/140/240/280 )
        bool m_cooler_rgb;          // Does Cooler have RGB
};

class Motherboard final : public Part {
    public:
        
        /**
         * @brief Construct a new Motherboard object
         * 
         */
        Motherboard();

        /**
         * @brief Prints MOTHERBOARD options from given file
         * 
         * @param partDataFile 
         * @return int 
         */
        int print_part_options(std::ifstream& partDataFile) override;

        /**
         * @brief Writes data to MOTHERBOARD object from file. Reads the file line by line,
         * until partChoice is reached. 
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        void write_part_data(int partChoice, std::ifstream& partDataFile) override;

        /**
         * @brief Writes MOTHERBOARD object data to given output file.
         * 
         * @param partDataFile 
         */
        void save_part_specs(std::ofstream& partDataFile) override;
    private:
        std::string m_motherboard_chipset; // Motherboard Chipset
        int m_motherboard_usbPorts;        // Number of USB ports
        int m_motherboard_m2Slots;         // Number of M.2 slots
        bool m_motherboard_wifi;           // Does Motherboard have Wifi
};

class Memory final : public Part {
    public:

        /**
         * @brief Construct a new Memory object
         * 
         */
        Memory();

        /**
         * @brief Prints MEMORY options from given file
         * 
         * @param partDataFile 
         * @return int 
         */
        int print_part_options(std::ifstream& partDataFile) override;

        /**
         * @brief Write data to Memory object from file. Reads the file line by line,
         * until partChoice is reached. 
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        void write_part_data(int partChoice, std::ifstream& partDataFile) override;

        /**
         * @brief Write COOLER object data to given output file
         * 
         * @param partDataFile 
         */
        void save_part_specs(std::ofstream& partDataFile) override;
    private:
        std::string m_memory_speed; // clock speeed of memory
        int m_memory_totalMemory;   // Total amount of memory in GB
        int m_memory_numSticks;     // Number of ram sticks
        int m_memory_memPerStick;   // Amount of memory per stick in GB
        bool m_memory_rgb;          // Does Memory have RGB
};

class Storage final : public Part {
    public:

        /**
         * @brief Construct a new Storage object
         * 
         */
        Storage();

        /**
         * @brief Construct a new Storage object based on type. Allows for build
         * to store different storage devices
         * 
         * @param type Boot storage or Game Storage
         * @param index 
         */
        Storage(std::string type, int index);

        /**
         * @brief Prints STORAGE options from given file
         * 
         * @param partDataFile 
         * @return int 
         */
        int print_part_options(std::ifstream& partDataFile) override;

        /**
         * @brief Write data to STORAGE object from file. Reads the file line by line,
         * until partChoice is reached. 
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        void write_part_data(int partChoice, std::ifstream& partDataFile) override;

        /**
         * @brief Write STORAGE object data to given output file
         * 
         * @param partDataFile 
         */
        void save_part_specs(std::ofstream& partDataFile) override;
    private:
        std::string m_storage_type; // type of storage device
        int m_storage_totalStorage; // total amount of storage in GB/TB
};

class GPU final : public Part {
    public:

        /**
         * @brief Construct a new GPU object
         * 
         */
        GPU();

        /**
         * @brief Prints GPU options from given file
         * 
         * @param partDataFile 
         * @return int 
         */
        int print_part_options(std::ifstream& partDataFile) override;

        /**
         * @brief Write data to GPU object from file. Reads the file line by line,
         * until partChoice is reached. 
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        void write_part_data(int partChoice, std::ifstream& partDataFile) override;

        /**
         * @brief Write GPU object data to given output file
         * 
         * @param partDataFile 
         */
        void save_part_specs(std::ofstream& partDataFile) override;
    private:
        std::string m_gpu_chipset; // GPU chipset
        int m_gpu_vram;            // GPU video memory in GB
        int m_gpu_coreClock;       // GPU core clock speed in MHz
        int m_gpu_boostClock;      // GPU boost clock speed in MHz
        bool m_gpu_rgb;            // Does GPU have RGB
};

class Chassis final : public Part {
    public:

        /**
         * @brief Construct a new Chassis object
         * 
         */
        Chassis();

        /**
         * @brief Prints CHASSIS options from given file
         * 
         * @param partDataFile 
         * @return int 
         */
        int print_part_options(std::ifstream& partDataFile) override;

        /**
         * @brief Write data to CHASSIS object from file. Reads the file line by line,
         * until partChoice is reached. 
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        void write_part_data(int partChoice, std::ifstream& partDataFile) override;

        /**
         * @brief Write CHASSIS object data to given output file
         * 
         * @param partDataFile 
         */
        void save_part_specs(std::ofstream& partDataFile) override;
    private:
        int m_chassis_maxFans;        // Max number of fans that fit
        bool m_chassis_temperedPanel; // Does chassis have tempered glass panel
        std::string m_chassis_color;  // Chassis color
};

class PSU final : public Part {
    public:

        /**
         * @brief Construct a new PSU object
         * 
         */
        PSU();

        /**
         * @brief Prints PSU options from given file
         * 
         * @param partDataFile 
         * @return int 
         */
        int print_part_options(std::ifstream& partDataFile) override;

        /**
         * @brief Write data to PSU object from file. Reads the file line by line,
         * until partChoice is reached. 
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        void write_part_data(int partChoice, std::ifstream& partDataFile) override;

        /**
         * @brief Writes PSU object data to given output file
         * 
         * @param partDataFile 
         */
        void save_part_specs(std::ofstream& partDataFile) override;
    private:
        std::string m_psu_rating; // PSU power rating
        int m_psu_maxPower;       // Max power draw threshold
};

class Fans final : public Part {
    public:

        /**
         * @brief Construct a new Fans object
         * 
         */
        Fans();

        /**
         * @brief Prints FANS options from given file
         * 
         * @param partDataFile 
         * @return int 
         */
        int print_part_options(std::ifstream& partDataFile) override;

        /**
         * @brief Write data to FANS object from file. Reads the file line by line,
         * until partChoice is reached. 
         * 
         * @param partChoice 
         * @param partDataFile 
         */
        void write_part_data(int partChoice, std::ifstream& partDataFile) override;

        /**
         * @brief Writes FANS object data to given output file
         * 
         * @param partDataFile 
         */
        void save_part_specs(std::ofstream& partDataFile) override;
    private:
        int m_fan_size;            // Size of each fan
        int m_fan_maxSpeed;        // Fan RPM
        std::string m_fan_color;   // Fan color
        std::string m_fan_airflow; // Fan airflow in CFM
        std::string m_fan_noiseLv; // Fan noise level in dB
        bool m_fans_rgb;           // Does fan have RGB
};

#endif
