#zad1
class Animal():
    def __init__(self, species, age, sound):
        self.species = species
        self.age = age
        self.sound = sound
    
    def make_sound(self):
        print(self.sound)

cat = Animal("Feline", 21, "Meow")
cat.make_sound()

#zad2
class Dog(Animal):
    def __init__(self, species, age, breed, sound):
        super().__init__(species, age, sound)
        self.breed = breed

    def make_sound(self):
        print(f"Dog of breed {self.breed} says Woof")

dog = Dog("Canine", 20, "Pomeran", "Woof")
dog.make_sound()

#zad3
class Vehicle():
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def info(self):
        return self.brand, self.model, self.year

v1 = Vehicle("Alfa Romeo", "Julieta", 2024)
print(v1.info())
    
#zad4
class Car(Vehicle):
    def __init__(self, brand, model, fuel_type, year):
        super().__init__(brand, model, year)
        self.fuel_type = fuel_type

    def info(self):
        return self.brand, self.model, self.fuel_type, self.year
    
c1 = Car("Alfa Romeo", "Julieta", 2024, "Diesel")
print(c1.info())

#zaad5
class Employee():
    def __init__(self, name, position, salary):
        self.position = position
        self.name = name
        self.salary = salary

    def describe(self):
        print(f"{self.name} is {self.position} and receives {self.salary} euro per month")
em1 = Employee("Jotaro", "Stripper", 3000)
em1.describe()
    
#zad6
class Manager(Employee):
    def __init__(self, name, position, team_size, salary):
        super().__init__(name, position, salary)
        self.position = "Manager"
        self.team_size = team_size

    def describe(self):
        print(f"{self.name} is Manager and receives {self.salary} per month with a team of {self.team_size} people")
mn1 = Manager("Josuke","Manager", 25, 3000)

#zad7
class Book():
    def __init__(self, title, author, pages):
        self.title = title
        self.author = author
        self.pages = pages

    def summary(self):
        print(f"{self.title} by {self.author} is {self.pages} pages")
b1 = Book("Treasure Island", "Robert Lewis Stevenson", 240)
b2 = Book("Jelezniq Svetilnik", "Dimitur Talev", 300)
b1.summary()
b2.summary()