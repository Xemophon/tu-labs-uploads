#reverse.py
def reverse_matrix():
    matrix_elements = (input("Enter numbers with spaces: ").split())
    size = float(len(matrix_elements) ** 0.5)
    if round(size) != size:
        print("Not reverseable")
    else:
        size = int(size)
        matrix = []
        for i in range(size):
            row = []
            for j in range(size):
                row.append(float(matrix_elements[i * size + j]))
            matrix.append(row)
        if size == 2:
            delta_det = int(matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0])
            if delta_det == 0:
                print("The matrix is not invertible.")
                return
            elif delta_det != 0:
                inv = [[matrix[1][1] / delta_det, -matrix[0][1] / delta_det],
                        [-matrix[1][0] / delta_det, matrix[0][0] / delta_det]]
            print("The inverse of the 2x2 matrix is:")
            for row in inv:
                print(row)
        elif size == 3:
            delta_det = (matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
                         matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
                         matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]))
            if delta_det == 0:
                print("The matrix is not invertible.")
                return
            elif delta_det != 0:
                inv = [[(matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) / delta_det,
                        (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) / delta_det,
                        (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) / delta_det],
                       [(matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) / delta_det,
                        (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) / delta_det,
                        (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) / delta_det],
                       [(matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) / delta_det,
                        (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) / delta_det,
                        (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) / delta_det]]
                print("The inverse of the 3x3 matrix is:")
                for row in inv:
                    print(row)
        else:
            print("Not calculable now")