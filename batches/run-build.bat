REM echo ####### Build 1d-profile 4-pyramid model #######
REM build -T 0 -p 4 -l 8 68pts jpg pts haarcascade_frontalface_alt2.xml my68-1d.amf

REM echo ####### Build 2d-profile 3-pyramid model #######
REM build -T 1 -p 3 -l 6 68pts jpg pts haarcascade_frontalface_alt2.xml my68-2d.amf

REM echo ####### Build LBP-profile 3-pyramid model #######
REM build -i 0 -l 8 -p 3 -t 0.975 -T PROFILE_1D 68pts jpg pts haarcascade_frontalface_alt2.xml my68-lbp.amf

buildD.exe ismail -l 8 jpg pts haarcascade_frontalface_alt2.xml ismailYENI.amf



REM build ..\..\eNTERFACE10\data\training\ismail jpg pts haarcascade_frontalface_alt2.xml ismaildata.amf

REM > build -i 0 -p 3 -l 8 -p 0.98 aam_api/images bmp asf haarcascade_frontalface_alt2.xml aamapi.amf

REM > build -i 1 -p 4 -l 8 yourimageset jpg pts haarcascade_frontalface_alt2.xml your.amf


	
pause
