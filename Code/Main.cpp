

/*										 C S - C
		A B D U L   M A N A N   S H A H				2 0 i - 2 4 4 8
		M U H A M M A D   M O O S A					2 0 i - 2 3 0 7						*/


#include "OptimizedTree.h"
#include "UnOptimizedTree1.h"
#include "UnOptimizedTree2.h"
#include <fstream>



int main()
{
	string filename  = "\0";
	char data[100];
	data[0] = '\0';
	char tempData[100];
	tempData[0] = '\0';

						/*  original array with duplicate chars is named "data"
							the coressponding size is "size"						*/

						/*  array with non-duplicate chars is named "tempData"
							the corresponding frequency array is "frequencies"
							the coressponding size is "tempSize"					*/

	int size = 0;
	int tempSize = 0;			
	int* frequencies = NULL;

	bool bOoL = 0;		// check if file is read or not //



	cout << "\n\n\n\n";
	cout << " \t\t";
	cout << " --------------------------------------------------";
	cout << "--------------------------------------------------";
	cout << "--------------------------------------------------";
	cout << "\n\n";
	cout << " \t\t\t\t\t\t\t\t\t";
	cout << " H  U  F  F  M  A  N    A  L  G  O  R  I  T  H  M";
	cout << "\n\n";
	cout << " \t\t";
	cout << " --------------------------------------------------";
	cout << "--------------------------------------------------";
	cout << "--------------------------------------------------";
	cout << "\n\n\n";



							// READ & STORE DATA FROM FILE INTO STRING VAR //

	cout << "\t\t F I L E N A M E : ";
	cin >> filename;
	cout << "\n";

	ifstream file;
	file.open(filename, ios::in);
	if ( file.is_open() )
	{
		bOoL = 1;
		cout << "\t\t\t FILE FOUND & OPENED \n";
		while (!file.eof())
		{
			file.getline(data, 100);
		}
	}
	else
	{
		bOoL = 0;
		cout << "\t\t\t CORRUPT FILE \n";
	}

	file.close();



	if (bOoL == 1)
	{



						// REMOVE DUPLICATE CHARS & FIND FREQUENCIES //

		for (int i=0; i<100; i++)
		{
			tempData[i] = data[i];
		}

		size = strlen(tempData);

		for (int i=0; i<size; i++)
		{
			for (int j=i+1; j<size; j++)
			{
				if (tempData[i] == tempData[j])
				{
					tempData[j] = '~';		
					// assign '~' symbol to duplicate chars which we will delete in next step //
				}
			}
		}

		for (int i=0; i<size; i++)
		{
			if (tempData[i] == '~')
			{
				for (int j=i; j<size; j++)
				{
					tempData[j] = tempData[j+1];	// decreasing size of array //
				}
				i--;	// so that it doesn't skip the new value at that position //
			}
		}

		tempSize = strlen(tempData);	// size of array after deleting duplicates //
		frequencies = new int[tempSize];



							// ASCENDING ORDER //

		int j = 0;			
		char temp = '\0';
		for (int i=1; i<tempSize; i++)
		{
			temp = tempData[i];
			j = i-1;
			while ( j>=0 && tempData[j]>temp )
			{
				tempData[j+1] = tempData[j];
				j--;
			}
			tempData[j+1] = temp;
		}



							// FINDING FREQUENCIES //

		for (int i=0; i<tempSize; i++)
		{
			frequencies[i] = 0;
		}

		for (int i=0; i<tempSize; i++)		
		{
			for (int j=0; j<size; j++)
			{
				if (tempData[i] == data[j])
				{
					frequencies[i]++;
				}
			}
		}

		cout << endl << endl << endl;



		cout << "\t\t\t\t U N O P T I M I Z E D   M A X - P R I O R I T Y   Q U E U E   H U F F M A N ";
		cout << "\n\n";
		unoptimizedTree2 unoptimizedHuffman2(tempSize);

		unoptimizedHuffman2.buildHuffmanTree(tempData, frequencies);

		unoptimizedHuffman2.calculateCodes(unoptimizedHuffman2.getRoot(), "");

		unoptimizedHuffman2.printCodes();

		unoptimizedHuffman2.encodeDecode(data);

		unoptimizedHuffman2.bitRate_compressionRatio();

		cout << endl << endl << endl; 
		
		
		
		cout << "\t\t\t\t U N O P T I M I Z E D   Q U E U E   H U F F M A N" << endl << endl;

		unoptimizedTree1 unoptimizedHuffman1(tempSize);

		unoptimizedHuffman1.buildHuffmanTree(tempData, frequencies);

		unoptimizedHuffman1.calculateCodes(unoptimizedHuffman1.getRoot(), "");

		unoptimizedHuffman1.printCodes();

		unoptimizedHuffman1.encodeDecode(data);

		unoptimizedHuffman1.bitRate_compressionRatio();

		cout << endl << endl << endl;



		cout << "\t\t\t\t O P T I M I Z E D   M I N - P R I O R I T Y   Q U E U E   H U F F M A N";
		cout << "\n\n";

		optimizedTree optimizedHuffman(tempSize);

		optimizedHuffman.buildHuffmanTree(tempData, frequencies);

		optimizedHuffman.calculateCodes(optimizedHuffman.getRoot(), "");

		optimizedHuffman.printCodes();

		optimizedHuffman.encodeDecode(data);

		optimizedHuffman.bitRate_compressionRatio();

		cout << endl << endl << endl;

	}
							


	cout << "\n\n\n\n";
	return 0;
}


/*										  C S - C
		A B D U L   M A N A N   S H A H				2 0 i - 2 4 4 8
		M U H A M M A D   M O O S A					2 0 i - 2 3 0 7						*/