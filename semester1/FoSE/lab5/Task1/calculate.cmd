FOR %%a in (MIN,MAX,SUM,AVG) DO (
SET FUNCTION=%%a
series.exe < a.txt >> b.txt
)