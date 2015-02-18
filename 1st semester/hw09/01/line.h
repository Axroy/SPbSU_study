#ifndef LINE_H
#define LINE_H

struct Line;

Line *createLine();
Line *createLine(int length);
Line *createLine(int length, char symbols[]);
Line *createLine(char symbols[]);
Line *createLine(Line *line);
void deleteLine(Line *line);
Line *clone(Line *line);
void concat(Line *argumentLine, Line *currentLine);
int lineLength(Line *line);
void printLine(Line *line);
bool areEqual(Line *line1, Line *line2);
bool isEmpty(Line *line);
Line *copy(Line *line, int startingPos, int length);
//char *getSymbols(Line *line);
char *getSymbols(Line *line);
void addLength(Line *line, int length);
void addSymbol(Line *line, char symbol);
char getSymbol(Line *line, int position);
void clearLine(Line *line);
int compareLines(Line *line1, Line *line2);

#endif // LINE_H
