#include <iostream>

void safe_printf(const char* s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw "invalid format string: missing arguments";
            }
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void safe_printf(const char* s, const T& value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                std::cout << value;
                safe_printf(s + 1, args...);
                return;
            }
        }
        std::cout << *s++;
    }
    throw "extra arguments provided to printf";
}
int main()
{
    // printf 문제점
    // => 인자의 갯수를 잘못 사용하면 컴파일 에러도 아니고
    // => 실행시 예외 같은 것도 나오지 않고(약속된 방식의 runtime error)
    // => 컴파일러마다 다른 현상(미정의 동작 발생)
    // => 즉, 프로세스의 비정상적인 종료나 잘못된 결과.. 
    printf("%d, %d\n", 1);    
    printf("%d, %d\n", 1, 2, 3);
    //---------------------------------------------------

    try
    {
        safe_printf("%, %\n", 1, 2); // ok
        //      safe_printf("%, %\n", 1);    // 인자 갯수 부족 => 예외 발생
        //      safe_printf("%, %\n", 1, 2, 3);// 인자 갯수 초과 => 예외 발생
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
    }
}