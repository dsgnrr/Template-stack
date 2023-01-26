#include <iostream>
#include <time.h>
using namespace std;
template <class T>
class Stack
{
	// ������ � ������� ������� �����
	enum { EMPTY = -1, FULL = 20 };
	// ������ ��� �������� ������
	T st[FULL + 1];
	// ��������� �� ������� �����
	int top;

public:
	// �����������
	Stack();

	// ���������� ��������
	void Push(char c);

	// ���������� ��������
	char Pop();

	// ������� �����
	void Clear();

	// �������� ������������� ��������� � �����
	bool IsEmpty();

	// �������� �� ������������ �����
	bool IsFull();

	// ���������� ��������� � �����
	int GetCount();

	void Output()
	{
		for (int i = 0; i < top + 1; i++)
		{
			cout << st[i] << " ";
		}
		cout << endl;
	}
};

template<class T>
Stack<T>::Stack()
{
	// ���������� ���� ����
	top = EMPTY;
}

template<class T>
void Stack<T>::Clear()
{
	// ����������� "�������" ����� 
	// (������ � ������� ��� ��� ����������, 
	// �� ������� ������, ��������������� �� ������ � �������� �����,
	// ����� �� ������������)
	top = EMPTY;
}
template<class T>
bool Stack<T>::IsEmpty()
{
	// ����?
	return top == EMPTY;
}
template<class T>
bool Stack<T>::IsFull()
{
	// �����?
	return top == FULL;
}
template<class T>
int Stack<T>::GetCount()
{
	// ���������� �������������� � ����� ���������
	return top + 1;
}
template<class T>
void Stack<T>::Push(char c)
{
	// ���� � ����� ���� �����, �� ����������� ���������
	// �� ������� ����� � ��������� ����� �������
	if (!IsFull())
		st[++top] = c;
}

template<class T>
char Stack<T>::Pop()
{
	// ���� � ����� ���� ��������, �� ���������� ������� �
	// ��������� ��������� �� ������� �����
	if (!IsEmpty())
		return st[top--];
	else // ���� � ����� ��������� ���
		return 0;
}

void main()
{
	srand(time(0));
	Stack<int> ST;
	char c;
	// ���� ���� �� ����������
	while (!ST.IsFull())
	{
		c = rand() % 4 + 2;
		ST.Push(c);
	}
	ST.Output();
	// ���� ���� �� �����������
	int i = 0;
	while (i < 5)
	{
		c = ST.Pop();
		cout << c << " ";
		i++;
	}
	cout << "\n\n";
	ST.Output();


	system("pause");
}

