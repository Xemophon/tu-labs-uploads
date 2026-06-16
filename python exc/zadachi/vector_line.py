res_matrix = []
res_matrix_elements = input(f"Input 2 number of right-side numbers: ").split()
for i in range(2):
    res_row = []
    res_row.append(float(res_matrix_elements[i]))
    res_matrix.append(res_row)
for res_row in res_matrix:
    print(res_row)