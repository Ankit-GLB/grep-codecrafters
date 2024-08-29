#include <iostream>
#include <string>

bool match_pattern(const std::string& input_line, const std::string& pattern) {
    if (pattern.length() == 1) {
        return input_line.find(pattern) != std::string::npos;
    }
    else {
        throw std::runtime_error("Unhandled pattern " + pattern);
    }
}


// here argc is the count of total number of arguments(if we pass 3 arguments, then argc = 3, since one argument arg[0] is the program name)
// here argv is a array of char* (C-style strings), they contain the command line arguments as string literals
int main(int argc, char* argv[]) {

    // Flush after every std::cout / std::cerr
    // we are flushing the stream instantly to show the output as soon as it available
    std::cout << std::unitbuf;// when we do this, we tell the output stream to disable buffering of data before sending it to its destination
    std::cerr << std::unitbuf;// a quick note, cerr o/p stream is unbufferred by default, so it not necessary according to me

    // You can use print statements as follows for debugging, they'll be visible when running tests.
    std::cout << "Logs from your program will appear here" << std::endl;

    if (argc != 3) {
        std::cerr << "Expected two arguments" << std::endl;
        return 1;
    }

    // these are the command line arguments,
    // arg[0] is the name of the program
    // arg[1] to arg[argc-1] are the arguments that we pass as a user to the command line
    // here "argc-1" means the last index of the command line arguments

    std::string flag = argv[1]; 
    std::string pattern = argv[2];

    if (flag != "-E") {
        std::cerr << "Expected first argument to be '-E'" << std::endl;
        return 1;
    }

    // Uncomment this block to pass the first stage
    
    std::string input_line;
    std::getline(std::cin, input_line);
    
    try {
        if (match_pattern(input_line, pattern)) {
            return 0;
        } else {
            return 1;
        }
        
    } 
    // here runtime_error is a standard exception class, that represents error the occurred during runtime
    // The variable is a "const reference" to the runtime_error class, it means that it can't be modified inside the catch block 
    catch (const std::runtime_error& e) { 
        std::cerr << e.what() << std::endl; // e.what() returns a char* (reference to C-style string) that describes the error
        return 1;
    }
}
