#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <vector>

bool myRecursiveFunction(std::pair<unsigned long long, std::vector<int> > x, int index, unsigned long long number, std::string myOperator)
{
	if(myOperator == "mult")
		number *= x.second[index];
	else if(myOperator == "add")
		number += x.second[index];
	else
	{
		std::string stringNumber = std::to_string(number);
		stringNumber += std::to_string(x.second[index]);
		number = std::stoll(stringNumber);
	}

	if(index < x.second.size() - 1)
	{
		return(myRecursiveFunction(x, index + 1, number, "add") || myRecursiveFunction(x, index + 1, number, "mult")
			|| myRecursiveFunction(x, index + 1, number, "cat"));
	}
	else
	{
		if(number == x.first)
			return true;
		else
			return false;
	}
}

int main(int argc, char *argv[])
{
	unsigned long long solution = 0;

	std::string myline;

	std::ifstream myfile = std::ifstream(argv[1]);

	std::vector<std::pair<unsigned long long, std::vector<int> > >numberLists;

	while(getline(myfile, myline))
	{
		std::stringstream ss(myline);
		std::pair<unsigned long long, std::vector<int> > pushMe;
		std::vector<int> holder;
		std::string targetString = "";

		ss >> myline;

		for(int i = 0; i < myline.length() - 1; i++)
			targetString += myline[i];

		pushMe.first = std::stoll(targetString);

		while(ss >> myline)
			holder.push_back(std::stoi(myline));

		pushMe.second = holder;

		numberLists.push_back(pushMe);
	}

	myfile.close();

	for(auto x : numberLists)
	{
		if(myRecursiveFunction(x, 1, x.second[0], "add") || myRecursiveFunction(x, 1, x.second[0], "mult") ||
			myRecursiveFunction(x, 1, x.second[0], "cat"))
			solution += x.first;
	}

	std::cout<<"Solution: "<<solution<<std::endl;

	return 0;
}