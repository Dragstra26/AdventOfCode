#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <utility>

int runner(char map[130][130], int row, int column)
{
	std::set<std::pair<int, int> > visited;

	std::string direction = "up";

	while(true)
	{
		if(direction == "up")
		{
			while(row >= 0)
			{
				if(map[row][column] == '#')
				{
					direction = "right";
					row++;
					break;
				}

				std::pair<int, int> myPair = std::pair<int, int>(row, column);

				visited.insert(myPair);

				if(row == 0)
					return visited.size();

				row--;
			}
		}

		if(direction == "right")
		{
			while(column < 130)
			{
				if(map[row][column] == '#')
				{
					direction = "down";
					column--;
					break;
				}

				std::pair<int, int> myPair = std::pair<int, int>(row, column);

				visited.insert(myPair);

				if(column == 129)
					return visited.size();

				column++;
			}
		}

		if(direction == "down")
		{
			while(row < 130)
			{
				if(map[row][column] == '#')
				{
					direction = "left";
					row--;
					break;
				}

				std::pair<int, int> myPair = std::pair<int, int>(row, column);

				visited.insert(myPair);

				if(row == 129)
					return visited.size();

				row++;
			}
		}

		if(direction == "left")
		{
			while(column >= 0)
			{
				if(map[row][column] == '#')
				{
					direction = "up";
					column++;
					break;
				}

				std::pair<int, int> myPair = std::pair<int, int>(row, column);

				visited.insert(myPair);

				if(column == 0)
					return visited.size();

				column--;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	std::string myline;
	std::ifstream myfile = std::ifstream(argv[1]);

	char map[130][130];

	int solution = 0;

	int row = 0;
	int column = 0;

	while(getline(myfile, myline))
	{
		for(auto x : myline)
		{
			map[row][column] = x;
			column++;
		}

		column = 0;
		row++;
	}

	for(int i = 0; i < 130; i++)
	{
		for(int j = 0; j < 130; j++)
		{
			if(map[i][j] == '^')
			{
				solution = runner(map, i, j);
			}
		}
	}

	myfile.close();

	std::cout << "Solution: " << solution << std::endl;

	return 0;
}