# include <iostream>
using namespace std;

char* readParagraph();
char** ReadKeywords(int& keywordCount);
void RemoveDuplicateKeywords(char*& paragraph, char** keywords, int keywordCount);
void displayParagraph(const char* paragraph);
void DeallocateMemory(char* paragraph, char** keywords, int keywordCount);

//helper functions
bool strcmp(char str1[], char str2[]);
void strcpy(char src[], char dest[]);
int strlen(char str[]);

int main()  {
    //test case
    int keywordCount = 0;
    char* paragraph = readParagraph();
    char** keywords = ReadKeywords(keywordCount);
    RemoveDuplicateKeywords(paragraph, keywords, keywordCount);
    displayParagraph(paragraph);
    DeallocateMemory(paragraph, keywords, keywordCount);

    return 0;
}

char* readParagraph()   {
    int dummySize = 20, counter = 0;
    char temp[100];

    char end[] = "END";
    char* paragraph = new char[dummySize];

    while (cin >> temp) {
        if (strcmp(temp, end)) break;

        if (counter > 0) {
            if (counter >= dummySize){
                dummySize *= 2;

                char* newArray = new char[dummySize];
                for (int j = 0; j < counter; j++)   {
                    *(newArray + j) = *(paragraph + j);
                }

                delete[] paragraph;
                paragraph = newArray;
            }

                *(paragraph + counter) = ' ';
                counter++;
            }

        for (int i = 0; i < strlen(temp); i++)  {
            if (counter >= dummySize){
                dummySize *= 2;

                char* newArray = new char[dummySize];
                for (int j = 0; j < counter; j++)   {
                    *(newArray + j) = *(paragraph + j);
                }

                delete[] paragraph;
                paragraph = newArray;
            }
            *(paragraph + counter) = temp[i];
            counter++;     
        }
    }
    *(paragraph + counter) = '\0';
    //exact size = counter
    char* exactSize = new char[counter + 1];
    strcpy(paragraph, exactSize);
    delete[] paragraph;

    paragraph = exactSize;

    return paragraph;
}

char** ReadKeywords(int& keywordCount)  {
    int dummySize = 20;

    char temp[100];
    char stop[] = "STOP";

    char** keywords = new char*[dummySize];

    while (cin >> temp) {
        if (strcmp(temp, stop)) break;

            if(keywordCount  >= dummySize)    {
                dummySize *= 2;

                char** newArray = new char*[dummySize];
                for (int j = 0; j < keywordCount; j++)   {      
                    *(newArray + j) = *(keywords + j);
                }
                delete[] keywords;

                keywords = newArray;
            }
        *(keywords + keywordCount) = new char[strlen(temp) + 1];
        strcpy(temp, *(keywords + keywordCount));
        keywordCount++;
    }
    
    //exact size
    char** exactSize = new char*[keywordCount];
    for (int i = 0; i < keywordCount; i++)  {
        *(exactSize + i) = *(keywords + i);
    }
    delete[] keywords;

    keywords = exactSize;

    return keywords;

}

void RemoveDuplicateKeywords(char*& paragraph, char** keywords, int keywordCount)   {

    for (int i = 0; i < keywordCount; i++)  {
        bool firstFound = false;
        int j = 0;
        while (paragraph[j] != '\0')    {
            int wordStart = j; //store before extracting
            char temp[100];
            int k = 0;
            while (paragraph[j] != ' ' && paragraph[j] != '\0') {
                temp[k++] = paragraph[j++];
            }
            temp[k] = '\0';

            if (strcmp(temp, *(keywords + i)) && !firstFound) {
                firstFound = true;
                if (*(paragraph + j) == ' ') j++;
            }
            else if (strcmp(temp, *(keywords + i)) && firstFound)   {
                int wordEnd = j;
                if (*(paragraph + wordEnd) == ' ') wordEnd++;

                int s = wordStart;
                while (*(paragraph + wordEnd) != '\0') {
                    *(paragraph + s) = *(paragraph + wordEnd);
                    s++;
                    wordEnd++;
                }
                *(paragraph + s) = '\0';
                j = wordStart;
            }
            else
                if (*(paragraph + j) == ' ') j++;
        }
    }
    int len = strlen(paragraph);

        char* exactSize = new char[len + 1];
        strcpy(paragraph, exactSize);

        delete[] paragraph;
        paragraph = exactSize;

        return;
}

void displayParagraph(const char* paragraph)    {
    cout << paragraph << endl;
    return;
}

void DeallocateMemory(char* paragraph, char** keywords, int keywordCount)   {
    //deallocate paragraph
    delete[] paragraph;

    //deallocate keywords
    for (int i = 0; i < keywordCount; i++)   {
        delete[] *(keywords + i);
    }
    delete[] keywords;
}

//helper functions

bool strcmp(char str1[], char str2[])   {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')  {
        if (str1[i] != str2[i]) return false;
        else i++;
    }

    return str1[i] == str2[i];
}

void strcpy(char src[], char dest[])    {
    int i = 0;
    while (src[i] != '\0')  {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return;
}

int strlen(char str[])    {
    int i = 0;
    while (str[i] != '\0')  {
        i++;
    }
    return i;
}