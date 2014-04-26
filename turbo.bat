.\..\tcc.exe -Wall -bench -D__WIN32 -I. ^
-Iwin32/include -Lwin32/lib win32/utils.c win32/mman.c win32/getdelim.c ^
win32/wingetopt.c win32/fnmatch.c win32/dlfcn.c win32/ftruncate.c ^
win32/time.c 0.c c.c mt.c p.c r.c k.c kc.c getline.c ^
kx.c kg.c km.c kn.c ko.c ks.c v.c va.c vc.c vd.c vf.c vg.c ^
vq.c main.c -o k.exe -lws2_32
pause