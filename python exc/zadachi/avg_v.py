#Podhodqsht kalkulator za sredna skorost
#Poneje V sredno ima formula, a ne e tui i onui vurhu 2
data_matrix = []
lenghts = input("Enter lenghts of sections: ").split()
velocities = input("Enter their max velocities: ").split()
data_elements = []
if len(lenghts) == len(velocities):
    for h in range(len(lenghts)):
        data_elements.append(lenghts[h])
        data_elements.insert(2*h+1, velocities[h])
    size = float(len(data_elements) / 2)
    size = int(size)
    for i in range(size):
        row = []
        for j in range(2):
            row.append(int(data_elements[i*2 + j]))
        data_matrix.append(row)
    delta_t = 0
    delta_s = 0
    for k in range(size):
        time = 0
        time = data_matrix[k][0] / data_matrix[k][1]
        delta_t += time
        delta_s += data_matrix[k][0]
    avg_v = round(delta_s / delta_t)
    print("Average velocity should be at most " + str(avg_v) + " km/h")
else:
    print("Missing data")
