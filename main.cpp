#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

//prototypes
void printFasta(struct fasta f);
int getMax(int a, int b);
int getMin(int a, int b);

//struct
struct fasta
{
        char name[70] = "";
	int a = 0, c = 0, g = 0, t = 0;
};

int main()
{
    fasta DNA_STRUCTS[20];
    FILE* fpin; // file declaration
    
    cout << "Enter filename : "; // user enters filename
    char filename[20];
    cin >> filename;
    
    int j = -1; 
    int i = 0; 
    char c; // letter by letter
    bool isDNA = 0; // detected DNA sequence
    int sequenceLength = 0;
    
    fpin = fopen(filename, "r"); // read file
    if(!fpin) { // file error case
        cout << "\nERROR! Could not open file " << filename;
    } else { // if file is opened
        while(!feof(fpin)) { // while running through file
            c = fgetc(fpin);
            if(c == '>') { // when sequence name is encountered, isDNA is false
                isDNA = 0;
                fgets(DNA_STRUCTS[i].name, 69, fpin); // gets name
                i++;
                j++;
            }
            else if(c == '\n' || c == '\r') { // when line break, isDNA is true
                isDNA = 1;
            }
            else {
                if(isDNA) {
                    if(c == 'A' || c == 'a' || c == 'C' || c == 'c' || c == 'G' || c == 'g' || c == 'T' || c == 't')
                        sequenceLength++; // counts alphabet 
                    
                    if(c == 'A' || c == 'a')
                        DNA_STRUCTS[j].a++;
                    else if (c == 'C' || c == 'c')
                        DNA_STRUCTS[j].c++;
                    else if (c == 'G' || c == 'g')
                        DNA_STRUCTS[j].g++;
                    else if (c == 'T' || c == 't')
                        DNA_STRUCTS[j].t++;
                }
            }
        }
        
        for(int i=0; i < 10; i++) // Loops through struct array and prints them out
            printFasta(DNA_STRUCTS[i]);
        
        cout << "*******************************\n"
         << "Report for file " << filename << endl
         << "Number of sequences: " << i 
         << "\nTotal sequence length: " << sequenceLength
         << "\nMaximum sequence length: "
         << "\nMinimum sequence length: "
         << "\n*******************************";
    }
}

void printFasta(struct fasta f) {
    if(strlen(f.name) > 2) { // if struct has no name, do not display
        cout << "\n>" << f.name << "\n"
             << "Length: " 
             << "A: " << f.a << "\n"
             << "C: " << f.c << "\n"
             << "G: " << f.g << "\n"
             << "T: " << f.t << "\n";
    }
}
