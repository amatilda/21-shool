# Тест только для expansion

# ${parameter=word} ##############################
unset zzzz
echo 'Тестируем ${parameter=word}: parameter - unset'
echo ${zzzz='А мы все тестим'}
echo $zzzz
unset zzzz
echo ${zzzz=test
ghjgh fghfghf

}dfhdf

unset zzzz
echo 'Тестируем ${parameter=word}: parameter - unset, word - empty'
echo ${zzzz=}
echo $zzzz

echo 'Тестируем ${parameter=word}: parameter - null'
zzzz=
echo ${zzzz='А мы все тестим'}
echo $zzzz

echo 'Тестируем ${parameter=word}: parameter - null, word - empty'
zzzz=
echo ${zzzz=}
echo $zzzz

echo 'Тестируем ${parameter=word}: parameter - set'
zzzz=set
echo ${zzzz='А мы все тестим'}
echo $zzzz

echo 'Тестируем ${parameter=word}: parameter - set, word - empty'
zzzz=set
echo ${zzzz=}
echo $zzzz

# ${parameter:-word} ##############################
unset zzzz
echo 'Тестируем ${parameter:-word}: parameter - unset'
echo ${zzzz:-'А мы все тестим'}
echo $zzzz

unset zzzz
echo 'Тестируем ${parameter:-word}: parameter - unset, word - empty'
echo ${zzzz:-}
echo $zzzz

echo 'Тестируем ${parameter:-word}: parameter - null'
zzzz=
echo ${zzzz:-'А мы все тестим'}
echo $zzzz

echo 'Тестируем ${parameter:-word}: parameter - null, word - empty'
zzzz=
echo ${zzzz:-}
echo $zzzz

echo 'Тестируем ${parameter:-word}: parameter - set'
zzzz=set
echo ${zzzz:-'А мы все тестим'}
echo $zzzz

echo 'Тестируем ${parameter:-word}: parameter - set, word - empty'
zzzz=set
echo ${zzzz:-}
echo $zzzz


# ${parameter:=word} ##############################
unset zzzz
echo 'Тестируем ${parameter:=word}: parameter - unset'
echo ${zzzz:='А мы все тестим'}
echo $zzzz

unset zzzz
echo 'Тестируем ${parameter:=word}: parameter - unset, word - empty'
echo ${zzzz:=}
echo $zzzz

echo 'Тестируем ${parameter:=word}: parameter - null'
zzzz=
echo ${zzzz:='А мы все тестим'}
echo $zzzz

echo 'Тестируем ${parameter:=word}: parameter - null, word - empty'
zzzz=
echo ${zzzz:=}
echo $zzzz

echo 'Тестируем ${parameter:=word}: parameter - set'
zzzz=set
echo ${zzzz:='А мы все тестим'}
echo $zzzz

echo 'Тестируем ${parameter:=word}: parameter - set, word - empty'
zzzz=set
echo ${zzzz:=}
echo $zzzz


# ${parameter:+word} ##############################
unset zzzz
echo 'Тестируем ${parameter:+word}: parameter - unset'
echo ${zzzz:+'А мы все тестим'}
echo $zzzz

unset zzzz
echo 'Тестируем ${parameter:+word}: parameter - unset, word - empty'
echo ${zzzz:+}
echo $zzzz

echo 'Тестируем ${parameter:+word}: parameter - null'
zzzz=
echo ${zzzz:+'А мы все тестим'}
echo $zzzz

echo 'Тестируем ${parameter:+word}: parameter - null, word - empty'
zzzz=
echo ${zzzz:+}
echo $zzzz

echo 'Тестируем ${parameter:+word}: parameter - set'
zzzz=set
echo ${zzzz:+'А мы все тестим'}
echo $zzzz

echo 'Тестируем ${parameter:+word}: parameter - set, word - empty'
zzzz=set
echo ${zzzz:+'А мы все тестим'}
echo $zzzz


# ${#parameter} ##############################
unset zzzz
echo 'Тестируем ${#parameter}: parameter - unset'
echo ${#zzzz}

echo 'Тестируем ${#parameter}: parameter - null'
zzzz=
echo ${#zzzz}

echo 'Тестируем ${#parameter}: parameter - set'
zzzz='я
сет'
echo ${#zzzz}


# ${parameter%word} ##############################
unset zzzz
echo 'Тестируем ${parameter%word}: parameter - unset'
echo ${zzzz%.c}.o

unset zzzz
echo 'Тестируем ${parameter%word}: parameter - unset, word - empty'
echo ${zzzz%}.o

echo 'Тестируем ${parameter%word}: parameter - null'
zzzz=
echo ${zzzz%.c}.o

echo 'Тестируем ${parameter%word}: parameter - null, word - empty'
zzzz=
echo ${zzzz%}.o

echo 'Тестируем ${parameter%word}: parameter - set'
zzzz=file.c
echo ${zzzz%.c}.o

echo 'Тестируем ${parameter%word}: parameter - set, word - empty'
zzzz=file.c
echo ${zzzz%}.o


# ${parameter#word} ##############################
unset zzzz
echo 'Тестируем ${parameter#word}: parameter - unset'
echo ${zzzz#$HOME}

unset zzzz
echo 'Тестируем ${parameter#word}: parameter - unset, word - empty'
echo ${zzzz#}

echo 'Тестируем ${parameter#word}: parameter - null'
zzzz=
echo ${zzzz#$HOME}

echo 'Тестируем ${parameter#word}: parameter - null, word - empty'
zzzz=
echo ${zzzz#}

echo 'Тестируем ${parameter#word}: parameter - set'
zzzz=$HOME/src/cmd
echo ${zzzz#$HOME}

echo 'Тестируем ${parameter#word}: parameter - set, word - empty'
zzzz=$HOME/src/cmd
echo ${zzzz#}


# ${parameter%%word} ##############################
unset zzzz
echo 'Тестируем ${parameter%%word}: parameter - unset'
echo ${zzzz%%/*}

unset zzzz
echo 'Тестируем ${parameter%%word}: parameter - unset, word - empty'
echo ${zzzz%%}

echo 'Тестируем ${parameter%%word}: parameter - null'
zzzz=
echo ${zzzz%%/*}

echo 'Тестируем ${parameter%%word}: parameter - null, word - empty'
zzzz=
echo ${zzzz%%}

echo 'Тестируем ${parameter%%word}: parameter - set'
zzzz=posix/src/std
echo ${zzzz%%/*}

echo 'Тестируем ${parameter%%word}: parameter - set, word - empty'
zzzz=posix/src/std
echo ${zzzz%%}


# ${parameter##word} ##############################
unset zzzz
echo 'Тестируем ${parameter##word}: parameter - unset'
echo ${zzzz##*/}

unset zzzz
echo 'Тестируем ${parameter##word}: parameter - unset, word - empty'
echo ${zzzz##}

echo 'Тестируем ${parameter##word}: parameter - null'
zzzz=
echo ${zzzz##*/}

echo 'Тестируем ${parameter##word}: parameter - null, word - empty'
zzzz=
echo ${zzzz##}

echo 'Тестируем ${parameter##word}: parameter - set'
zzzz=/one/two/three
echo ${zzzz##*/}

echo 'Тестируем ${parameter##word}: parameter - set, word - empty'
zzzz=/one/two/three
echo ${zzzz##}

# Тут будет уже различия между оболочками ############################################################
# Цепочки из переменных сред ##############################
unset zzzz
${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=$PWD}}}}}}}}}}}
unset zzzz1 zzzz2 zzzz3 zzzz4 zzzz5 zzzz6 zzzz7 zzzz8 zzzz9 zzzz10

unset zzzz
${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=}}}}}}}}}}} ls
unset zzzz1 zzzz2 zzzz3 zzzz4 zzzz5 zzzz6 zzzz7 zzzz8 zzzz9 zzzz10

unset zzzz
ls ${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=}}}}}}}}}}} ${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=d}}}}}}}}}}}
unset zzzz1 zzzz2 zzzz3 zzzz4 zzzz5 zzzz6 zzzz7 zzzz8 zzzz9 zzzz10

unset zzzz
echo ${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=$PWD}}}}}}}}}}}
echo $zzzz $zzzz1 $zzzz2 $zzzz3 $zzzz4 $zzzz5 $zzzz6 $zzzz7 $zzzz8 $zzzz9 $zzzz10

unset zzzz
echo ${zzzz=${zzzz1=${zzzz2=${zzzz3=${zzzz4=${zzzz5=${zzzz6=${zzzz7=${zzzz8=${zzzz9=${zzzz10=$PWD}}}}}}}}}}}
echo $zzzz $zzzz1 $zzzz2 $zzzz3 $zzzz4 $zzzz5 $zzzz6 $zzzz7 $zzzz8 $zzzz9 $zzzz10
unset zzzz1 zzzz2 zzzz3 zzzz4 zzzz5 zzzz6 zzzz7 zzzz8 zzzz9 zzzz10

unset zzzz
echo ${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=$PWD}}}}}}}}}}} | cat -e
echo $zzzz $zzzz1 $zzzz2 $zzzz3 $zzzz4 $zzzz5 $zzzz6 $zzzz7 $zzzz8 $zzzz9 $zzzz10
unset zzzz1 zzzz2 zzzz3 zzzz4 zzzz5 zzzz6 zzzz7 zzzz8 zzzz9 zzzz10

unset zzzz
ls ${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=$PWD}}}}}}}}}}} 
echo $zzzz $zzzz1 $zzzz2 $zzzz3 $zzzz4 $zzzz5 $zzzz6 $zzzz7 $zzzz8 $zzzz9 $zzzz10
unset zzzz1 zzzz2 zzzz3 zzzz4 zzzz5 zzzz6 zzzz7 zzzz8 zzzz9 zzzz10

unset zzzz
ls ${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=$PWD}}}}}}}}}}} | cat -e
echo $zzzz $zzzz1 $zzzz2 $zzzz3 $zzzz4 $zzzz5 $zzzz6 $zzzz7 $zzzz8 $zzzz9 $zzzz10
unset zzzz1 zzzz2 zzzz3 zzzz4 zzzz5 zzzz6 zzzz7 zzzz8 zzzz9 zzzz10

unset zzzz
zz=${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=$PWD}}}}}}}}}}} | cat -e
echo $zz $zzzz $zzzz1 $zzzz2 $zzzz3 $zzzz4 $zzzz5 $zzzz6 $zzzz7 $zzzz8 $zzzz9 $zzzz10
unset zz zzzz1 zzzz2 zzzz3 zzzz4 zzzz5 zzzz6 zzzz7 zzzz8 zzzz9 zzzz10

unset zzzz
zz=${zzzz:=${zzzz1:=${zzzz2:=${zzzz3:=${zzzz4:=${zzzz5:=${zzzz6:=${zzzz7:=${zzzz8:=${zzzz9:=${zzzz10:=$PWD}}}}}}}}}}} env
echo $zz $zzzz $zzzz1 $zzzz2 $zzzz3 $zzzz4 $zzzz5 $zzzz6 $zzzz7 $zzzz8 $zzzz9 $zzzz10
unset zz zzzz1 zzzz2 zzzz3 zzzz4 zzzz5 zzzz6 zzzz7 zzzz8 zzzz9 zzzz10

echo 'Тестируем на правильную работу патернов'
zzzz=/one/two/three/

echo 'Тестируем ${parameter%*}'
echo ${zzzz%*}
echo 'Тестируем ${parameter%%*}'
echo ${zzzz%%*}

echo 'Тестируем ${parameter%''}'
echo ${zzzz%''}
echo 'Тестируем ${parameter%%''}'
echo ${zzzz%%''}

echo 'Тестируем ${parameter%three/}'
echo ${zzzz%three/}
echo 'Тестируем ${parameter%%three/}'
echo ${zzzz%%three/}

echo 'Тестируем ${parameter%*[a-z]}'
echo ${zzzz%*[a-z]}
echo 'Тестируем ${parameter%%*[a-z]}'
echo ${zzzz%%*[a-z]}

echo 'Тестируем ${parameter%*[a-z-a]}'
echo ${zzzz%*[a-z-a]}
echo 'Тестируем ${parameter%%*[a-z-a]}'
echo ${zzzz%%*[a-z-a]}

echo 'Тестируем ${parameter%*??}'
echo ${zzzz%*??}
echo 'Тестируем ${parameter%%*??}'
echo ${zzzz%%*??}

zzzz=/one/two/three/?*

echo 'Тестируем ${parameter%\?\*}'
echo ${zzzz%\?\*}
echo 'Тестируем ${parameter%%\?\*}'
echo ${zzzz%%\?\*}

zzzz=/one/two/three/\[\]

echo 'Тестируем ${parameter%\[\]}'
echo ${zzzz%\[\]}
echo 'Тестируем ${parameter%%\[\]}'
echo ${zzzz%%\[\]}

zzzz=/one/two/three/a

echo 'Тестируем ${parameter%[!c-z]}'
echo ${zzzz%[!c-z]}
echo 'Тестируем ${parameter%%[!c-z]}'
echo ${zzzz%%[!c-z]}

zzzz=/one/two/three/a' 'b

echo 'Тестируем ${parameter%[ -z]}'
echo ${zzzz%[ -z]}
echo 'Тестируем ${parameter%%[ -z]}'
echo ${zzzz%%[ -z]}

echo 'Тестируем ${parameter%[а-я]}'
echo ${zzzz%[а-я]}
echo 'Тестируем ${parameter%%[а-я]}'
echo ${zzzz%%[а-я]}

zzzz=/one/two/three/я

echo 'Тестируем ${parameter%[а-я]}'
echo ${zzzz%[а-я]}
echo 'Тестируем ${parameter%%[а-я]}'
echo ${zzzz%%[а-я]}

echo 'Тестируем ${parameter%[я-а]}'
echo ${zzzz%[я-а]}
echo 'Тестируем ${parameter%%[я-а]}'
echo ${zzzz%%[я-а]}

zzzz=/one/two/three/\\

echo 'Тестируем ${parameter%\\}'
echo ${zzzz%\\}
echo 'Тестируем ${parameter%\\}'
echo ${zzzz%%\\}

zzzz=/one/two/three/\\?*

echo 'Тестируем ${parameter%\\?*}'
echo ${zzzz%\\}
echo 'Тестируем ${parameter%%\\?*}'
echo ${zzzz%%\\}

zzzz=/one/two/three/

echo 'Тестируем ${parameter#*}'
echo ${zzzz#*}
echo 'Тестируем ${parameter##*}'
echo ${zzzz##*}

echo 'Тестируем ${parameter#''}'
echo ${zzzz#''}
echo 'Тестируем ${parameter##''}'
echo ${zzzz##''}

echo 'Тестируем ${parameter#three/}'
echo ${zzzz#three/}
echo 'Тестируем ${parameter##three/}'
echo ${zzzz##three/}

echo 'Тестируем ${parameter#*[a-z]}'
echo ${zzzz#*[a-z]}
echo 'Тестируем ${parameter##*[a-z]}'
echo ${zzzz##*[a-z]}

echo 'Тестируем ${parameter#*[a-z-a]}'
echo ${zzzz#*[a-z-a]}
echo 'Тестируем ${parameter##*[a-z-a]}'
echo ${zzzz##*[a-z-a]}

echo 'Тестируем ${parameter#*??}'
echo ${zzzz#*??}
echo 'Тестируем ${parameter##*??}'
echo ${zzzz##*??}

zzzz=/one/two/three/?*

echo 'Тестируем ${parameter#\?\*}'
echo ${zzzz#\?\*}
echo 'Тестируем ${parameter##\?\*}'
echo ${zzzz##\?\*}

zzzz=/one/two/three/\[\]

echo 'Тестируем ${parameter#\[\]}'
echo ${zzzz#\[\]}
echo 'Тестируем ${parameter##\[\]}'
echo ${zzzz##\[\]}

zzzz=/one/two/three/a

echo 'Тестируем ${parameter#[!c-z]}'
echo ${zzzz#[!c-z]}
echo 'Тестируем ${parameter##[!c-z]}'
echo ${zzzz##[!c-z]}

zzzz=/one/two/three/a' 'b

echo 'Тестируем ${parameter#[ -z]}'
echo ${zzzz#[ -z]}
echo 'Тестируем ${parameter##[ -z]}'
echo ${zzzz##[ -z]}

echo 'Тестируем ${parameter#[а-я]}'
echo ${zzzz#[а-я]}
echo 'Тестируем ${parameter##[а-я]}'
echo ${zzzz##[а-я]}

zzzz=/one/two/three/я

echo 'Тестируем ${parameter#[а-я]}'
echo ${zzzz#[а-я]}
echo 'Тестируем ${parameter##[а-я]}'
echo ${zzzz##[а-я]}

echo 'Тестируем ${parameter#[я-а]}'
echo ${zzzz#[я-а]}
echo 'Тестируем ${parameter##[я-а]}'
echo ${zzzz##[я-а]}

zzzz=/one/two/three/\\

echo 'Тестируем ${parameter#\\}'
echo ${zzzz#\\}
echo 'Тестируем ${parameter#\\}'
echo ${zzzz##\\}

zzzz=/one/two/three/\\?*

echo 'Тестируем ${parameter#\\?*}'
echo ${zzzz#\\}
echo 'Тестируем ${parameter##\\?*}'
echo ${zzzz##\\}

zzzz=/привет/как/дела/

echo 'Тестируем ${parameter#дела/}'
echo ${zzzz#дела/}
echo 'Тестируем ${parameter##дела/}'
echo ${zzzz##дела/}

echo 'Тестируем ${parameter%дела/}'
echo ${zzzz%дела/}
echo 'Тестируем ${parameter%%дела/}'
echo ${zzzz%%дела/}

zzzz=/привет/как/дел\а\/

echo 'Тестируем ${parameter#\a\\}'
echo ${zzzz#\a\\}
echo 'Тестируем ${parameter##\a\\}'
echo ${zzzz##\a\\}

echo 'Тестируем ${parameter%\a\\}'
echo ${zzzz%\a\\}
echo 'Тестируем ${parameter%%\a\\}'
echo ${zzzz%%\a\\}

# Патерн в переменной среде ##############################

www='three'
zzzz=/one/two/three

echo 'Тестируем ${parameter%$www}'
echo ${zzzz%$www}
echo 'Тестируем ${parameter%%$www}'
echo ${zzzz%%$www}

echo 'Тестируем ${parameter#$www}'
echo ${zzzz#$www}
echo 'Тестируем ${parameter##$www}'
echo ${zzzz##$www}

www='*e'
echo 'Тестируем ${parameter%$www}'
echo ${zzzz%$www}
echo 'Тестируем ${parameter%%$www}'
echo ${zzzz%%$www}

echo 'Тестируем ${parameter#$www}'
echo ${zzzz#$www}
echo 'Тестируем ${parameter##$www}'
echo ${zzzz##$www}

# ~ ##############################
echo 'Тестируем ~'
echo ~/hk
echo ~root
echo zzzz=~root/dfgdf
echo zzzz=::~root:dfgdf
echo "~root"
echo "~"root
echo ~"root"
echo ~::root:
echo ~:sdfds:=~root:

~/hk
~root
zzzz=~root/dfgdf
zzzz=::~root:dfgdf
"~root"
"~"root
~"root"
~::root:
~:sdfds:=~root:

# ${parameter:?word} ##############################
./expansion/01.sh;echo $?
./expansion/02.sh;echo $?
./expansion/03.sh;echo $?
./expansion/04.sh;echo $?
./expansion/05.sh;echo $?
./expansion/06.sh;echo $?

# Ошибки в синтаксисе ##############################
echo 'Тестируем: ошибки в синтаксисе'
./expansion/07.sh;echo $?
./expansion/08.sh;echo $?
./expansion/09.sh;echo $?
./expansion/10.sh;echo $?
./expansion/11.sh;echo $?
./expansion/12.sh;echo $?

# ##############################
echo 'Это должно всегда отображаться'