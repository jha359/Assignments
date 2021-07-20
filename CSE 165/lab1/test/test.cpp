#include <igloo/igloo.h>
#include <mymath.h>

using namespace igloo;


Context(AdditionFunction){
	Spec(NegOnePlusOneIsZero){
		Assert::That(add(-1, 1), Equals(0));
	};

	Spec(TwoPlusOneIsThree){
		Assert::That(add(2, 1), Equals(3));
	};

	Spec(MinusTestOne)
	{
		Assert::That(sub(10, 3), Equals(7));
	};

	Spec(MinusTestTwo)
	{
		Assert::That(sub(-5, 3), Equals(-8));
	};

	Spec(MultTestOne)
	{
		Assert::That(mult(15, 6), Equals(90));
	};

	Spec(MultTestTwo)
	{
		Assert::That(mult(-5, 4), Equals(-20));
	};

	Spec(DivTestOne)
	{
		Assert::That(divide(10, 2), Equals(5));
	};

	Spec(DivTestTwo)
	{
		Assert::That(divide(37, 5), Equals(7));
	};

	Spec(RemainTestOne)
	{
		Assert::That(remain(41, 2), Equals(1));
	};

	Spec(RemainTestTwo)
	{
		Assert::That(remain(63, 5), Equals(3));
	};

	Spec(RemainTestThree)
	{
		Assert::That(remain(49, 7), Equals(0));
	};
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
