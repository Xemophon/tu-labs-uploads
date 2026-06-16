def rect_area(a,b):
    try:
        area = int(a) * int(b)
        if area <= 0:
            raise ValueError
        print(area)
    except ValueError:
        print("Invalid Input")

