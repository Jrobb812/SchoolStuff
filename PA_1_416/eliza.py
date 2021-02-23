import re
import string
import random

class Eliza:

  def userInput(self):
    if flag == 1:
      print()
    else:  
      user_input = input('> ')
      return user_input

  def respond(self, user_input):
    #checks to make sure user has not said "goodbye to eliza"
      flag = 0
      goodbyeFound = re.compile(r'goodbye+([^.]*)')
      goodbyeMatch = goodbyeFound.findall(user_input)
      if len(goodbyeMatch) > 0:
        flag = 1
        print("Goodbye, friend.")
        userInput(flag)
      isFound = re.compile(r'was+([^.]*)')
      isMatch = isFound.findall(user_input)
      if len(isMatch) > 0 and flag == 0:
        isWord = isMatch[0].replace('i', 'you')
        isWord = isMatch.replace('I', 'you')
        isWord = isMatch.replace('me', 'you')
        isWord = isMatch.replace('my', 'your')
  def main():
    flag = 0
    while flag != 1:
      user_input = userInput()
      respond(user_input)

  if __name__ == "__main__":
    main()
