EXEC = main

# Αχεια .ο
OBJS= main.o living.o shop.o grid.o items.o spells.o debuff.o

#Ο μεταγλωτιστης
CC = g++
CXXFLAGS += -std=c++0x

$(EXEC): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)
