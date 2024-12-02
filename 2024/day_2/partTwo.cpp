#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

bool tester(std::vector<int> numberList)
{
	bool ascending = false;

	for(int i = 0; i < numberList.size() - 1; i++)
	{
		if(i == 0)
				ascending = (numberList[0] < numberList[1]);

		if(ascending)
		{
			if(!(numberList[i] < numberList[i + 1]) || !(3 >= numberList[i + 1] - numberList[i] >= 1))
				return false;
		}
		else
		{
			if(!(numberList[i] > numberList[i + 1]) || !(3 >= numberList[i] - numberList[i + 1] >= 1))
				return false;
		}
	}

	return true;
}


int main(int argc, char *argv[])
{
	std::string myline;
	std::string number;
	std::ifstream myfile = std::ifstream(argv[1]);

	int solution = 0;

	while(getline(myfile, myline))
	{
		int count = 0;
		std::vector<std::vector <int> > masterList;
		std::vector<int> tempList;

		std::stringstream ss(myline);
		while(ss >> myline)
			tempList.push_back(stoi(myline));

		for(int i = 0; i < tempList.size(); i++)
			masterList.push_back(tempList);

		for(int i = 0; i < masterList.size(); i++)
		{
			masterList[i].erase(masterList[i].begin() + i);
			if(tester(masterList[i]))
				count += 1;
		}

		if(count)
			solution += 1;
	}

	myfile.close();

	std::cout << "Solution: " << solution << std::endl;

	return 0;
}