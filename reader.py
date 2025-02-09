class Reader:
    first_name: str
    last_name: str

    def __init__(self, first_name: str, last_name: str):
        self.first_name = first_name
        self.last_name = last_name
        self.books = []

    def __str__(self):
        return f"Reader(first_name='{self.first_name}', last_name='{self.last_name}')"

    def print_books(self):
        if len(self.books) == 0:
            print("No books found.")
            return

        print(f"Books borrowed by {self.first_name} {self.last_name}:")
        for book in self.books:
            print(f"- {book.title} by {book.author}")

    def add_book(self, the_book):
        self.books.append(the_book)


if __name__ == "__main__":
    # Example usage
    from book import Book

    reader1 = Reader("John", "Doe")
    reader2 = Reader("Jane", "Smith")

    book1 = Book("To Kill a Mockingbird", "Harper Lee")
    book2 = Book("1984", "George Orwell")

    reader1.add_book(book1)
    reader1.add_book(book2)
