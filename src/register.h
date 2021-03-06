/*
 * This is the file for the general includes, constant defines and function definitions of Archiver.
 *
 * Written by Gabriel Alves <https://github.com/CptSpookz> and Matheus Bortoleto <https://github.com/explodingnuggets>.
 * São Carlos - SP, 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define REGSIZE 85
#define BLKSIZE 512
#define KEYSIZE 5
#define TITLESIZE 30
#define AUTHORSIZE 20
#define LINKSIZE 30

/* Register for a file manager of book download links
 * Total number of bytes: 84 bytes
 * Defines the format of the register
 */
typedef struct{
    char key[KEYSIZE]; // 5 bytes
    char title[TITLESIZE]; // 30 bytes
    char author[AUTHORSIZE]; // 20 bytes
    char link[LINKSIZE]; // 30 bytes [better store shortened link]
} reg;

/*
 * Block structure for register control
 * Blocks have fixed 512 bytes size, 2 bytes header + 6 registers array
 * Blocks start with a 0x23 0x21 (ASCII '#!') header for identification
 */
typedef struct{
    char header[2];
    reg reg_index[6];
} block;

// Register related operations
int searchreg(reg*, char*, char*);
int teststr(char*, char*, const char*);
int insertreg(reg, char*);
int listreg(char*);
int removereg(char*, char*);
void readreg(reg*);
void writereg(reg);

// Block operations
block* newblock();

// General file operations
int createfile(char*);
int compactfile(char*);
