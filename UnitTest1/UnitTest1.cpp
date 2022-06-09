#include "pch.h"
#include "CppUnitTest.h"
#include "../6.5/6.5.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;
			Elem* first1 = NULL,
				* last1 = NULL;

			readTXT(first, last, first1, last1);

			print(first);
		}
	};
}
