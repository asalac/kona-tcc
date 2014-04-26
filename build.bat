.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c 0.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c c.c
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c getline.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c mt.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c p.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c r.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c k.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c kc.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c kx.c
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c kg.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c km.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c kn.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c ko.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c ks.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c v.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c va.c
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c vc.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c vd.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c vf.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c vg.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c vq.c 
pause
.\..\tcc.exe -D__WIN32  -I. -Iwin32/include -c main.c 
pause
.\..\tcc.exe -D__WIN32 -I. -Iwin32/include -c win32/ftruncate.c 
pause
.\..\tcc.exe -D__WIN32 -I. -Iwin32/include -c win32/dlfcn.c 
pause
.\..\tcc.exe -D__WIN32 -I. -Iwin32/include -c win32/fnmatch.c 
pause
.\..\tcc.exe -D__WIN32 -I. -Iwin32/include -c win32/getdelim.c 
pause
.\..\tcc.exe -D__WIN32 -I. -Iwin32/include -c win32/mman.c 
pause
.\..\tcc.exe -D__WIN32 -I. -Iwin32/include -c win32/utils.c 
pause
.\..\tcc.exe -D__WIN32 -I. -Iwin32/include -c win32/time.c 
pause
.\..\tcc.exe -D__WIN32 -I. -Iwin32/include -c win32/wingetopt.c 
pause
.\..\tcc.exe -Wall -bench -Lwin32/lib utils.o ^
mman.o getdelim.o wingetopt.o fnmatch.o dlfcn.o ftruncate.o ^
time.o 0.o c.o mt.o p.o r.o k.o kc.o getline.o kx.o kg.o ^
km.o kn.o ko.o ks.o v.o va.o vc.o vd.o vf.o vg.o ^
vq.o main.o -o k1.exe -lws2_32
pause
del *.o
pause


