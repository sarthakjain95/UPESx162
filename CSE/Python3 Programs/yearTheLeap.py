
# UPESx162
# CSE / Python3 Programs
# LeapYearChecker
# Recommended execution on https://repl.it/languages/python3

def isLeap(year):
        if year<0:
                return False
        if year%4==0:
                if year%100==0 and (year/100)%4!=0:
                        return False
                else:
                        return True
        return False 

# https://github.com/sarthakjain95
# Sarthak Jain