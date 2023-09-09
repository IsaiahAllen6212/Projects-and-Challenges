#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>  // Include vector header

using namespace std;

class VMTranslator {
public:
    enum class CommandType {
        ARITHMETIC,
        PUSH,
        POP
        // Add more command types here as needed
    };

    VMTranslator() {
        // Get the input VM file name from the user
        cout << "Enter the path of the input .vm file: ";
        string inputFileName;
        cin >> inputFileName;

        // Open the input VM file
        inFile.open(inputFileName);

        if (!inFile.is_open()) {
            cerr << "Error opening file: " << inputFileName << endl;
            exit(EXIT_FAILURE);
        }

        // Initialize the command type mapping
        commandTypeMap = {
            {"add", CommandType::ARITHMETIC},
            {"push", CommandType::PUSH},
            {"pop", CommandType::POP}
            // Add more commands here as needed
        };
    }

    ~VMTranslator() {
        // Close the input file
        if (inFile.is_open()) {
            inFile.close();
        }
    }

    void translate(const string& outputFileName, const vector<string>& inputFiles) {
        // Open the output file
        ofstream outFile(outputFileName);

        if (!outFile.is_open()) {
            cerr << "Error creating output file: " << outputFileName << endl;
            exit(EXIT_FAILURE);
        }

        // Loop through each input file
        for (const string& inputFileName : inputFiles) {
            inFile.open(inputFileName);

            if (!inFile.is_open()) {
                cerr << "Error opening file: " << inputFileName << endl;
                continue;
            }

            string line;
            while (getline(inFile, line)) {
                // Trim leading and trailing whitespace from the line
                trim(line);

                // Ignore comments and empty lines
                if (line.empty() || line[0] == '/') {
                    continue;
                }

                // Tokenize the line and extract the command and arguments
                istringstream iss(line);
                string command, arg1, arg2;
                if (!(iss >> command >> arg1 >> arg2)) {
                    // Handle invalid command format here if needed
                    continue;
                }

                // Translate the VM command into assembly code
                string assemblyCode;
                CommandType type = getCommandType(command);
                switch (type) {
                    case CommandType::ARITHMETIC:
                        assemblyCode = translateArithmetic(command);
                        break;
                    case CommandType::PUSH:
                        if (arg1 == "constant") {
                            assemblyCode = translatePushConstant(arg2);
                        } else if (arg1 == "local") {
                            assemblyCode = translatePushLocal(arg2);
                        } // Add more cases for other push commands as needed
                        break;
                    // Add more cases for additional command types
                }

                // Write the assembly code to the output file
                outFile << assemblyCode << endl;
            }

            inFile.close();
        }

        // Close the output file
        outFile.close();
    }

private:
    ifstream inFile;
    unordered_map<string, CommandType> commandTypeMap;

    // Trim leading and trailing whitespace from a string
    void trim(string& str) {
        size_t start = str.find_first_not_of(" \t");
        size_t end = str.find_last_not_of(" \t");
        str = (start == string::npos || end == string::npos) ? "" : str.substr(start, end - start + 1);
    }

    // Get the command type of a given VM command
    CommandType getCommandType(const string& command) {
        auto it = commandTypeMap.find(command);
        if (it != commandTypeMap.end()) {
            return it->second;
        }
        return CommandType::ARITHMETIC; // Default to ARITHMETIC if the command is not found
    }

    // Translate an arithmetic command into assembly code
    string translateArithmetic(const string& command) {
        // Handle arithmetic commands here
        stringstream assemblyCode;

        if (command == "add") {
            // The "add" command pops the top two values from the stack, adds them, and pushes the result back to the stack.
            assemblyCode << "@SP" << endl;
            assemblyCode << "AM=M-1" << endl;
            assemblyCode << "D=M" << endl;
            assemblyCode << "A=A-1" << endl;
            assemblyCode << "M=M+D" << endl;
        }

        // Add more arithmetic commands as needed

        return assemblyCode.str();
    }

    // Translate a push constant command into assembly code
    string translatePushConstant(const string& index) {
        int value = stoi(index); // Convert the index from string to an integer value

        // The "push constant" command simply loads the constant value onto the stack.
        // The value is stored in the A register and then pushed onto the stack.
        stringstream assemblyCode;
        assemblyCode << "@" << value << endl;   // Load the constant value into the A register
        assemblyCode << "D=A" << endl;         // Store the value in the D register
        assemblyCode << "@SP" << endl;         // Load the stack pointer into A
        assemblyCode << "A=M" << endl;         // Set A to the current stack address
        assemblyCode << "M=D" << endl;         // Store the value in the stack
        assemblyCode << "@SP" << endl;         // Load the stack pointer into A
        assemblyCode << "M=M+1" << endl;       // Increment the stack pointer

        return assemblyCode.str();
    }

    // Translate a push local command into assembly code
    string translatePushLocal(const string& index) {
        int value = stoi(index); // Convert the index from string to an integer value

        // The "push local" command loads the value at the local segment index onto the stack.
        // The value is loaded from RAM[LCL + index] and then pushed onto the stack.
        stringstream assemblyCode;
        assemblyCode << "@LCL" << endl;       // Load the base address of the local segment into A
        assemblyCode << "D=M" << endl;        // Store the value at LCL into D
        assemblyCode << "@" << value << endl; // Load the index into A
        assemblyCode << "A=D+A" << endl;      // Calculate the address LCL + index and store in A
        assemblyCode << "D=M" << endl;        // Load the value at the calculated address into D
        assemblyCode << "@SP" << endl;        // Load the stack pointer into A
        assemblyCode << "A=M" << endl;        // Set A to the current stack address
        assemblyCode << "M=D" << endl;        // Store the value in the stack
        assemblyCode << "@SP" << endl;        // Load the stack pointer into A
        assemblyCode << "M=M+1" << endl;      // Increment the stack pointer

        return assemblyCode.str();
    }
};

int main() {
    VMTranslator vmTranslator;

    vector<string> inputFiles;
    int numFiles;
    cout << "Enter the number of input .vm files: ";
    cin >> numFiles;

    for (int i = 0; i < numFiles; ++i) {
        string inputFileName;
        cout << "Enter the path of input .vm file " << i + 1 << ": ";
        cin >> inputFileName;
        inputFiles.push_back(inputFileName);
    }

    string outputFileName = "output.asm";  // Set default output file name

    vmTranslator.translate(outputFileName, inputFiles);

    cout << "Translation complete. Output written to: " << outputFileName << endl;

    return 0;
}
