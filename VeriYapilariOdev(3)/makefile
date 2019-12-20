hepsi:derle calistir

derle:BinaryTree.o Node.o Test.o
	g++ ./lib/BinaryTree.o ./lib/Node.o ./lib/Test.o -o ./bin/Test

BinaryTree.o:
	g++ -I "./include/" -o ./lib/BinaryTree.o -c ./src/BinaryTree.cpp 

Node.o:
	g++ -I "./include/" -o ./lib/Node.o -c ./src/Node.cpp 

Test.o:
	g++ -I "./include/" -o ./lib/Test.o -c ./src/Test.cpp 

calistir:
	./bin/Test

