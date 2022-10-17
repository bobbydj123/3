#include <iostream>
#include<cmath>
#include<climits>
#include<queue>

#define ll long long int

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	bool flag, isZero;
	int test, n;
	ll a, temp, diff, x, y, next;
	priority_queue<ll> coordinateX;
	priority_queue<ll> coordinateY;

	scanf("%d", &test);
	while(test!=0){
		coordinateX = priority_queue<ll>();
		coordinateY = priority_queue<ll>();

		isZero = false;
		flag = true;

		a = LONG_MAX;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%lld %lld", &x, &y);
			coordinateX.push(y+x);
			coordinateY.push(y-x);
		}
		while(!coordinateX.empty()){
			if(isZero)
				break;
			if(flag){
				temp = coordinateX.top();
				coordinateX.pop();
				flag = false;
				continue;
			}
			next = coordinateX.top();
			diff = abs(temp - next);
			if(diff < a)
				a = diff;
			if(diff == 0)
				isZero = true;
			temp = next;
			coordinateX.pop();
		}
		flag = true;
		while(!coordinateY.empty()){
			if(isZero)
				break;
			if(flag){
				temp = coordinateY.top();
				coordinateY.pop();
				flag = false;
				continue;
			}
			next = coordinateY.top();
			diff = abs(temp - next);
			if(diff < a)
				a = diff;
			if(diff == 0)
				isZero = true;
			temp = next;
			coordinateY.pop();
		}		
		cout<<a/2.0<<"\n";
		test--;
	}
	return 0;
}