#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <vector>

int recursiveCall(int row, int column, char charNumber, char(&map)[59][59], char (&ninesMap)[59][59])
{
    int length = 59;

    std::string stringNumber = "";
    stringNumber += charNumber;
    int number = std::stoi(stringNumber);

    int solution = 0;

    if(row + 1 < length)
    {
        stringNumber = "";
        charNumber = map[row + 1][column];
        stringNumber += charNumber;
        int underNumber = std::stoi(stringNumber);

        if(underNumber == number + 1)
        {
            if(number + 1 == 9 && ninesMap[row + 1][column] != '9')
            {
                solution += 1;
                ninesMap[row + 1][column] = '9';
            }
            else
                solution += recursiveCall(row + 1, column, std::to_string(number + 1)[0], map, ninesMap);
        }
    }

    if(row - 1 >= 0)
    {
        stringNumber = "";
        charNumber = map[row - 1][column];
        stringNumber += charNumber;
        int aboveNumber = std::stoi(stringNumber);

        if(aboveNumber == number + 1)
        {
            if(number + 1 == 9 && ninesMap[row - 1][column] != '9')
            {
                solution += 1;
                ninesMap[row - 1][column] = '9';
            }
            else
                solution += recursiveCall(row - 1, column, std::to_string(number + 1)[0], map, ninesMap);
        }
    }

    if(column + 1 < length)
    {
        stringNumber = "";
        charNumber = map[row][column + 1];
        stringNumber += charNumber;
        int rightNumber = std::stoi(stringNumber);

        if(rightNumber == number + 1)
        {
            if(number + 1 == 9 && ninesMap[row][column + 1] != '9')
            {
                solution += 1;
                ninesMap[row][column + 1] = '9';
            }
            else
                solution += recursiveCall(row, column + 1, std::to_string(number + 1)[0], map, ninesMap);
        }
    }

    if(column - 1 >= 0)
    {
        stringNumber = "";
        charNumber = map[row][column - 1];
        stringNumber += charNumber;
        int leftNumber = std::stoi(stringNumber);

        if(leftNumber == number + 1)
        {
            if(number + 1 == 9 && ninesMap[row][column - 1] != '9')
            {
                solution += 1;
                ninesMap[row][column - 1] = '9';
            }
            else
                solution += recursiveCall(row, column - 1, std::to_string(number + 1)[0], map, ninesMap);
        }
    }

    return solution;
}

int main(int argc, char *argv[])
{
	unsigned long long solution = 0;

	std::string myline;

	std::ifstream myfile = std::ifstream(argv[1]);

    char map[59][59];
    char ninesMap[59][59];

	int row = 0;
	int column = 0;

    int length = 59;

    std::vector<int> scores;

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
            ninesMap[i][j] = '.';
    }

    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            if(map[i][j] == '0')
            {
                solution += recursiveCall(i, j, '0', map, ninesMap);
                for(int k = 0; k < length; k++)
                {
                    for(int l = 0; l < length; l++)
                        ninesMap[k][l] = '.';
                }
            }
        }
    }

	myfile.close();

	std::cout<<"Solution: "<<solution<<std::endl;

	return 0;
}