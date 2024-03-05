chcp 65001

SET flipbyte="%~1"

if %flipbyte% == "" (
	echo Please specify path to program
	echo /B 1
)

echo Test1: Args not specified
%flipbyte% > nul
if not (%ERRORLEVEL%) == (1) goto err
echo Test 1 passed

echo Test2: Arg is not int or empty
%flipbyte% "string" > nul
if not (%ERRORLEVEL%) == (1) goto err
echo Test 2 passed

echo Test3: Num is lower 0 or bigger 255
%flipbyte% -1 > nul
if not (%ERRORLEVEL%) == (1) goto err
echo Test 3 passed

echo Test4: test valid num 6
%flipbyte% 6 > "%TEMP%\out.txt"
if not (%ERRORLEVEL%) == (0) goto err
fc Tests\ValidNum6Result.txt "%TEMP%\out.txt" > nul || goto err
echo Test 4 passed

echo Test5: test valid num 128
%flipbyte% 128 > "%TEMP%\out.txt"
if not (%ERRORLEVEL%) == (0) goto err
fc Tests\ValidNum128Result.txt "%TEMP%\out.txt" > nul || goto err
echo Test 5 passed

echo Test6: test valid num 0
%flipbyte% 0 > "%TEMP%\out.txt"
if not (%ERRORLEVEL%) == (0) goto err
fc Tests\ValidNum0Result.txt "%TEMP%\out.txt" > nul || goto err
echo Test 6 passed

echo All tests passed

exit /B 0

:err
echo Test failed
exit /B 1