#include "pch.h"
#include <iostream>
#include "AD_Problem3.h"
#include <queue>


#ifndef NULL
#define NULL 0
#endif
int flag = 0;

struct TreeWrapper
{
	TreeWrapper()
	{
		tree = NULL;
	}
	TreeWrapper(Tree* t)
	{
		tree = t;
	}
	bool operator<(const TreeWrapper &tw) const 
	{
		return tree->getWeight() > tw.tree->getWeight();
	}
	Tree* tree;
};

int main()
{
	priority_queue<TreeWrapper> q;
	priority_queue<char> cq;

	string str = "qwertyuiopqqwwe";
	for (string::size_type i = 0; i < str.size(); ++i) 
	{
		cq.push(str[i]);
	}

	int cqSize = cq.size();
	char previousChar = NULL;
	int counter = 0;

	// create a queue of nodes
	for (int i = 0; i <= cqSize; i++)
	{
		if (previousChar != NULL)
		{
			if (cq.empty() || previousChar != cq.top())
			{
				cout << counter << " : " << previousChar << endl;
				q.push(TreeWrapper(new Tree(counter, previousChar))); // create node of the weight and the letter.
				counter = 0;
			}
		}
		if (!cq.empty())
		{
			counter++;
			previousChar = cq.top();
			cq.pop();
		}
	}
	cout << endl;

	
	TreeWrapper l;
	TreeWrapper r;

	int qSize = q.size();
	// bind the nodes into a tree
	for(int i = 0; i < qSize-1; i++)
	{
		l = q.top();
		q.pop();
		
		r = q.top();
		q.pop();
		
		q.push(TreeWrapper(new Tree(l.tree->getWeight() + r.tree->getWeight(), l.tree, r.tree)));
	}
	
	vector<char> bitString;
	q.top().tree->printTree(bitString);
	
	return 0;
};

Tree::Tree(int w, char c)
{
	weight = w;
	character = c;
}

Tree::Tree(int w, Tree * t1, Tree * t2)
{
	weight = w;
	left = t1;
	right = t2;
}

Tree::~Tree()
{
}

int Tree::getWeight() const
{
	return weight;
}


void Tree::printTree(vector<char> bitString) const
{	

	
	if (left != NULL)
	{
		bitString.push_back('1');
		left->printTree(bitString);
	}
	if (right != NULL)
	{
		// If we found a leaf last itteration, the last pushback will be left as an artifact.
		if (flag == 1)
		{
			flag = 0;
			bitString.pop_back();
		}

		bitString.push_back('0');
		right->printTree(bitString);
	}

	//Reached a leaf.
	if (character != NULL)
	{
		for (int i = 0; i < bitString.size(); i++)
		{
			cout << bitString[i];
		}

		cout << " : " << character << endl;
		flag = 1;
	}
}