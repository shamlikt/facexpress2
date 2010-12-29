REM fit.exe -m ismail4-p5.amf -h haarcascade_frontalface_alt2.xml -v myvideo.avi
REM fit.exe -m ismail4-p5.amf -h haarcascade_frontalface_alt2.xml -c
REM fit.exe -m generic.amf -h haarcascade_frontalface_alt2.xml -c -g 1 -e 0 -r 1
REM fit.exe -m generic.amf -h haarcascade_frontalface_alt2.xml -c -g 1 -e 1 -r 1 -f 1 -t 1
REM fit.exe -m generic.amf -h haarcascade_frontalface_alt2.xml -i Goruntu007.jpg
REM fitD.exe -m ismail4-p5.amf -h haarcascade_frontalface_alt2.xml -i C:\Users\Onur\Desktop\yeni\Goruntu005.jpg
REM fitD.exe -m ismail4-p5.amf -h haarcascade_frontalface_alt2.xml -i C:\Users\Onur\Desktop\yeni\Goruntu006.jpg
REM fitD.exe -m ismail4-p5.amf -h haarcascade_frontalface_alt2.xml -i C:\Users\Onur\Desktop\yeni\Goruntu007.jpg
REM fitD.exe -m ismail4-p5.amf -h haarcascade_frontalface_alt2.xml -i C:\Users\Onur\Desktop\yeni\Goruntu008.jpg

REM echo off
set haarcascade=haarcascade_frontalface_alt2.xml
set model=onurp4l5.amf
REM set shape_model=C:\Users\ismail\eNTERFACE10\data\models\ismail.xml
set fit=fit.exe

set input_folder=C:\Users\Onur\Desktop\onurres\ekstra\
set image_extension=.jpg
REM set point_extension=.pts
REM set pose_extension=.pose
for /f %%a IN ('dir /b %input_folder%*%extension%') do %fit% -m %model% -h %haarcascade% -i %input_folder%%%~na%image_extension%

pause