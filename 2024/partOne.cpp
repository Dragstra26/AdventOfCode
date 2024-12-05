#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	int solution = 0;

	std::string myline;

	std::ifstream secondfile = std::ifstream(argv[2]);

	while(getline(secondfile, myline))
	{

		std::ifstream firstfile = std::ifstream(argv[1]);

		std::vector<int> updateOrder;
		std::vector<int> order;

		std::string numberString = "";

		for(auto x : myline)
		{
			if(x == ',')
			{
				updateOrder.push_back(std::stoi(numberString));
				numberString = "";
				continue;
			}

			numberString += x;
		}

		updateOrder.push_back(std::stoi(numberString));

		order = updateOrder;

		while(getline(firstfile, myline))
		{

			bool flag = false;

			std::string firstNumberString = "";
			std::string secondNumberString = "";

			for(auto x : myline)
			{
				if(x == '|')
				{
					flag = true;
					continue;
				}

				if(!flag)
					firstNumberString += x;

				else
					secondNumberString += x;
			}

			int firstNumber = std::stoi(firstNumberString);
			int secondNumber = std::stoi(secondNumberString);

			if(std::find(updateOrder.begin(), updateOrder.end(), firstNumber) != updateOrder.end() &&
				std::find(updateOrder.begin(), updateOrder.end(), secondNumber) != updateOrder.end())

			{
				std::vector<int>::iterator firstIterator = std::find(order.begin(), order.end(), firstNumber);
				std::vector<int>::iterator secondIterator = std::find(order.begin(), order.end(), secondNumber);

				int firstIndex = std::distance(order.begin(), firstIterator);
				int secondIndex = std::distance(order.begin(), secondIterator);

				if(firstIndex > secondIndex)
				{
					int temp = order[secondIndex];
					order[secondIndex] = order[firstIndex];
					order[firstIndex] = temp;

					for(int i = firstIndex; i > secondIndex + 1; i--)
					{
						temp = order[i - 1];
						order[i - 1]  = order[i];
						order[i] = temp;
					}
				}
			}
		}

		firstfile.close();

		firstfile = std::ifstream(argv[1]);

		while(getline(firstfile, myline))
		{

			bool flag = false;

			std::string firstNumberString = "";
			std::string secondNumberString = "";

			for(auto x : myline)
			{
				if(x == '|')
				{
					flag = true;
					continue;
				}

				if(!flag)
					firstNumberString += x;

				else
					secondNumberString += x;
			}

			int firstNumber = std::stoi(firstNumberString);
			int secondNumber = std::stoi(secondNumberString);

			if(std::find(updateOrder.begin(), updateOrder.end(), firstNumber) != updateOrder.end() &&
				std::find(updateOrder.begin(), updateOrder.end(), secondNumber) != updateOrder.end())

			{
				std::vector<int>::iterator firstIterator = std::find(order.begin(), order.end(), firstNumber);
				std::vector<int>::iterator secondIterator = std::find(order.begin(), order.end(), secondNumber);

				int firstIndex = std::distance(order.begin(), firstIterator);
				int secondIndex = std::distance(order.begin(), secondIterator);

				if(firstIndex > secondIndex)
				{
					int temp = order[secondIndex];
					order[secondIndex] = order[firstIndex];
					order[firstIndex] = temp;

					for(int i = firstIndex; i > secondIndex + 1; i--)
					{
						temp = order[i - 1];
						order[i - 1]  = order[i];
						order[i] = temp;
					}					
				}
			}
		}

		int count = 0;

		for(std::vector<int>::iterator it = std::find(order.begin(), order.end(), updateOrder[0]); it != order.end(); it++)
		{
			if(std::find(it, order.end(), updateOrder[count]) != order.end())
			{
				it = std::find(it, order.end(), updateOrder[count]);
				count++;
			}
		}

		if(count == updateOrder.size())
			solution += updateOrder[updateOrder.size() / 2];

		firstfile.close();
	}

	secondfile.close();

	std::cout<<"Solution: "<<solution<<std::endl;

	return 0;
}