JAVAC = javac
JAVA = java
MAIN = swing.Screen

SOURCES := $(wildcard *.java)
CLASSES := $(SOURCES:.java=.class)

all: compile

compile:
	$(JAVAC) -d .. $(SOURCES)

run: compile
	$(JAVA) -cp .. $(MAIN)

clean:
	rm -f *.class

.PHONY: all compile run clean
