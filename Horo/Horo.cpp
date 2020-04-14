#include "Horo.h"


/// \return whether dancer1 and dancer2 are neighbours
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



/// Return dancer from list of dancers for constant time
/// If there is no such dancer, behaviour is undefined
Dancer& Horo::getDancerByName(std::string name)
{
	return *dictionary[name];
}




/// Suggest d1 is leftNeighbour to d2
void Horo::printRelation(Dancer& d1, Dancer& d2) const
{
	std::cout << " ";
	if (d2.getHoldsLeft())
		std::cout << "<";
	std::cout << "--";
	
	if (d1.getHoldsRight())
		std::cout << ">";
	std::cout << " ";
}



/// \param firstDancers dancers to start the horo
/// \throw invalid_argument if given number of dancers is smaller than 3
Horo::Horo(std::vector<Dancer>& firstDancers) {
	if (firstDancers.size() < 3)
		throw std::invalid_argument("Too few dancers to create horo");
	
	auto iter = dancers.end(); // dancers.begin() == dancers.end()

	for (auto dancer : firstDancers) {
		iter = dancers.insert(iter, dancer);
		dictionary[dancer.name()] = iter;
		++iter;
	}
}



void Horo::printInfo(std::string name)
{
	Dancer dancer = getDancerByName(name);
	Dancer leftNeigh = leftNeighbour(dancer);
	Dancer rightNeigh = rightNeighbour(dancer);

	std::cout << leftNeigh.name() << " ";
	printRelation(leftNeigh, dancer);
	std::cout << dancer.name();
	printRelation(dancer, rightNeigh);
	std::cout << rightNeigh.name();
}






