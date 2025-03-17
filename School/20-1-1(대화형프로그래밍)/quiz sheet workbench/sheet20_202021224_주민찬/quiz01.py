setU = {'A','B','C','D','E','F','G','H','I','J','K','L','M'}
set1 = {'C','D','J','K','L'}
set2 = {'B','E','H','L'}

colorset = setU - (set1 | set2)
print(colorset)
