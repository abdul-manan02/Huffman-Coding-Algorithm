#include "Node.h"



node::node()
{
	character = '\0';
	frequency = 0;
	left = right = NULL;
}

node::node(char ch, int freq, node* l, node* r)
{
	character = ch;
	frequency = freq;
	left = l;
	right = r;
}