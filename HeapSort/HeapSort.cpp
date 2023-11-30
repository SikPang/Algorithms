#include "HeapSort.hpp"

namespace heap
{

static void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

/*

2x+1, 2x+2

(x-1)/2

*/

void sort(std::vector<int>& buf)
{
	// heapify
	for (int i=1; i<(int)buf.size(); ++i)
	{
		int cur = i;
		while (cur > 0)
		{
			int parent = (cur - 1) / 2;

			if (buf[parent] < buf[cur])
				swap(buf[parent], buf[cur]);
			cur = parent;
		}
	}

	// swap maxValue(firstElement) and lastElement
	for (int i=(int)buf.size()-1; i>=0; --i)
	{
		swap(buf[0], buf[i]);
		int parent = 0;

		// and then heapify again
		while (true)
		{
			int cur = 2*parent+1;

			if (cur >= i)
				break;

			// 어차피 큰 게 위로 와야되니까, 큰 거랑 바꿔야 함
			// 바꾼게 큰 거니까 바꾼 걸로 내려가서 계속 수행하면 됨
			// 작은 거는 안 건드렸으니까 따로 볼 필요가 없음 
			if (cur+1 < i && buf[cur+1] > buf[cur])
				cur = cur+1;
			if (buf[parent] < buf[cur])
				swap(buf[parent], buf[cur]);
			parent = cur;
		}
	}
}

}