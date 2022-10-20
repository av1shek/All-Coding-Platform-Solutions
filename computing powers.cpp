#include <iostream>
#include <limits.h>
using namespace std;

 int power(int x, int n)
{
	if(n == 0)
		return 1;

	int temp = power(x, n/2);

	temp = temp * temp;

	if(n % 2 == 0)
		return temp;
	else
		return temp * x; 
}
int main() {
    
    int x = 9, n = 6;

	cout<<power(x, n);
}
