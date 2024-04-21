# Q1
# Develop a Python function inputRecord(dataBase, group, id, score) for TAs to enter one record,
# where dataBase is the database implemented by your data structure,
# group is a string representing a group name,
# id is a student’s id number (positive integers ranging from 1 to 40),
# and score is the grade of the student.

#{'group': 'FE1', 'score':50, 'ID': 11}
#def read_data()
#   groupName = input("input group name")
#sID = int(input("..."))
#score = int(input("..."))
# return { ('group'):groupName,    #can return a list instead of dict, and process the list
#         ('ID'):sID,               #simplest is to just return the 3 variables.
#         ('score'):score
# }
#def insertRecord(dataBase, group, id, score):
#   dataKey = (group,id)
#   dataBase[dataKey] = score


def inputRecord(dataBase, group, id, score):
    dataBase [(group, id)] = score
    print (dataBase)

dB = input("input database ")
dB = {}
grp = input("input group ")
id = int(input("input id "))
score = int(input("input score "))
inputRecord(dB, grp, id, score)

# Q2
# Develop a Python function query(dataBase, group, id) for TAs to get the score of a student in a lab group,
# where dataBase is the database implemented by your data structure, group is a string representing a group name,
# and id is the student’s id.
# This function should return the score.
#
#  def query(dataBase, group, id):
#     try:
#         key = (group, id)
#         return dataBase[key]
#     except KeyError: #Exception handling, KeyError (when key is not found in dictionary)
#         return None

def query(dataBase, group, id):
    print (dataBase [(group, id)])
    return dataBase [(group, id)]

# Q3
# Develop a Python function listGrades(dataBase, group) for TAs to get all the student grades in a group,
# where dataBase is the database implemented by your data structure and group is a string representing a group name.
# This function should return a list of grades in the group.

# def listGrades(dataBase, group):
#     listOfScores = []
#     for key, value in dataBase.items(): #dataBase.items() returns all key:value pairs
#         if key[0] == group:   #key[0] --> first element e.g 'FS6' in ('FS6', 55): 80
#             listOfScores.append(value)
#     return listOfScores

def listGrades(dataBase, group):
    if

# Q4
# Develop a Python function maxGrade(dataBase, group) for TAs to get the highest grade in a group,
# where dataBase is the database implemented by your data structure and group is a string representing a group name.
# This function should return the highest grade.

# def maxGrade(dataBase, group):
#     scores = listGrades(dataBase, group)
#     return max(score)

def maxGrade(dataBase, group):
    for

# main #
#grades = {}
#data = read_data()
#print(data)
#while data['score']!= -1:
#   insertRecord)grades, data['group'], data['ID'], data['score'])
#   data = read_data()
#print(grades)