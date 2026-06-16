#Shape task
class Shape():
    def __init__(self, side):
        self.side = side

class Circle(Shape):
    def __init__(self, side):
        super().__init__(side)
    
    def area(self):
        print(3.14 * (self.side ** 2))

class Square(Shape):
    def __init__(self, side):
        super().__init__(side)
    
    def area(self):
        print(self.side ** 2)

class Triangle(Shape):


    def __init__(self, side):
        super().__init__(side)
    
    def area(self):
        print((self.side ** 2) * (3 ** 0.5) * (0.25))

#Book Task
class Book():
    def __init__(self, title, author, availability):
        self.title = title
        self.author = author
        self.availability = availability

class Library(Book):
    def __init__(self, title, author, availability, count):
        super().__init__(title, author, availability)
        self.count = count
        self.books = {}

    def sumamry(self):
        return self.title, self.author, self.count

    def add_book(self, amount):
        if self.title in self.books.keys():
            self.books[self.title] += amount
            print(f"Added {self.count} instances of {self.title}")
        else:
            self.count += amount
            self.books.update({self.title : self.count})
            print("Added new book to library")
    
    def borrow_book(self):
        for i in range(len(self.books)):
            if self.title in self.books.keys():
                if self.count >= 1:
                    self.count -= 1
                    print("Borrowed")
                else:
                    print("Unavaiable")
            else:
                print("Unavaiable")

    def return_book(self):
        for i in range(len(self.books)):
            if self.title in self.books.keys():
                self.count += 1
        print("Returned")
b1 = Library("Mein Kempf", "Adolf Hitler", "available", 3)