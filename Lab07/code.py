start = 0
subarrays = []
string = input("Enter string")
# string = "BITSPilaniGoaCampus";
length = 0;
answer = ""
for i, el in enumerate(string):
    if el in string[start:i]:
        # subarray will be from start to before current character
        if i - start >= length :
            answer = string[start:i]
            length = i - start
        # new start will be the character after the first occurrence of the current character
        start = string.find(el, start, i) + 1

# final subarray will be from current start to end of the string
if len(string) - start >= length :
    answer = string[start:len(string)]

print(answer)
