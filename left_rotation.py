#this is a python code for left rotation of a list of integers from given position


n = int(input('Enter size of array:'))
rot = []
print('Give data: ')
rot=list(map(int,input().split()))

pos = int(input('Enter the position from where u want left rotation:'))

for i in range(pos):
    temp = rot[0]
    for j in range(1, n):
        rot[j - 1] = rot[j]
    rot[n-1] = temp

for k in range(0, n):
    print(rot[k],end=" ")
