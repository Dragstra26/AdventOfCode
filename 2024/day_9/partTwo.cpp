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
    std::vector<std::pair<int, int> > blockSize;
    std::vector<std::pair<int, int> > periodSize;

	getline(myfile, myline);

    int index = 0;
	
    for(int i = 0; i < myline.length(); i += 2)
    {
        int count = 0;

        int initialIndex = index;

        std::string charHolder  = "";
        charHolder += myline[i];
        
        for(int j = 0; j < std::stoi(charHolder); j++)
        {
            arranged.push_back(std::to_string(i / 2));
            count++;
            index++;
        }   

        std::pair<int, int> myPair(count, initialIndex);
        blockSize.push_back(myPair);

        count = 0;

        charHolder = "";
        
        if(i + 1 < myline.length() && myline[i + 1] != '0')
        {
            initialIndex = index;

            charHolder += myline[i + 1];

            for(int j = 0; j < std::stoi(charHolder); j++)
            {
                arranged.push_back(".");
                count++;
                index++;
            }

            std::pair<int, int> mySecondPair(count, initialIndex);
            periodSize.push_back(mySecondPair);
        }
    }

    int blockIndex = blockSize.size() - 1;

    sorted = arranged;

    for(int i = arranged.size() - 1; i > 0; i--)
    {
        if(arranged[i] != ".")
        {
            bool flag = false;

            for(int j = 0; periodSize[j].second < blockSize[blockIndex].second; j++)
            {
                if(blockSize[blockIndex].first <= periodSize[j].first)
                {
                    flag = true;

                    int startingIndex = periodSize[j].second;

                    for(int k = 0; k < blockSize[blockIndex].first; k++)
                    {
                        sorted[startingIndex] = arranged[i];
                        sorted[i] = ".";
                        i--;
                        startingIndex++;
                    }

                    if(blockSize[blockIndex].first == periodSize[j].first)
                        periodSize.erase(periodSize.begin() + j);
                    else
                    {
                        periodSize[j].first -= blockSize[blockIndex].first;
                        periodSize[j].second += blockSize[blockIndex].first;
                    }

                    break;
                }
            }
            
            if(!flag)
            {
                for(int k = 0; k < blockSize[blockIndex].first; k++)
                    i--;
            }

            i++;
            blockIndex--;
        }
    }

    int secondCount = 0;

    while(secondCount < sorted.size())
    {
        if(sorted[secondCount] != ".")
        {
            std::string charHolder  = "";
            charHolder += sorted[secondCount];
            solution += secondCount * std::stoi(charHolder);
        }
        secondCount++;
    }    

	myfile.close();

	std::cout<<"Solution: "<<solution<<std::endl;

	return 0;
}