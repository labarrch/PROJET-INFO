makefile :

lexer : lexeur.cpp
	g++ -o lexer lexeur.cpp
	./lexer

lexer_json.o : lexeur_json.cpp lexeur_json.h
	g++ -o lexeur_json.cpp
	./lexer

simulateur : simulateur.cpp lexeur_json.cpp
	g++ -o simulateur simulateur.cpp lexeur_json.cpp
	./simulateur
