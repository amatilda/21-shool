# Тест только для expansion

# ${parameter:?word}
unset zzzz
echo 'Тестируем ${parameter:?word}: parameter - unset'
echo ${zzzz:?'А мы все тестим'}
echo $zzzz

