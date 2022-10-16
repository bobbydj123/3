#include<iostream>

using namespace std;

const unsigned int c = 1000000007;

long recur(long x, int y){
	if(y==0)
		return x;
	else
		return recur((x+y+x*y)%c , y-1);
}

int main(){
	int test, n;
	scanf("%d", &test);
	while(test!=0){
		scanf("%d", &n);
		printf("%ld\n", recur(n,n-1));
		test--;
	}
	return 0;
}