# Тест только для inhibitors

#  ##############################
echo 'Тестируем:  \'
echo \'
echo foo\
echo \"
echo \\\\fg\fgh\ytr\trt\\yy\
echo \ав\авпва…÷ћ\ћ\ћћ\ћћ\ћ\ћћ\\\ћ
echo \$hkhj
echo \$выапываыв
echo \$++++выапываыв
echo \$HOME

#  ##############################
echo 'Тестируем:  "'
echo "\\'abcd\\'"
echo "\$   \`   \"   \\"
echo "\
"
echo "$   \`   "   \"
echo "\авв\вапва\вапва\вап÷ћћ\ћ÷ћћ÷\ћ÷ћ÷ћ"
echo "$hkhj"
echo "$выапываыв"
echo "$+++++выапываыв"
echo "$HOME"
echo "${HOMES=test
ghjgh ftghfg

}"

#  ##############################
echo "Тестируем:  '"
echo '\\'abcd\\''
echo '\$   \`   \"   \\'
echo '\
'
echo '$   \`   "   \'
echo '\авв\вапва\вапва\вап÷ћћ\ћ÷ћћ÷\ћ÷ћ÷ћ'
echo '$hkhj'
echo '$выапываыв'
echo '$+++++выапываыв'
echo '$HOME'
echo '${HOMES=test
ghjgh ftghfg

}'

#  ##############################
echo "Тестируем:  mix"
echo ''hjg\jg\''fghgff"g"hgf'\gjghjgh'hjkjhkhjkjh"ghjghjghjgjghjg\пропропропропрvxvxћvxxzxћ÷'"""'""""'"
echo "$HOME '$HOME' \$HOME"
echo "$HOME '$HOME' \$HOME

{}
"

# Идут отличия 		 ##############################
#  ##############################
echo 'Тестируем:  \'
\'
foo\
\"
\\\\fg\fgh\ytr\trt\\yy\
\ав\авпва…÷ћ\ћ\ћћ\ћћ\ћ\ћћ\\\ћ
 \$hkhj
 \$выапываыв
 \$++++выапываыв
\$HOME


#  ##############################
echo 'Тестируем:  "'
"\\'abcd\\'"
"\$   \`   \"   \\"
"\
"
"$   \`   "   \"
"\авв\вапва\вапва\вап÷ћћ\ћ÷ћћ÷\ћ÷ћ÷ћ"
 "$hkhj"
 "$выапываыв"
 "$++++выапываыв"
 "$HOME"
"${HOMES=test
ghjgh ftghfg

}"

#  ##############################
 "Тестируем:  '"
 '\\'abcd\\''
 '\$   \`   \"   \\'
 '\
'
 '$   \`   "   \'
 '\авв\вапва\вапва\вап÷ћћ\ћ÷ћћ÷\ћ÷ћ÷ћ'
 '$hkhj'
 '$выапываыв'
 '$+++++выапываыв'
 '$HOME'
'${HOMES=test
ghjgh ftghfg

}'

 #  ##############################
"Тестируем:  mix"
''hjg\jg\''fghgff"g"hgf'\gjghjgh'hjkjhkhjkjh"ghjghjghjgjghjg\пропропропропрvxvxћvxxzxћ÷'"""'""""'"
"$HOME '$HOME' \$HOME"

# Ошибки в синтаксисе ##############################
echo 'Тестируем: ошибки в синтаксисе'
./inhibitors/01.sh;echo $?
./inhibitors/02.sh;echo $?
./inhibitors/03.sh;echo $?

# ##############################
echo 'Это должно всегда отображаться'
