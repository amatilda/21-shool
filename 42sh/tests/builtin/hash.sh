# Тест только для hash

echo 'При первом юзание в скрипте всегда ничего не выводит'
hash

echo 'hash - подерживает любые имена'
hash 113213=hfghfghfg

echo 'hash - добавим'
hash ls='/bin/ls ghjghjghjgh'
hash ls2='/bin/ls'

echo 'hash - отобразим что добавили'
hash

echo 'Запустим хешированое ранее'
113213
ls
ls2

echo 'Проверим неизвестные опции'
hash --
hash -drghd
hash -фваыфафы
hash -t

echo 'Сбросим хеш и отобразим он должен быть пуст'
hash -r
hash

# ##############################
echo 'Это должно всегда отображаться'