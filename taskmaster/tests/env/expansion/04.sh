# Тест только для expansion


# ${parameter:?word}
unset zzzz
echo 'Тестируем ${parameter:?}: parameter - unset, word - empty'
echo ${zzzz:?}
echo $zzzz

