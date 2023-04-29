#pragma once
#ifndef NODE_H_
#define NODE_H_
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;



struct node
{
	char character;
	int frequency;
	node* left;
	node* right;

	node();
	node(char ch, int freq, node* l, node* r);
};



#endif // !NODE_H_
