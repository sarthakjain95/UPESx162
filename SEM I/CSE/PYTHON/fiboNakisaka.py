
# UPESx162
# CSE / Python3 Programs
# fibonacciNumberFinder
# Recommended execution on https://repl.it/languages/python3

def getFibnacciSeriesUpto(n):
        if n<0:
                return -1
        nums=[0,1];
        n1,n2 = 0,1
        while len(nums)<n:
                n1,n2=n2,n1+n2
                nums.append(n2)
        return nums   

# https://github.com/sarthakjain95
# Sarthak Jain