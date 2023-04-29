#pragma once
#ifndef UNOPTIMIZEDTREE1_H_
#define UNOPTIMIZEDTREE1_H_
#include "Node.h"


// uses simple queues //
class unoptimizedTree1
{
	private:
		int size;
		node* root;
		node* nodes;
		string* codes;
		int* codeLength;
	public:
		unoptimizedTree1();
		unoptimizedTree1(int Size);
		node* getRoot();
		void buildHuffmanTree(char ch[], int freq[]);
		void calculateCodes(node* Root, string code);
		void printCodes();
		void encodeDecode(char data[]);
		void bitRate_compressionRatio();
};



#endif // !UNOPTIMIZEDTREE_H_
