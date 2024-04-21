# When choosing a password for online accounts, there are typically certain requirements for the strength of the password.
# Develop a Python program for testing if a string satisfies some appropriate criteria for a strong password.
# It’s up to you to define the requirements.

password = input("type in password ")
#Requirements: Length more than 8,1 upper, 1 lower, one digit
check = 0
if len(password) > 8:
    check += 1

if any(password.isdigit() for char in password):
    check += 1


print(check)
    # for a in password:
    #     if