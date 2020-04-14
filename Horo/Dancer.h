#pragma once

#include <string>

enum class Direction {
	LEFT, RIGHT
};

/// Dancer in Horo
class Dancer
{
private:
	std::string nickname; /// nickname/label of the dancer
	bool holdsLeft;		  /// Whether he holds the left neighbour(dancer)
	bool holdsRight;	  /// Whether he holds the right neighbour(dancer)
	// ASK is it ok to has pointer to horo

public:

	/// Construct the dancer as he holds the two neighbours
	/// Every horo starts with dancers holding their neighbours
	Dancer(std::string nickname)
		: nickname(nickname), holdsLeft(true), holdsRight(true)
	{}



	// ASK not needed copy constr, operator=, destr
	
	/// Grab neighbour
	/// \param neighbour to grab
	void grab(Direction d) {
		if (d == Direction::LEFT)
			holdsLeft = true;
		
		else if (d == Direction::RIGHT)
			holdsRight = true;
		
	}



	/// Release neighbour
	/// \param neighbour to release
	void release(Direction d) {
		if (d == Direction::LEFT)
			holdsLeft = false;
		else if (d == Direction::RIGHT)
			holdsRight = false;
	}



	/// Return name/nickname/label of dancer
	std::string name() const {
		return nickname;
	}



	/// Checks whether hold his left neighbour
	bool getHoldsLeft() const {
		return holdsLeft;
	}



	/// ChecksWhether hold his right neighbour
	bool getHoldsRight() const {
		return holdsRight;
	}


	// print to test
	void print() const {
		std::cout << holdsLeft << " " << nickname << " " << holdsRight << std::endl;
	}

};

