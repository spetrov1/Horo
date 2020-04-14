
#include <iostream>
#include "Task.h"
#include "TaskParser.h"
#include <string>
#include "Horo.cpp"


// just to test
void print(std::vector<std::string> data) {
    for (auto elem : data)
        std::cout << elem << " " << elem.length() << "\n";
}


int main()
{
    std::vector<Dancer> v;
    
    v.push_back(Dancer("Goliamata bira"));
    v.push_back(Dancer("Mustaka"));
    v.push_back(Dancer("Slavcho"));
    v.push_back(Dancer("Georgi"));
    

    Horo h(v);
    h.print();
}

