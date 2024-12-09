#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <vector>

int main(int argc, char *argv[])
{
	unsigned long long solution = 0;

	std::string myline;

	std::ifstream myfile = std::ifstream(argv[1]);

    std::vector<std::string> arranged;
    std::vector<std::string> sorted;

    int count;

	getline(myfile, myline);
	
    for(int i = 0; i < myline.length(); i += 2)
    {
        std::string charHolder  = "";
        charHolder += myline[i];
        
        for(int j = 0; j < std::stoi(charHolder); j++)
            arranged.push_back(std::to_string(i / 2));

        charHolder = "";
        
        if(i + 1 < myline.length())
        {
            charHolder += myline[i + 1];

            for(int j = 0; j < std::stoi(charHolder); j++)
            {
                arranged.push_back(".");
                count++;
            }
        }
    }

    sorted = arranged;
    
    for(int i = arranged.size() - 1; i > arranged.size() - count - 1; i--)
    {
        if(arranged[i] != ".")
        {
            for(int j = 0; j < sorted.size(); j++)
            {
                if(sorted[j] == ".")
                {
                    sorted[j] = sorted[i];
                    sorted[i] = ".";
                    break;
                }
            }
        }
    }

    int secondCount = 0;

    while(sorted[secondCount] != ".")
    {
        std::string charHolder  = "";
        charHolder += sorted[secondCount];

        solution += secondCount * std::stoi(charHolder);
        secondCount++;
    }

	myfile.close();

	std::cout<<"Solution: "<<solution<<std::endl;

	return 0;
}