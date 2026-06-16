from random import randint

try:
    n = int(input("Enter count of numbers between 25 and 45: "))
    if n < 25 or n > 45:
        raise Exception
except Exception:
    print("Number should be between the ranges")

i = 0
lst_1 = []
p = randint(-3700, -1600)
q = randint(2222, 3333)
while i < n:
    try:
        num = int(input(f"Enter number between {p} and {q}: "))
        if num < p or num > q:
            raise Exception
        else:
            lst_1.append(num)
            i += 1
    except Exception:
        print("Number should be between the ranges")

neg_count = 0
for dig in lst_1:
    if dig >= 100:
        str_dig = list(str(dig))
        st_dig = int(str_dig[-3])
        if st_dig % 2 == 0:
            neg_count += 1

lst_1.sort()
for i in range(len(lst_1)):
    if lst_1[i] % 6 == 3:
        print(i)

lst_2 = []
for num in lst_1:
    if abs(num) >=10 and abs(num) < 100:
        if num % 5 == 0:
            lst_2.append(num)

multip = 1
for i in range(1, len(lst_2), 2):
    multip *= lst_2[i]

k = len(lst_2)
j = 1
while j < k:
    if j % 2 != 0:
        if lst_2[j] % 2 == 0:
            lst_2.pop(j)
            k -= 1
    j += 1

if len(lst_1) > len(lst_2):
    lst_2.insert(round(len(lst_2)/2), lst_2[0] + lst_2[len(lst_2)-1])