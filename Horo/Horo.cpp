#include "Horo.h"


/// \param firstDancers dancers to start the horo
Horo::Horo(std::vector<Dancer>& firstDancers) {
	auto iter = dancers.end(); // dancers.begin() == dancers.end()

	for (auto dancer : firstDancers) {
		iter = dancers.insert(iter, dancer);
		dictionary[dancer.name()] = iter;
		++iter;
	}
}


bool Horo::areNeighbours(Dancer& dancer1, Dancer& dancer2) {
	if (dancer1 == leftNeighbour(dancer2) ||
		dancer2 == leftNeighbour(dancer1)) {
		return true;
	}
	return false;
}


// ASK
// Following function set to const make problem

/// \param dancer whose left neighbour in the horo to be returned
Dancer& Horo::leftNeighbour(const Dancer& dancer) {
	auto dancer_position = dictionary[dancer.name()];

	if (dancer_position == dancers.cbegin())
		return *(--dancers.end());

	dancer_position--;
	return *dancer_position;
}



/// \param dancer whose right neighbour in the horo to be returned
Dancer& Horo::rightNeighbour(const Dancer& dancer) {
	auto dancer_position = dictionary[dancer.name()];

	if (dancer_position == --dancers.end())
		return *dancers.begin();

	return *(++dancer_position);
}