import re
import string
import random

class eliza:

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
      #userInput(flag)

    isFound = re.compile(r'is+([^.]*)')
    isMatch = isFound.findall(user_input)

    if len(isMatch) > 0 and flag == 0:
      isWord = isMatch[0].replace('i', 'you')
      isWord = isMatch.replace('I', 'you')
      isWord = isMatch.replace('me', 'you')
      isWord = isMatch.replace('my', 'your')

    wasFound = re.compile((r'was+([^.]*)')
    #wasMatch = wasFound.findall(user_input)
    if len(wasMatch) > 0 and flag == 0:
      wasWord = wasMatch[0].replace('i', 'you')
      wasWord = wasMatch.replace('I', 'you')
      wasWord = wasMatch.replace('me', 'you')
      wasWord = wasMatch.replace('my', 'your')

    wasntFound = re.compile((r'wasn\'t+([^.]*)')
    wasntMatch = wasntFound.findall(user_input)
    if len(wasntMatch) > 0 and flag == 0:
      wasntWord = wasntMatch[0].replace('i', 'you')
      wasntWord = wasMatch.replace('I', 'you')
      wasntWord = wasMatch.replace('me', 'you')
      wasntWord = wasMatch.replace('my', 'your')

      
  def main():
    print("Hi, I'm a psychotherapist. What's your name?")
    flag = 0
    while flag != 1:
      user_input = userInput()
      respond(user_input)

  if __name__ == "__main__":
    main()
