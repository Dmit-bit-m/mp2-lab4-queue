#include <iostream>
#include"Queue.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	size_t c;
	cout << "Введите длину очереди" << endl;
	cin >> c;
	try
	{
		TQueue<int> q(c);
		for (int i = 0; i < c; i++)
		{
			q.Push(i);
			cout << "Добавлено " << i << endl;
		}

		while (!q.isEmpty())
		{
			c = q.Pop();
			cout << "Извлечено " << c << endl;
		}
	}
	catch (const char* e) {
		cout << e << endl;
	}
	return 0;
}