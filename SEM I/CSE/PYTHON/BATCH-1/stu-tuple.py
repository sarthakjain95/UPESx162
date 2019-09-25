book_details = ()

# Store details of any 5 books
for i in range(2):
    book_name = input("Enter book name: ")
    book_price = float(input("Enter book price: "))
    book_year = int(input("Enter publishing year: "))
    book_details = book_details+((book_name, book_price, book_year),)
#print(book_details)

# Display all book details

# Find the sum of cost of all books
sum_ = 0
for i in book_details:
        sum_ += i[1] #Price
print("Sum of books is: ", sum_)

# Find the costliest book
# Display the books published before 2010