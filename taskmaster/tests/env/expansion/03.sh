# Тест только для expansion

# ${parameter:?word}
echo 'Тестируем ${parameter:?word}: parameter - set'
zzzz=set
echo ${zzzz:?'А мы все тестим'}
echo $zzzz
