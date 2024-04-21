def reverser(a_str):
   if len(a_str) == 1:	# base case
      return a_str

   else:				# recursive step
      new_str = reverser(a_str[1:])+ a_str[0]
      return new_str

def reverseAndRepeat(a_str, num):
    if len(a_str) == 1:	# base case
        return a_str * num

    else:				# recursive step
      new_str = reverseAndRepeat(a_str[1:], num) + a_str[0] * num
      return new_str

# myStr = "ABC"
# str1 = reverseAndRepeat(myStr, 2)
# str2 = reverseAndRepeat(myStr, 3)

# print(str1)	# CCBBAA
# print(str2)	# CCCBBBAAA

def reverseAndOppositeCase(a_str):
    if len(a_str) == 1:	# base case
        if a_str.isupper():
            return a_str.lower()
        else:
            return a_str.upper()

    else:				# recursive step
        if a_str[0].isupper():
            new_str = reverseAndOppositeCase(a_str[1:])+ a_str[0].lower()
        else:
            new_str = reverseAndOppositeCase(a_str[1:])+ a_str[0].upper()
        return new_str


# myStr = "AbCdE"
# str1 = reverseAndOppositeCase(myStr)

# print(str1)	# eDcBa


def symmetricString(a_str):
    new_str = a_str + reverser(a_str) #This is non-recursive
    return new_str


# myStr = "AbCdE"
# str1 = symmetricString(myStr)

# print(str1)	# AbCdEEdCbA