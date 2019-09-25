amount = int(input("Enter amount: "))

#Conventional Way

# if(amount>500) and (amount<=1000):
#     print("Discounted amount is: ",amount-(amount*0.05))
# elif(amount>1000) and (amount<=2000):
#     print("Discounted amount is: ",amount-(amount*0.10))
# elif amount > 2000:
#     print("Discounted amount is: ",amount-(amount*0.15))
# else:
#     print("Amount is:",amount)

#Efficient Way
if amount <= 0:
    print("Invalid Amount.")
elif amount<=500:
    print("Discounted amount is: ",amount)
elif amount<=1000:
    print("Discounted amount is: ",amount-(amount*0.05))
elif amount <= 2000:
    print("Discounted amount is: ",amount-(amount*0.10))
else:
    print("Amount is:",amount-(amount*0.15))