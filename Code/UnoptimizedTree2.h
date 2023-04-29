#pragma once
#ifndef UNOPTIMIZEDTREE2_H_
#define UNOPTIMIZEDTREE2_H
#include "Node.h"


// uses max-priority queue //
class condition2
{
	public:
		bool operator()(node* node1, node* node2)
		{
			if ( node1->frequency < node2->frequency )
			{
				return 1;
			}
			else if ( node1->frequency > node2->frequency )
			{
				return 0;
			}
			else
			{
				if( node1->character < node2->character )
				{	 
					return 1;
				}
				else
				{
					return 0;
				}
		}
	}
};



class unoptimizedTree2
{
	private:
		int size;
		node* root;
		node* nodes;
		string* codes;
		int* codeLength;
	public:
		unoptimizedTree2();
		unoptimizedTree2(int Size);
		node* getRoot();
		void buildHuffmanTree(char ch[], int freq[]);
		void calculateCodes(node* Root, string code);
		void printCodes();
		void encodeDecode(char data[]);
		void bitRate_compressionRatio();
};



#endif