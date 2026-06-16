print("Test how square matrixes and PY co-work")
x = ""
while x != "exit":
    matrix_elements = (input("Enter squarable number of digits with spaces: ").split())
    size = float(len(matrix_elements) ** 0.5)
    if round(size) != size:
        print("Not a square matrix")
    else:
        size = int(size)
        matrix = []
        for i in range(size):
            row = []
            for j in range(size):
                row.append(float(matrix_elements[i * size + j]))
            matrix.append(row)
        for row in matrix:
            print(row)
    matrix = []
    x = input("Type 'continue' to proceed or 'exit' to quit: ") 
print("Exited the loop.")
