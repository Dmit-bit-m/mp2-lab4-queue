#pragma once
#include <iostream>
using namespace std;
template <class T>

class TQueue {
protected:
	int max_size;
	int first;
	int last;
	int size;
	T* mas;

public:
	TQueue(int _max_size = 0) {
		if (_max_size < 0)
			throw "Неверная длина";
		else {
			max_size = _max_size;
			size = 0;
			mas = new T[max_size];
			first = 0;
			last = -1;
		}
	}
	TQueue(const TQueue& q) {
		max_size = q.max_size;
		size = q.size;
		mas = new T[max_size];
		first = q.first;
		last = q.last;
		for (size_t i = 0; i < size; i++) {
			mas[(first + i) % max_size] = q.mas[(q.first + i) % max_size];
		}

	}
	~TQueue()
	{
		delete[] mas;
	}
	bool isEmpty() 
	{
		return (size == 0);
	}

	bool isFull()
	{
		return (size == max_size);
	}

	void Push(T a) 
	{
		if (isFull()) throw "Очередь полная";
		if (last == max_size - 1) last = 0;
		else {
			last = (last + 1) % max_size;
			mas[last] = a;
			size++;
		}
	}

	T Pop() 
	{
		if (isEmpty())
			throw "Очередь пустая";
		else
		{
			T a = mas[first];
			first = (first + 1) % max_size;
			size--;
			return a;
		}

	}

	T Top() 
	{
		if (isEmpty())  throw "Очередь пустая";
		return mas[first];
	}

	int GetFirst() 
	{
		return first;
	}

	int GetMaxSize() 
	{
		return max_size;
	}

	int GetSize()
	{
		return size;
	}

	T& operator = (const T& tq) 
	{
		if (max_size != tq.MaxSize)
		{
			delete[] mas;
			max_size = tq.MaxSize;
			size = tq.Size;
			mas = new T[max_size];
		}
		for (size_t i = 0; i < max_size; i++)
		{
			mas[i] = tq.mas[i];
		}
		first = tq.first;
		last = tq.last;
		return *this;
	}


};