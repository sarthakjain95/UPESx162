
#! /usr/bin/env python3

# How do you make N/20 NaOH solution that we use in labs ?

# W = ( N * equivalent_weight * volume_of_solution ) / 1000
 
print("*Enter Details*")

N= int(input("Normality:"))
E= float(input("Enter equivalent weight of Substance:"))
vol= float(input("Enter the volume of solution (in ml):"))

W= ( 1/N * E * vol ) / 1000

print("\nYou need {} gram(s) of the substance to make {}ml N/{} solution.".format(W,vol,N))
