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
	Horo(std::vector<Dancer>& firstDancers) {
		auto iter = dancers.begin();

		for (auto dancer : firstDancers) {
			dancers.insert(iter, dancer);
			dictionary[dancer.name()] = iter; // or iter maybe ?
		}
	}


	void print() const {
		// TODO

		for (auto elem : dancers)
			elem.print();
		

		std::cout << "\n\n";

		for (auto elem : dictionary)
			(*elem.second).print();

	}

	/// Prints neighbours as shows if they hold each other
	void printNeighbours(Dancer a, Dancer b) {
		// TODO
	}


	bool areNeighbours(const Dancer& a, const Dancer& b) const {
		if (precede(a, b) || precede(b, a)) {
			// TODO
		}
		return bool();
	}

	bool precede(const Dancer& a, const Dancer& b) const {

		// TODO

		return bool();
	}
};

