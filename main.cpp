//
//  CSCI 160
//  Assignment 5
//  main.cpp
//
//  Created by snowyard on 2022-11-25.
//  Copyright © 2022 snowyard. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

// Struct Prototypes.
// Contains the number of each nucleotide and the sequence name.
struct fasta {
    char name[70];
    int a, c, g, t;

    // Constructor.
    fasta() : name(""), a(0), c(0), g(0), t(0) {}
};

// Function Prototypes.
// Outputs the DNA details in FASTA format.
void printFasta(struct fasta f);
// Returns the maximum integer of two values.
int getMax(int a, int b);
// Returns the minimum integer of two values.
int getMin(int a, int b);

int main() {
    // Variable declarations.
    // Array of DNA structs.
    fasta DNA_STRUCTS[20];
    int i = 0, j = -1;
    // The character placeholder, letter by letter.
    char c;
    // Whether the text line is the DNA sequence.
    bool isDNA = false;
    // The length of the sequence.
    int sequenceLength = 0;
    // The file name placeholder.
    char filename[20];
	
    // File pointer stream.
    FILE* fpin;
    
    // Ask for input.
    cout << "Enter filename: ";
    cin >> filename;
    
    // Open the file in read-mode and assign it to the file pointer stream.
    fpin = fopen(filename, "r");
	
    // If there is an error opening the file.
    if(!fpin) { 
        cout << endl << "ERROR! Could not open file " << filename;
    } 
    // If the file was opened successfully.
    else {
	// While not at the end of the file, iterate through each character.
        while(!feof(fpin)) {
	    // Get the character in question from the file.
            c = fgetc(fpin);
		
	    // If the character is '>', the next set of characters until '\n' or '\r' is part of the sequence name.
            if(c == '>') {
		// State that the text line in question is not a DNA sequence, but is rather a sequence name.
                isDNA = false;
		
		// Get the string from the rest of the line - is the sequence name.
                fgets(DNA_STRUCTS[i].name, 69, fpin);
		    
                i++;
                j++;
            }
	    // If the character is a newline character. Ignore and break to next line.
            else if(c == '\n' || c == '\r') {
		// Reset whether the text line in question is a DNA sequence or a sequence name.
                isDNA = true;
            }
	    // If the character is anything else.
            else {
		// If the character belongs to the DNA sequence.
                if(isDNA) {
		    switch (c) {
			case 'a':
			case 'A':
			    sequenceLength++;
			    DNA_STRUCTS[j].a++;
			    break;
			case 'c':
			case 'C':
			    sequenceLength++;
			    DNA_STRUCTS[j].c++;
			    break;
			case 'g':
			case 'G':
			    sequenceLength++;
			    DNA_STRUCTS[j].g++;
			    break;
			case 't':
			case 'T':
			    sequenceLength++;
			    DNA_STRUCTS[j].t++;
			    break;
			default:
			    break;
		    }
                }
            }
        }
        
	// For each DNA structure.
        for(int i=0; i < 10; i++) {
	    printFasta(DNA_STRUCTS[i]);
	}
        
	// Print the summary.
        cout << string(31, '*') << endl
         << "Report for file " << filename << endl
         << "Number of sequences: " << i << endl
         << "Total sequence length: " << sequenceLength << endl
         << "Maximum sequence length: " << endl
         << "Minimum sequence length: " << endl
         << string(31, '*') << endl;
    }
}

void printFasta(struct fasta f) {
    // If the length of the sequence name is longer than 2 characters.
    if(strlen(f.name) > 2) {
	// Print the sequence name and number of nucleotides.
        cout << endl << ">" << f.name << endl
             << "Length: " << endl
             << "A: " << f.a << endl
             << "C: " << f.c << endl
             << "G: " << f.g << endl
             << "T: " << f.t << endl
    }
}
