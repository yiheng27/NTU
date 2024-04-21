# from sense_hat import SenseHat
# sense = SenseHat()

#Ask Red Text
MaxTries = 3
tries = 1
while tries <= MaxTries:
    TextR = (input("Red value for text color: "))
    if TextR.isdigit() == False: #Check if inputs are digits
        print ("Invalid, use numbers only, ({})".format(tries))
        tries += 1
    elif int(TextR) > 255 or int(TextR) < 0: #Check if inputs are within range of 0-255
        print ("Value has to be between 0 and 255 ({})".format(tries))
        tries += 1
    else: #save input and exit loop
        TextRint = int(TextR)
        break
else: #Exceed number of trials, end program
    print('You have exceeded the number of trials allowed. Bye!')
    exit()

#Redo for green
tries = 1
while tries <= MaxTries:
    TextG = (input("Green value for text color: "))
    if TextG.isdigit() == False:
        print ("Invalid, use numbers only, ({})".format(tries))
        tries += 1
    elif int(TextG) > 255 or int(TextG) < 0:
        print ("Value has to be between 0 and 255 ({})".format(tries))
        tries += 1
    else:
        TextGint = int(TextG)
        break
else:
    print('You have exceeded the number of trials allowed. Bye!')
    exit()

#Redo for blue
tries = 1
while tries <= MaxTries:
    TextB = (input("Blue value for text color: "))
    if TextB.isdigit() == False:
        print ("Invalid, use numbers only, ({})".format(tries))
        tries += 1
    elif int(TextB) > 255 or int(TextB) < 0:
        print ("Value has to be between 0 and 255 ({})".format(tries))
        tries += 1
    else:
        TextBint = int(TextB)
        break
else:
    print('You have exceeded the number of trials allowed. Bye!')
    exit()


color_msg = TextRint, TextGint, TextBint


# speed = float(input("scroll speed (default is 0.1): "))
# sense.set_rotation(180)
# sense.show_message("This is fun!", text_colour = color_msg, back_colour = (0,0,0), scroll_speed = speed)



# MaxTries = 3
# tries = 1
# while tries <= MaxTries:
#     try:
#         TextR = (input("Red value for text color: "))
#     except ValueError:
#             print ("Invalid, use numbers only, ({})".format(tries))
#             tries += 1
#     if int(text) > 255 or int(text) < 0: #Check if inputs are within range of 0-255
#         print ("Value has to be between 0 and 255 ({})".format(tries))
#         tries += 1
#     else: #save input and exit loop
#         textValue = int(text)
# else: #Exceed number of trials, end program
#     print('You have exceeded the number of trials allowed. Bye!')
#     exit()

# TextR = (input("Red value for text color: "))