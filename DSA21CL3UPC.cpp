#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#repo3
 
using namespace __gnu_pbds;
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define filewr() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 
int ans = INT_MIN;
void solve(int curr, int currcost, vector<int> visited, vector<int> nums, vector<int> energy){
	cout << curr << endl;
	if(nums[curr]==0) ans = max(ans, currcost);
	for(int i=0;i<nums.size() && nums[i]!=nums[curr];i++){
		if(find(visited.begin(), visited.end(),nums[i])==visited.end()){
			visited.push_back(nums[i]);
			if(nums[curr] < nums[i]){
				solve(i,currcost + pow(energy[i]-energy[curr], 3) + pow(curr - i, 2), visited, nums, energy);
			}else{
				solve(i,currcost + pow(curr - i, 2), visited, nums, energy);
			}
			visited.pop_back();
		}
	}
}

int main(){
	fastio();
	long long ini, n;
	cin >> ini >> n;
	vector<int> nums(n,0), energy(n,0);
	for(int i=0;i<n;i++){
		cin >> nums[i];
	}
	for(int i=0;i<n;i++){
		cin >> energy[i];
	}
	vector<int> visited;
	solve(ini, 0, visited,nums, energy);
	cout << ans << endl;

	return 0;
}
