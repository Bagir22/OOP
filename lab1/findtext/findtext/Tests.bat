chcp 1251 > nul

SET findtext="%~1"

if %findtext% == "" (
	echo Please specify path to program
	echo /B 1
)
REM "$(ProjectDir)Tests.bat" "$(TargetPath)"
echo Test 1: test empty file
%findtext% Tests\Empty.txt nostrud > "%TEMP%\out.txt"
if not (%ERRORLEVEL%) == (1) goto err
fc Tests\EmptyResult.txt "%TEMP%\out.txt" > nul || goto err
echo Test 1 passed

echo Test 2: test english file
%findtext% Tests\English.txt nostrud > "%TEMP%\out.txt"
if not (%ERRORLEVEL%) == (0) goto err
fc Tests\EnglishResult.txt "%TEMP%\out.txt" > nul || goto err
echo Test 2 passed

echo Test 3: test russian file
%findtext% Tests\Russian.txt ñâåæèé > "%TEMP%\out.txt"
if not (%ERRORLEVEL%) == (0) goto err
fc Tests\RussianResult.txt "%TEMP%\out.txt" > nul || goto err
echo Test 3 passed

echo Test 4: testing file that doesn't exist
%findtext% Missing.txt "ìàìà" > nul
if not (%ERRORLEVEL%) == (2) goto err
echo Test 4 passed

echo Test 5: testing file with not specified text
%findtext% Missing.txt > nul
if not (%ERRORLEVEL%) == (2) goto err
echo Test 5 passed

echo Test 6: testing file with not specified file
%findtext% "ìàìà" > nul
if not (%ERRORLEVEL%) == (2) goto err
echo Test 6 passed

echo All tests passed

exit /B 0

:err
echo Test failed
exit /B 1