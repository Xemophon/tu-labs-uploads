def gaussian_probability():
    cho = int(input("Choose Normal(1), Standard Normal(2) or Binomial(3): "))
    if cho == 1:
        st_dev = float(input("Enter standard deviation: "))
        fr_res = float(input("Enter the most frequent occurance: "))
        res = float(input("Enter the desired occurance: "))
        res_res = res - fr_res
        z = round(res_res / st_dev, 2)
        chnc = 0.5000 + 0.0040 * z * 100
        if chnc >= 1:
            print("Occurance is 100%")
        else:
            print(f"The chance to occur up to the desired one is {round(chnc * 100,2)} %")
    if cho == 2:
        res = input("Enter number between 0.00 and 3.00")
        if res <= 0 or res >= 3.00:
            print("Chance is around 99.99 %")
        else:
           chnc = 0.5000 + 0.0040 * res * 100 
           print(f"The chance to occur up to the desired one is {round(chnc * 100,2)} %")
    if cho == 3:
        p = float(input("Enter chance of desired occurance: "))
        q = float(input("Enter chance of opposite occurance: "))
        n = float(input("Tries: "))
        multip = n * p * q
        st_dev = multip ** 0.5
        res = float(input("Enter the desired occurance: "))
        res_res = res - fr_res
        z = round(res_res / st_dev, 2)
        chnc = 0.5000 + 0.0040 * z * 100
        if chnc >= 1:
            print("Occurance is 100%")
        else:
            print(f"The chance to occur up to the desired one is {round(chnc * 100,2)} %")
    else:
        print("Exited")