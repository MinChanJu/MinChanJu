set1 = input('첫 번째 집합 원소 입력 : ')
set2 = input('두 번째 집합 원소 입력 : ')
set1 = set(set1.split())
set2 = set(set2.split())

if bool(set1 >= set2) == True :
    print('=> 부분 집합입니다.')
    print('=> 교집합은 {}입니다.' .format(set1 & set2))
else :
    print('=> 부분 집합이 아닙니다.')
    print('=> 합집합은 {}입니다.' .format(set1 | set2))
