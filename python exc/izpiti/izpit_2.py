class ClothesShop:
    def __init__(self, id, type, brand, price, quantity):
        self.id = id
        self.type = type
        self.brand = brand
        self.price = price
        self.quantity = quantity
    
    def cloth_info(self):
        return self.id, self.type, self.brand, self.price, self.quantity
    
    def change_price(self):
        self.price = float(input("Enter new price: "))
    
    def change_quantity(self):
        self.quantity = float(input("Enter new quantity: "))
    
clt1 = ClothesShop(1, "Coat", "Adibas", 12.50, 3)
clt2 = ClothesShop(2, "Flops", "Adibas", 25.50, 9)
clt3 = ClothesShop(3, "Fishnet", "Filia", 69.42, 6)
clothes_list = [clt1, clt2, clt3]

def search_by_id(clothes_list, id):
    for sid in clothes_list:
        if sid.id == id:
            print(f"The cloth is {sid.cloth_info()}")
            return
    print("Not found")

def search_by_brand(clothes_list, brand):
    found_count = 0
    for sbrand in clothes_list:
        if sbrand.brand.lower() == brand.lower():
            print(sbrand.cloth_info())
            found_count += 1
    if found_count == 0:
        print("Not found")
    else:
        pass

def sell_cloth_by_id(clothes_list, id, num):
    found_count_1 = 0
    for s2id in clothes_list:
        if s2id.id == id:
            if num <= s2id.quantity:
                s2id.quantity -= num
                print(f"Success! {num} are sold.")
            else:
                print("Not available")
                pass
            found_count_1 += 1
    if found_count_1 == 0:
        print("Not found")
    else:
        pass    