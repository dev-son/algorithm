#include <iostream>

class LinkedList
{
	LinkedList() 
		: num(0) , pNext(nullptr)
	{

	}
	LinkedList(int _number)
		: num(_number), pNext(nullptr)
	{

	}

	LinkedList* pNext;
	int num;

	void HeadInsertNode()
	{

	}
};

int main()
{
	LinkedList* pHead = new LinkedList();
}