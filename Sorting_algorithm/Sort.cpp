#include "Sort.h"

void InsertSort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int end=i,temp=array[end+1];
		for (; end >= 0; end--)
		{
			if (array[end] > temp)
			{
				array[end + 1] = array[end];
			}
			else
			{
				break;
			}
		}
		array[end + 1] = temp;
	}

}



void ShellSort(int* array, int size)
{
	//gap>1的时候进行预排序
	//gap==1的时候，直接插入排序
	int gap = size;
	for (;gap>1;)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int temp = array[end + gap];
			while (end >= 0)
			{
				if (array[end] > temp)
				{
					array[end + gap] = array[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			array[end + gap] = temp;
		}
	}
}

void Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void SelectSort(int* array, int size)
{
	int left=0, right=size-1;
	while (left<right)
	{
		int minIndex = left, maxIndex = left;
		for (int i = left; i <= right; i++)
		{
			if (array[i] < array[minIndex])
			{
				minIndex = i;
			}

			if (array[i] > array[maxIndex])
			{
				maxIndex = i;

			}	
		}
		Swap(array[left],array[minIndex]);
		//如果maxIndex和left重叠，maxIndex被换走了，要修正一下maxindex的位置
		if (left==maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(array[right],array[maxIndex]);
		left++;
		right--;
	}

}

void adjustBigHeap(int* array, int parent, const int size)
{
	int child = parent * 2 + 1;
	while (child<size)
	{
		if (child + 1 < size && array[child] < array[child + 1])
		{
			child++;
		}

		if (array[child]> array[parent])
		{
			Swap(array[child], array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* array, const int size)
{
	//建堆  从最后一个分支结点开始，自下而上建堆
	for (int i = (size - 1) / 2; i >= 0; i--)
	{
		adjustBigHeap(array, i, size);
	}

	for (int end = size - 1;end>0;end--)
	{
		Swap(array[0], array[end]);
		adjustBigHeap(array, 0, end);
	}
}

void BubbleSort(int* array, const int size)
{
	bool exchange = false;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array[j], array[j + 1]);
				exchange = true;
			}
		}
		if (!exchange)
		{
			return;
		}
	}
}


int GetMinIndex(int* array, const int left, const int right)
{
	int mid= (left + right) >> 1;
	if (array[left] < array[mid])
	{
		if (array[mid] < array[right])
		{
			return mid;
		}
		else if(array[left]>array[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (array[mid] > array[right])
		{
			return mid;
		}
		else if (array[left] < array[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//左右指针法
int PartSort1(int* array, int left, int right)
{
	int temp=GetMinIndex(array, left, right);
	Swap(array[temp], array[left]);
	int keyi = left;
	while (left<right)
	{
		while (left<right&&array[right] >= array[keyi])
		{
			right--;
		}

		while (left < right && array[left] <= array[keyi])
		{
			left++;
		}
		Swap(array[left], array[right]);
	}
	Swap(array[keyi], array[left]);

	return left;
}

//挖坑法
int PartSort2(int* array, int left, int right)
{
	int temp = GetMinIndex(array, left, right);
	Swap(array[temp], array[left]);
	int key = array[left];
	while (left < right)
	{
		//找小
		while (left < right&&array[right]>=key)
		{
			right--;
		}
		//放到 左边 的坑位中，右边就形成新的坑
		array[left] = array[right];
		//找大
		while (left < right && array[left] <= key)
		{
			left++;
		}
		//放到 右边 的坑位中，左边就形成新的坑
		array[right] = array[left];
	}
	array[left] = key;
	return left;
}

//前后指针法
int PartSort3(int* array, int left, int right)
{
	
	int temp = GetMinIndex(array, left, right);
	Swap(array[temp], array[left]);

	int prev = left;
	int cur = left + 1;
	int key = left;
	while (cur<=right)
	{
		if (array[cur] < array[key])
		{
			prev++;
			Swap(array[cur], array[prev]);
		}	
		cur++;
	}
	Swap(array[prev], array[key]);
	return prev;
}

void QuickSort(int* array, int begin, int end)
{
	if (begin>=end)
	{
		return;
	}

	//小区间优化
	//1.如果这个子区间是数据较多，继续选key单趟，分割子区间分治递归
	//2.如果这个子区间是数据较小，再去分治递归不太划算
	if (end-begin > 20)
	{
		int key = PartSort3(array, begin, end);
		QuickSort(array, begin, key - 1);
		QuickSort(array, key + 1, end);
	}
	else
	{
		ShellSort(array+begin, end- begin +1);
		//HeapSort(array+begin, end-begin+1);
	}

}

void QuickSortNonR(int* array, int left, int right)
{
	//这个栈用来存放要排序的区间
	stack<int>s;
	s.push(left);
	s.push(right);
	while (!s.empty())
	{
		int begin, end;
		end = s.top();
		s.pop();
		begin = s.top();
		s.pop();

		int key = PartSort1(array, begin, end);

		if (begin < key - 1)
		{
			s.push(begin);
			s.push(key - 1);
		}

		if (key+1 < end)
		{
			s.push(key + 1);
			s.push(end);
		}
	}
}

void _MergeSort(int* array, int left, int right, int* tempArr)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) >> 1;
	//[left,min]  [mid+1,right]
	_MergeSort(array, left, mid, tempArr);
	_MergeSort(array, mid+1, right, tempArr);

	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;

	//两段有序子区间归并给tempArr，并拷贝回给array
	//只要有一个数组内的元素空了，就跳出循环
	//出来后把另外一个还未空的数组的元素放进tempArr中
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] < array[begin2])
		{
			tempArr[i++] = array[begin1++];
		}
		else
		{
			tempArr[i++] = array[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tempArr[i++] = array[begin1++];
	}

	while (begin2 <= end2)
	{
		tempArr[i++] = array[begin2++];
	}

	//拷贝给array数组
	for (int j = left; j <= right; j++)
	{
		array[j] = tempArr[j];
	}
}


void MergeSort(int* array, int size)
{
	int *tempArray = new int [sizeof(int)*size];

	if (NULL == tempArray)
	{
		cout << "new开辟空间失败" << endl;
		exit(-1);
	}
	_MergeSort(array, 0, size - 1,tempArray);
	delete []tempArray;
}


void _MergeSortNonR(int* array, int* tempArr,int begin1,int end1, int begin2, int end2)
{
	int i = begin1;
	int j = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] < array[begin2])
		{
			tempArr[i++] = array[begin1++];
		}
		else
		{
			tempArr[i++] = array[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tempArr[i++] = array[begin1++];
	}

	while (begin2 <= end2)
	{
		tempArr[i++] = array[begin2++];
	}

	//拷贝给array数组
	for (; j <= end2; j++)
	{
		array[j] = tempArr[j];
	}
}

void MergeSortNonR(int* array, int size)
{
	int* tempArray = new int[sizeof(int) * size];

	if (NULL == tempArray)
	{
		cout << "new开辟空间失败" << endl;
		exit(-1);
	}
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			//[i,i+gap-1]  [i+gap,i+2*gap-1]归并
			//如果第二个小区间不存在就不需要归并了，结束本次循环
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;

			/*
			1.最后一个小组归并时，第二个小区间不存在，不需要归并了
			2.最后一个小组归并时，第一个小区间不够gap个，不需要归并
			这两种情况合并成如  1来预防
			*/
			if (begin2 >= size)		//   1
			{
				break;
			}

			//如果第二个小区间存在，但是第二个小区间不够gap个，结束位置越界了，需要修正一下
			//如   2
			if (end2 >= size)		//	2
			{
				end2 = size - 1;
			}

			_MergeSortNonR(array, tempArray, begin1, end1, begin2, end2);
		}
		gap *= 2;
	}
	delete[]tempArray;
}

// 时间复杂度：O(size+range)
// 只适合，一组数据，数据的范围比较集中. 如果范围集中，效率是很高的，但是局限性也在这里
// 并且只适合整数，如果是浮点数、字符串等等就不行了
// 空间辅助度：O(range)
void CountSort(int* array, int size)
{
	int max = array[0], min = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] > max)

			max = array[i];

		if (array[i] < min)
			min = array[i];
	}

	int range = max - min + 1;
	int* count = new int[sizeof(int) * range];
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < size; ++i)
	{
		count[array[i] - min]++;
	}

	int i = 0;
	for (int j = 0; j < range; ++j)
	{
		while (count[j]--)
		{
			array[i++] = j + min;
		}
	}

	delete []count;
}