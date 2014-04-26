This is an attempt to compile Kona (https://github/kevinlawler/kona) with tcc, the Tiny C Compiler.
You can obtain tcc from http://bellard.org/tcc.
I supplied some extra headers like winsock2.h that not come with tcc.
I tried to make the minimum changes in the codebase and put the extra code in separate files.
K.exe can run some scripts like 'apl.k' in the bench folder.
By now k_test can't compile due that tcc can't parse some characters like "`"or "\\". 
I'm currently working on translate those characters using escape sequences.
