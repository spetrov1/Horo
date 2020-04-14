#pragma once

#include <cassert>
#include <vector>


/// Task prepared for Horo running in Application
/// Task (command) consists of verb + arguments
class Task
{
public:
	std::vector<std::string> data; /// Task elements as vector's elements

public:
	Task(std::vector<std::string>& _data) : data(_data) 
	{}

	std::string verb() const {
		return data[0];
	}

	std::string argument(size_t arg_index) const {
		assert(arg_index >= 1);

		return data[arg_index];
	}

	size_t numberOfArgs() const {
		return data.size() - 1;
	}
};

