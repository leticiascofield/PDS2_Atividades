
vpl_execution: ./build/Pessoa.o ./build/Funcionario.o ./build/Professor.o ./build/main.o
	g++ ./build/*.o -o vpl_execution

./build/Pessoa.o: ./include/Pessoa.hpp ./src/entidades/Pessoa.cpp
	g++ -I ./include/ -c ./src/entidades/Pessoa.cpp -o ./build/Pessoa.o

./build/Funcionario.o: ./include/Pessoa.hpp ./include/Funcionario.hpp ./src/entidades/Funcionario.cpp
	g++ -I ./include/ -c ./src/entidades/Funcionario.cpp -o ./build/Funcionario.o

./build/Professor.o: ./include/Pessoa.hpp ./include/Funcionario.hpp ./include/Professor.hpp ./src/entidades/Professor.cpp
	g++ -I ./include/ -c ./src/entidades/Professor.cpp -o ./build/Professor.o

./build/main.o: ./include/Funcionario.hpp ./include/Pessoa.hpp ./include/Professor.hpp ./src/main.cpp
	g++ -I ./include/ -c ./src/main.cpp -o ./build/main.o
