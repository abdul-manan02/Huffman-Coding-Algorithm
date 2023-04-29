#include "UnOptimizedTree1.h"



unoptimizedTree1 :: unoptimizedTree1()
{
	root = NULL;
	nodes = NULL;
	codes = NULL;
	codeLength = NULL;
	size = 0;
}



unoptimizedTree1 :: unoptimizedTree1(int Size)
{
	root = NULL;
	size = Size;
	codes = new string[size];
	nodes = new node[size];
	codeLength = new int[size];
}



node* unoptimizedTree1 :: getRoot()
{
	return root;
}



void unoptimizedTree1 :: buildHuffmanTree(char ch[], int freq[])
{
	node* left = NULL;
	node* right = NULL;
	node* parent = NULL;

	queue < node* > Queue;
	// a simple queue containing all the leaf ndoes 

	for (int i = 0; i < size; i++)
	{
		nodes[i].character = ch[i];
		nodes[i].frequency = freq[i];
		nodes[i].left = nodes[i].right = NULL;
		// push every node into heap, the first node pushed becomes the top //
		Queue.push(&nodes[i]);
	}

	while ( Queue.size()!=1 )
	{
		left = Queue.front();
		Queue.pop();

		//		a queue's pop function only deletes the value at the top, it does not 
		//				fetch it so that's why i used top & pop 

		right = Queue.front();
		Queue.pop();

		parent = new node('~', left->frequency + right->frequency, left, right);
		// internal nodes will have '~' as char

		//		the parent node which is pointing to the left & right nodes is now
		//				pushed to the queue while the two left & right nodes are
		//							popped so size decreases by 1		
		Queue.push(parent);
	}
	//		once the huffman tree has been compeltely constructed, the private data member root
	//							is pointed to the root of that tree
	root = Queue.front();
}



void unoptimizedTree1 :: calculateCodes(node* Root, string code)
{
	if (Root == NULL)	// no tree exists //
	{
		return;
	}

	if (Root->character != '~')		// not internal node //
	{
		for (int j = 0; j < size; j++)
		{
			// if the "Root" that we are pointing to has the same character as the 
			// character in the "nodes" array, take the index of that node and save
			// that code on the same index of the "codes" array
			if (Root->character == nodes[j].character)
			{
				codes[j] = code;
				break;
			}
		}
	}

	calculateCodes(Root->left, code + "0");	// Add a 0 if going left //
	calculateCodes(Root->right, code + "1");	// Add a 1 if going right //
}



void unoptimizedTree1 :: printCodes()
{
	cout << "\n";
	cout << "\t\t\t\t\t C O D E S \n";

	for (int i = 0; i < size; i++)
	{
		cout << "\t\t\t\t\t           ";
		cout << nodes[i].character << " : " << codes[i] << endl;
	}

	cout << "\n";
}



void unoptimizedTree1 :: encodeDecode(char data[])
{
	string encodedData = "\0";
	string decodedData = "\0";
	int dataLength = strlen(data);
	int encodedLength = 0;
	node* tempNode = NULL;

	for (int i = 0; i < dataLength; i++)
	{
		for (int j = 0; j < size; j++)
		{
			// search for the data character in the "nodes" array
			// if found, take that node index, fetch the code 
			// for that index from the "codes" array
			// concatenate it to the "encodedData"
			if (data[i] == nodes[j].character)
			{
				encodedData += codes[j];
				break;
			}
		}
	}

	encodedLength = encodedData.size();
	tempNode = root;

	for (int i = 0; i < encodedLength; i++)
	{
		if (tempNode)
		{

			// if we encounter 0, go left
			// if we encounter 1, go right
			// if we encounter leaf-node, add the char of that leaf node to "decodedData"
			// point the "tempNode" to root of Huffman Tree
			// keep doing this until the last character of "encodedLength" has been read

			if (encodedData[i] == '0')
			{
				tempNode = tempNode->left;
			}
			else if (encodedData[i] == '1')
			{
				tempNode = tempNode->right;
			}

			if (tempNode != NULL && tempNode->left == NULL && tempNode->right == NULL)
			{
				decodedData += tempNode->character;
				tempNode = root;
			}
		}
	}

	cout << "\n";
	cout << "\t\t\t\t\t E N C O D E D \n";
	cout << "\t\t\t\t\t               " << encodedData << endl;
	cout << "\n\n";

	cout << "\t\t\t\t\t D E C O D E D \n";
	cout << "\t\t\t\t\t               " << decodedData << endl;
	cout << "\n";
}



void unoptimizedTree1 :: bitRate_compressionRatio()
{
	float bitRate = 0;
	float temp = 0;
	float ratio = 0;
	int totalFrequency = 0;

	for (int i = 0; i < size; i++)
	{
		codeLength[i] = codes[i].size();
		temp += (codeLength[i] * nodes[i].frequency);
		totalFrequency += nodes[i].frequency;
	}

	// Total Frequency = number of characters in file
	bitRate = temp / totalFrequency;

	ratio = 8 / bitRate;

	cout << "\t\t\t\t\t C O M P R E S S I O N   R A T I O \n";
	cout << "\t\t\t\t\t\t\t                   " << ratio << "\n\n";
}