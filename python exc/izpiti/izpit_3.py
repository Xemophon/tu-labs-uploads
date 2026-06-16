class Person():
    def __init__(self, id, name, gender, birth_date):
        self.id = id
        self.name = name
        self.gender = gender
        self.birth_date = birth_date
    def data_p(self):
        return self.id, self.name, self.gender, self.birth_date

class Student(Person):
    def __init__(self, id, name, gender, birth_date, year, status):
        super().__init__(id, name, gender, birth_date)
        self.year = year
        self.status = status
        
    def change_status(self):
        self.status = input("Active or inactive: ").lower()

    def data_s(self):
        return self.id, self.name, self.gender, self.birth_date, self.year, self.status

p1 = Person(123131231, "John Doe", "male", "14.06.2012")
p2 = Student(12123123123, "Ivan Ivanov", "male", "23.02.2006", "first year", "active")