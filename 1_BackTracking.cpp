// ConsoleApplication10.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

void solution(int* arrResult, bool* arrUsed, int curIdx, const int m, const int n)
{
	if (curIdx == n)
	{		
		string line = "";
		for (int idx = 0; idx < n; idx++)
		{			
			line += to_string(arrResult[idx]) + " ";
		}
		
		cout << line << '\n';
		return;
	}

	// 전체 돌면서 확인
	for (int idx = 0; idx < m; idx++)
	{
		if (!arrUsed[idx])
		{
			arrUsed[idx] = true;
			arrResult[curIdx] = idx+1;
			solution(arrResult, arrUsed, curIdx + 1, m, n);
			arrUsed[idx] = false;
		}
	}
}

/*
int main()
{	int* arrResult;
	bool* arrUsed;
	int m, n;
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	arrResult = (int*)malloc(sizeof(int) * n);
	arrUsed = (bool*)malloc(sizeof(bool) * m);
	fill(arrUsed, arrUsed + m, false);

	solution(arrResult, arrUsed, 0, m, n);

	return 0;
}
*/