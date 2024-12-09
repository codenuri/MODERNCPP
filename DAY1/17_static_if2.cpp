// 17_static_if - 51 page

template<typename T> void foo(T a)
{
	if (false)
		*a = 10;
}
int main()
{
	foo(0); 
}

