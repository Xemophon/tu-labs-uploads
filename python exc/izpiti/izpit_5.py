from random import choice, randint

class Market():
    def __init__(self, barcode, name, manufacturer, price, quantity):
        self.barcode = barcode
        self.name = name
        self.manufacturer = manufacturer
        self.price = price
        self.quantity = quantity

    def sale(self, quantity):
        self.quantity -= quantity

    def info(self):
        return self.barcode, self.name, self.manufacturer, self.price, self.quantity

    def discount(self):
        if self.price < 50 and self.price >= 30:
            self.price = self.price - self.price * 0.05
        elif self.price < 30 and self.price >= 10:
            self.price = self.price - self.price * 0.07
        else:
            pass

manus = ["KFM", "Tandem", "Pedal"]
names = ["Nadenica", "Prasence", "Fishnet", "Goth momicheta"]

n = int(input("Enter number of products: "))
products_list = []

for i in range(n):
    barcodec = randint(1000000000000, 9999999999999)
    products_list.append(Market(barcodec, choice(names), choice(manus), randint(2, 100), randint(1, 20)))

def search_by_barcode(products_list, barcode):
    found = 0
    for i in range(n):
        barcoded = products_list[i].barcode
        if barcode == barcoded:
            print(products_list[i].info())
            found += 1
    if found == 0:
        print('Wrong barcode!!!')
        for j in range(n):
            print(products_list[j].barcode)

def search_by_manufacturer(products_list, manufacturer):
    found = 0
    founded = []
    for i in range(n):
        manusf = products_list[i].manufacturer
        if manufacturer == manusf:
            founded.append(products_list[i])
            found += 1
    if found == 0:
        print('Wrong manufacturer!!!')
    else:
        sump = 0
        for i in range(len(founded)):
            sump += founded[i].price
        avg = sump / len(founded)
        for i in range(len(founded)):
            if founded[i].price <= avg:
                print(founded[i].info())

def quantified(q):
    return q.quantity

def sort_by_quantity(products_list):
    products_list.sort(reverse = False, key = quantified)
    for i in range(n):
        print(products_list[i].info())

def delete_by_name(products_list, name):
    found = 0
    i = 0
    while i < len(products_list):
        named = products_list[i].name
        if name == named:
            if products_list[i].quantity <= 3:
                products_list.remove(products_list[i])
                i -= 1
            found += 1
        i += 1
    if found == 0:
        print('Wrong name!!!')
    for i in range(len(products_list)):
        print(products_list[i].info())

search_by_barcode(products_list, randint(1000000000000, 9999999999999))
search_by_manufacturer(products_list, "KFM")
sort_by_quantity(products_list)
delete_by_name(products_list, "Nadenica")