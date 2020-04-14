#pragma once

#include <iostream>
#include "Dancer.h"
#include <unordered_map>
#include <list>
#include <vector>


/// Horo of dancers
class Horo
{

private:
	// TODO ASK remove this ugly code around std

	/// Used to increase speed of accessing dancers
	/// Hashed the nicknames of dancers to access them by iterator position
	std::unordered_map<std::string, std::list<Dancer>::iterator> dictionary;


	/// participants in the horo
	std::list<Dancer> dancers;


	bool areNeighbours(Dancer& dancer1, Dancer& dancer2);
	Dancer& leftNeighbour(const Dancer& );
	Dancer& rightNeighbour(const Dancer& );

public:

	Horo(std::vector<Dancer>& firstDancers);


	// already just to test
	void print() const {

		for (auto elem : dancers)
			elem.print();

	}


	 

	


	
	
	

};

