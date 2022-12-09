#include "part.h"

Part::Part() {
    m_name = "null";
    m_type = "null";
    m_price = 0.0;
    m_partNumber = 0;
    m_index = 0;
}

Part::~Part() {
    delete this;
}

std::string Part::getName() const {
    return m_name;
}

std::string Part::getType() const {
    return m_type;
}


std::string Part::getFileName( const int PART_TYPE_CHOICE ) const {
    std::string fileName;
    
    // file name corresponds to the user choice
    if ( PART_TYPE_CHOICE == 1 ) 
    {
        fileName = "PartData/cpu_data.txt";
    } 
    else if ( PART_TYPE_CHOICE == 2 ) 
    {
        fileName = "PartData/cooler_data.txt";
    }
    else if ( PART_TYPE_CHOICE == 3 ) 
    {
        fileName = "PartData/motherboard_data.txt";
    }
    else if ( PART_TYPE_CHOICE == 4 ) 
    {
        fileName = "PartData/memory_data.txt";
    }
    else if ( PART_TYPE_CHOICE == 5 || PART_TYPE_CHOICE == 6 ) 
    {
        fileName = "PartData/storage_data.txt";
    }
    else if ( PART_TYPE_CHOICE == 7 ) 
    {
        fileName = "PartData/gpu_data.txt";
    }
    else if ( PART_TYPE_CHOICE == 8 ) 
    {
        fileName = "PartData/chassis_data.txt";
    }
    else if ( PART_TYPE_CHOICE == 9 ) 
    {
        fileName = "PartData/psu_data.txt";
    }
    else if ( PART_TYPE_CHOICE == 10 ) 
    {
        fileName = "PartData/fans_data.txt";
    }
    return fileName;
}

int Part::getIndex() const {
    return m_index;
}
float Part::getPrice() const {
    return m_price;
}

void Part::print_name_price() {
    std::cout << m_name << " | $" << m_price << std::endl;
}

CPU::CPU() {
    this->m_type = "CPU";
    m_index = 1;
    m_cpu_cores = 0;
    m_cpu_coreClock = 0.0;
    m_cpu_boostClock = 0.0;
    m_cpu_socket = "null";
    m_cpu_powerDraw = 0; 
}


int CPU::print_part_options(std::ifstream& partDataFile) {

    // number of parts to choose from
    int parts = 0;

    // temporary variables used for printing
    std::string t_name, t_socket;
    float t_price, t_coreClock, t_boostClock;
    int t_cores, t_powerDraw, t_partNumber;

    std::cout << " -------------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Name | Price | Cores | Core Clock | Boost Clock | Socket | Power Draw | Part Number |" << std::endl;
    std::cout << " -------------------------------------------------------------------------------------" << std::endl;

    // loop until all lines have been read
    while( partDataFile >> t_name >> t_price >> t_cores >> t_coreClock >> t_boostClock >> t_socket >> t_powerDraw >> t_partNumber ) {
        std::cout
            << "| " << std::left << std::setw(24) << t_name << " | " 
            << "$" << std::setw(6) << t_price << " | "
            << std::right << std::setw(2) << t_cores << " | " 
            << t_coreClock << " GHz" << " | "  
            << t_boostClock << " GHz" << " | "  
            << t_socket << " | "  
            << std::setw(3) << t_powerDraw << " W" << " | "
            << std::setw(2) << t_partNumber << " | " 
            << 
        std::endl;
        parts++;
    }
    std::cout << " ------------------------------------------------------------------------------------" << std::endl;

    return parts;
}

void CPU::write_part_data(int partChoice, std::ifstream& partDataFile) {
    // write data to part until part choice is reached
    do {
        partDataFile >> m_name >> m_price 
                     >> m_cpu_cores >> m_cpu_coreClock
                     >> m_cpu_boostClock >> m_cpu_socket 
                     >> m_cpu_powerDraw >> m_partNumber;
    } while ( m_partNumber != partChoice );
}

void CPU::save_part_specs(std::ofstream& partDataFile) {
    // write CPU specs to output file
    partDataFile << "Name: " << m_name << std::endl;
    partDataFile << "Price: $" << m_price << std::endl;
    partDataFile << "Cores: " << m_cpu_cores << std::endl;
    partDataFile << "Core Clock: " << m_cpu_coreClock << " GHz" << std::endl;
    partDataFile << "Boost Clock: " << m_cpu_boostClock << " GHz" << std::endl;
    partDataFile << "Socket: " << m_cpu_socket << std::endl;
    partDataFile << "Power Draw: " << m_cpu_powerDraw << " W" << std::endl;
}

Cooler::Cooler() {
    this->m_type = "Cooler";
    m_index = 2;
    m_cooler_type = "null";
    m_cooler_color = "null";
    m_cooler_height = 0;
    m_cooler_radSize = 0;
    m_cooler_rgb = false;

}

int Cooler::print_part_options(std::ifstream& partDataFile) {

    // number of parts to choose from
    int parts = 0;

    // temporary variables for printing
    std::string t_name, t_type, t_color;
    float t_price;
    int t_height, t_partNumber, t_radSize;
    bool t_rgb;

    std::cout << " --------------------------------------------------------------------------" << std::endl;
    std::cout << "|  Name | Price | Type | Height | Fan/Rad Size | RGB | Color | Part Number |" << std::endl;
    std::cout << " --------------------------------------------------------------------------------" << std::endl;

    // loop until all lines have been read
    while ( partDataFile >> t_name >> t_price >> t_type >> t_height >> t_radSize >> t_rgb >> t_color >> t_partNumber ) {

        // convert RGB to string
        std::string t_str_rgb;
        if ( t_rgb == 1 ) { t_str_rgb = "Yes"; }
        else { t_str_rgb = "No"; }

        std::cout 
            << "| " << std::left << std::setw(21) << t_name << " | " 
            << "$" << std::setw(6) << t_price << " | "
            << std::right << std::setw(5) << t_type << " | " 
            << std::setw(4) << t_height << " mm" << " | "
            << std::setw(3) << t_radSize << " mm" << " | " 
            << std::setw(3) << t_str_rgb << " | "
            << std::setw(6) << t_color << " | "
            << std::setw(2) << t_partNumber << " | " 
            <<
        std::endl;
        parts++;
    }
    std::cout << " --------------------------------------------------------------------------------" << std::endl;

    return parts;  
}

void Cooler::write_part_data(int partChoice, std::ifstream& partDataFile) {
    // write data to part until part choice is reached
    do {
        partDataFile >> m_name >> m_price 
                     >> m_cooler_type >> m_cooler_height
                     >> m_cooler_radSize >> m_cooler_rgb
                     >> m_cooler_color >> m_partNumber;
    } while ( m_partNumber != partChoice );
}

void Cooler::save_part_specs(std::ofstream& partDataFile) {
    // convert RGB to string
    std::string t_rgb;
    if ( m_cooler_rgb == 1 ) { t_rgb = "Yes"; }
    else { t_rgb = "No"; }

    // write COOLER specs to output file
    partDataFile << "Name: " << m_name << std::endl;
    partDataFile << "Price: $" << m_price << std::endl;
    partDataFile << "Type: " << m_cooler_type << std::endl;
    partDataFile << "Height: " << m_cooler_height << " mm" << std::endl;
    partDataFile << "Rad Size: " << m_cooler_radSize << " mm" << std::endl;
    partDataFile << "RGB: " << t_rgb << std::endl;
    partDataFile << "Color: " << m_cooler_color << std::endl;

}


Motherboard::Motherboard() {
    this->m_type = "Motherboard";
    m_index = 3;
    m_motherboard_chipset = "null";
    m_motherboard_usbPorts = 0;
    m_motherboard_m2Slots = 0;
    m_motherboard_wifi = false;

}

int Motherboard::print_part_options(std::ifstream& partDataFile) {

    // number of parts to choose from
    int parts = 0;

    // temporary variables for printing
    std::string t_name, t_chipset;
    float t_price;
    int t_usbPorts, t_m2Slots, t_partNumber;
    bool t_wifi;

    std::cout << " ---------------------------------------------------------------------" << std::endl;
    std::cout << "| Name | Price | Chipset | Usb Ports | M.2 Slots | Wifi | Part Number |" << std::endl;
    std::cout << " ---------------------------------------------------------------------" << std::endl;

    // loop until all lines have been reado
    while ( partDataFile >> t_name >> t_price >> t_chipset >> t_usbPorts >> t_m2Slots >> t_wifi >> t_partNumber ) {

        // convert RGB to string
        std::string t_str_wifi;
        if ( t_wifi == 1 ) { t_str_wifi = "Yes"; }
        else { t_str_wifi = "No"; }

        
        std::cout 
            << "| " << std::left << std::setw(24) << t_name << " | " 
            << "$" << std::setw(6) << t_price << " | "
            << std::right << t_chipset << " | " 
            << t_usbPorts << " | "
            << t_m2Slots << " | " 
            << std::setw(3) << t_str_wifi << " | "
            << std::setw(2) << t_partNumber << " | " <<
        std::endl;
        parts++;
    }
    std::cout << " --------------------------------------------------------------" << std::endl;
    return parts;
}

void Motherboard::write_part_data(int partChoice, std::ifstream& partDataFile) {
    // write data to part until part choice is reached
    do {
        partDataFile >> m_name >> m_price 
                     >> m_motherboard_chipset >> m_motherboard_usbPorts
                     >> m_motherboard_m2Slots >> m_motherboard_wifi
                     >> m_partNumber;
    } while ( m_partNumber != partChoice );
}

void Motherboard::save_part_specs(std::ofstream& partDataFile) {

    // convert RGB to string
    std::string t_wifi;
    if ( m_motherboard_wifi == 1 ) { t_wifi = "Yes"; }
    else { t_wifi = "No"; }

    // write MOTHERBOARD specs to output file
    partDataFile << "Name: " << m_name << std::endl;
    partDataFile << "Price: $" << m_price << std::endl;
    partDataFile << "Chipset: " << m_motherboard_chipset << std::endl;
    partDataFile << "Number of USB ports: " << m_motherboard_usbPorts << std::endl;
    partDataFile << "Number of M.2 Slots: " << m_motherboard_m2Slots << std::endl;
    partDataFile << "Wifi: " << t_wifi << std::endl;
}

Memory::Memory() {
    this->m_type = "Memory";
    m_index = 4;
    m_memory_speed = "null";
    m_memory_totalMemory = 0;
    m_memory_numSticks = 0;
    m_memory_memPerStick = 0;
    m_memory_rgb = false;

}

int Memory::print_part_options(std::ifstream& partDataFile) {

    // number of parts to choose from
    int parts = 0;

    // temporary variables for printing
    std::string t_name, t_speed;
    float t_price;
    int t_totalMemory, t_numSticks, t_memPerStick, t_partNumber;
    bool t_rgb;
    
    std::cout << " ---------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Name | Price | Speed | Total Memory | Num. of sticks | Memory Per Stick | RGB | Part Number |" << std::endl;
    std::cout << " ---------------------------------------------------------------------------------------------" << std::endl;

    // loop until all lines have been read
    while ( partDataFile >> t_name >> t_price >> t_speed >> t_totalMemory >> t_numSticks >> t_memPerStick >> t_rgb >> t_partNumber ) {

        // convert RGB to string
        std::string t_str_rgb;
        if ( t_rgb == 1 ) { t_str_rgb = "Yes"; }
        else { t_str_rgb = "No"; }

        std::cout 
            << "| " << std::left << std::setw(26) << t_name << " | " 
            << "$" << std::setw(6) << t_price << " | "
            << t_speed << " | " 
            << t_totalMemory << " GB" << " | " 
            << t_numSticks << " | " 
            << std::right << std::setw(2) << t_memPerStick << " GB" << " | " 
            << std::setw(3) << t_str_rgb << " | " 
            << t_partNumber << " | " <<
        std::endl;
        parts++;
    }
    std::cout << " --------------------------------------------------------------------------------" << std::endl;

    return parts;
}

void Memory::write_part_data(int partChoice, std::ifstream& partDataFile) {
    // write data to part until part choice is reached
    do {
        partDataFile >> m_name >> m_price 
                     >> m_memory_speed >> m_memory_totalMemory 
                     >> m_memory_numSticks >> m_memory_memPerStick 
                     >> m_memory_rgb >> m_partNumber;
    } while ( m_partNumber != partChoice );
}

void Memory::save_part_specs(std::ofstream& partDataFile) {
    // write MEMORY specs to output file
    partDataFile << "Name: " << m_name << std::endl;
    partDataFile << "Price: $" << m_price << std::endl;
    partDataFile << "Speed: " << m_memory_speed << std::endl;
    partDataFile << "Total Memory: " << m_memory_totalMemory << " GB" << std::endl;
    partDataFile << "Number of ram sticks: " << m_memory_numSticks << std::endl;
    partDataFile << "Memory per stick: " << m_memory_memPerStick << " GB" << std::endl;
    // convert RGB to string
    std::string t_rgb;
    if ( m_memory_rgb == 1 ) { t_rgb = "Yes"; }
    else { t_rgb = "No"; }
    
    partDataFile << "RGB: " << t_rgb << std::endl;
}

Storage::Storage() {
    this->m_type = "Storage";
    m_index = 0;
    m_storage_type = "null";
    m_storage_totalStorage = 0;
}

Storage::Storage(std::string type, int index) {
    this->m_type = type;
    m_index = index;
    m_storage_type = "null";
    m_storage_totalStorage = 0;
}

int Storage::print_part_options(std::ifstream& partDataFile) {

    // number of parts to choose from
    int parts = 0;

    // temporary variables for printing
    std::string t_name, t_type;
    float t_price;
    int t_totalStorage, t_partNumber;

    std::cout << " ---------------------------------------------------------------" << std::endl;
    std::cout << "| Name | Price | Type-Form Factor | Total Storage | Part Number |" << std::endl;
    std::cout << " ---------------------------------------------------------------" << std::endl;
    
    // loop until all lines have been read
    while ( partDataFile >> t_name >> t_price >> t_type >> t_totalStorage >> t_partNumber ) {

        // convert total storage from GB to TB 
        t_totalStorage = t_totalStorage / 1000;

        std::cout
            << "| " << std::left << std::setw(21) << t_name <<  " | " 
            << "$" << std::setw(6) << t_price << " | "
            << std::setw(12) << t_type << " | " 
            << std::right << std::setw(2) << t_totalStorage << " TB" << " | "
            << std::setw(2) << t_partNumber << " | " << 
        std::endl;
        parts++;
    }
    std::cout << " -------------------------------------------------------------" << std::endl;

    return parts;
}

void Storage::write_part_data(int partChoice, std::ifstream& partDataFile) {
    // write data to part until part choice is reached
    do {
        partDataFile >> m_name >> m_price 
                     >> m_storage_type >> m_storage_totalStorage
                     >> m_partNumber;
    } while ( m_partNumber != partChoice );

}

void Storage::save_part_specs(std::ofstream& partDataFile) {

    // convert total storage from GB to TB 
    m_storage_totalStorage = m_storage_totalStorage / 1000;

    // write STORAGE specs to output file
    partDataFile << "Name: " << m_name << std::endl;
    partDataFile << "Price: $" << m_price << std::endl;
    partDataFile << "Type: " << m_storage_type << std::endl;
    partDataFile << "Total Storage: " << m_storage_totalStorage << " TB" << std::endl;
}

GPU::GPU() {
    this->m_type = "GPU";
    m_gpu_chipset = "null";
    m_index = 7;
    m_gpu_vram = 0;
    m_gpu_coreClock = 0;
    m_gpu_boostClock = 0;
    m_gpu_rgb = false;

}

int GPU::print_part_options(std::ifstream& partDataFile) {

    // number of parts to choose from
    int parts = 0;

    // temporary variables for printing
    std::string t_name, t_chipset;
    float t_price;
    int t_vram, t_coreClock, t_boostClock, t_partNumber;
    bool t_rgb;

    std::cout << " --------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Name | Chipset | Price | Memory | Core Clock | Boost Clock | RGB | Part Number |" << std::endl;
    std::cout << " ---------------------------------------------------------------------------------------" << std::endl;

    // loop until all lines have been read
    while ( partDataFile >> t_name >> t_chipset >> t_price >> t_vram >> t_coreClock >> t_boostClock >> t_rgb >> t_partNumber ) {
        
        // convert RGB to string
        std::string t_str_rgb;
        if ( t_rgb == 1 ) { t_str_rgb = "Yes"; }
        else { t_str_rgb = "No"; }

        std::cout
            << "| " << std::left << std::setw(18) << t_name << " | " 
            << std::setw(12) << t_chipset << " | "
            << "$" << std::setw(7) << t_price << " | " 
            << std::right << std::setw(2) << t_vram << " GB" << " | " 
            << t_coreClock << " MHz" << " | "
            << t_boostClock << " MHz" << " | "
            << std::setw(3) << t_str_rgb << " | " 
            << std::setw(2) << t_partNumber << " | " <<
        std::endl;
        parts++;
    }
    std::cout << " ---------------------------------------------------------------------------------------" << std::endl;

    return parts;
}

void GPU::write_part_data(int partChoice, std::ifstream& partDataFile) {
    // write data to part until part choice is reached
    do {
        partDataFile >> m_name >> m_gpu_chipset
                     >> m_price >> m_gpu_vram 
                     >> m_gpu_coreClock >> m_gpu_boostClock 
                     >> m_gpu_rgb >> m_partNumber;
    } while ( m_partNumber != partChoice );
}

void GPU::save_part_specs(std::ofstream& partDataFile) {
    // write GPU specs to output file
    partDataFile << "Name: " << m_name << std::endl;
    partDataFile << "Chipset: " << m_gpu_chipset << std::endl;
    partDataFile << "Price: $" << m_price << std::endl;
    partDataFile << "Vram: " << m_gpu_vram << " GB" << std::endl;
    partDataFile << "Core Clock: " << m_gpu_coreClock << " MHz" << std::endl;
    partDataFile << "Boost Clock: " << m_gpu_boostClock << " MHz" << std::endl;
    std::string t_rgb;
    if ( m_gpu_rgb == 1 ) { t_rgb = "Yes"; }
    else { t_rgb = "No"; }
    partDataFile << "RGB: " << t_rgb << std::endl;
}

Chassis::Chassis() {
    this->m_type = "Chassis";
    m_index = 8;
    m_chassis_maxFans = 0;
    m_chassis_temperedPanel = false;
    m_chassis_color = "null";

}

int Chassis::print_part_options(std::ifstream& partDataFile) {

    // number of parts to choose from
    int parts = 0;

    // temporary variables for printing
    std::string t_name, t_color;
    float t_price;
    int t_maxFans, t_partNumber;
    bool t_panel;

    std::cout << " --------------------------------------------------------------- " << std::endl;
    std::cout << "|  Name | Price | Max Fans | Glass Panel | Color | Part Number  |" << std::endl;
    std::cout << " --------------------------------------------------------------- " << std::endl;

    // loop until all lines have been read
    while ( partDataFile >> t_name >> t_price >> t_maxFans >> t_panel >> t_color >> t_partNumber ) {

        // convert Panel to string
        std::string t_str_panel;
        if ( t_panel == 1 ) { t_str_panel = "Yes"; }
        else { t_str_panel = "No"; }

        std::cout 
            << "| " << std::left << std::setw(27) << t_name << " | " 
            << "$" << t_price << " | "
            << t_maxFans << " | " 
            << std::right << std::setw(3) << t_str_panel << " | " 
            << std::setw(6) << t_color << " | " 
            << std::setw(2) << t_partNumber << " | "  <<
        std::endl;
        parts++;
    }
    std::cout << " --------------------------------------------------------------- " << std::endl;
    return parts;
}

void Chassis::write_part_data(int partChoice, std::ifstream& partDataFile) {
    // write data to part until part choice is reached
    do {
        partDataFile >> m_name >> m_price 
                     >> m_chassis_maxFans >> m_chassis_temperedPanel 
                     >> m_chassis_color >> m_partNumber;
    } while ( m_partNumber != partChoice );
}

void Chassis::save_part_specs(std::ofstream& partDataFile) {

    // convert Panel to string
    std::string t_str_panel;
    if ( m_chassis_temperedPanel == 1 ) { t_str_panel = "Yes"; }
    else { t_str_panel = "No"; }

    // write CHASSIS specs to output file
    partDataFile << "Name: " << m_name << std::endl;
    partDataFile << "Price: $" << m_price << std::endl;
    partDataFile << "Max Number of fans: " << m_chassis_maxFans << std::endl;
    partDataFile << "Tempered Panel: " << t_str_panel << std::endl;
    partDataFile << "Color: " << m_chassis_color << std::endl;
}

PSU::PSU() {
    this->m_type = "PSU";
    m_index = 9;
    m_psu_rating = "null";
    m_psu_maxPower = 0;

}

int PSU::print_part_options(std::ifstream& partDataFile) {

    // number of parts to choose from
    int parts = 0;

    // temporary variables for printing
    std::string t_name, t_rating;
    float t_price;
    int t_maxPower, t_partNumber;

    std::cout << " -------------------------------------------------" << std::endl;
    std::cout << "| Name | Price | Rating | Max Power | Part Number |" << std::endl;
    std::cout << " -----------------------------------------------------------" << std::endl;

    // loop until all lines have been read
    while ( partDataFile >> t_name >> t_price >> t_rating >> t_maxPower >> t_partNumber ) {
        std::cout
            << "| " << std::left << std::setw(18) << t_name << " | " 
            << "$" << std::setw(6) << t_price << " | "
            << std::setw(13) << t_rating << " | " 
            << t_maxPower << " W" << " | "
            << std::right << std::setw(2) << t_partNumber << " | " <<
        std::endl;
        parts++;
    }
    std::cout << " -----------------------------------------------------------" << std::endl;

    return parts;
}

void PSU::write_part_data(int partChoice, std::ifstream& partDataFile) {
    // write data to part until part choice is reached
    do {
        partDataFile >> m_name >> m_price 
                     >> m_psu_rating >> m_psu_maxPower
                     >> m_partNumber;
    } while ( m_partNumber != partChoice );
}

void PSU::save_part_specs(std::ofstream& partDataFile) {
    // write PSU specs to output file 
    partDataFile << "Name: " << m_name << std::endl;
    partDataFile << "Price: $" << m_price << std::endl;
    partDataFile << "Rating: " << m_psu_rating << std::endl;
    partDataFile << "Max Power: " << m_psu_maxPower << "w" << std::endl;
}

Fans::Fans() {
    this->m_type = "Fans";
    m_index = 10;
    m_fan_size = 0;
    m_fan_maxSpeed = 0;
    m_fan_color = "null";
    m_fan_noiseLv = "null";
    m_fan_airflow = "null";
    m_fans_rgb = false;
}

int Fans::print_part_options(std::ifstream& partDataFile) {

    // number of parts to choose from
    int parts = 0;

    // temporary variables for printing
    std::string t_name, t_color;
    float t_price, t_airFlow, t_noiseLV;
    int t_maxSpeed, t_size, t_partNumber;
    bool t_rgb;

    std::cout << " ---------------------------------------------------------------------------------------" << std::endl;
    std::cout << "| Name | Price | Size | Color | Speed (rpm) | Airflow | Noise Level | RGB | Part Number |" << std::endl;
    std::cout << " --------------------------------------------------------------------------------------------------------" << std::endl;

    // loop until all lines have been read
    while ( partDataFile >> t_name >> t_price >> t_size >> t_color >> t_maxSpeed >> t_airFlow >> t_noiseLV >> t_rgb >> t_partNumber ) {
        
        // convert RGB to string
        std::string t_str_rgb;
        if ( t_rgb == 1 ) { t_str_rgb = "Yes"; }
        else { t_str_rgb = "No"; }
        
        std::cout
            << "| " << std::left << std::setw(25) << t_name << " | " 
            << "$" << std::setw(6) << t_price << " | "
            << std::setw(3) << t_size << " mm" << " | " 
            << std::right << std::setw(11) << t_color << " | "
            << t_maxSpeed << " RPM" << " | " 
            << std::setw(5) << t_airFlow << " CFM" << " | " 
            << std::setw(4) << t_noiseLV << " dB" << " | " 
            << std::right << std::setw(3) << t_str_rgb << " | "
            << std::setw(2) << t_partNumber << " | " << 
        std::endl;
        parts++;
    }
    std::cout << " --------------------------------------------------------------------------------------------------------" << std::endl;

    return parts;
}

void Fans::write_part_data(int partChoice, std::ifstream& partDataFile) {
    // write data to part until part choice is reached
    do {
        partDataFile >> m_name >> m_price 
                     >> m_fan_size >> m_fan_color
                     >> m_fan_maxSpeed >> m_fan_airflow
                     >> m_fan_noiseLv >> m_fans_rgb 
                     >> m_partNumber;
    } while ( m_partNumber != partChoice );
}

void Fans::save_part_specs(std::ofstream& partDataFile) {
    // write FANS specs to output file
    partDataFile << "Name: " << m_name << std::endl;
    partDataFile << "Price: $" << m_price << std::endl;
    partDataFile << "Size: " << m_fan_size << " mm" << std::endl;
    partDataFile << "Color: " << m_fan_color << std::endl;
    partDataFile << "Speed: " << m_fan_maxSpeed << " RPM" << std::endl;
    partDataFile << "Airflow: " << m_fan_airflow << " CFM" << std::endl;
    partDataFile << "Noise Lv: " << m_fan_noiseLv << " dB" <<std::endl;  
    // convert RGB to string
    std::string t_rgb;
    if ( m_fans_rgb == 1 ) { t_rgb = "Yes"; }
    else { t_rgb = "No"; } 
    partDataFile << "RGB: " << t_rgb << std::endl;
}

