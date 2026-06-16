print("Да състави програма за обработка на масива A[6,6]")
print("Author: Maxim Trenev")

matrix_A = []
j = 0

for i in range(6):
    row = []
    while j < 6:
        try:
            row.append(float(input("Enter number with point: ")))
            j += 1
        except TypeError:
            print('Should be float')
        except ValueError:
            print('Should be number')
    matrix_A.append(row)
    if i != 5:
        j = 0

for row in matrix_A:
    print(row)

matrix_C = []
break_upper = 0
found = 0

for i in range(6):
    for j in range(6):
        row = []
        found = 0
        if j != 5:
            if matrix_A[i][j] == matrix_A[i][j+1]:
                row = [matrix_A[i][j], i, j]
                print(f"Found duplicate: {row}")
                matrix_C.append(row)
                found = 1
        if i != 5:
            if matrix_A[i][j] == matrix_A[i+1][j] and found == 0:
                row = [matrix_A[i][j], i, j]
                print(f"Found duplicate: {row}")
                matrix_C.append(row)
                found = 1
        if i != 0:
            if matrix_A[i][j] == matrix_A[i-1][j] and found == 0:
                row = [matrix_A[i][j], i, j]
                print(f"Found duplicate: {row}")
                matrix_C.append(row)
                found = 1
        if j != 0:
            if matrix_A[i][j] == matrix_A[i][j-1] and found == 0:
                row = [matrix_A[i][j], i, j]
                print(f"Found duplicate: {row}")
                matrix_C.append(row)
                found = 1
        if i == 5 and j == 5:
            break_upper = 1
            break
    if break_upper == 1:
        break

for row in matrix_C:
    print(row)