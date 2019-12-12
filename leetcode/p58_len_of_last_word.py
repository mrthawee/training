def lengthOfLastWord(str):
    words = str.split(' ')
    print(words)
    for w in words[::-1]:
    #for w in reversed(words):
        #print(len(w), 'w=', w)
        if len(w) != 0:
            return len(w)
    return 0  # for empty string

str = 'I '
print(lengthOfLastWord(str))
