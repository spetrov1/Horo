#include "Horo.h"

#include <cassert>

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
	assert(existsDancerByName(name));

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



/// Checks if dancer with the specified name exists
bool Horo::existsDancerByName(std::string dancer_name)
{
	return dictionary.find(dancer_name) != dictionary.end();
}


/// Checks if dancer is ready to be removed from the horo
/// Checks if dancer holds neighbours or is being holded by them
bool Horo::readyToLeave(Dancer& dancer)
{
	Dancer& leftNeigh = leftNeighbour(dancer);
	Dancer& rightNeigh = rightNeighbour(dancer);

	return !dancer.getHoldsLeft() && !dancer.getHoldsRight() &&
		!leftNeigh.getHoldsRight() &&
		!rightNeigh.getHoldsLeft();
}



/// Checks if given dancers are ready to be swapped
/// Checks if they are being holded by their neighbours
bool Horo::readyToBeSwapped(Dancer& dancer1, Dancer& dancer2)
{
	if (dancer1 == leftNeighbour(dancer2)) {
		return !
			( leftNeighbour(dancer1).getHoldsRight() ||
			dancer1.getHoldsLeft() ||
			rightNeighbour(dancer2).getHoldsLeft() ||
			dancer2.getHoldsRight()
			);
	}
	else if (dancer2 == leftNeighbour(dancer1)) {
		return !
			(leftNeighbour(dancer2).getHoldsRight() ||
				dancer2.getHoldsLeft() ||
				rightNeighbour(dancer1).getHoldsLeft() ||
				dancer1.getHoldsRight()
				);
	}

	// else given dancers are not neighbours

	return false;
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



/// Prints info about dancer with specified name
///     his neighbour and relations between them
/// \param name(nickname) of dancer
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



/// Release neighbour/neighbours
/// \param direction specify which neighbour/neighbours to release
/// \param dancer to do the action
void Horo::release(std::string name, const Direction& direction) {
	Dancer& dancer = getDancerByName(name);
	dancer.release(direction);
}



/// Grab neighbour/neighbours
/// \param direction specify which neighbour/neighbour to grab
/// \param dancer to do the action
void Horo::grab(std::string name, const Direction& direction)
{
	getDancerByName(name).grab(direction);
}


/// Insert new dancer in the horo between neighbours. \n
/// If left_dancer and right_dancer are not neighbours, error message is printed
///   to standard output.
/// \return true if operation is successful
bool Horo::add(std::string new_dancer_name, std::string left_dancer_name, std::string right_dancer_name)
{
	Dancer& dancer1 = getDancerByName(left_dancer_name);
	Dancer& dancer2 = getDancerByName(right_dancer_name);
	auto iter = dictionary[right_dancer_name];

	if (!areNeighbours(dancer1, dancer2)) {
		std::cout << "Trying to insert between dancers who are not neighbours \n";
		return false;
	}

	// Checks if left and right dancers order is incorrect
	if (leftNeighbour(dancer1) == dancer2) {
		iter = dictionary[left_dancer_name];
	}

	iter = dancers.insert(iter, Dancer(new_dancer_name));
	dictionary[new_dancer_name] = iter;
	dancer1.grab(Direction::RIGHT);
	dancer2.grab(Direction::LEFT);

	return true;
}


/// Remove dancer from the horo with the specified name. \n
/// \return If operation is successfull, true is returned
///    else false and error is printed to stdout
bool Horo::remove(std::string dancer_name)
{
	Dancer& dancer = getDancerByName(dancer_name);

	if (!readyToLeave(dancer)) {
		std::cout << "This won't be so easy! \n";
		return false;
	}

	dancers.erase(dictionary[dancer_name]);
	dictionary.erase(dancer_name);

	std::cout << dancer_name << " is free at last! \n";

	if (dancers.size() <= 2) {
		std::cout << ".... and the music stops!";
	}

	return true;
}



/// Swap given dancers if they are ready (not being holded by their neighbours)
/// \return true if operation is successfull
bool Horo::swap(std::string dancer1_name, std::string dancer2_name)
{
	Dancer& dancer1 = getDancerByName(dancer1_name);
	Dancer& dancer2 = getDancerByName(dancer2_name);

	if (!readyToBeSwapped(dancer1, dancer2)) {
		std::cout << "Couldn't swap " << dancer1_name
			<< " and " << dancer2_name << std::endl;

		return false;
	}

	std::swap(dictionary[dancer1_name], dictionary[dancer2_name]);
	std::swap(dancer1, dancer2);

	return true;
}







