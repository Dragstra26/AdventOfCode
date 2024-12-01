#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	std::string myline;
	std::ifstream myfile = std::ifstream(argv[1]);
	std::vector<int> leftNumbers;
	std::vector<int> rightNumbers;

	int length = 0;

	while(myfile >> myline)
	{
		length += 1;

		if(length % 2 == 1)
			leftNumbers.push_back(std::stoi(myline));
		else
			rightNumbers.push_back(std::stoi(myline));
	}

	myfile.close();

	length /= 2;

	std::sort(leftNumbers.begin(), leftNumbers.end());
	std::sort(rightNumbers.begin(), rightNumbers.end());

	int solution = 0;

	for(int i = 0; i < length; i++)
		solution += (std::abs(leftNumbers[i] - rightNumbers[i]));

	std::cout << "Solution: " << solution << std::endl;

	return 0;
}

	