
#include <iostream>
#include "Task.h"
#include "TaskParser.h"
#include <string>


// just to test
void print(std::vector<std::string> data) {
    for (auto elem : data)
        std::cout << elem << " " << elem.length() << "\n";
}


int main()
{
    std::string input;

    getline(std::cin, input);
    print( TaskParser().parse(input).data );
    
    

}

