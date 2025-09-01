all:
	g++ -fPIC -shared -o ../bin/hello.so hello.cpp

	g++ -fPIC -shared -o ../bin/hello.so msgpack.cpp

all
	./elfloader ./hello.so main1

	./elfloader ./hello.so Install

	g++ -o ../bin/elfloader elf_loader.cpp main.cpp wheelc/list.cpp  -ldl -lpthread

	g++ -o ../bin/elfloader elf_loader.cpp main.cpp wheelc/list.cpp  -ldl -lpthread -L ./ -lmyasio -Wl,-rpath,./

