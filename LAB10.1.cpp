#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintTXT(char* fname) // ��������� ����� �� �����
{
	ifstream fin(fname); // ������� ���� ��� ����������
	string s; // ���������� �����
	while (getline(fin, s)) // ���� ����� ��������� �����
	{
		cout << s << endl; // �������� ���� �� �����
	}
	cout << endl;
}
bool ProcessTXT1(char* fname) // ��������� "SQ" � "QS"
{
	ifstream fin(fname);
	string s;

	while (getline(fin, s))
	{ 
		if (s.length() < 2)
			return false;

		for (int i = 1; s[i] != 0; i++)
			if (s[i - 1] == 'S' && s[i] == 'Q' || s[i - 1] == 'Q' && s[i] == 'S')
				return true;
		return false;
	}

}


int main()
{
	// text files
	char fname[100]; // ��'� ������� �����
	cout << "enter file name 1: "; cin >> fname;
	PrintTXT(fname); // ������ ���� ������� ����� �� �����
	if (ProcessTXT1(fname))
		cout << "Found a pair 'SQ' or 'QS' in the file." << std::endl;

	else
		cout << "No pair 'SQ' or 'QS' found in the file." << std::endl;

	return 0;
}