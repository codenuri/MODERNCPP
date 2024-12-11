class Point
{
	int x = 0;
	int y = 0;
public:

	void set(int a, int b)
	{
		x = a;
		y = b;
	}

	int getx() 
	{
		return x;	
	}
};

int main()
{
	Point pt;
	
	pt.set();

	int n = pt.getx();
}
