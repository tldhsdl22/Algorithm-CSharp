#include <iostream>
#include <string>
using namespace std;

int* merge(int* arrayData1, int len1, int* arrayData2, int len2) { // cur번째 row에 말을 배치할 예정임

	int* result = (int*)malloc(sizeof(int) * (len1 + len2));
	int idx1 = 0;
	int idx2 = 0;

	for (int idx = 0; idx < len1 + len2; idx++)
	{
		if (idx1 >= len1)
		{
			result[idx] = arrayData2[idx2++];
		}
		else if (idx2 >= len2)
		{
			result[idx] = arrayData1[idx1++];
		}
		else
		{
			result[idx] = arrayData1[idx1] < arrayData2[idx2] ? arrayData1[idx1++] : arrayData2[idx2++];
		}
	}
	free(arrayData1);
	free(arrayData2);

	return result;
}

int* mergeSort(int* arrayData, int length) {

	if (length == 1)
	{
		return arrayData;
	}
	else if (length == 2)
	{
		if (arrayData[0] > arrayData[1])
		{
			int tmp = arrayData[0];
			arrayData[0] = arrayData[1];
			arrayData[1] = tmp;
		}
		return arrayData;
	}
	else
	{
		int mid = length / 2;
		int* array1 = (int*)malloc(sizeof(int) * mid);
		int* array2 = (int*)malloc(sizeof(int) * (length-mid));
		for (int idx = 0; idx < mid; idx++)
		{
			array1[idx] = arrayData[idx];
		}
		for (int idx = 0; idx < length - mid; idx++)
		{
			array2[idx] = arrayData[mid + idx];
		}
		int* result1 = mergeSort(array1, mid);
		int* result2 = mergeSort(array2, length - mid);

		return merge(result1, mid, result2, length - mid);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int* a = (int*)malloc(sizeof(int) * (n));

	for (int i = 0; i < n; i++) cin >> a[i];
	int* result = mergeSort(a, n);
	for (int i = 0; i < n; i++) cout << result[i] << '\n';

	free(a);
	free(result);
	return 0;
}