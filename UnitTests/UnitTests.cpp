
#include "CppUnitTest.h"
#include "../Horo/Task.h"
#include "../Horo/TaskParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


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

};

