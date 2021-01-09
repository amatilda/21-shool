
export tmp_dir='/tmp/A02A174F3F3846E2A6CF58A2FF938CCC/' # Временная директория где будем все временные файлы сохранять
export READ #=/usr/bin/read #Что бы прогнать автоматом без пауз
out42sh=$tmp_dir'42sh.out' # Создадим переменные куда будем записывать файлы сравнения
outzsh=$tmp_dir'zsh.out' # Создадим переменные куда будем записывать файлы сравнения
outbash=$tmp_dir'bash.out' # Создадим переменные куда будем записывать файлы сравнения
diff1=$tmp_dir'diff1.command' # Создадим для сравнения и запуска в отдельном окне
diff2=$tmp_dir'diff2.command' # Создадим для сравнения и запуска в отдельном окне

rm -fr $tmp_dir # На всякий случай все удалим
mkdir $tmp_dir # Создадим дерикторию для тестов

echo '\033[1m ВНИМАНИЕ!!! результаты тестов недолжны быть полностью индетичны между оболочками. \033[0m'

##############################
cd './other' # Перейдем в папку где будем тестить
cmp='./calc.sh' # То что будем тестить
name='other calc'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

exit 0

##############################
cd './other' # Перейдем в папку где будем тестить
cmp='./chek_list.sh' # То что будем тестить
name='other chek_list'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp  # Запустим скрипт на 42sh
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './other' # Перейдем в папку где будем тестить
cmp='./calc.sh' # То что будем тестить
name='other calc'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './other' # Перейдем в папку где будем тестить
cmp='./globing.sh' # То что будем тестить
name='other globing'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./cd.sh' # То что будем тестить
name='builtin cd'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './pipe' # Перейдем в папку где будем тестить
cmp='./pipe.sh' # То что будем тестить
name='pipe pipe'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './pipe' # Перейдем в папку где будем тестить
cmp='./redirect.sh' # То что будем тестить
name='pipe redirect'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './pipe' # Перейдем в папку где будем тестить
cmp='./heredoc.sh' # То что будем тестить
name='pipe heredoc'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './other' # Перейдем в папку где будем тестить
cmp='./logic.sh' # То что будем тестить
name='other logic'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./jobs.sh' # То что будем тестить
name='builtin jobs'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./type.sh' # То что будем тестить
name='builtin type'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################


##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./bg.sh' # То что будем тестить
name='builtin bg'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################


##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./fg.sh' # То что будем тестить
name='builtin fg'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################


##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./unset.sh' # То что будем тестить
name='builtin unset'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################


##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./set.sh' # То что будем тестить
name='builtin set'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################


##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./export.sh' # То что будем тестить
name='builtin export'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################


##############################
cd './env' # Перейдем в папку где будем тестить
cmp='./env.sh' # То что будем тестить
name='env env'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2

echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################


##############################
cd './other' # Перейдем в папку где будем тестить
cmp='./inhibitors.sh' # То что будем тестить
name='other inhibitors'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2

echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################


##############################
cd './env' # Перейдем в папку где будем тестить
cmp='./expansion.sh' # То что будем тестить
name='env expansion'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2

echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./alias.sh' # То что будем тестить
name='builtin alias'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./hash.sh' # То что будем тестить
name='builtin hash'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./test.sh' # То что будем тестить
name='builtin test'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./exit.sh' # То что будем тестить
name='builtin exit'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
echo 'Если желаете приступить к другому тесту нажмите "Enter"'
$READ
cd - >&- 2>&- # Востановим дерикторию
##############################

##############################
cd './builtin' # Перейдем в папку где будем тестить
cmp='./echo.sh' # То что будем тестить
name='builtin echo'
echo "Тестируем: \033[1m$name\033[0m"
echo "Тестируем: \033[1m$name\033[0m" 1>&2
$cmp 1> $out42sh 2>&1 # Запустим скрипт на 42sh
/bin/zsh $cmp 1> $outzsh 2>&1 # Запустим скрипт на zsh
/bin/bash $cmp 1> $outbash 2>&1 # Запустим скрипт на bash
echo "echo \033[1m$cmp : $name' : 42sh <-> zsh'\033[0m;cd $PWD;diff $out42sh $outzsh" > $diff1;chmod 755 $diff1; open $diff1
echo "echo \033[1m$cmp : $name' : 42sh <-> bash'\033[0m;cd $PWD;diff $out42sh $outbash" > $diff2;chmod 755 $diff2; open $diff2
cd - >&- 2>&- # Востановим дерикторию
##############################

echo 'Все больше тестов нет'
echo 'Для завершения нажмите "Enter"'
$READ
rm -fr $tmp_dir #После себя удалим временные файлы