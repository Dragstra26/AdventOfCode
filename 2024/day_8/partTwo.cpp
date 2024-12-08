#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <vector>

void lineFinder(char targetCharacter, int row, int column, char (&nodesMap) [50][50], char charactersMap[50][50])
{
	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			if(charactersMap[i][j] == targetCharacter && (i != row && j != column))
			{
				int count = 0;

				while((0 <= i + count * (i - row)) && (i + count * (i - row) < 50) && (0 <= j + count * (j - column)) && (j + count * (j - column) < 50))
				{
					nodesMap[i + count * (i - row)][j + count * (j - column)] = '#';
					count++;
				}

				count = 0;
					
				while((0 <= row + count * (row - i)) && (row + count * (row - i) < 50) && (0 <= column + count * (column - j)) && (column + count * (column - j) < 50))
				{
					nodesMap[row + count * (row - i)][column + count * (column - j)] = '#';
					count++;
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	unsigned long long solution = 0;

	std::string myline;

	std::ifstream myfile = std::ifstream(argv[1]);

	char charactersMap[50][50];
	char nodesMap[50][50];

	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
			nodesMap[i][j] = '.';
	}

	int row = 0;

	while(getline(myfile, myline))
	{
		for(int i = 0; i < 50; i++)
		{
			charactersMap[row][i] = myline[i];
		}

		row++;
	}

	myfile.close();

	char targetCharacter;

	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			if(charactersMap[i][j] != '.')
			{
				targetCharacter = charactersMap[i][j];
				lineFinder(targetCharacter, i, j, nodesMap, charactersMap);
			}
		}
	}

	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			if(nodesMap[i][j] == '#')
			solution++;
		}
	}

	std::cout<<"Solution: "<<solution<<std::endl;

	return 0;
}