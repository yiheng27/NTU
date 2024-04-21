# Consider a system for storing anonymous grades of each lab class.
# Define a data structure, which can identify individuals in each lab group by an ID number 1-40 (inclusive).
# To identify the person in the entire class you would also need the group name, e,g., ‘FE2’.
# Each corresponding person should have a number between 1-100 (inclusive) to define grade.

from random import randint
SC3 = {}
for n in range (1,41):
    SC3[n] = randint(1,101)
print(SC3)



#soln 1: dictionary, key is a tuple (group_name, ID), value is the grade
#Key has to be immutable and unique

# Grades = {
# 	(‘FS1’,1) : 45,
# 	(‘FS1’, 2) :75,
# 	…
# 	(‘FS2’, 1) : 69
# }


#soln 2: dict, key is string of group name(immutable)
# value is list of grades in group
#ID= index + 1
# Grades2 = {
# 	‘FS1’: [45,75…]
# 	‘FS2’: [75, 40…]
# }
# print(grades2[‘FS1’][1])

