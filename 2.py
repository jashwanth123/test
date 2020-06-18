# Taking input
input = input()
length = len(input)

i=0
strings_list = []

pre_index = 0

# Storing the words in the list

while i < length:
    if input[i]==" ":
        strings_list.append(input[pre_index:i])
        pre_index=i+1
    i+=1

# This will take care of the last word
strings_list.append(input[pre_index:i])


dual_list = []
words_count = len(strings_list)

# For each word in the above list generating pairs of letters
j=0
while j < words_count:
    k=0
# This will take care of single lettered words
    while k<len(strings_list[j])-1:
        dual_list.append(strings_list[j][k:k+2])
        k+=1
    j+=1

# Using python inbuilt function to agg words list
count_of_words = {x:dual_list.count(x) for x in dual_list}

# Sorting in the descending order of the counts
sorted_count_of_words = sorted(count_of_words.items(), key=lambda x: x[1], reverse=True)

# Since the output above is List(Tuple) converting it into dictionary

sorted_histogram = {}

# Populating the dictionary
for i in sorted_count_of_words:
    sorted_histogram[i[0]]=i[1]

print(sorted_histogram)
