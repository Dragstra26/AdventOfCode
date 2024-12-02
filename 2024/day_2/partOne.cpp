#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	std::string myline;
	std::string number;
	std::ifstream myfile = std::ifstream(argv[1]);

	int solution = 0;

	while(getline(myfile, myline))
	{
		bool ascending = false;
		bool addToSolution = false;

		std::vector<int> numberList;

		std::stringstream ss(myline);

		while(ss >> number)
			numberList.push_back(std::stoi(number));

		int count = 0;

		for(int i = 0; i < numberList.size() - 1; i++)
		{
			if(i == 0)
			{
				if(numberList[0] == numberList [1])
					break;
				ascending = (numberList[0] < numberList [1]);
			}

			if(ascending)
			{
				if(numberList[i] < numberList[i + 1] && (3 >= numberList[i + 1] - numberList[i] >= 1))
					count += 1;
			}
			else
				if(numberList[i] > numberList[i + 1] && (3 >= numberList[i] - numberList[i + 1] >= 1))
					count += 1;

			if(count == numberList.size() - 1)
				addToSolution = true;
		}

		if(addToSolution)
			solution += 1;
	}

	myfile.close();

	std::cout << "Solution: " << solution << std::endl;

	return 0;
}

	