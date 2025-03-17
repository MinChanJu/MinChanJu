student = input('학생 이름, 학과를 입력하세요: ')

print(student.split(', '))
print('이름:', student.split(', ')[0].upper())
print('학과: **'+student.split(', ')[1].title()+'**')
