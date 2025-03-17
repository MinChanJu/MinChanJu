tupleA = (2, 0, 0, 2)
list = list(tupleA)
list[2],list[3] = list[3],list[2]
tupleB = tuple(list)

print(tupleA)
print(list)
print(tupleB)
