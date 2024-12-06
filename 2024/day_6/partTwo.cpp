#include <cstdlib>
#include <fstream>
#include <iostream>
#include <utility>

int runner(char map[130][130], int row, int column)
{
	std::string direction = "up";

	bool edgeBlocker = false;

	int length = 130;
	int count = 0;
	int stuck = 0;
	int limit = length * length;

	int initialRow = row;
	int initialColumn = column;

	std::pair<int, int> blockadePosition;

	bool flag = true;

	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length; j++)
		{
			if(map[i][j] != '#')
			{
				map[i][j] = '#';
				blockadePosition.first = i;
				blockadePosition.second = j;
				i = length;
				break;
			}
		}
	}

	char copyMap[130][130];
	
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length; j++)
		{
			copyMap[i][j] = map[i][j];
		}
	}

	while(true)
	{
		if(direction == "up" && flag)
		{
			while(row >= 0)
			{
				count++;

				if(map[row][column] == '#')
				{
					direction = "right";
					row++;
					copyMap[row][column] = '>';
					break;
				}

				copyMap[row][column] = '|';

				if(row == 0)
				{
					count = 0;
					flag = false;
					break;
				}

				row--;
			}
		}

		if(direction == "right" && flag)
		{
			while(column < length)
			{
				count++;

				if(map[row][column] == '#')
				{
					direction = "down";
					column--;
					copyMap[row][column] = '`';
					break;
				}

				copyMap[row][column] = '-';

				if(column == length - 1)
				{
					count = 0;
					flag = false;
					break;
				}
				
				column++;
			}
		}

		if(direction == "down" && flag)
		{
			while(row < length)
			{
				count++;

				if(map[row][column] == '#')
				{
					direction = "left";
					row--;
					copyMap[row][column] = '<';
					break;
				}

				copyMap[row][column] = '|';

				if(row == length - 1)
				{
					count = 0;
					flag = false;
					break;
				}

				row++;
			}
		}

		if(direction == "left" && flag)
		{
			while(column >= 0)
			{
				count++;

				if(map[row][column] == '#')
				{
					direction = "up";
					column++;
					copyMap[row][column] = '^';
					break;
				}

				copyMap[row][column] = '-';

				if(column == 0)
				{
					count = 0;
					flag = false;
					break;
				}

				column--;
			}
		}

		if(!flag || count > limit)
		{
			if(count > limit)
				stuck++;

			if(blockadePosition.first + blockadePosition.second == length * 2 - 2)
				break;

			map[blockadePosition.first][blockadePosition.second] = '.';

			if(blockadePosition.second == length - 1)
			{
				if(!edgeBlocker)
					blockadePosition.first++;
				else
					edgeBlocker = false;

				blockadePosition.second = -1;
			}

			for(int i = blockadePosition.first; i < length; i++)
			{
				for(int j = blockadePosition.second + 1; j < length; j++)
				{
					if(map[i][j] != '#' && map[i][j] != '^')
					{
						map[i][j] = '#';
						blockadePosition.first = i;
						blockadePosition.second = j;
						i = length;
						break;
					}
					else if(map[i][j] == '#' && j == 129)
						edgeBlocker = true;
				}
			}

			for(int i = 0; i < length; i++)
			{
				for(int j = 0; j < length; j++)
				{
					copyMap[i][j] = map[i][j];
				}
			}

			row = initialRow;
			column = initialColumn;
			direction = "up";

			count = 0;
			flag = true;
		}
	}

	return stuck;
}

int main(int argc, char *argv[])
{
	std::string myline;
	std::ifstream myfile = std::ifstream(argv[1]);

	int length = 130;

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

	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < length; j++)
		{
			if(map[i][j] == '^')
				solution = runner(map, i, j);
		}
	}

	myfile.close();

	std::cout << "Solution: " << solution << std::endl;

	return 0;
}