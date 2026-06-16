x = int(input("Numbers: "))
numbers = []
sum = 0
for i in range(x):
    numbers.append(i+1)
    sum += numbers[i]
print(sum)