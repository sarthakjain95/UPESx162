book_details = ()

# Store details of any 5 books
for i in range(2):
    book_name = input("Enter book name: ")
    book_price = float(input("Enter book price: "))
    book_year = int(input("Enter publishing year: "))
    book_details = book_details+((book_name, book_price, book_year),)
print("\n")

# Display all book details
for i in book_details:
    print("Book name is:", i[0], "and author is", i[1], "and publishing year is", i[2])
print("\n")

# Find the sum of cost of all books
sum_ = 0
for i in book_details:
        sum_ += i[1] #Price
print("Sum of books is: ", sum_)
print("\n")

# # # Find the costliest book
# max_cost = book_details[0][1]
# index_tuple = 0
# for k in range(len(book_details)):
#     if max_cost < book_details[k][1]:
#         max_cost = book_details[k][1]
#         index_tuple = book_details.index(k)
# print("Book details of costliest book is: ", book_details[index_tuple])

# # Display the books published before 2010
# for ele in range(len(book_details)):
#     if book_details[ele][2] > 2010:
#         print("Book details of the new books are: ", book_details[ele])

#Display book names starting with A
print("\n")
for ele in range(len(book_details)):
    bookname = book_details[ele][0]
    if bookname[0] == 'A' or bookname[0]=='a':
        print("Book name is:", book_details[ele][0], "and author is", book_details[ele][1], "and publishing year is", book_details[ele][2])

print("\n")
for ele in range(len(book_details)):
    if book_details[ele][2] > 2015 and ((book_details[ele][1] >= 200) and (book_details[ele][1] <= 500)):
        print("Book details of the books are: ", book_details[ele])

#Ascending order
book_details_ = list(book_details)
temp = book_details_[0][1]
for ele in range(len(book_details_)):
    if book_details_[ele][1] < book_details_[ele-1][1]:
        temp = book_details_[ele][1]
        book_details_[ele][1] = book_details_[ele-1][1]
        book_details_[ele-1][1] = temp
print(book_details_)