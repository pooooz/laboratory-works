@ECHO OFF

if exist out.tmp (
ECHO Error: "File out.tmp exists"
GOTO Exit
) else (
FIND /N /I *.txt %1 >> out.tmp
FIND /V out.tmp "----------" >> out1.tmp
type out1.tmp 
del out.tmp
del out1.tmp
)
:Exit