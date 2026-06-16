from kramer import method_of_Kramer
from determinant import determinant
from reverse import reverse_matrix
from gaus_P import gaussian_probability

try:
    print("Starting the calc...")
    print("Optoions: \n 1.Reverse a Matrix \n 2.Determinant \n 3.Kramer's Method \n 4.Probability \n 0 to exit")
    while True:
        x = int(input("Enter calc number: "))
        if x == 1:
            reverse_matrix()
        elif x == 2:
            determinant()
        elif x == 3:
            method_of_Kramer()
        elif x == 4:
            gaussian_probability()
        elif x == 0:
            print("Exiting the program.")
            break
        else:
            print("Wrong Input")
            continue
except ValueError:
    print("Didn't write a number??")