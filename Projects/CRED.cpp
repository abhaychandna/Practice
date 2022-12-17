// CRED.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    class ComplexNumberTest : public CppUnit::TestCase {
    public:
        ComplexNumberTest(std::string name) : CppUnit::TestCase(name) {}

        void runTest() {
            CPPUNIT_ASSERT(Complex(10, 1) == Complex(10, 1));
            CPPUNIT_ASSERT(!(Complex(1, 1) == Complex(2, 2)));
        }
    };
    int n = 1;
    n++;
    std::cout << "Hello World!\n" << n;
}
