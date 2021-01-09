# Тест только для test

tempos=$tmp_dir'zzzz'

echo 'Флаг -b: истина, если файл существует и специальное блочноное устройство.'
test -b /dev/disk0;echo $?

echo 'Флаг -c: истина, если файл существует и символьное устройство.'
test -c /dev/random;echo $?

echo 'Флаг -d: истина, если файл существует и является каталогом.'
test -d ~;echo $?

touch $tempos

echo 'Флаг -e: истина, если файл существует.'
test -e $tempos; echo $?

echo 'Флаг -f: истина, если файл существует и является обычным файлом.'
test -f $tempos; echo $?

chmod 7777 $tempos
echo 'Флаг -g: истина, если файл существует и имеет установленным групповой идентификатор (set-group-id).'
test -g $tempos; echo $?
echo 'Флаг -u: истина, если файл существует и имеет установленным бит пользователя (set-user-id).'
test -u $tempos; echo $?
echo 'Флаг -k: истина, если файл существует и имеет установленным «sticky» бит.'
test -k $tempos; echo $?

echo 'Флаг -L: истина, если файл существует и является символьной ссылкой.'
test -L /tmp; echo $?
echo 'Флаг -h: истина, если файл существует и является символьной ссылкой.'
test -h /tmp; echo $?

rm -f $tempos
mkfifo $tempos

echo 'Флаг -p: истина, если файл существует и является именованным каналом (pipe).'
test -p $tempos; echo $?

echo 'Флаг -S: истина, если файл существует и является сокетом.'
test -S /var/run/systemkeychaincheck.socket; echo $?

rm -f $tempos
echo 'test' > $tempos
chmod 777 $tempos

echo 'Флаг -r: истина, если файл существует и читаем.'
test -r $tempos; echo $?

echo 'Флаг -s: истина, если файл существует и имеет размер больше, чем ноль.'
test -s $tempos; echo $?

echo 'Флаг -w: истина, если файл существует и записываем.'
test -w $tempos; echo $?

echo 'Флаг -x: истина, если файл существует и исполняем.'
test -x $tempos; echo $?

echo 'Флаг -O: истина, если файл существует и его владелец имеет эффективный идентификатор пользователя.'
test -O $tempos; echo $?

echo 'Флаг -G: истина, если файл существует и его владелец имеет эффективный идентификатор группы.'
test -G $tempos; echo $?

rm -f $tempos #После себя удалим временные файлы

echo 'Флаг -z: истина, если длина string равна нулю.'
test -z ""; echo $?

echo 'Флаг -n: истина, если длина string не ноль.'
test -n "hgfhgf"; echo $?

echo 'str1 = str2: истина, если строки  равны.'
test str = str; echo $?

echo 'str1 != str2: истина, если строки не равны.'
test str1 != str2; echo $?

echo 'arg1 -eq arg2: истина, если равно.'
test +1888 -eq 1888; echo $?
test +1888 -eq 176888; echo $?
test +1888 -eq -1888; echo $?

echo 'arg1 -ne arg2: истина, если не равно.'
test +1888 -ne 1888; echo $?
test +1888 -ne 176888; echo $?
test +1888 -ne -1888; echo $?

echo 'arg1 -lt arg2: истина, если меньше чем.'
test +1888 -lt 1888; echo $?
test +1888 -lt 176888; echo $?
test +1888 -lt -1888; echo $?

echo 'arg1 -le arg2: истина, если меньше чем или равно'
test +1888 -le 1888; echo $?
test +1888 -le 176888; echo $?
test +1888 -le -1888; echo $?

echo 'arg1 -gt arg2: истина, если больше чем'
test +1888 -gt 1888; echo $?
test +1888 -gt 176888; echo $?
test +1888 -gt -1888; echo $?

echo 'arg1 -ge arg2: истина, если больше чем или равно'
test +1888 -ge 1888; echo $?
test +1888 -ge 176888; echo $?
test +1888 -ge -1888; echo $?

echo '! expr: истина, если выражение expr ложь.'
test ! -n "hgfhgf"; echo $?
test ! +1888 -ge 1888; echo $?
test ! tfyhtfuyft; echo $?

echo 'Тест на ошибки'
test -фваыфафы
test +1888 -le +8888888878236479842365423467231888; echo $?
test +1888 -ge ++1888; echo $?
test !-n "hgfhgf"; echo $?
test -Q "hgfhgf"; echo $?
test -yjgh fgjh fgjghjfg "hgfhgf"; echo $?
test +1888 -lyyt -1888; echo $?


# ##############################
echo 'Это должно всегда отображаться'