#ifndef DIRECTORY_H
#define DIRECTORY_H

struct DirectoryElement;
struct Directory;

DirectoryElement *createElement(char name[], int number, DirectoryElement *next);
Directory *createDirectory();
void deleteDirectory(Directory *directory);
bool isEmpty(Directory *directory);
bool endOfDirectory(DirectoryElement *element);
void insertFirst(Directory *directory, char name[], int number);
void insertAfter(DirectoryElement *elem, char name[], int number);
int compareStrings(char string1[], char string2[]);
void insertSorted(Directory *directory, char name[], int number);
void printDirectory(Directory *directory);
void findNameByPhone(Directory *directory, int number);
void findPhoneByName(Directory *directory, char name[]);
void saveToFile(Directory *directory, char fileName[]);
void readFromFile(Directory *directory, char fileName[]);

#endif // DIRECTORY_H
