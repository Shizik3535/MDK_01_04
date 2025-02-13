class Book:
    def __init__(self, title, author, id, is_available):
        self.title = title
        self.author = author
        self.id = id
        self.is_available = is_available

    def __str__(self):
        return "%s %s %d %d" % (self.title, self.author, self.id, self.is_available)


if __name__ == '__main__':
    print('Печать модуля')
    book1 = Book("Идиот", "Ф.В. Достоевский", 1, 1)
    book2 = Book("Сияние", "С. Кинг", 2, 0)
    book3 = Book("Пять поросят", "А. Кристи", 3, 1)

    books = [book1, book2, book3]
    books.sort(key=lambda book: book.title)
    print(*books, sep="\n")

    f = open("books.txt", "w")
    for book in books:
        print(book, file=f)
    f.close()
