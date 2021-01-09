# Тест только для expansion

# ${parameter:?word}
echo 'Тестируем ${parameter:?}: parameter - null, word - empty'
zzzz=
echo ${zzzz:?}
echo $zzzz
