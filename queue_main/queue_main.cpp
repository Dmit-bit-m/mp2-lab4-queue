#include <iostream>
#include"Queue.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	size_t c;
	cout << "������� ����� �������" << endl;
	cin >> c;
	try
	{
		TQueue<int> q(c);
		for (int i = 0; i < c; i++)
		{
			q.Push(i);
			cout << "��������� " << i << endl;
		}

		while (!q.isEmpty())
		{
			c = q.Pop();
			cout << "��������� " << c << endl;
		}
	}
	catch (const char* e) {
		cout << e << endl;
	}
	return 0;
}