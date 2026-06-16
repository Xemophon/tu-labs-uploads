#zad6
class Bank_System():
    def __init__(self, balance):
        self.balance = balance
    
    def deposit(self):
        deposit = float(input("Enter desired deposit: "))
        if deposit <= 0:
            print("Can't deposit negative number, blud")
        else:
            self.balance += deposit
            return(print(self.balance))
    
    def withdraw(self):
        withdraw = float(input("Enter desired withdraw: "))
        if withdraw > self.balance:
            print("Not enough assets")
        else:
            self.balance -= withdraw
            return(print(self.balance))
        
    def get_balance(self):
        print(f"Current balance is {self.balance}")

class Savings_Account(Bank_System):
    def __init__(self, balance, interes_rate, savings):
        super().__init__(balance)
        self.interes_rate = interes_rate
        self.savings = savings
    
    def get_savings(self):
        return(print(f"{self.savings} are available"))
    
    def calc_ints(self):
        dur = float(input("Enter years: "))
        return(print(dur * self.interes_rate * self.savings + self.savings))


ch = 0
p1 = Savings_Account(120000, 0.05, 900)

while True:
    print("Welcome to KaputBank")
    ch = int(input("Choose from 0 to 5 "))
    if ch == 1:
        p1.deposit()
    elif ch == 2:
        p1.withdraw()
    elif ch == 3:
        p1.get_balance()
    elif ch == 4:
        p1.get_savings()
    elif ch == 5:
        p1.calc_ints()
    else:
        break