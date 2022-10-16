from copy import deepcopy
def gcd(a, b):
	while(b):
		a , b = b , a%b
	return a

test = int(input())
while(test != 0):
	n = int(input())
	nums = list(map(int, input().split()))
	divisors = [nums[0]]

	if(len(nums) == 2):
		print(nums[0] + nums[1])
		test-=1
		continue
	
	for i in nums[1:]:
		temp = deepcopy(divisors)
		l = 0
		for j in divisors:
			x = gcd(i, j)
			if(x == 1):
				l+=1
				if(l == len(divisors)):
					if i not in temp:
						temp.append(i) 
			else:
				temp.remove(j)
				temp.append(x)

		divisors = temp
		
		if(len(divisors) > 2):
			break
		
	if(len(divisors) == 1):
		print(max(nums) + divisors[0])
	elif(len(divisors) == 2):
		print(max(divisors[0] + divisors[1], max(nums) + 1))
	else:
		print(max(nums) + 1)
	
	test-=1