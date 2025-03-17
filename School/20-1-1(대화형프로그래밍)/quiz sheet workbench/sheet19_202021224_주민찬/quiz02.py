store = {'연필':'200원', '펜':'800원', '지우개':'500원', '자':'300원'}

print('1:', list(store.values()))
print('2: 이 문구점에서 지우개는', '지우개' in store, '이다')
print('3: 이 문구점에서 공책은', '공책' in store, '이다')
store['파일'] = '1000원'
print('4:', store)
print('5:', store.keys())
