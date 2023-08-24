all: JavaBot.class CppBot

clean:
	rm -rvf CppBot *.class

JavaBot.class: JavaBot.java
	javac JavaBot.java

CppBot: CppBot.cpp
	clang++ -O2 CppBot.cpp -o CppBot