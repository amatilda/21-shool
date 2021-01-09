# Тест только для chek_list

echo '
If at least one of these tests fails, then the entire section is failed
and the correction stops. Perform the following tests:
- Perform the following commands and check that the display is compliant:
$> echo abc; exit; echo def
abc
$> echo ${?}
0

'
echo abc; exit; echo def
