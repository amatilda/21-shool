# Тест только для heredoc
unset zzz
cat -e << БРЕД -b | cat -e

dsgd
${zz:?}
echo 'Не Отобразиться'