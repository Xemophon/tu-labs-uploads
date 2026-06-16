#zad 1
#list_num = input("Enter numbers: ").split()
def evens(list):
    evens = []
    for i in range(len(list)):
        if int(list[i]) % 2 == 0:
            evens.append(list[i])
        else:
            print(f"{list[i]} is not even")
    print(evens)

#zad 2 
#text = input("Enter text: ").split()
def word_count(list):
    word_count = {}
    for i in range(len(list)):
        if list[i] not in word_count:
            word_count.update({list[i]: 1})
        elif list[i] in word_count.keys():
            word_count[list[i]] += 1
    print(word_count)

#zad3
#n = int(input("Enter desired Fibunacci number: "))
def fib_num(int):
    fib_num = 1
    for i in range(1, n):
        fib_num += (2*i + 1)
    return print(fib_num)

#zad4
a = [[1, 2], [3, 4], [5]]
def flatt(list):
    b = []
    for i in range(len(list)):
        for j in range(len(list[i])):
            b.append(list[i][j])
    return print(b)

#zad5
schl = {"Alice": [85, 90], 
        "Bob": [78, 82]}
def aveg(dict):
    keys = list(dict.keys())
    aveg_schl = {}
    for i in range(len(keys)):
        sum = 0
        avg = 0
        marks = dict[keys[i]]
        for j in range(0,2):
            sum += marks[j]
        avg = sum / 2
        aveg_schl[keys[i]] = avg
    return(print(aveg_schl))