from random import randint

lst_1 = []
for i in range(21):
    lst_1.append(randint(-90, -1))
print(lst_1)

print(f"Max number is {max(lst_1)}")
print(f"Sum is {sum(lst_1)}")

lst_2 = [num for num in lst_1 if num % 3 == 0]

lst_2.sort(reverse=True)
print(lst_2)

try:
    lst_2_odd = [lst_2[i] for i in range(1, len(lst_2), 2)]
    for num in lst_2_odd:
        lst_2.remove(num)

    print(lst_2)
except ValueError:
    print("No numbers were dividable by 3")