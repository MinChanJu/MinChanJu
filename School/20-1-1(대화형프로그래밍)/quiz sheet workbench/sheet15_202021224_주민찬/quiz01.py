string = input('문자열을 입력하세요: ')

print('총 문자 개수:', len(string))
upstr = string.upper()
print('문자 P의 개수:', str(upstr.count('P'))+'개')
if 'A' in upstr :
    print('A가', str(upstr.count('A'))+'개 포함되어 있습니다.')
else :
    print('A가 포함되어 있지 않습니다.')
