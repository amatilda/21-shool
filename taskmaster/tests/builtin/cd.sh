# Тест только для cd


# ##############################
echo "Просто тестируем переходы"
cd /
pwd
echo $PWD $OLDPWD

cd ~
pwd
echo $PWD $OLDPWD

cd $HOME
cd /tmp
cd ~
cd ../../../../../../../
pwd
echo $PWD $OLDPWD

cd $tmp_dir
pwd
echo $PWD $OLDPWD

mkdir рапрапрапрапрапрап
cd рапрапрапрапрапрап
pwd
echo $PWD $OLDPWD
cd ../
rm -fr рапрапрапрапрапрап

unset PWD OLDPWD
echo $PWD $OLDPWD

cd /tmp
pwd
echo $PWD $OLDPWD
cd

echo "Тестируем переходы с флагам L"
cd -L /
pwd -L
echo $PWD $OLDPWD

cd -L ~
pwd
echo $PWD $OLDPWD

cd -L $HOME
cd -L /tmp
cd -L ~
cd -L ../../../../../../../
pwd -L
echo $PWD $OLDPWD

cd -L $tmp_dir
pwd -L
echo $PWD $OLDPWD

mkdir рапрапрапрапрапрап
cd -L рапрапрапрапрапрап
pwd -L
echo $PWD $OLDPWD
cd -L ../
rm -fr рапрапрапрапрапрап

unset PWD OLDPWD
echo $PWD $OLDPWD

cd -L /tmp
pwd -L
echo $PWD $OLDPWD
cd -L 

cd -L $tmp_dir
pwd -L
echo $PWD $OLDPWD

cd -L ../../
pwd -L
echo $PWD $OLDPWD

echo "Тестируем переходы с флагам P"
cd -P /
pwd -P
echo $PWD $OLDPWD

cd -P ~
pwd -P
echo $PWD $OLDPWD

cd -P $HOME
cd -P /tmp
cd -P ~
cd -P ../../../../../../../
pwd -P
echo $PWD $OLDPWD

cd -P $tmp_dir
pwd -P
echo $PWD $OLDPWD

mkdir рапрапрапрапрапрап
cd -P рапрапрапрапрапрап
pwd -P
echo $PWD $OLDPWD
cd -P ../
rm -fr рапрапрапрапрапрап

unset PWD OLDPWD
echo $PWD $OLDPWD

cd -P /tmp
pwd -P
echo $PWD $OLDPWD
cd -P 

cd -P $tmp_dir
pwd -P
echo $PWD $OLDPWD

cd -P ../../
pwd -P
echo $PWD $OLDPWD

echo "Тестируем с CDPATH"
pwd
cd $tmp_dir
CDPATH=/:./:/bin
mkdir tmp
pwd
cd ./tmp
pwd
echo $PWD $OLDPWD
cd tmp
cd ../
pwd
unset CDPATH
cd $tmp_dir
rm -fr tmp


# Тут будет уже различия между оболочками ############################################################
cd ~root

cd ~
cd -
pwd
echo $PWD $OLDPWD

unset HOME
cd ~
pwd
echo $PWD $OLDPWD
cd -
pwd
echo $PWD $OLDPWD

echo "Тестируем переходы с несколькими флагам"
cd -P -L /tmp
pwd
echo $PWD $OLDPWD

cd -P -L -P /tmp
pwd
echo $PWD $OLDPWD

cd ~
cd -
pwd
echo $PWD $OLDPWD

echo "Тестируем несуществующие директории"
pwd
cd drhjgjghjghkj
pwd

echo "Тестируем несуществующие флаги"
pwd
cd -LPgcfgcfварапра
pwd

echo "Тестируем недоступные директории"
pwd
cd $tmp_dir
mkdir dfhfghfghfg
chmod 000 dfhfghfghfg
cd dfhfghfghfg
chmod 755 dfhfghfghfg
rm -fr dfhfghfghfg
pwd

echo "Тестируем с файлам"
pwd
cd $tmp_dir
touch dfhfghfghfg
chmod 000 dfhfghfghfg
cd dfhfghfghfg
chmod 755 dfhfghfghfg
rm -fr dfhfghfghfg
pwd

echo "Тестируем с CDPATH"
pwd
cd $tmp_dir
CDPATH=/:./:/bin
mkdir tmp
pwd
cd tmp
pwd
echo $PWD $OLDPWD
cd tmp
cd ../
pwd
cd $tmp_dir
unset CDPATH
rm -fr tmp

# ##############################
echo 'Это должно всегда отображаться'
