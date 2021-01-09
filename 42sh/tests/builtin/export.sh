# Тест только для export

# ##############################
export zzz=dfgdfgdf
echo $zzz

export zzz='вапавпвапвапвапвапва dfgdfgdfgdвапвап\вапвпавэ'
echo $zzz

export zzz1='вапавпвапвапвапвапва dfgdfgdfgdвапвап\вапвпавэ' zzz2=dfgdfgdf zzz3="dfgdfg\dffg\hfg"
echo $zzz1 $zzz2 $zzz3

export zzz1='вапавпвапвапвапвапва dfgdfgdfgdвапвап\вапвпавэ' zzz2=dfgdfgdf zzz1="dfgdfg\dffg\hfg"
echo $zzz1 $zzz2 $zzz3

export zzz4='
'
echo $zzz4

export zzz4='
ghjgh
'
echo $zzz4

export zzz4=~:root
echo $zzz4



# Тут будет уже различия между оболочками ############################################################
env
export
export -p
export -pdfghdfgdfgdf
export -p jhkjhkjhjh
export -p HOME PATH zzz1 zzz2
export -p dfgdf HOME PATH zzz1 zzz2
export -- -p
export =ghjghjgh


unset zz
zz=drghfdhfghf
export zz
env

 # Ошибки в синтаксисе ##############################
echo 'Тестируем: ошибки в синтаксисе'
./export/01.sh;echo $?
./export/02.sh;echo $?
./export/03.sh;echo $?
./export/04.sh;echo $?

# ##############################
echo 'Это должно всегда отображаться'
