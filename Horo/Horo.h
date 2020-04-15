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

public:

	bool areNeighbours(Dancer& dancer1, Dancer& dancer2);
	// ASK if following function is const --> error
	Dancer& leftNeighbour(const Dancer& );
	Dancer& rightNeighbour(const Dancer& );
	Dancer& getDancerByName(std::string );  /// Consider public function, for testing purposes
	void printRelation(Dancer& d1, Dancer& d2) const;
	bool existsDancerByName(std::string);

public:

	Horo(std::vector<Dancer>& firstDancers);

	void printInfo(std::string name);

	void release(std::string, const Direction& ); // TODO problem

	void grab(std::string, const Direction&); // TODO arguments
	
	bool add(std::string new_dancer, std::string left_dancer, std::string right_dancer);

	bool remove(std::string dancer);

	// already just to test
	void print() const {

		for (auto elem : dancers)
			elem.print();

	}


	 

	


	
	
	

};

