nums = [4,5,4]
a ={}
for i in range(len(nums)):
    if nums[i] not in a:
        a[nums[i]] =1
    else:
        a[nums[i]] += 1

for i in range (len(nums)):
    if(a[nums[i]] > (len(nums)/2)):
        print(nums[i])
        break
