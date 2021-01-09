# Тест только для expansion

# ${parameter:?word}
echo 'Тестируем ${parameter:?word}: parameter - null'
zzzz=
echo ${zzzz:?'А мы все тестим'}
echo $zzzz
