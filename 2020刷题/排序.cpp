#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=n-1; j>i; j--)
		{
			if(a[j] < a[j-1])
				swap(a[j], a[j-1]);
		}
	}
}

void select_sort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int k = i;
		for(int j=i+1; j<n; j++)
		{
			if(a[j] < a[k])
				k = j;
		}
		if(k != i)
			swap(a[k], a[i]);
	}
}

void insert_sort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		if(a[i+1] < a[i])
		{
			int j;
			int tmp = a[i+1];
			for(j=i; j>=0 && a[j]>tmp; j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = tmp;
		}
	}
}

void shell_sort(int a[], int n)
{
	int gap = n / 2;
	while(gap)
	{
		for(int i=0; i<n-gap; i++)
		{
			if(a[i+gap] < a[i])
			{
				int j;
				int tmp = a[i+gap];
				for(j=i; j>=0 && a[j]>tmp; j-=gap)
				{
					a[j+gap] = a[j];
				}
				a[j+gap] = tmp;
			}
		}
		gap /= 2;
	}
}

int partition(int a[], int begin, int end)
{
	int tmp = a[begin];
	while(begin < end)
	{
		while(begin < end && a[end] >= tmp)
			end--;
		a[begin] = a[end];
		
		while(begin < end && a[begin] <= tmp)
			begin++;
		a[end] = a[begin];
	}
	a[begin] = tmp;
	return begin;
}
void quick_sort(int a[], int begin, int end)
{
	if(begin < end)
	{
		int k = partition(a, begin, end);
		quick_sort(a, begin, k);
		quick_sort(a, k+1, end);
	}
}
void quick_sort_norecursive(int a[], int start, int end)
{
	int k = partition(a, start, end);
	stack<int> s;
	if(k - 1 > start)
	{
		s.push(start);
		s.push(k-1);
	}
	if(k + 1 < end)
	{
		s.push(k+1);
		s.push(end);
	}
	while(!s.empty())
	{
		end = s.top();
		s.pop();
		start = s.top();
		s.pop();
		int index = partition(a, start, end);
		if(index - 1 > start)
		{
			s.push(start);
			s.push(index - 1);
		}
		if(index + 1 < end)
		{
			s.push(index+1);
			s.push(end);
		}
	}
}

void merge(int a[], int start, int mid, int end)
{
	int tmp[end - start + 1] = {0};
	int i = start, j = mid + 1;
	int k = 0;
	while(i<=mid && j<=end)
	{
		if(a[i] < a[j])
		{
			tmp[k++] = a[i++];
		}
		else
		{
			tmp[k++] = a[j++];
		}
	}
	while(i <= mid)
	{
		tmp[k++] = a[i++];
	}
	while(j <= end)
	{
		tmp[k++] = a[j++];
	}
	
	for(i=start, k=0; i<=end; i++, k++)
	{
		a[i] = tmp[k];
	}
}
void merge_sort(int a[], int begin, int end)
{
	if(begin < end)
	{
		int mid = (begin + end) / 2;  // begin + (end - begin) / 2;
		merge_sort(a, begin, mid);
		merge_sort(a, mid+1, end);
		merge(a, begin, mid, end);
	}
}

void heap_adjust(int a[], int begin, int end)
{
	int tmp = a[begin];
	for(int i=begin*2+1; i<=end; i=i*2+1)
	{
		if(i < end && a[i] < a[i+1])
			i++;
		if(tmp > a[i])
			break;
		a[begin] = a[i];
		begin = i;
	}
	a[begin] = tmp;
}
void head_sort(int a[], int n)
{
	for(int i=n/2; i>=0; i--)
		heap_adjust(a, i, n-1);
	for(int i=n-1; i>0; i--)
	{
		swap(a[0], a[i]);
		heap_adjust(a, 0, i-1);
	}
}

void print(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout<<a[i] <<" ";
	cout<<endl;
}

int main()
{
	int a[] = {2, 1, 3, 5, 8, 6, 7, 4};
	//bubble_sort(a, 8);
	//select_sort(a, 8);
	//insert_sort(a, 8);
	//shell_sort(a, 8);
	//quick_sort(a, 0, 7);
	quick_sort_norecursive(a, 0, 7);
	//merge_sort(a, 0, 7);
	//head_sort(a, 8);
	print(a, 8);
	return 0;
}
