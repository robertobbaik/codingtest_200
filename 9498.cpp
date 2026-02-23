#include <iostream>
using namespace std;

int main()
{
	int A;
	cin >> A;

	string s;

	if(A < 60)
	{
		s = "F";
	}
	else if(A < 70)
	{
		s = "D";
	}
	else if(A < 80)
	{
		s = "C";
	}
	else if(A < 90)
	{
		s = "B";
	}
	else
	{
		s = "A";
	}

	cout << s << endl;
	return 0;
}