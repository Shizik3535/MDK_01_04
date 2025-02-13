# Задание: Управление библиотекой
# Необходимо разработать систему управления библиотекой, используя классы и объекты в Python.
# Система должна позволять добавлять книги, искать книги, выдавать книги читателям и отображать информацию о библиотеке.
import book
from reader import Reader


class Library:
    def __init__(self, name, lib_id):
        self.name = name
        self.lib_id = lib_id
        self.books = []
        self.readers = []

    def __str__(self):
        return f"{self.name} {self.lib_id} {self.books}"

    def add_book(self, the_book):
        self.books.append(the_book)

    def add_reader(self, the_reader):
        self.readers.append(the_reader)


book1 = book.Book("Идиот", "Ф.В. Достоевский", 1, 1)
book2 = book.Book("Сияние", "С. Кинг", 2, 0)
book3 = book.Book("Пять поросят", "А. Кристи", 3, 1)

reader1 = Reader("John", "Doe")
reader2 = Reader("Jane", "Smith")


lib = Library("KMPO", 1)
lib.add_book(book1)
lib.add_book(book2)
lib.add_book(book3)
lib.add_reader(reader1)
lib.add_reader(reader2)

lib.books.sort(key=lambda book: book.title)
print(*lib.books, sep="\n")

f = open("books.txt", "w")
for book in lib.books:
    print(book, file=f)
f.close()
