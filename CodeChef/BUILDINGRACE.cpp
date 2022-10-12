/*
PROBLEM:
Two friends Chef and Chefina are currently on floors AA and BB respectively. They hear an announcement that prizes are being distributed on the ground floor and so decide to reach the ground floor as soon as possible.

Chef can climb down XX floors per minute while Chefina can climb down YY floors per minute. Determine who will reach the ground floor first. In case both reach the ground floor together, print Both.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
The first line of each test case contains four space-separated integers AA, BB, XX, and YY — the current floor of Chef, the current floor of Chefina, speed of Chef and speed of Chefina in floors per minute respectively.
Output Format
For each test case, output on a new line:

Chef if Chef reaches the ground floor first.
Chefina if she reaches the ground floor first.
Both if both reach the ground floor at the same time.
You may print each character of the string in uppercase or lowercase. For example, the strings CHEF, chef, Chef, and chEF are all considered the same.

Constraints
1 \leq T \leq 25001≤T≤2500
1 \leq A, B \leq 1001≤A,B≤100
1 \leq X, Y \leq 101≤X,Y≤10 */

// SOLUTION

#include <iostream>
using namespace std;
string reachFirst(double A, double B, double X, double Y){
    if(A/X < B/Y)
        return "Chef";
    else if(A/X > B/Y)
        return "Chefina";
    else
        return "Both";
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    double A, B, X, Y;
	    cin>>A>>B>>X>>Y;
	    cout<<reachFirst(A,B,X,Y)<<endl;
	}
	return 0;
}
