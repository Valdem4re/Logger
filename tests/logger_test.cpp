#include "logger.h"
#include <iostream>
#include <fstream>

int main() {
    std::cout << "Running tests..." << std::endl;

    Logger::setLoggingOutput(std::cout);
    Logger::info("Info output");
    Logger::info("Formatted %s %d", "info output", 12345);
    Logger::info("Warning output");
    Logger::info("Formatted %s %d", "warning output", 12345);
    Logger::error("Error output");
    Logger::error("Formatted %s %d", "error output", 12345);
    Logger::debug("Debug output");
    Logger::debug("Formatted %s %d", "debug output", 12345);

    std::ofstream file_output("log.txt");
    Logger::info("Info output");
    Logger::info("Formatted %s %d", "info output", 12345);
    Logger::info("Warning output");
    Logger::info("Formatted %s %d", "warning output", 12345);
    Logger::error("Error output");
    Logger::error("Formatted %s %d", "error output", 12345);
    Logger::debug("Debug output");
    Logger::debug("Formatted %s %d", "debug output", 12345);

    std::ifstream file("log.txt");
    std::cout << "File log.txt content:\n";
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();


    std::cout << "All tests passed!" << std::endl;
    return 0;
}
