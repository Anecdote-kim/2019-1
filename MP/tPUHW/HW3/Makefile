all:
	g++ -o tpu2 CCode.cpp CDecode.cpp CExecute.cpp CRegister.cpp CMemory.cpp main.cpp

mat:
	g++ -o mat CCode.cpp CDecode.cpp CExecute.cpp CRegister.cpp CMemory.cpp main.cpp
	./mat2 5x5mat.bin 128

mat2:
	g++ -o mat2 CCode.cpp CDecode.cpp CExecute.cpp CRegister.cpp CMemory.cpp main.cpp
	./mat2 mat.bin 47
