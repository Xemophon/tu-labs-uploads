#determinant.py
def determinant():
    matrix_elements = (input("Enter numbers with spaces: ").split())
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
        if size == 2:
            det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
            if det == 0:
                print("The determinant of the 2x2 matrix is: 0")
            else:
                print(f"The determinant of the 2x2 matrix is: {det}")
        elif size == 3:
            det = (matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
                    matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
                    matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]))
            if det == 0:
                print("The determinant of the 3x3 matrix is: 0")
            else:
                print(f"The determinant of the 3x3 matrix is: {det}")
        else:
            print("Not calculable now")
            return None