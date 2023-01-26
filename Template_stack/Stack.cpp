#include <iostream>
#include <time.h>
using namespace std;
template <class T>
class Stack
{
	// Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 20 };
	// Массив для хранения данных
	T st[FULL + 1];
	// Указатель на вершину стека
	int top;

public:
	// Конструктор
	Stack();

	// Добавление элемента
	void Push(char c);

	// Извлечение элемента
	char Pop();

	// Очистка стека
	void Clear();

	// Проверка существования элементов в стеке
	bool IsEmpty();

	// Проверка на переполнение стека
	bool IsFull();

	// Количество элементов в стеке
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
	// Изначально стек пуст
	top = EMPTY;
}

template<class T>
void Stack<T>::Clear()
{
	// Эффективная "очистка" стека 
	// (данные в массиве все еще существуют, 
	// но функции класса, ориентированные на работу с вершиной стека,
	// будут их игнорировать)
	top = EMPTY;
}
template<class T>
bool Stack<T>::IsEmpty()
{
	// Пуст?
	return top == EMPTY;
}
template<class T>
bool Stack<T>::IsFull()
{
	// Полон?
	return top == FULL;
}
template<class T>
int Stack<T>::GetCount()
{
	// Количество присутствующих в стеке элементов
	return top + 1;
}
template<class T>
void Stack<T>::Push(char c)
{
	// Если в стеке есть место, то увеличиваем указатель
	// на вершину стека и вставляем новый элемент
	if (!IsFull())
		st[++top] = c;
}

template<class T>
char Stack<T>::Pop()
{
	// Если в стеке есть элементы, то возвращаем верхний и
	// уменьшаем указатель на вершину стека
	if (!IsEmpty())
		return st[top--];
	else // Если в стеке элементов нет
		return 0;
}

void main()
{
	srand(time(0));
	Stack<int> ST;
	char c;
	// пока стек не заполнится
	while (!ST.IsFull())
	{
		c = rand() % 4 + 2;
		ST.Push(c);
	}
	ST.Output();
	// пока стек не освободится
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

