start = 0
subarrays = []
string = input("Enter string")
for i, el in enumerate(string):
    if el in string[start:i]:
         subarrays.append((start, i -1))
         start = string.find(el, start, i) + 1

subarrays.append((start, len(string) - 1))


max = 0
max_subarray = ""
for start, end in subarrays:
    if end - start >= max:
        max = end - start
        max_subarray = string[start:end+1]

print(max_subarray)
