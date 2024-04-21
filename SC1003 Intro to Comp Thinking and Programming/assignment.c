/*The NTU Hotel has a capacity of MAX (e.g., 5 for this program) rooms. 
You are required to write a NTU Hotel Room Reservation Program. 
The program uses an array of MAX structures for hotel rooms. 
Each structure should hold:
- roomID – It stores the room identification number. 
- status – It stores a marker that indicates whether the room is assigned or not (i.e., EMPTY or TAKEN). 
- customerName – It stores the name of the customer who occupies the room.  

The roomID must be unique. 
Therefore, each Room structure will have a different number of roomID when it is created. 
You may assume that the name of a customer is not more than 20 characters long. 
In the program, it should display a menu to support the following functions: 

NTU HOTEL ROOM RESERVATION PROGRAM:  
1: listOccupiedRooms() 
2: assignRoom() 
3: removeRoom() 
4: findCustomer() 
5: quit 

The program should execute the functions (or options) of its menu. 
It will continue execution until the user selects to quit from the program.  
You are required to write the program and the functions according to the program requirements. 
Note that:
- You should design the program and define the functions according to the requirements.

- You only need to consider the requirements stated in the program specification, 
and you do not need to implement any user input checking which is not stated in the specification.

- You may add any other supporting functions in the program if needed.

- You may include any C library functions in your program if needed.

- Sample test case are given below. 
A sample program running session is given below 
(please note that the input data are shown in orange color): */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

void choice ();
void listOccupiedRooms();
void assignRoom();
void removeRoom();
void findCustomer();

//Rooms have roomID, status and customername
typedef struct
{
    int roomID;
    int status;
    char customerName[20];
}
Room;

Room rooms[5];


int main (void)
{
    //create a structure variable of Room called room
    rooms[0].roomID = 1;
    rooms[1].roomID = 2;
    rooms[2].roomID = 3;
    rooms[3].roomID = 4;
    rooms[4].roomID = 5;

    int choiced;
    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n"
            "1: listOccupiedRooms()\n"
            "2: assignRoom()\n"
            "3: removeRoom()\n"
            "4: findCustomer()\n"
            "5: quit\n"
            "Enter your choice: \n");
    scanf("%d", &choiced);
    //printf("%d", choice);
    switch(choiced)
        {
            case 1:
                listOccupiedRooms();
                break;
            case 2:
                assignRoom();
                break;
            case 3:
                removeRoom();
                break;
            case 4:
                findCustomer();
                break;
            case 5:
                return 0;
            default:
                printf("Wrong input!\n");
        }

}

//Choice
void choice (void)
{
    int choice;
    printf("Enter your choice: \n");
    scanf("%d", &choice);
    switch(choice)
        {
            case 1:
                listOccupiedRooms();
                break;
            case 2:
                assignRoom();
                break;
            case 3:
                removeRoom();
                break;
            case 4:
                findCustomer();
                break;
            case 5:
                return;
            default:
                printf("Wrong input!\n");
        }
    return;
}
/*(1) listOccupiedRooms() – The function prints the list of room assignments in hotel.  
Please note: 
- The function prints the following message when it is executed: "listOccupiedRooms():"

- If the hotel is empty, i.e., no room is occupied, 
the function should display the message: "The hotel is empty". */
void listOccupiedRooms(void)
{
    int count=0;
    printf("listOccupiedRooms():\n");
    for (int i=0; i<MAX; i++)
    {
        if (rooms[i].status == 1)
        {
            printf("roomID: %d\n", rooms[i].roomID);
            printf("customer name: %s\n", rooms[i].customerName);
            count++;
        }
    }
    if (count == 0)
    {
        printf("The hotel is empty\n");
    }
    choice();
}


/*(2) assignRoom() – The function assigns a customer to a room. 
It reads in the selected room number (roomID) and customer name from user, 
and then assigns the room accordingly. 
Please note:
- The function prints the following message when it is executed: "assignRoom():"

- After assigning a room suceessfully, #4
the function should display the message: "The room has been assigned successfully ".

- If the hotel is full (i.e. MAX) during room assignment, 
the function should display the message: "The hotel is full". #1

- If the selected room has been assigned to another customer already, 
the function should display the message: "Occupied! Enter another roomID". #3

- If the selected room number is not between 1 and MAX (i.e., 5), 
the function should display the  message: "Enter a roomID between 1 and 5".  #2
The function should continue to read a room number from the user. */
void assignRoom(void)
{
    int full=0, roomid=0;
    char *p;
    printf("assignRoom():\n");
    for (int i=0; i<MAX;i++) //#1
    {
        if (rooms[i].status == 1)
        {
            full++;
        }
    }
    if (full == MAX)
    {
        printf("The hotel is full\n");
        choice();
        return;
    }
    do //#2
    {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d",&roomid);
        if (rooms[roomid-1].status == 1)
        {
            printf("Occupied! Enter another roomID\n"); //#3
            roomid = 0;
        }
    }
    while (roomid<1 || roomid>5);

    printf("Enter customer name:\n");
    scanf("\n");
    fgets(rooms[roomid-1].customerName, 20, stdin);
    p=strchr(rooms[roomid-1].customerName,'\n');
    *p='\0';
    //printf("%s\n",rooms[roomid-1].customerName);
    rooms[roomid-1].status = 1;
    printf("The room has been assigned successfully\n"); //#4
    choice();
    return;
}

/*(3) removeRoom() – The function removes a room assignment. 
It reads in the selected room number (i.e. roomID) from user and then remove the assigned room accordingly.
Please note:
- The function prints the following message when it is executed: "removeRoom():"

- After room removal, the function should display the message: "Removal is successful". #4

- If all the rooms in the hotel are empty, 
the function should display the message: "All the rooms are empty". #1

- If the selected room is empty, #3
the function should display the message: "Empty! Enter another roomID for removal".

- If the selected room number is not between 1 and 5 (i.e., MAX), #2
the function should display the message: "Enter a roomID between 1 and 5". */

void removeRoom(void)
{
    int full=0, roomid=0;
    printf("removeRoom():\n");
    for (int i=0; i<MAX;i++) //#1
    {
        if (rooms[i].status == 1)
        {
            full++;
        }
    }
    if (full == 0)
    {
        printf("All the rooms are empty\n");
        choice();
        return;
    }

    do //#2
    {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d",&roomid);
        if (roomid<=5 && roomid>=1 && rooms[roomid-1].status == 0)
        {
            printf("Empty! Enter another roomID for removal\n"); //#3
            roomid = 0;
        }
    }
    while (roomid<1 || roomid>5);

    rooms[roomid-1].status = 0;
    for(int i=0; i<strlen(rooms[roomid-1].customerName);i++)
    {
        rooms[roomid-1].customerName[i]='\0';
    }
    printf("Removal is successful\n"); //#4
    choice();
    return;
}

/*(4) findCustomer() – The function finds the target customer name from the Room records stored in hotel, 
and prints the target room information to the screen.
Please note:
- The function prints the following message when it is executed: "findCustomer():"

- The function finds the first appearance of the target customer name in the array structure 
(i.e. according to roomID), and prints the corresponding target customer information to the screen.  

- The target string matching should be done irregardless of the letter cases 
(upper case letter and lower case letter will be treated to be the same).

- If target customer name is found in hotel, the function should display the message: 
"The target customer name is found" and display the room information of the corresponding customer.

- If target customer name does not exist in hotel, the function should display the message: 
"The target customer name is not found".*/

void findCustomer(void)
{
    int element=0, check=0;
    char name[20], lname[20],lcname[20], *p;
    printf("findCustomer():\n");
    printf("Enter customer name:\n");
    scanf("\n");
    fgets(name,20,stdin);
    p=strchr(name,'\n');
    *p='\0';

//convert search name to lower
    for (int i=0; i<strlen(name);i++)
    {
        lname[i]=tolower(name[i]);
    }

    for(int i=0; i<MAX;i++)
    {
        if (rooms[i].status == 0)
        {
            continue;
        }

        //clear lcname
        for(int k=0; k<20;k++)
        {
            lcname[k]='\0';
        }

        //put customer name into lcname
        for (int j=0; j<strlen(rooms[i].customerName);j++)
        {
            lcname[j]=tolower(rooms[i].customerName[j]);
        }

        //compare lname w lcname
        if (strcmp(lname, lcname) == 0)
        {
            element = i;
            check = 1;
            break;
        }
    }
    if (check == 0)
    {
        printf("The target customer name is not found\n");
        choice();
        return;
    }
    else
    {
        printf("The target customer name is found\n");
        printf("roomID: %d\n", rooms[element].roomID);
        printf("customer name: %s\n",rooms[element].customerName);
        choice();
        return;
    }
}