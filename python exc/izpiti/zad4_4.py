x = abs(int(input("Number: ")))
y = 0
for i in range(x):
    if x % (i+1) == 1:
        pass
    elif x % (i+1) == 0:
        y += 1
    elif y > 2:
        break
if y == 2:
    print("Simple")
elif y > 2:
    print("Complex")
else:
    print("Neither")