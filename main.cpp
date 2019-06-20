#include <stdexcept>
#include <vector>
#include <iostream>
#include <regex>
#include <string>


/// Function to determine if a string is a number
bool isNumber(const std::string &argument) noexcept
{

    // A number is a series of one or more digits that may or may not start with a minus
    const std::regex numberRgx("(\\-|)[[:digit:]]+");

    return std::regex_match(argument, numberRgx);
}


/// Function to run the program
int doMain(const std::vector<std::string> &args)
{
    try{

        // There should be exactly one argument provided
        if (args.size() != 2u) throw std::runtime_error("Error: Invalid number of arguments.");

        // The argument should be a number
        if (!isNumber(args[1u])) throw std::runtime_error("Error: Argument is not a number.");

        // Extract the last digit
        const int lastDigit = int(args[1u].back());

        // Is the last digit even? Show the result
        lastDigit % 2 == 0 ? std::cout << "true" : std::cout << "false";

    }
    catch (const std::exception &err)
    {
        std::cout << err.what() << '\n';
        return 1;
    }

    return 0;
}


/// Function to test the task performing behavior of the program
void testUse()
{
    
}


/// Function to test the error handling behavior of the program
void testAbuse()
{
    
}

/// Function to test the program
void test()
{
    testUse();
    testAbuse();
}


/// Program to determine if a number is even
int main(int argc, char * argv[])
{

    // Preparation
    const std::vector<std::string> args(argv, argv + argc);
    
    // Test the program
    test();

    // Run the program
    return doMain(args);

}