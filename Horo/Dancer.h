#pragma once

#include <string>

enum class Direction {
	LEFT, RIGHT, BOTH
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
		if (d == Direction::LEFT) {
			holdsLeft = true;
		}
		else if (d == Direction::RIGHT) {
			holdsRight = true;
		}
		else {
			holdsLeft = true;
			holdsRight = true;
		}
		
	}



	/// Release neighbour
	/// \param neighbour to release
	void release(Direction d) {
		if (d == Direction::LEFT) {
			holdsLeft = false;
		}
		else if (d == Direction::RIGHT) {
			holdsRight = false;
		}
		else {
			holdsLeft = false;
			holdsRight = false;
		}
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
		std::cout << "holdsLeft = " << holdsLeft << " " 
			<< nickname << " "
			<< "holdsRight = " << holdsRight << std::endl;
	}


	/// We consider equal data member is not enough for equallity
	/// Dancers may be from different horos
	/// \return true if they are same objects
	bool operator==(const Dancer& other) {
		return this == &other;
	}

};

