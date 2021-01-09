# Тест только для chek_list


#  ##########################################################################################
echo '\033[1m Prerequisites from minishell. \033[0m'
#  ##############################

echo '
- Execute the following command and check that the display is correct:

$> doesnotexist
{{ Error message indicating that the command does not exist/is not found }}
$> echo ${?}
{{ Return code different from 0 }}

'
doesnotexist; echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:

$> /sbin/yubikey_shell
{{ Error message indicating that the command cannot be executed due to
insufficient permission }}
$> echo ${?}
{{ Return code different from 0 }}

'
/sbin/halt; echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> /bin/ls
{{ Output of the "ls" command }}
$> echo ${?}
0

'
/bin/ls; echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> ls
{{ Output of the "ls" command }}
$> echo ${?}
0

'

ls; echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> /bin/ls -alF
{{ Output of the "ls" command with the "alF" arguments }}
$> echo ${?}
0

'
/bin/ls -alF ; echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> /bin/ls -l -a -F
{{ Output of the "ls" command with the "alF" arguments }}
$> echo ${?}
0

'
/bin/ls -l -a -F ; echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##########################################################################################
echo '\033[1m Prerequisites from 21sh. \033[0m'

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> ls > /tmp/ftsh_ls_out /
$> cat /tmp/ftsh_ls_out
{{ Output of the "ls" command on the system root }}

'
ls > /tmp/ftsh_ls_out
cat /tmp/ftsh_ls_out
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> < /tmp/ftsh_ls_out cat -e >> /tmp/ftsh_ls_out
$> cat /tmp/ftsh_ls_out
{{ 2 listings of the root must appear and the second must have a $ at the end of
each line }}

'
< /tmp/ftsh_ls_out cat -e >> /tmp/ftsh_ls_out
cat /tmp/ftsh_ls_out
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> echo 1 >out >&2 2>err
1
$> echo 2 >out 2>err
$> cat err
$> cat out
2
$>

'
echo 1 >out >&2 2>err
echo 2 >out 2>err
cat err
cat out
rm err out
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> echo non-standard fd > dup_fd
$> cat 4 non-standard fd$
$>

'
echo '44564554' >out
cat out 142343253453>1
rm out 1

echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> cat <&4
{{ Error message indicating that the file descriptor is invalid }}
$>

'
cat <&4
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> echo abc >redir_one_to_all
$> cat 9 abc$
Придеться потом тут cat прерывать в ручную

'
cat 9>abc
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> cat <&- abc
$>
'
cat <&- abc
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
rm abc
$READ

#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> ls doesnotexist . 2>&1 >/dev/null
ls: doesnotexist: No such file or directory
$> ls doesnotexist . >/dev/null 2>&1
$>

'
ls doesnotexist . 2>&1 >/dev/null
ls doesnotexist . >/dev/null 2>&1
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> ls | sort -rn | cat -e
{{ Content of the current folder, sorted, with a '$' at the end of each line }}
$>

'
ls | sort -rn | cat -e
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> base64 < /dev/urandom | head -c 1000 | grep 42 | wc -l | sed -e s/1/Yes/g -e
s/0/No/g
{{ Displays "Yes" or "No" randomly }}
$> ps a | grep "base64" | grep -v "grep"
$>


'
base64 < /dev/urandom | head -c 1000 | grep 42 | wc -l | sed -e s/1/Yes/g -e s/0/No/g
ps a | grep 'base64' | grep -v 'grep'
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> ls -1; touch test_file; ls -1
{{ Display of 2 'ls'. An additional file, "test_file", must appear in the second
output }}
$>

'
ls -1; touch test_file; ls -1
rm test_file
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> exit 1 | exit 2 | exit 3; echo "stayin alive"
$>

'
exit 1 | exit 2 | exit 3; echo "stayin alive"
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
$> echo out >&-; echo out2
{{ Optional error message indicating that it is impossible to write to stdout }}
out2
$> echo out >&- | echo out2
{{ Optional error message indicating that it is impossible to write to stdout }}
out2
$> echo out >&- && echo out2
{{ Optional error message indicating that it is impossible to write to stdout }}
$> echo out >&- || echo out2
{{ Optional error message indicating that it is impossible to write to stdout }}
out2

'
echo out >&-; echo out2
echo out >&- | echo out2
echo out >&- && echo out2
echo out >&- || echo out2
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> cat << END
heredoc> hello world
heredoc> and good
heredoc> morning!
heredoc> END
hello world
and good
morning!
$>

'
cat << END
hello world
and good
morning!
END
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> cat << EO\
> F
heredoc> hi
heredoc> EOF
hi

'
cat << EO\
F
hi
EOF

echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> cat > /tmp/heredoc-append << FIN
heredoc> abc
heredoc> FIN
$> cat -e >> /tmp/heredoc-append << FIN
heredoc> def
heredoc> ghi
heredoc> FIN
$> cat /tmp/heredoc-append
abc
def$
ghi$
$>

'
cat > /tmp/heredoc-append << FIN
abc
FIN
cat -e >> /tmp/heredoc-append << FIN
def
ghi
FIN
cat /tmp/heredoc-append
rm /tmp/heredoc-append
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> (cat < heredoc> abd
heredoc> abc
heredoc> abb
heredoc> EOF
abb$
abc$
abd$
$>

'
cat -e << EOF > abd
abc
abb
EOF

cat abd
rm abd
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##########################################################################################
echo '\033[1m Built-ins. \033[0m'

#  ##############################
./chek_list/01.sh;echo $?
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
./chek_list/02.sh;echo $?
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> exit abc
{{ Error message indicating that a numerical value is expected }}
$> echo ${?}
{{ Return code different from 0 }}

'
exit abc
echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> exit 1 2 3
{{ Error message indicating too many arguments }}
$> echo ${?}
{{ Return code different from 0 }}

'
exit 1 2 3
echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> cd {{ /absolute/path/of/your/choice }}
$> pwd
{{ /absolute/path/of/your/choice }}
$>

'
cd /private/tmp
pwd
cd -
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> cd relative/path/of/your/choice
$> pwd
{{ relative/path/of/your/choice }}
$>

'
cd ~/../
pwd
cd -
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> cd /tmp
$> /bin/pwd
/tmp
$> cd
$> /bin/pwd
/Users/{{login_session}}
$>

'
cd /tmp
/bin/pwd
cd
/bin/pwd
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> cd /tmp
$> pwd
/tmp
$> cd /bin
$> pwd
/bin
$> cd -
$> pwd
/tmp
$>

'
cd /tmp
pwd
cd /bin
cd -
pwd
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
$> cd -L /tmp; cd -P ..
$> pwd
/private

'
cd -L /tmp; cd -P ..
pwd
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> type type ls
{{ Message indicating that "type" is a builtin and "ls" a command with its path
}}
$>

'
type type ls
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##########################################################################################
echo '\033[1m Logical operators. \033[0m'

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> ls -l && ls
{{ Display of the "ls" command twice with different parameters }}
$>

'
ls -l && ls
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> ls doesnotexist || echo "Notice me senpai"
ls: doesnotexist: No such file or directory
Notice me senpai
$> echo ${?}
0
$>

'
ls doesnotexist || echo "Notice me senpai"
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> echo 'No error' || echo 'You cant see me'
No error
$> echo ${?}
0
$>

'

echo 'No error' || echo 'You cant see me'
echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> false && echo foo || echo bar
bar
$> true || echo foo && echo bar
bar
$>

'

false && echo foo || echo bar
true || echo foo && echo bar
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##########################################################################################
echo '\033[1m Environment management. \033[0m'

#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> a=hello b=world; b=42 echo ${a}_${b} && echo ${b}
hello_world
world
$>

'

a=hello b=world; b=42 echo ${a}_${b} && echo ${b}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> directory=/ ls_opt=-atr
$> ls ${ls_opt} ${directory}
{{ Output of the "ls -atr" command on the system root }}
$>

'

directory=/ ls_opt=-atr
ls ${ls_opt} ${directory}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> echo ${empty}|cat -e
$
$>

'

echo ${empty}|cat -e
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> set
{{ All internal shell and environment variables }}
$> set | grep -E "(a|b)="
a=hello
b=world
$>

'

set
set | grep -E "(a|b)="
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Execute the following command and check that the display is correct:
$> env
{{ All environment variables only }}
$> env | grep -E "(a|b)="
$>


'

env
env | grep -E "(a|b)="
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> export b
$> printenv b
world
$>

'
export b
printenv b
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> ONESHOT= env | grep ONESHOT
ONESHOT=
$> env | grep ONESHOT
$>

'

ONESHOT= env | grep ONESHOT
env | grep ONESHOT
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> unset a b
$> env | grep -E "(a|b)="
$> set | grep -E "(a|b)=""
$>

'

unset a b
env | grep -E "(a|b)="
set | grep -E "(a|b)="
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> unset PATH
$> PATH=/bin:/usr/bin
$> mkdir testdir
$> echo ${?}
0
$> ls -1 | grep testdir
testdir
$>

'
cd /tmp
tempos=$PATH
unset PATH
PATH=/bin:/usr/bin
mkdir testdir
echo ${?}
ls -1 | grep testdir
export PATH=$tempos

echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##############################
echo '
- Perform the following commands and check that the display is compliant:
$> true; echo ${?}; false; echo ${?}
0
1
$>

'
true; echo ${?}; false; echo ${?}
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ


#  ##########################################################################################
echo '\033[1m Job control. \033[0m'


#  ##############################
echo '
Скрипт jobs не подерживает

'
echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ

#  ##########################################################################################
echo '\033[1m Inhibitors. \033[0m'

echo '
For example, you can test these commands and check that the
shell reacts in the same way as the reference shell chosen by the group:

'
echo foo\
echo "\\'abcd\\'"
echo \'

echo 'Если желаете приступить к следующему шагу нажмите "Enter"'
$READ
