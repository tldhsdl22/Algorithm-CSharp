#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int** arrayData) { // cur번째 row에 말을 배치할 예정임
	int size = _msize(*arrayData) / sizeof(int);	

	for (int fixedIdx = 1; fixedIdx < size; fixedIdx++)
	{
		for (int idx = 0; idx < size - fixedIdx; idx++)
		{
			if ((*arrayData)[idx] > (*arrayData)[idx + 1])
			{
				int tmp = (*arrayData)[idx];
				(*arrayData)[idx] = (*arrayData)[idx + 1];
				(*arrayData)[idx + 1] = tmp;
			}
		}
	}	
}
/*
int main(void) {
	int n = 0;
	cin >> n;
	int* arrayData = (int*)malloc(sizeof(int) * n);
	for (int idx = 0; idx < n; idx++)
	{
		cin >> arrayData[idx];
	}
	bubbleSort(&arrayData);

	for (int idx = 0; idx < n; idx++)
	{
		cout << arrayData[idx] << " ";
	}
	return 0;
}
*/