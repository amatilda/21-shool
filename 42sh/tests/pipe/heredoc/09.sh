# Тест только для heredoc
cat -e << БРЕД -b | cat -e

dsgd
${zz:?}

echo 'Не Отобразиться'