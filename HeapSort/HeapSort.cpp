#include "HeapSort.hpp"

#include <vector>
#include <iostream>

namespace heap
{

void print(std::vector<int>& buf)
{
	for (int i=0; i<buf.size(); ++i)
		std::cout << buf[i] << " ";
	std::cout << "\n";
}

static void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

	// 이미 돼있다.

	/*
					0
			1				2
		3		4		5		6
	7	8	9
	
	2x+1, 2x+2

	(x-1)/2
	
	0, 1, 2
	1, 3, 4
	2, 5, 6
	3, 7, 8
	4,  9, 10
	*/

void sort(std::vector<int>& buf)
{
	// for (int i=0; i<buf.size(); ++i)
	// {
	// 	int left = 2*i+1;
	// 	int right = 2*i+2;

	// 	if (left < buf.size())
	// 	{
	// 		buf[left];

	// 	}
	// 	print(buf);
	// }
	for (int i=1; i<buf.size(); ++i)
	{
		int c=i;
		do {
			int root = (c-1)/2;
			if (buf[root] < buf[c])
				swap(buf[root], buf[c]);
			c=root;
		}while (c!=0);
		print(buf);
	}
}

}

int main()
{
	std::vector<int> buf = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	heap::print(buf);
	heap::sort(buf);
	heap::print(buf);
}