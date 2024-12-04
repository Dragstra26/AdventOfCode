#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

bool positionChecker(int row, int column, char map[140][140])
{
	if((139 > column > 0) || (139 > row > 0))
	{
		if((map[row - 1][column - 1] == 'M') && (map[row + 1][column + 1] == 'S') &&
		(map[row - 1][column + 1] ==  'M') && (map[row + 1][column - 1] ==  'S'))
		{
			/*
			   M M
				A
			   S S
			*/

			std::cout<<"Coords: "<<row<<", "<<column<<std::endl;
			std::cout<<"Two top M"<<std::endl;
			return 1;
		}

		if((map[row - 1][column + 1] == 'M') && (map[row - 1][column - 1] == 'S') &&
		(map[row + 1][column + 1] ==  'M') && (map[row + 1][column - 1] ==  'S'))
		{
			/*
			   S M
				A
			   S M
			*/

			std::cout<<"Coords: "<<row<<", "<<column<<std::endl;
			std::cout<<"Two right M"<<std::endl;
			return 1;
		}

		if((map[row + 1][column + 1] == 'M') && (map[row - 1][column - 1] == 'S') &&
		(map[row + 1][column - 1] ==  'M') && (map[row - 1][column + 1] ==  'S'))
		{
			/*
			   S S
				A
			   M M
			*/

			std::cout<<"Coords: "<<row<<", "<<column<<std::endl;
			std::cout<<"Two bottom M"<<std::endl;
			return 1;
		}

		if((map[row + 1][column - 1] == 'M') && (map[row - 1][column + 1] == 'S') &&
		(map[row - 1][column - 1] ==  'M') && (map[row + 1][column + 1] ==  'S'))
		{
			/*
			   M S
				A
			   M S
			*/

			std::cout<<"Coords: "<<row<<", "<<column<<std::endl;
			std::cout<<"Two left M"<<std::endl;
			return 1;
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	std::string myline;
	std::string number;
	std::ifstream myfile = std::ifstream(argv[1]);

	int solution = 0;
	char map[140][140];

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

	myfile.close();

	for(int i = 1; i < 139; i++)
	{
		for(int j = 1; j < 139; j++)
		{
			if(map[i][j] == 'A')
				solution += positionChecker(i, j, map);
		}
	}

	std::cout << "Solution: " << solution << std::endl;

	return 0;
}