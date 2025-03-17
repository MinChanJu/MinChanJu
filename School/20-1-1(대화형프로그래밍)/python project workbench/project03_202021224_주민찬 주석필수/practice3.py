Qsec=10000+203
sec=Qsec%60
min=Qsec//60
hour=min//60
min-=60*hour
print(hour,':',min,':',sec)
