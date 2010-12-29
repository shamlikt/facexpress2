CPPFLAGS = -fpic -O2 -Wall -g -MD -I../include -I/usr/local/include/opencv
PROGRAMS = fit build 
LIBS = -Wl,-rpath=/usr/local/lib  -L/usr/local/lib  -lcv -lcxcore -lhighgui

all: $(PROGRAMS)


demo_build.o: demo_build.cpp
	g++  $(CPPFLAGS)  -c -o demo_build.o demo_build.cpp
demo_fit.o: demo_fit.cpp
	g++  $(CPPFLAGS)  -c -o demo_fit.o demo_fit.cpp
video_camera.o: video_camera.cpp
	g++  $(CPPFLAGS)  -c -o video_camera.o video_camera.cpp
vjfacedetect.o: vjfacedetect.cpp
	g++  $(CPPFLAGS)  -c -o vjfacedetect.o vjfacedetect.cpp

fit: demo_fit.o vjfacedetect.o video_camera.o 
	g++ -o fit demo_fit.o vjfacedetect.o video_camera.o ../libs/linux/libasmlibrary.a $(LIBS) 

build: demo_build.o vjfacedetect.o
	g++ -o build demo_build.o vjfacedetect.o ../libs/linux/libasmlibrary.a $(LIBS)
clean:
	rm -f *.o $(PROGRAMS)
