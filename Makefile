all : testSystem testFlow




testSystem: testSystem.o System.o
	@g++ -o testSystem System.o testSystem.o -Wall -lm

testSystem.o: test/unit/testSystem.cpp
	@g++ -c test/unit/testSystem.cpp -Wall

System.o: src/System.cpp
	@g++ -c src/System.cpp -Wall




testFlow: testFlow.o Flow.o System.o
	@g++ -o testFlow Flow.o testFlow.o System.o -Wall -lm

testFlow.o: test/unit/testFlow.cpp 
	@g++ -c test/unit/testFlow.cpp -Wall -lm

Flow.o: src/Flow.cpp
	@g++ -c src/Flow.cpp -Wall



































# all: testFlow testSystem testModel

# testFlow: testFlow.o Flow.o Model.o System.o
# 	@g++ -o testFlow testFlow.o Flow;o Model.o System.o -Wall

# testSystem: testSystem.o Flow.o Model.o System.o
# 	@g++ -o testSystem testSystem.o Flow;o Model.o System.o -Wall

# testModel: testModel.o Flow.o Model.o System.o
# 	@g++ -o testModel testModel.o Flow;o Model.o System.o -Wall

# Flow.o: Flow.cpp
# 	@g++ -c src/Flow.cpp -Wall

# Model.o: Model.cpp
# 	@g++ -c src/Model.cpp -Wall

# System.o: System.cpp
# 	@g++ -c src/System.cpp -Wall

# testFlow.o: testFlow.cpp
# 	@g++ -c unit/testFlow.cpp -Wall

# testModel.o: testModel.cpp
# 	@g++ -c unit/testModel.cpp -Wall

# testSystem.o: testSystem.cpp
# 	@g++ -c unit/testSystem.cpp -Wall

# testFunc.o: testFunc.cpp
# 	@g++ -c func/testFunc.cpp -Wall



# all: main.o horario.o pessoa.o ponto.o supervisor.o venda.o vendedor.o data.o excecao.o funcionario.o chefe.o menu.o
# 	@g++ -o sistema main.o horario.o pessoa.o ponto.o supervisor.o venda.o vendedor.o data.o excecao.o funcionario.o chefe.o menu.o -Wall -g 
# 	@rm -r *.o
# main.o: main.cpp
# 	@g++ -c main.cpp -Wall  -g
# horario.o: horario.cpp
# 	@g++ -c horario.cpp -Wall -g
# pessoa.o: pessoa.cpp
# 	@g++ -c pessoa.cpp -Wall -g
# ponto.o: ponto.cpp
# 	@g++ -c ponto.cpp -Wall -g
# supervisor.o: supervisor.cpp
# 	@g++ -c supervisor.cpp -Wall -g
# venda.o: venda.cpp
# 	@g++ -c venda.cpp -Wall -g
# vendedor.o: vendedor.cpp
# 	@g++ -c vendedor.cpp -Wall -g
# data.o: data.cpp
# 	@g++ -c data.cpp -Wall -g
# excecao.o: excecao.cpp
# 	@g++ -c excecao.cpp -Wall -g
# funcionario.o: funcionario.cpp
# 	@g++ -c funcionario.cpp -Wall -g
# chefe.o: chefe.cpp
# 	@g++ -c chefe.cpp -Wall -g
# menu.o: menu.cpp
# 	@g++ -c menu.cpp -Wall -g

# run:
# 	@./sistema