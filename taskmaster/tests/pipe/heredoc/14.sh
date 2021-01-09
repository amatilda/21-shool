# Тест только для heredoc

unset zz ss
cat -e << БРЕД -b | cat -e

dsgd
${zz:?}
${ss:?}

echo 'Не отобразиться'