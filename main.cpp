#include <iostream>
#include <string>
#include <vector>

/// is_even main function
/// @param args the command line argument, excluding the path to the file itself
int do_main(const std::vector<std::string>& args)
{
  // zero arguments: user did not enter comman-line arguments
  if (argc != 1) return 1;
  const std::regex even("");

  try
  {
    std::cout << std::boolalpha << (std::stoi(argv[1]) % 2 != 0) << '\n';
  }
  catch (const std::invalid_argument&)
  {
    return 1;
  }
  catch (const std::out_of_range&)
  {
    return 1;
  }
}

/// is_even main function
int main(int argc, char* argv[]) 
{
  return do_main(std::vector<std::string>(argv + 1, argv + argc));
}
