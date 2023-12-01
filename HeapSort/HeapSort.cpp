#include "HeapSort.hpp"

namespace heap
{
	static void swap(int& first, int& second)
	{
		int temp = first;
		first = second;
		second = temp;
	}

	static void re_heapify(std::vector<int>& buf, int max)
	{
		int parent = 0;

		while (true)
		{
			int cur = 2*parent+1;
			if (cur >= max)
				break;
			if (cur+1 < max && buf[cur+1] > buf[cur])
				cur = cur+1;
			if (buf[parent] < buf[cur])
				swap(buf[parent], buf[cur]);
			parent = cur;
		}
	}

	static void heapify(std::vector<int>& buf)
	{
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
	}

	void sort(std::vector<int>& buf)
	{
		heapify(buf);

		for (int i=(int)buf.size()-1; i>=0; --i)
		{
			swap(buf[0], buf[i]);
			re_heapify(buf, i);
		}
	}
}