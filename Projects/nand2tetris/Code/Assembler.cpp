#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <unordered_map>
#include <bitset>

using namespace std;

std::string ExePath() {
    char buffer[MAX_PATH] = { 0 };
    GetModuleFileNameA(NULL, buffer, MAX_PATH); // Use GetModuleFileNameA for narrow strings
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    return std::string(buffer).substr(0, pos);
}

class Assembler {
public:
    std::ifstream myfile;
    std::ofstream outfile; // New member variable for the output file
    std::string user;
    std::string assembly;
    std::unordered_map<std::string, int> symbolTable;
    int nextRAMAddress = 16;

    Assembler() {
        cout << "Enter assembly file: " << endl;
        cin >> user;
        cout << "Trying to open file: " << user << endl;

        symbolTable["SP"] = 0;
        symbolTable["LCL"] = 1;
        symbolTable["ARG"] = 2;
        symbolTable["THIS"] = 3;
        symbolTable["THAT"] = 4;
        symbolTable["SCREEN"] = 16384;
        symbolTable["KBD"] = 24576;

        // Open the output file with the extension .hack
        std::string outputDirectory = "C:\\Users\\Isaiah\\Desktop\\nand2tetris\\projects\\06\\";
        std::string outputFileName = outputDirectory + user.substr(0, user.find_last_of('.')) + ".hack";
                outfile.open(outputFileName);

        myfile.open("C:\\Users\\Isaiah\\Desktop\\nand2tetris\\projects\\06\\" + user.substr(0, user.find_last_of('.')) + "\\" + user);

        if (myfile.is_open()) {
            cout << "File opened successfully." << endl;
            while (getline(myfile, assembly)) {
                std::string binaryInstruction = translateInstructionToBinary(assembly);
                if (!binaryInstruction.empty()) {
                    outfile << binaryInstruction << std::endl;
                }
            }
            outfile.close(); // Close the output file after writing all the binary instructions
        } else {
            cerr << "Error opening file. Check if the file exists or if it is in the correct location." << endl;
            cerr << "Error details: " << strerror(errno) << endl;
        }
    }

    // Rest of the code (translateAInstruction, translateCInstruction, symbol table, etc.) remains the same

    std::string translateInstructionToBinary(const std::string& instruction) {
        if (instruction.empty() || instruction[0] == '/' || instruction[0] == '(') {
            // Ignore empty lines, comments, and labels (not translated to binary)
            return "";
        }

        if (instruction[0] == '@') {
            // A-instruction: @value or @symbol
            return translateAInstruction(instruction);
        } else {
            // C-instruction: dest=comp;jump
            return translateCInstruction(instruction);
        }
    }

    std::string translateAInstruction(const std::string& instruction) {
            std::string address = instruction.substr(1); // Remove the leading '@'
            int value;

            // Check if it's a numeric constant or a symbol (label)
            if (std::isdigit(address[0])) {
                // Numeric constant
                value = std::stoi(address);
            } else {
                // Symbol (label)
                if (symbolTable.find(address) != symbolTable.end()) {
                    value = symbolTable[address];
                } else {
                    // Handle user-defined symbols or labels
                    // For simplicity, in this example, we assume all user-defined symbols are RAM addresses starting from 16.
                    value = nextRAMAddress;
                    symbolTable[address] = value;
                    nextRAMAddress++;
                }
            }

            // Convert the value to a 15-bit binary representation
            std::string binaryValue = std::bitset<16>(value).to_string().substr(1);
            return "0" + binaryValue;
        }

    std::string translateCInstruction(const std::string& instruction) {
        // Initialize strings for dest, comp, and jump components
        std::string dest = "000";
        std::string comp;
        std::string jump = "000";

        // Find the position of '=', if it exists
        size_t eqPos = instruction.find('=');
        // Find the position of ';', if it exists
        size_t semicolonPos = instruction.find(';');

        // If '=' exists, extract dest and comp
        if (eqPos != std::string::npos) {
            dest = instruction.substr(0, eqPos);
            comp = instruction.substr(eqPos + 1);
        }
        // If ';' exists, extract comp and jump
        if (semicolonPos != std::string::npos) {
            comp = instruction.substr(0, semicolonPos);
            jump = instruction.substr(semicolonPos + 1);
        }

        // Binary representations for the comp mnemonic according to the Hack specification
        std::unordered_map<std::string, std::string> compBinary = {
            {"0",   "0101010"},
            {"1",   "0111111"},
            {"-1",  "0111010"},
            {"D",   "0001100"},
            {"A",   "0110000"},
            {"M",   "1110000"},
            {"!D",  "0001101"},
            {"!A",  "0110001"},
            {"!M",  "1110001"},
            {"-D",  "0001111"},
            {"-A",  "0110011"},
            {"-M",  "1110011"},
            {"D+1", "0011111"},
            {"A+1", "0110111"},
            {"M+1", "1110111"},
            {"D-1", "0001110"},
            {"A-1", "0110010"},
            {"M-1", "1110010"},
            {"D+A", "0000010"},
            {"D+M", "1000010"},
            {"D-A", "0010011"},
            {"D-M", "1010011"},
            {"A-D", "0000111"},
            {"M-D", "1000111"},
            {"D&A", "0000000"},
            {"D&M", "1000000"},
            {"D|A", "0010101"},
            {"D|M", "1010101"}
        };

        // Binary representations for the dest mnemonic according to the Hack specification
        std::unordered_map<std::string, std::string> destBinary = {
            {"",    "000"},
            {"M",   "001"},
            {"D",   "010"},
            {"MD",  "011"},
            {"A",   "100"},
            {"AM",  "101"},
            {"AD",  "110"},
            {"AMD", "111"}
        };

        // Binary representations for the jump mnemonic according to the Hack specification
        std::unordered_map<std::string, std::string> jumpBinary = {
            {"",    "000"},
            {"JGT", "001"},
            {"JEQ", "010"},
            {"JGE", "011"},
            {"JLT", "100"},
            {"JNE", "101"},
            {"JLE", "110"},
            {"JMP", "111"}
        };

        // Get the binary representations for the comp, dest, and jump components
        std::string binaryComp = compBinary[comp];
        std::string binaryDest = destBinary[dest];
        std::string binaryJump = jumpBinary[jump];

        // Combine the binary components into the full 16-bit C-instruction binary code
        std::string binaryInstruction = "111" + binaryComp + binaryDest + binaryJump;

        return binaryInstruction;
    }

};

int main() {
    Assembler assembler; // Create an instance of the Assembler class
    std::cout << "My directory is " << ExePath() << "\n";

    return 0;
}




