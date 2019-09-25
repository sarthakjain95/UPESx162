marks = int(input("Enter marks: "))
if marks < 0 or marks > 100:
    print("Invalid Marks.")
elif marks <= 35:
    print("Fail.")
elif marks<50:
    print("C+ grade.")
elif marks<60:
    print("B grade.")
elif marks<70:
    print("B+ grade.")
elif marks<80:
    print("A grade.")
elif marks<90:
    print("A+ grade.")
else:
    print("O grade.")