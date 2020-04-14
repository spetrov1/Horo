
#include "CppUnitTest.h"
#include "../Horo/Task.h"
#include "../Horo/TaskParser.h"

#include "../Horo/Horo.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// ASK TODO tests in different .cpp files ?


/*
TEST_CLASS(HoroTests) {
private:
	// Horo horo;
	Dancer d1;
	Dancer d2;
	Dancer d3;
	Dancer d4;
	std::vector<Dancer> dancers;

public:
	HoroTests() : d1("Slavcho"), d2("Goliama riba"), d3("Georgi"), d4("Atanas")
	{
		dancers.push_back(d1);
		dancers.push_back(d2);
		dancers.push_back(d3);
		dancers.push_back(d4);
	}

	TEST_METHOD(SomeTestMethod) {
		// Horo horo(dancers);
		// TODO
	}

	TEST_METHOD(SomeTestMethod2) {
		// Horo horo(dancers);
		// TODO
	}

	
};
*/


TEST_CLASS(TaskParserTests)
{
private:
	TaskParser parser;
	
public:
	
	TEST_METHOD(TwoSimpleArgumentsCorrectVerbIsReturned)
	{
		
		std::string input = "add who1 who2";
		Task result = parser.parse(input);
		std::string expected = "add";

		Assert::AreEqual(expected, result.verb());
	}

	TEST_METHOD(TwoComplexArgumentsCorrectVerbIsReturned) {
		std::string input = "add 'who1.1 who1.2' who2";
		Task result = parser.parse(input);
		std::string expected = "add";

		Assert::AreEqual(expected, result.verb());
	}


	TEST_METHOD(OneComplexAndOneSimpleArgumentCorrectVerbIsReturned) {
		std::string input = "swap 'who1.1 who1.2' who2";
		Task result = parser.parse(input);
		std::string expected = "swap";

		Assert::AreEqual(expected, result.verb());
	}


	TEST_METHOD(ExpectedNumberOfArgumentsIsReturned) {
		std::string input = "add who1 who2";
		Task task = parser.parse(input);

		Assert::AreEqual((size_t)2, task.numberOfArgs());
	}

	TEST_METHOD(ReturnFirstArgumentExpectedIsReturned) {
		std::string input = "add who1 who2";
		Task task = parser.parse(input);
		std::string expected = "who1";

		Assert::AreEqual(expected, task.argument(1));
	}


	TEST_METHOD(ReturnSecondArgumentExpectedIsReturned) {
		std::string input = "add who1 who2";
		Task task = parser.parse(input);
		std::string expected = "who2";

		Assert::AreEqual(expected, task.argument(2));
	}


	TEST_METHOD(ReturnFirstComplexArgumentExpectedIsReturned) {
		std::string input = "add \"ana banana\" haimanata";
		Task task = parser.parse(input);
		std::string expected = "ana banana";

		Assert::AreEqual(expected, task.argument(1));
	}


	TEST_METHOD(ReturnSecondComplexArgumentExpectedIsReturned) {
		std::string input = "add \"ana banana\" \"haimanata 2\" ";
		Task task = parser.parse(input);
		std::string expected = "haimanata 2";

		Assert::AreEqual(expected, task.argument(2));
	}

	TEST_METHOD(OneArgumentTaskCorrectTaskIsCreated) {
		std::string input = "info \"haimanata 2\" ";
		Task task = parser.parse(input);
		std::string expected = "haimanata 2";

		Assert::AreEqual(expected, task.argument(1));
	}
	
};



