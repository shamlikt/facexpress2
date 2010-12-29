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

..\bin\fit.exe -m ..\models\onurp4l5.amf -h ..\cascades\haarcascade_frontalface_alt2.xml -c -g 1 -e 0 -r 0 -f 0 -t 1

REM echo ## face tracking from live camera ##
REM fit.exe -m my.amf -h haarcascade_frontalface_alt2.xml

pause