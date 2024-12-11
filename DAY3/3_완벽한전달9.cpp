// 3_�Ϻ�������9.cpp - 8�� ����

// git �� stopwatch.h �ֽ��ϴ� �ȿ� ���� ����

#include <chrono>
#include <iostream>

class stop_watch
{
	std::chrono::system_clock::time_point start;
	bool log_at_finish;
public:
	stop_watch(bool b = false) : log_at_finish(b) { start = std::chrono::system_clock::now(); }
	~stop_watch() { if (log_at_finish) log(); }

	std::chrono::duration<double> stop()
	{
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

		return std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	}
	void log()
	{
		std::cout << stop().count() << " seconds." << std::endl;;
	}
};


template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	stop_watch sw(true);	// true �� �Ҹ��ڿ��� ȭ�鿡 �ɸ� �ð� ����� �޶�� �ǹ�

	return f(std::forward<T>(arg)...);
}

int foo(int start, int end)
{
	int sum = 0;

	for (int i = start; i <= end; ++)
	{
		sum = sum + size;
	}
	return sum;
}

int main()
{
	int n = chronometry(foo, 1, 1000000); // 0 6��

	std::cout << n << std::endl;
}
