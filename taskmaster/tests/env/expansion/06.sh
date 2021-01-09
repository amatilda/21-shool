# Тест только для expansion

# ${parameter:?word}
echo 'Тестируем ${parameter:?word}: parameter - set, word - empty'
zzzz=set
echo ${zzzz:?}
echo $zzzz
