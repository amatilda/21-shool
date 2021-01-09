# Тест только для redirect

tmp_out_1=$tmp_dir/tmp_out_1.c
tmp_out_2=$tmp_dir/tmp_out_2.c

tmp_exe=$tmp_dir/tmp_exe


#  ##############################
echo 'Скампилируем программу для проверки'
echo '
# include <unistd.h>
# include <stdlib.h>

int			main(int argc, char **argv)
{
	static char		buff[100];
	int				fd_in;
	int				fd_out;
	ssize_t			count;

	if (argc != 3)
	{
		write(STDERR_FILENO, "error arg\\n", 10);
		return (0);
	}
	fd_in = atoi(argv[1]);
	fd_out = atoi(argv[2]);
	if ((count = read(fd_in, buff, 99)) == -1 || count == 0)
	{
		write(STDERR_FILENO, "error read\\n", 11);
		return (0);
	}
	write(fd_out, buff, count);
	return (0);
}
' > $tmp_out_1
gcc $tmp_out_1 -o $tmp_exe
chmod 755 $tmp_exe

#  ##############################
echo 'Просто проверка на выход параметров в случае программ'
ls > $tmp_out_1
cat $tmp_out_1
ls 2> $tmp_out_1
cat $tmp_out_1
ls fdsfs 2> $tmp_out_1
cat $tmp_out_1
ls fdsfs 2>$tmp_out_1 2>&1
cat $tmp_out_1
ls | cat -e >$tmp_out_1
cat $tmp_out_1


echo 'Просто проверка на выход параметров в случае бултинов'
cd > $tmp_out_1
cat $tmp_out_1
echo 'Привет розы цветут и пахнут
и Не только так и еще много как - лала'> $tmp_out_1
cat $tmp_out_1


echo 'Просто проверка на вход параметров в случае программ'
cat <$tmp_out_1
cat <$tmp_out_1 -e -b
cat 2<$tmp_out_1 1<&-

echo 'Просто проверка на вход параметров в случае бултинов'
echo < $tmp_out_1


echo 'Просто проверка на не стандартные fd'
$tmp_exe 4<$tmp_out_1 4 0
$tmp_exe 9<$tmp_out_1 9 4 4>$tmp_out_2
cat $tmp_out_2


echo 'Просто проверка на дописывание'
echo "Припишем" >> $tmp_out_2
cat $tmp_out_2
ls ddfgdfgd ./ 2>> $tmp_out_2  >> $tmp_out_1 
cat $tmp_out_1
cat $tmp_out_2

ls ddfgdfgd ./ 2>> $tmp_out_2  | cat -e >> $tmp_out_1 
cat $tmp_out_1
cat $tmp_out_2

< $tmp_out_1
< $tmp_out_2

ls 9<&2 2>&9

ls 9<&2 9>&- 9>&2

#  ############################################################
echo 'Тут будет уже различия между оболочками'
echo "Не существующий файл"
cat <sadfsdfsd -b

< $tmp_out_1 -b
< $tmp_out_2 -b

ls 2>&9

ls 9<&2 9>&2

ls <&-fghfg

echo "fgtjhfhjfgвапрварварва" >&-fghfhfg

# Ошибки в синтаксисе ##############################
echo 'Тестируем: ошибки в синтаксисе'
./redirect/01.sh;echo $?
./redirect/02.sh;echo $?
./redirect/03.sh;echo $?
./redirect/04.sh;echo $?
./redirect/05.sh;echo $?
./redirect/06.sh;echo $?



# ##############################
echo 'Это должно всегда отображаться'
rm -f $tmp_out_1 $tmp_out_2 $tmp_exe #После себя удалим временные файлы

