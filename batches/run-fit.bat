REM echo ## Image aligment using 30 iterations ##
REM fit.exe -m my.amf -h haarcascade_frontalface_alt2.xml -i multipeople.jpg -n 30

REM echo ## Image aligment using 24 iterations ##
REM fit.exe -m my.amf -h haarcascade_frontalface_alt2.xml -i multipeople2.jpg -n 24

REM echo ## face tracking from video ##
REM fit.exe -m my.amf -h haarcascade_frontalface_alt2.xml -v seq4.avi -n 24

REM echo ## face tracking from live camera ##
REM fit.exe -m my.amf -h haarcascade_frontalface_alt2.xml -c -n 24

REM echo ## face tracking from live camera ##
REM fit.exe -m ismaildata.amf -h haarcascade_frontalface_alt2.xml -c


REM fit.exe -m my.amf -h haarcascade_frontalface_alt2.xml -v myvideo.avi

REM ..\bin\fit.exe -m ..\models\onurp4l5.amf -h ..\cascades\haarcascade_frontalface_alt2.xml -c -g 1 -e 0 -r 0 -f 0 -t 1
REM ..\bin\fit.exe -v C:/Users/Onur/Videos/test.avi -c ../users/onur/onur6.txt -m ../users/onur/onur.amf -E C:/Users/Onur/Videos/test.txt 
REM ..\bin\fit.exe -v C:/Users/Onur/Videos/ismail4.avi -c ../users/ismail/ismail4.txt -m ../users/ismail/ismail.amf -E C:/Users/Onur/Videos/ismail4.expr 
REM ..\bin\fit.exe -v C:/Users/Onur/Videos/ismail7.avi -c ../users/ismail/ismail7.txt -m ../users/ismail/ismail.amf -E C:/Users/Onur/Videos/ismail7.expr 

REM ..\bin\fit.exe -v C:/Users/Onur/Videos/serhan4.avi -c ../users/serhan/serhan4.txt -m ../users/serhan/serhan.amf -E C:/Users/Onur/Videos/serhan4.expr 
REM ..\bin\fit.exe -v C:/Users/Onur/Videos/serhan7.avi -c ../users/serhan/serhan7.txt -m ../users/serhan/serhan.amf -E C:/Users/Onur/Videos/serhan7.expr 

REM ..\bin\fit.exe -v C:/Users/Onur/Videos/baris4.avi -c ../users/baris/baris4.txt -m ../users/baris/baris.amf -E C:/Users/Onur/Videos/baris4.expr 
..\bin\fit.exe -v C:/Users/Onur/Videos/baris7.avi -c ../users/baris/baris7.txt -m ../users/baris/baris.amf -E C:/Users/Onur/Videos/baris7.expr 

REM ..\bin\fit.exe -v C:/Users/Onur/Videos/onur4.avi -c ../users/onur/onur4.txt -m ../users/onur/onur.amf -E C:/Users/Onur/Videos/onur4.expr 
REM ..\bin\fit.exe -v C:/Users/Onur/Videos/onur7.avi -c ../users/onur/onur7.txt -m ../users/onur/onur.amf -E C:/Users/Onur/Videos/onur7.expr 

REM ..\bin\fit.exe -v C:/Users/Onur/Videos/selcan4.avi -c ../users/selcan/selcan4.txt -m ../users/selcan/selcan.amf -E C:/Users/Onur/Videos/selcan4.expr 
REM ..\bin\fit.exe -v C:/Users/Onur/Videos/selcan7.avi -c ../users/selcan/selcan7.txt -m ../users/selcan/selcan.amf -E C:/Users/Onur/Videos/selcan7.expr 
REM ..\bin\fit.exe -v C:/Users/Onur/Videos/selcan7.avi -c ../users/selcan/selcan72.txt -m ../users/selcan/selcan.amf -E C:/Users/Onur/Videos/selcan72.expr 


REM echo ## face tracking from live camera ##
REM fit.exe -m my.amf -h haarcascade_frontalface_alt2.xml

pause