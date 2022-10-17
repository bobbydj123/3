#include<iostream>

using namespace std;

int main()
{
	int n, m, test, token;
	scanf("%d", &test);
	while(test!=0){
		token = 0;
		scanf("%d %d",&n,&m);
		while(n!=0 && m!=0){
			token = 1 - token;
			if(n<m)
				m = m%n;
			else
				n = n%m;
		}
		if(token==1)
			printf("Ari\n");
		else
			printf("Rich\n");
		test--;
	}
	return 0;
}