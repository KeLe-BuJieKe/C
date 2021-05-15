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
	//gap>1��ʱ�����Ԥ����
	//gap==1��ʱ��ֱ�Ӳ�������
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
		//���maxIndex��left�ص���maxIndex�������ˣ�Ҫ����һ��maxindex��λ��
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
	//����  �����һ����֧��㿪ʼ�����¶��Ͻ���
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

//����ָ�뷨
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

//�ڿӷ�
int PartSort2(int* array, int left, int right)
{
	int temp = GetMinIndex(array, left, right);
	Swap(array[temp], array[left]);
	int key = array[left];
	while (left < right)
	{
		//��С
		while (left < right&&array[right]>=key)
		{
			right--;
		}
		//�ŵ� ��� �Ŀ�λ�У��ұ߾��γ��µĿ�
		array[left] = array[right];
		//�Ҵ�
		while (left < right && array[left] <= key)
		{
			left++;
		}
		//�ŵ� �ұ� �Ŀ�λ�У���߾��γ��µĿ�
		array[right] = array[left];
	}
	array[left] = key;
	return left;
}

//ǰ��ָ�뷨
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

	//С�����Ż�
	//1.�����������������ݽ϶࣬����ѡkey���ˣ��ָ���������εݹ�
	//2.�����������������ݽ�С����ȥ���εݹ鲻̫����
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
	//���ջ�������Ҫ���������
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

	//��������������鲢��tempArr���������ظ�array
	//ֻҪ��һ�������ڵ�Ԫ�ؿ��ˣ�������ѭ��
	//�����������һ����δ�յ������Ԫ�طŽ�tempArr��
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

	//������array����
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
		cout << "new���ٿռ�ʧ��" << endl;
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

	//������array����
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
		cout << "new���ٿռ�ʧ��" << endl;
		exit(-1);
	}
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			//[i,i+gap-1]  [i+gap,i+2*gap-1]�鲢
			//����ڶ���С���䲻���ھͲ���Ҫ�鲢�ˣ���������ѭ��
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;

			/*
			1.���һ��С��鲢ʱ���ڶ���С���䲻���ڣ�����Ҫ�鲢��
			2.���һ��С��鲢ʱ����һ��С���䲻��gap��������Ҫ�鲢
			����������ϲ�����  1��Ԥ��
			*/
			if (begin2 >= size)		//   1
			{
				break;
			}

			//����ڶ���С������ڣ����ǵڶ���С���䲻��gap��������λ��Խ���ˣ���Ҫ����һ��
			//��   2
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

// ʱ�临�Ӷȣ�O(size+range)
// ֻ�ʺϣ�һ�����ݣ����ݵķ�Χ�Ƚϼ���. �����Χ���У�Ч���Ǻܸߵģ����Ǿ�����Ҳ������
// ����ֻ�ʺ�����������Ǹ��������ַ����ȵȾͲ�����
// �ռ丨���ȣ�O(range)
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