start = 0
subarrays = []
string = input("Enter string")
for i, el in enumerate(string):
    if el in string[start:i]:
         # subarray will be from start to before current character
         subarrays.append((start, i -1))
         # new start will be the character after the first occurrence of the current character
         start = string.find(el, start, i) + 1

# final subarray will be from current start to end of the string
subarrays.append((start, len(string) - 1))


max = 0
max_subarray = ""
for start, end in subarrays:
    if end - start >= max:
        max = end - start
        max_subarray = string[start:end+1]

print(max_subarray)
