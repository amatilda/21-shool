# Тест только для logic

#  ##############################
ls -l && ls
echo $?

ls -l || ls
echo $?

ls ygjghjgl && ls
echo $?

ls ygjghjgl || ls
echo $?

# Ошибки в синтаксисе ##############################
echo 'Тестируем: ошибки в синтаксисе'
./logic/01.sh;echo $?
./logic/02.sh;echo $?
./logic/03.sh;echo $?
./logic/04.sh;echo $?
./logic/05.sh;echo $?
./logic/06.sh;echo $?
./logic/07.sh;echo $?
./logic/08.sh;echo $?
./logic/09.sh;echo $?
./logic/10.sh;echo $?


# ##############################
echo 'Это должно всегда отображаться'
