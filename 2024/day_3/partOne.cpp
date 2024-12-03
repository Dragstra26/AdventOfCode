#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	std::string myline;
	std::string number;
	std::ifstream myfile = std::ifstream(argv[1]);

	int solution = 0;

	while(getline(myfile, myline))
	{
		std::string construction = "";

		for(int i = 0; i < myline.size(); i++)
		{
			char character = myline[i];

			if(character == 'm' && i != myline.size() - 1)
			{
				 std::string::iterator it;
				 it = std::find(myline.begin() + i, myline.end(), ')');

				 int myRange = std::distance(myline.begin() + i, it) - 1;

				 if(it != myline.end())
				 {
				 	if(myline[i + 1] == 'u' && myline[i + 2] == 'l' && myline[i + 3] == '(')
				 	{
				 		std::string numberLine = "";

				 		for(int j = 4; j <= myRange; j++)
				 		{
				 			char x = myline[i + j];
				 			if(x == '0' || x == '1' || x == '2' || x == '3' || x == '4'
				 				|| x == '5' || x == '6' || x == '7' || x == '8' || x == '9' || x == ',')
				 			{
				 				numberLine += x;
				 			}
				 			else
				 				break;

				 			if(j == myRange)
				 			{
				 				std::string firstNumberString = "";
				 				std::string secondNumberString = "";

				 				bool comma = false;

				 				for(auto y : numberLine)
				 				{
				 					if(y == ',')
				 					{
				 						comma = true;
				 						continue;
				 					}

				 					if(!comma)
				 						firstNumberString += y;
				 					else
				 						secondNumberString += y;
				 				}

				 				if(firstNumberString == "" || secondNumberString == "")
				 					break;

				 				int firstNumber = std::stoi(firstNumberString);
				 				int secondNumber = std::stoi(secondNumberString);

				 				int finalResult = firstNumber * secondNumber;

				 				solution += finalResult;
				 			}
				 		}
				 	}
				 }
			}
		}
	}

	myfile.close();

	std::cout << "Solution: " << solution << std::endl;

	return 0;
}