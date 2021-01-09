# Тест только для heredoc


#  ##############################
echo 'Просто проверка'

cat -e << 'БРЕД' -b | cat -e

dsgd
${zz:?
БРЕД
echo 'Отобразиться'

<< 'БРЕД'  | cat -e

dsgd
${zz:?
БРЕД
echo 'Отобразиться'

<< 'БРЕД'  | cat -e

dsgd
${zz:?
БРЕД
echo 'Отобразиться'

unset zzz
cat -e << БРЕД -b | cat -e

dsgd
${zzz:=${zzz:=${zzz=$PWD    }    }    }     $PWD   $ZZZZZ
БРЕД
echo $zzz
unset zzz

unset zzz
 << БРЕД | cat -e

dsgd
${zzz:=${zzz:=${zzz=$PWD    }    }    }     $PWD   $ZZZZZ
БРЕД
echo $zzz
unset zzz

cat -e <<EOF
Привет! " #
'EOF
EOF
ls
zz=fhfghf << 'БРЕД' | cat -e
dsgd
$zz
БРЕД

cat -e <<EOF
Привет! " #
'EOF
EOF

<<EOF
Привет! " #
'EOF
EOF
ls
zz=fhfghf << 'БРЕД' | cat -e
dsgd
$zz
БРЕД

<<EOF
Привет! " #
'EOF
EOF

zz=fhfghf << 'БРЕД' | cat -e

dsgd
$zz
БРЕД

cat -e <<''
fghfghf

cat -e <<''

cat -e << 'БРЕД' -b | cat -e

dsgd
$PWD
БРЕД

cat -e << БРЕД -b | cat -e

dsgd
$PWD
БРЕД

zz=fhfghf cat -e << 'БРЕД' -b | cat -e

dsgd
$zz
БРЕД

cat -e <<EOF | cat -b
Привет! " #
'EOF
EOF

cat -e << Приве
Привет! " #
'EOF
Приве
echo 'test'

<< Приве
Привет! " #
'EOF
Приве
echo 'test'

zzz=dfgdfgd 2>&- cat -e <<EOF | cat -b
Привет! " #
'EOF
EOF
echo $zzz

cat -e <<$PWD
Привет! " #
'EOF
$PWD

cat -e <<  "$PWD   "
Привет! " #
'EOF
$PWD   

cat -e <<'EOF FFF'
Привет! " #
'EOF
EOF FFF

cat -e <<'EOF""FFF'
Привет! " #
'EOF
EOFFFF

cat -e << "EOF''FFF"
Привет! " #
'EOF
EOF""FFF

cat -e <<""
Привет! " #
'EOF


cat -e <<" "
Привет! " #
'EOF
 

<<""
Привет! " #
'EOF


<<" "
Привет! " #
'EOF
 


#  ##############################
echo 'Проверка на работу с fd: тут придеться нажать нескольто раз ctr + D' >&0
cat -e 9<<EOF
Привет! " #
'EOF
EOF
echo 'Проверка на работу с fd: провели проверку' >&0

#  ##############################
echo 'Тестируем: когда не находит конец хередока'
./heredoc/01.sh;echo $?
./heredoc/02.sh;echo $?
./heredoc/03.sh;echo $?
./heredoc/04.sh;echo $?
./heredoc/05.sh;echo $?
./heredoc/06.sh;echo $?
./heredoc/13.sh;echo $?


#  ############################################################
echo 'Тут будет уже различия между оболочками'

<< 'БРЕД' | cat -e

dsgd
$zz
БРЕД

zz=fhfghf cat -e << БРЕД -b | cat -e

dsgd
$zz
БРЕД

<<'' -e
fghfghf


<<''
fghfghf

#  ##############################
./heredoc/08.sh;echo $?
./heredoc/09.sh;echo $?
./heredoc/14.sh;echo $?

# Ошибки в синтаксисе ##############################
echo 'Тестируем: ошибки в синтаксисе'
./heredoc/10.sh;echo $?
./heredoc/11.sh;echo $?
./heredoc/12.sh;echo $?


# ##############################
echo 'Это должно всегда отображаться'
