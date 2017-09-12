

// sudo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
#include<algorithm>
#include <ctime>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;
int Sudoku_out();
void start(int t);
bool Sudoku_check(int i, int j, int key);
bool Sudoku_dfs(int i, int j);


int num[12][12];
//ofstream outfile("sudoku.txt",ios::out);
int main(int argc, char* argv[])
{
	string file_name = "sudoku.txt";
	string tmp = argv[0];
	int pos = tmp.rfind('\\');
	string file_path = "";
	for (int i = 0; i <= pos; ++i) file_path += tmp[i];
	file_path += file_name;
	
	freopen(file_path.c_str(), "w", stdout);

	int n = 0;
	//n = atoi(argv[2]);
	int len = strlen(argv[2]);
	for (int i = 0; i < len; ++i) n = n * 10 + argv[2][i] - '0';
	//cout << n << endl;
	while (n--) {
		start(n);
		Sudoku_dfs(1, 0);
		Sudoku_out();
	}


	//system("pause");


}


int Sudoku_out()
{

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			cout << num[i][j] << ' ';
			//outfile<<num[i][j]<<' ';
		}

		cout << endl;
		//outfile<<endl;
	}

	cout << endl;
	//outfile<<endl;
	return 0;
}



bool Sudoku_check(int i, int j, int key)
{
	if (i > 8 || j > 8)
		return true;

	bool sign = true;
	for (int m = 0; m < i; m++)
		if (num[m][j] == key) {
			sign = false;
			return false;
		}

	if (sign)
		for (int n = 0; n < j; n++) {
			if (num[i][n] == key) {
				sign = false;
				return false;
			}
		}
	if (sign) {
		int xx = i / 3 * 3;
		int yy = j / 3 * 3;
		for (int p = xx; p < xx + 3; p++) {
			if (sign == false) return false;
			for (int q = yy; q < yy + 3; q++) {
				if (num[p][q] == key)
				{
					sign = false;
					return false;
				}
			}
		}
	}



	return true;
}

bool Sudoku_dfs(int i, int j)
{
	for (int k = 1; k < 10; k++) {
		if (Sudoku_check(i, j, k))
		{
			num[i][j] = k;
			if (j < 8)
			{
				if (Sudoku_dfs(i, j + 1))
					return true;
			}
			else {
				if (i < 9)
				{
					if (Sudoku_dfs(i + 1, 0))
						return true;
				}
				else
					return true;
			}
			num[i][j] = 0;
		}
	}
	return false;
}
void start(int t)
{
	srand(t);  /* 产生random_shuffle的随机数种子 */
	for (int i = 0; i<9; ++i)
		for (int j = 0; j <9; ++j)
			num[i][j] = 0;
	num[0][0] = 2;   //左上角的第一个数为：（学号后两位相加）% 9 + 1   --学号后两位为27
	num[0][1] = 1;
	for (int i = 2; i <9; i++)
		num[0][i] = i + 1;

	random_shuffle(&(num[0][1]), &(num[0][8]));  /* 第一行随机排列产生 */

}







