from sense_hat import SenseHat
sense = SenseHat()
from time import sleep
from random import randint

w = (255,255,255)
b = (0, 0, 0)
r = (255, 0, 0)
g = (0, 255, 0)
# while True:
#     pitch = sense.get_orientation()['pitch']
#     roll = sense.get_orientation()['roll']
#     print("pitch {0} roll {1}".format(round(pitch,0), round(roll,0)))
# sleep(0.05)

board = [[r,r,r,r,r,r,r,r],
         [r,b,b,b,b,b,b,r],
         [r,b,b,b,b,b,b,r],
         [r,b,b,b,b,b,b,r],
         [r,b,b,b,b,g,b,r],
         [r,b,b,b,b,b,b,r],
         [r,b,b,b,b,b,b,r],
         [r,r,r,r,r,r,r,r] ]


y=2                     # y coordinate of marble
x=2                     # x coordinate of marble
board[y][x] = w   # a white marble

board_1D=sum(board,[])        # convert to 1-dimension list
#print(board_1D)               # for code debugging
sense.set_pixels(board_1D)    # display it

# This function checks the pitch value and the x coordinate
# to determine whether to move the marble in the x-direction.
# Similarly, it checks the roll value and y coordinate to
# determine whether to move the marble in the y-direction.
def move_marble(pitch,roll,x,y):
    new_x = x    #assume no change to start with
    new_y = y    #assume no change to start with
    if 1 < pitch < 179 and x != 0:
        new_x -= 1    # move left
    elif 359 > pitch > 179 and x != 7:
        new_x += 1    # move right

    if 1 < roll < 179 and y != 7:
        new_y += 1    # move up
    elif 359 > roll > 179 and y != 0:
        new_y -= 1    # move down

    new_x,new_y = check_wall(x,y,new_x,new_y)
    game_over(new_x,new_y)
    return new_x, new_y

def check_wall(x,y,new_x,new_y):
    if board[new_y][new_x] != r:
        return new_x, new_y
    elif board[new_y][x] != r:
        return x, new_y
    elif board[y][new_x] != r:
        return new_x, y
    else:
        return x,y

def game_over(new_x,new_y):
    if board[new_y][new_x] == g:
        sense.show_message('yay!!')
        exit()


# while not game_over:
#     pitch = sense.get_orientation()['pitch']
#     roll = sense.get_orientation()['roll']
#     x,y = move_marble(pitch,roll,x,y)
#       :               # add your code here

# sense.show_message('yay!!')


while True:

    pitch = sense.get_orientation()['pitch']
    roll = sense.get_orientation()['roll']
    board[y][x] = b
    x,y = move_marble(pitch,roll,x,y)
    board[y][x] = w
    sense.set_pixels(sum(board,[]))
    sleep(0.05)