// 3_부분특수화1 - 156 p
#include <iostream>

// primary template
template<typename T> class Stack
{
public:
	void push(T a) { std::cout << "T" << std::endl; }
};

// partial specialization(부분 특수화)
template<typename T> class Stack<T*>
{
public:
	void push(T* a) { std::cout << "T*" << std::endl; }
};

// specialization(특수화), 타입이 확정된것, typename T 를 표기하지 않는다.
template<> class Stack<char*>
{
public:
	void push(char* a) { std::cout << "char*" << std::endl; }
};

int main()
{
	Stack<int>   s1; s1.push(0);
	Stack<int*>  s2; s2.push(0);
	Stack<char*> s3; s3.push(0);
}
