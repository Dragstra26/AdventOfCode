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
				if((0 <= i + (i - row)) && (i + (i - row) < 50) && (0 <= j + (j - column)) && (j + (j - column) < 50))
					nodesMap[i + (i - row)][j + (j - column)] = '#';
				if((0 <= row + (row - i)) && (row + (row - i) < 50) && (0 <= column + (column - j)) && (column + (column - j) < 50))
					nodesMap[row + (row - i)][column + (column - j)] = '#';
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