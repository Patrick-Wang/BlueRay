set dt=%date:~0,4%%date:~5,2%%date:~8,2%%time:~0,2%%time:~3,2%%time:~6,2%
cd "C:\Program Files\MySQL\MySQL Server 5.6\bin\"
mysqldump -u root -p root bluelightplm > d:\1\bluelightplm_%dt%.sql
pause