
#include <iostream>
#include "Task.h"
#include <string>


// just to test
void print(std::vector<std::string> data) {
    for (auto elem : data)
        std::cout << elem << " " << elem.length() << "\n";
}



// skip spaces in 'input' through index 'i'
void skipSpaces(std::string& input, size_t& i) {
    while (input[i] == ' ')   // skip unnecessary spaces
        ++i;
}


/// read argument consisted of 1 word
std::string readSimpleArgument(std::string& input, size_t& i) {
    
    std::string word;
    while (input[i] != ' ' && i != input.length() ) {
        word += input[i];
        ++i;
    }

    return word;
}


/// read first argument from input after i-th position
std::string readComplexArgument(std::string& input, size_t& i) {
    std::string word;

    while (input[i] != '"') {
        word += input[i];
        ++i;
    }

    return word;
}


/// return Task
std::vector<std::string> parse(std::string input) {
    std::vector<std::string> task_data;
    size_t inputLength = input.length(),
        i = 0;
    std::string arg;
    
    std::string verb = readSimpleArgument(input, i);
    task_data.push_back(verb);

    skipSpaces(input, i);

    for (i; i < inputLength; ++i) {
        skipSpaces(input, i);

        if (input[i] == '"') {
            ++i;                         // skipping "
            arg = readComplexArgument(input, i);
        }
        else {                          // else it is a character
            arg = readSimpleArgument(input, i);
        }

        task_data.push_back(arg);
    }

    return task_data;
}

int main()
{
    std::string input;

    getline(std::cin, input);

    print( parse(input) );
    
    

}

