#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <memory.h>
#include <conio.h>

int main()
	{
	const int numCols(50);
	const int numRows(50);
	int startingPoints;
	int col, row;
	bool currentGen[numRows+2] [numCols+2];
	bool nextGen[numRows+2] [numCols+2];
	int Generation(0);
	time_t stopTime;
	time_t waitTime(2);

	memset (currentGen, false, (numRows+2) * (numCols+2) * sizeof(bool));	//set all current gen to dead
	memset (nextGen, false, (numRows+2) * (numCols+2) * sizeof(bool));		//set all next gen to dead

	srand( time (NULL) );  // seed srand

	std::cout << "How many live cell do you want to start with: ";
	std::cin >> startingPoints;
	std::cout << std::endl;

	for( int i = 0; i < startingPoints; i++ )
	{
	col = rand() % numCols + 1;
	row = rand() % numRows + 1;
	currentGen[row][col] = true;
	}
	for(;;)
		{
		system("cls");
		std::cout << "\tGeneration: "<< Generation << std::endl;
		for (row = 1; row <= numRows; row++)
			{
			for(col = 1; col <= numCols; col++)
				std::cout << (currentGen [row] [col] ? '*' : ' ' );
			std::cout<< std::endl;
			}

		for(int row = 1; row <= numRows; row++)
			{
			for (int col = 1; col <= numCols; col++)
				{
				int cellCount(0);
				if (currentGen [row - 1] [col - 1] == 1)
					cellCount++;
				if (currentGen [row - 1] [col] == 1)
					cellCount++;
				if (currentGen [row - 1] [col + 1] == 1)
					cellCount++;
				if (currentGen [row] [col - 1] == 1)
					cellCount++;
				if (currentGen [row] [col + 1] == 1)
					cellCount++;
				if (currentGen [row + 1] [col - 1] == 1)
					cellCount++;
				if (currentGen [row + 1] [col] == 1)
					cellCount++;
				if (currentGen [row + 1] [col + 1] == 1)
					cellCount++;

				if(currentGen[row][col] == 1)
					{
					if(cellCount <= 1 || cellCount >= 4)
						nextGen[row][col] = 0;
//					if(cellCount >= 4)
//						nextGen[row][col] = 0;
					else
						nextGen[row][col] = 1;
					}
				if(currentGen[row][col] == 0)
					{
					if(cellCount == 3)
						nextGen[row][col] = 1;
					else
						nextGen[row][col] = 0;
					}
				}
			}
			memcpy(currentGen, nextGen, (numRows + 2)*(numCols + 2) * sizeof(bool));
			Generation++;
			stopTime = time(0) + waitTime;
			while (time(0) < stopTime);
			if( _kbhit())
				exit(0);
			else;	
		}
	}

		
	

