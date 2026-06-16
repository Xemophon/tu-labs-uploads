from random import randint

try:
    mylist1 = []
    n = int(input("Number "))
    if n <= 10 or n >= 50:
        raise ValueError
    a = randint(-2500, -1300)
    b = randint(1111, 4444)
    for i in range(n):
        numb = int(input(f"Enter number between {a} and {b}: "))
        if int(numb) <= a or int(numb) >= b:
            raise ValueError
        else:
            mylist1.append(numb)

    counter_345 = 0
    for i in range(n):
        if abs(int(mylist1[i])) >= 10:
            digit_3 = list(str(abs(int(mylist1[i]))))[-2]
            if int(mylist1[i]) < 0:
                if int(digit_3) % 4 == 0 or int((digit_3)) % 5 == 0:
                    counter_345 += 1
    print(counter_345)

    sumed = 0
    counter_ind = 0
    for i in range(n):
        if abs(int(mylist1[i])) >= 10 and abs(int(mylist1[i])) < 100 and int(mylist1[i]) % 2 == 0:
            sumed += mylist1[i]
            counter_ind +=1
    print(sumed / counter_ind)

    mylist2 = []
    for i in range(n):
        if len(str(mylist1[i])) == 3 and int(mylist1[i]) % 3 == 0:
            mylist2.append(mylist1[i])
    
    counter_k = 0
    for i in range(0, len(mylist2), 2):
        if int(mylist2[i]) % 2 != 0:
            counter_k += 1
    print(counter_k)

    for i in range(1, len(mylist2), 2):
        mylist2[i] = 13
    
    if len(mylist2) < len(mylist1):
        mylist1.pop(0)
        mylist1.pop(len(mylist1)-1)

except ValueError:
    print("Number should be between ranges")
except ZeroDivisionError:
    print("No numbers checked in average")