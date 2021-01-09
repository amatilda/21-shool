# Тест только для type

# Тут все отличаеться ##############################

tempos=$tmp_dir'zzzz'

# ##############################
type
echo $?


# ##############################
echo 'Проверим builtin'
type echo true false fg bg set alias unset unalias cd hash jobs test exit type 'export'
echo $?

type echo fhfghfg echo
echo $?

type echo fhfghfg
echo $?


# ##############################
echo 'Проверим невалидные полностью'
type -fghfg fhfghfg '' -fghfg
echo $?


# ##############################
echo 'Проверим пути к папкам и файла'
type /tmp /Users
echo $?

type /bin/zsh /bin/bash
echo $?


# ##############################
echo 'Проверим на исполнение файлы'
touch $tempos
type $tempos
echo $?

chmod 755 $tempos
type $tempos
echo $?


# ##############################
echo 'Проверим команды через получаемые через PATH'
type ls env pwd printf mkdir touch la zsh
echo $?


# ##############################
echo 'Проверим alias'
alias ls=dfsgfsd mkdir=dfgdfgd
type ls env pwd printf mkdir touch la zsh
echo $?


# ##############################
echo 'Проверим hash'
hash ls=dfsgfsd mkdir=dfgdfgd la=fthfghfghgf pwd=fdghdfgdfgd
type ls env pwd printf mkdir touch la zsh
echo $?

rm -f $tempos #Удалим за собой
# ##############################
echo 'Это должно всегда отображаться'