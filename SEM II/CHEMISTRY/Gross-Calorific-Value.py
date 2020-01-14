# Calculate Gross Calorific Value using Dulong Formula

per_carbon = int(input("Enter percentage of C: "))
per_hydrogen = int(input("Enter percentage of H: "))
per_oxygen = int(input("Enter percentage of O: "))
per_sulphur = int(input("Enter percentage of S: "))

calorific_value = ((8080*per_carbon) + 34500*(per_hydrogen - (per_oxygen)/8) + 2240*per_sulphur)/100

print("Calorific Value for the fuel is:", calorific_value, "kcal/kg.")
