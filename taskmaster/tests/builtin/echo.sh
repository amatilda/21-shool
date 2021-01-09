# Тест только для echo

echo \\a # Write an <alert>.
echo \\b # Write a <backspace>.
echo \\c # Suppress the <newline> that otherwise follows the final argument in the output. All characters following the '\c' in the arguments shall be ignored.
echo \\f # Write a <form-feed>.
echo \\n # Write a <newline>.
echo \\r # Write a <carriage-return>.
echo \\t # Write a <tab>.
echo \\v # Write a <vertical-tab>.
echo \\\  # Write a <backslash> character.
echo \\077 # Write an 8-bit value that is the zero, one, two, or three-digit octal number num.

echo \\n -n \\n
echo -n \\n -n \\n
echo -n

echo abc 123
echo def 456 ghi 789 '' quote

echo abc -- def
echo -- ghi
echo zzz ---
echo -- -n abc

echo "a" "" "" "b"

echo '\a\b\c\f\n\r\t\v\\'
echo "\a\b\c\f\n\r\t\v\\"
echo \a\b\c\f\n\r\t\v\\
echo \0777 \0123 \0 '\01' "\02"

echo "\\'abcd\\'"
echo \'
echo "It works"


# ##############################
echo 'Это должно всегда отображаться'
