# Тест только для env

# ##############################
echo $HOME
echo $HOMEsdrgdfgdf
echo $HOMEsвапвапва
echo ${HOME}
echo ${HOMEsdrgdfgdf}
echo ${HOMEsвапвапва}
echo $+++HOMEsвапвапва
echo $++++++++++'+++HOME'
echo $\\\\''
echo $'+++HOMEsвапвапва'
echo $''
echo $

# Тут будет уже различия между оболочками ############################################################
 $HOME
 $HOMEsdrgdfgdf
 $HOMEsвапвапва
 ${HOME}
 ${HOMEsdrgdfgdf}
 ${HOMEsвапвапва}
 $+++HOMEsвапвапва
 $++++++++++'+++HOME'
 $\\\\''
 $'+++HOMEsвапвапва'
 $''
 $

 # Ошибки в синтаксисе ##############################
echo 'Тестируем: ошибки в синтаксисе'
./env/01.sh;echo $?
./env/02.sh;echo $?
./env/03.sh;echo $?
./env/04.sh;echo $?
./env/05.sh;echo $?
./env/06.sh;echo $?
./env/07.sh;echo $?
./env/08.sh;echo $?
./env/09.sh;echo $?
./env/10.sh;echo $?
./env/11.sh;echo $?
./env/12.sh;echo $?

# ##############################
echo 'Это должно всегда отображаться'