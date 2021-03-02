import re
import string
import sys

class ngram:
    def __init__():
        argArray = sys.argv
        n = sys.argv[1]
        m = sys.argv[2]
        i = 3
        text = []
        for i in range(len(argArray)):
            f = open(sys.argv[i])
            text = text + f.read()
        interpretFile(text)

    def interpretFile(text):
        words = []
        for word in text.split:
            word = word.strip(",:;-_")
            word = word.lower()
            if len(word) > 0:
                words.append(word)
        

            

    def main():
        print("something")

    if __name__ == "__main__": 
        main()