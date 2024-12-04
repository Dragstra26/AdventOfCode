#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int positionChecker(int row, int column, char map[140][140])
{
	int result = 0;

	std::cout<<"Row: "<<row<<"\nColumn: "<<column<<std::endl;

	if(column >= 3 && map[row][column - 1] == 'M' && map[row][column - 2] == 'A' && map[row][column - 3] ==  'S')
	{
		std::cout<<"Right to Left"<<std::endl;
		result += 1;
	}

	if(column < 137 && map[row][column + 1] == 'M' && map[row][column + 2] == 'A' && map[row][column + 3] == 'S')
	{
		std::cout<<"Left to Right"<<std::endl;
		result += 1;
	}

	if(row >= 3 && map[row - 1][column] == 'M' && map[row - 2][column] == 'A' && map[row - 3][column] ==  'S')
	{
		std::cout<<"Bottom to Top"<<std::endl;
		result += 1;
	}

	if(row < 137 && map[row + 1][column] == 'M' && map[row + 2][column] == 'A' && map[row + 3][column] == 'S')
	{
		std::cout<<"Top to Bottom"<<std::endl;
		result += 1;
	}

	if(column >= 3 && row >= 3 && map[row - 1][column - 1] == 'M' && map[row - 2][column - 2] == 'A' && map[row - 3][column - 3] ==  'S')
	{
		std::cout<<"Middle to Top-Left"<<std::endl;
		result += 1;
	}

	if(column < 137 && row < 137 && map[row + 1][column + 1] == 'M' && map[row + 2][column + 2] == 'A' && map[row + 3][column + 3] ==  'S')
	{
		std::cout<<"Middle to Bottom-Right"<<std::endl;
		result += 1;
	}

	if(column >= 3 && row < 137 && map[row + 1][column - 1] == 'M' && map[row + 2][column - 2] == 'A' && map[row + 3][column - 3] ==  'S')
	{
		std::cout<<"Middle to Bottom-Left"<<std::endl;
		result += 1;
	}

	if(column < 137 && row >= 3 && map[row - 1][column + 1] == 'M' && map[row - 2][column + 2] == 'A' && map[row - 3][column + 3] ==  'S')
	{
		std::cout<<"Middle to Top-Right"<<std::endl;
		result += 1;
	}

	return result;
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

	for(int i = 0; i < 140; i++)
	{
		for(int j = 0; j < 140; j++)
		{
			if(map[i][j] == 'X')
				solution += positionChecker(i, j, map);
		}
	}

	std::cout << "Solution: " << solution << std::endl;

	return 0;
}