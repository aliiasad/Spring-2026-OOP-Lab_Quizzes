# include <iostream>
using namespace std;

char* readParagraph();

//helper functions
void findWord(char* array, char end[]);
bool strcmp(char str1[], char str2[]);
void strcpy(char src[], char dest[]);
int strlen(char str[]);

int main()  {

    char end[] = "END";
    char* array = readParagraph();
    //findWord(array, end);

    cout << array;

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

void findWord(char* array, char end[])  {
    int i = 0;
    while (array[i] != '\0')    {
        char temp[101];
        int j = 0;

        while (array[i] != ' ' && array[i] != '\0') {
            temp[j++] = array[i++];
        }
        temp[j] = '\0';

        if (strcmp(temp, end)) {
            i-=4;
            array[i] = '\0';
            return;
        }
        if (array[i] == ' ') i++;
    }
}

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