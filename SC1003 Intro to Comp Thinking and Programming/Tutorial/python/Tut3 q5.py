#Write a Python program, in the fewest number of lines possible, which creates a list
#of all the square numbers: x2 (where 1<=x<=100) that are divisible by 3.
list1 = []
for num in range (1,101):
    if (num ** 2) % 3 == 0:
        list1.append(num ** 2)
print(list1)


#soln 2 list comprehension
# list1 = [x**2 for x in range(1,101) if x**2%3 ==0]
# print(list1)dataBase [(group, id)] = score