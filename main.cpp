#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void QuikeSort(long*, long, long, long);
void swap(long*, long, long);
void PrintArr(long*, long);
long Partition(long*, long, long, long);

int main()
{
	long L, k;
	long* arr;
	scanf("%ld %ld", &L, &k);
	arr = (long*)malloc(sizeof(long) * L);
	for (long i = 0; i < L; i++)
	{
		scanf("%ld", &arr[i]);
	}
	QuikeSort(arr, 0, L - 1, k-1);
	PrintArr(arr, L);
	long j = 0;
	long i;
	printf("\n %ld", arr[k-1]);
}

void QuikeSort(long* arr, long left, long right, long k)
{
	long StoreIndex;
	long PivotIndex;
	if (left < right)
	{
		PivotIndex = (left + right) / 2;
		StoreIndex = Partition(arr, left, right, PivotIndex);
		if (k < StoreIndex)
			QuikeSort(arr, left, StoreIndex - 1, k);
		else if (k > StoreIndex)
			QuikeSort(arr, StoreIndex + 1, right, k);
		else
			return;
	}
}
long Partition(long* arr, long left, long right, long PivotIndex)
{
	long PivotValue = arr[PivotIndex];
	long StoreIndex = left;
	swap(arr, PivotIndex, right);
	for (long i = left; i < right; i++)
	{
		if (arr[i] >= PivotValue)
		{
			swap(arr, i, StoreIndex);
			StoreIndex++;
		}
	}
	swap(arr, StoreIndex, right);
	return StoreIndex;
}

void swap(long* arr, long i, long j)
{
	long tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void PrintArr(long* arr, long L)
{
	for (long i = 0; i < L; i++)
	{
		printf("arr[%d] is %ld\n", i, arr[i]);
	}
}
