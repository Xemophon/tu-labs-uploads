#zad1
first_list = []
for i in range(20):
    num = int(input("Enter whole number: "))
    first_list.append(num)
print(f"Sum of minimal and maximal is {max(first_list) + min(first_list)}")
second_list = [num for num in first_list if num % 5 == 0]
print(f"Diffrence between max and avg is {max(second_list) - (sum(second_list)/len(second_list))}")
second_list.append((second_list[0] + second_list[-1]))

#zad2
class FoodDelivery():
    def __init__(self, order_number, destination, price, delivery_term, order_status):
        self.order_number = order_number
        self.destination = destination
        self.price = price
        self.delivery_term = delivery_term
        self.order_status = order_status

    def order_info(self):
        return self.order_number, self.destination, self.price, self.delivery_term, self.order_status
    
    def change_term(self):
        self.delivery_term = str(input("Enter new date: "))
        return self.delivery_term

def status_info(order_list, num):
    found = False
    req_order = None
    for order in order_list:
        if order.order_number == num:
            found = True
            req_order = order
            break
    if found == 0:
        print("Not found")
    else:
        print(f"Found and {req_order.order_status}")

def add_order(order_list, new_order):
    order_list.append(new_order)

order_list = []

for i in range(3):
    ord_num = i + 1
    address = str(input("Enter address: "))
    price = int(input("Enter price: "))
    term = str(input("Enter hour: "))
    status = str(input("Enter state (delivered, delayed, denied): "))
    order = FoodDelivery(ord_num, address, price, term, status)
    add_order(order_list, order)