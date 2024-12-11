// 3_완벽한전달9.cpp - 8번 복사

// git 에 stopwatch.h 있습니다 안에 내용 복사

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
	stop_watch sw(true);	// true 는 소멸자에서 화면에 걸린 시간 출력해 달라는 의미

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
	int n = chronometry(foo, 1, 1000000); // 0 6개

	std::cout << n << std::endl;
}
