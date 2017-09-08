// sudo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int Sudoku_out();
bool Sudoku_check(int t, int key);
int Sudoku_in(int t);

int num[9][9];
int main()
{
	Sudoku_in(0);
	Sudoku_out();
	int x;
	cin >> x;
    return 0;
}



int Sudoku_out()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << num[i][j]<<' ';
		}
		cout << endl;
	}
	return 0;
}

bool Sudoku_check(int t, int key) {
	int x = t / 9;//������
	int y = t % 9;//������
	
	//�����
	for (int i = 0; i < 9; i++) {
		if (num[i][y] == key)
			return false;
	}
	//�����
	for (int j = 0; j < 9; j++) {
		if (num[x][j] == key)
			return false;
	}
	//�����߹�
	int xx = x / 9 * 3;
	int yy = y / 9 * 3;  
	for (int i = xx; i < xx + 3; i++) {
		for (int j = yy; j < yy + 3; j++) {
			if (num[i][j] == key)
				return false;
		}
	}
	return true;
}
//��Sudoku_check()������ϣ��������
int Sudoku_in(int t)
{
	int x = t / 9;
	int y = t % 9;
	if (t > 80)
		return 0;
	else {
		for (int i = 1; i < 10; i++) {
			if (Sudoku_check(t, i) == true) {
				num[x][y] = i;
				Sudoku_in(t + 1);
			}

		}
	}
}

