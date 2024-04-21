from random import randint

target = str(randint(1000,9999))

def check (guess):
    a = 0
    b = 0
    for n in range(0,4):
        if guess[n] == target [n]:
            a += 1
        elif guess[n] in guess:
            b += 1
    if guess == target:
        return True
    else:
        print (str(a) + " A (Bulls) {} B (Cows)".format(b))
        return False


attempt = 0
print(target)
while True:
    c = check(input("Please input 4 digits: "))
    if c == True:
        print("You Win!")
        print("Attempts: {}".format(attempt))
        exit()
    else:
        attempt += 1


#Suggested Answer

# pseudocode:
# 1. generate the target (4 digits)
import random
WIDTH = 4
numList = [1,2,3,4,5,6,7,8,9,0]
def genNumbers(numList, count):
    random.shuffle(numList) #Create random list of 4 digits
    numbers = []
    for i in range(count):
        numbers.append(numList[i])
    return numbers #or use numbers = random.sample([1,2,3,4,5,6,7,8,9,0], 4)

# 2. get the number gussing from users
def userGuess():
    #get and check user input
    inputStr = input("Please input 4 digits: ")
    while inputStr.isdigit() == False or len(inputStr) != WIDTH: #input error checking
        inputStr = input("Wrong format!! Please input 4 digits: ")

    #Create user guess list of 4 digits
    guess = [] #empty list
    for i in range(WIDTH):
        num = int(inputStr[i])
        guess.append(num)

    return guess #input convert into list of 4 digits

# 3. compare the user guessing with target
def checkGuess(guessList, answerList):
    bulls = 0
    cows = 0

    #traverse and count
    for i in range(len(guessList)):
        for j in range(len(asnwerList)):
            if guessList[i] == answerList[i]:
                if i == j:
                    bulls += 1
                else:
                    cows += 1
    return (bulls, cows)

# 4. if user guessing is not correct, go to step 2
answer = genNumbers(numList, WIDTH)
#print answer

attempts = 0
while True:
    guesses = userGuess()
    attempts =+ 1
    #print guesses

    result = checkGuess(guesses, asnwer)
    #print result

    if result[0] == WIDTH:
        print ("You Win!!")
        print ("Attempts: {}", attempts)
        break

    else:
        print(result[0], "A (Bulls)", result[1], "B(Cows)")

# 5. if user guessing hits, terminate the game

