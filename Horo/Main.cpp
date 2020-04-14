
#include <iostream>
#include "Task.h"
#include "TaskParser.h"
#include <string>
#include "Horo.cpp"


// just to test
template <typename T>
void print(std::vector<T> data) {
    for (auto elem : data)
        std::cout << elem << "\n";
}


int main()
{
    /*
    std::vector<int> v;
    auto iter = v.end();
    iter = v.insert(iter, 5);

    ++iter; // = v.end();
    v.insert(iter, 6);

    print(v);
    */

    std::vector<Dancer> v;

    Dancer d1 = Dancer("Goliamata bira");
    Dancer d2 = Dancer("Mustaka");
    Dancer d3 = Dancer("Slavcho");
    Dancer d4 = Dancer("Georgi");

    v.push_back(d1);
    v.push_back(d2);
    v.push_back(d3);
    v.push_back(d4);

    Horo h(v);
    h.print();

}
