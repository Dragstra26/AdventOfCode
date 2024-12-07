#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <vector>

bool myRecursiveFunction(std::pair<unsigned long long, std::vector<int> > x, int index, unsigned long long number, bool multiply)
{
	if(multiply)
		number *= x.second[index];
	else
		number += x.second[index];

	if(index < x.second.size() - 1)
	{
		return(myRecursiveFunction(x, index + 1, number, false) || myRecursiveFunction(x, index + 1, number, true));
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
		if(myRecursiveFunction(x, 1, x.second[0], false) || myRecursiveFunction(x, 1, x.second[0], true))
			solution += x.first;
	}

	std::cout<<"Solution: "<<solution<<std::endl;

	return 0;
}