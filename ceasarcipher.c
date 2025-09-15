#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(const char *inputFile, const char *outputFile, int key) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");
    char ch;
    if (!fin || !fout) {
        printf("File error\n");
        return;
    }
    while ((ch = fgetc(fin)) != EOF) {
        if (ch >= 'a' && ch <= 'z')
            fputc(((ch - 'a' + key) % 26) + 'a', fout);
        else if (ch >= 'A' && ch <= 'Z')
            fputc(((ch - 'A' + key) % 26) + 'A', fout);
        else
            fputc(ch, fout);
    }
    fclose(fin);
    fclose(fout);
    printf("Encryption done. Saved in %s\n", outputFile);
}

void decryptFile(const char *inputFile, const char *outputFile, int key) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");
    char ch;
    if (!fin || !fout) {
        printf("File error\n");
        return;
    }
    while ((ch = fgetc(fin)) != EOF) {
        if (ch >= 'a' && ch <= 'z')
            fputc(((ch - 'a' - key + 26) % 26) + 'a', fout);
        else if (ch >= 'A' && ch <= 'Z')
            fputc(((ch - 'A' - key + 26) % 26) + 'A', fout);
        else
            fputc(ch, fout);
    }
    fclose(fin);
    fclose(fout);
    printf("Decryption done. Saved in %s\n", outputFile);
}

int main() {
    char inputFile[100], outputFile[100];
    int key, choice, cont = 1;

    while (cont) {
        printf("Enter input filename: ");
        scanf("%s", inputFile);
        printf("Enter output filename: ");
        scanf("%s", outputFile);
        printf("Enter key: ");
        scanf("%d", &key);
        printf("1. Encrypt\n2. Decrypt\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            encryptFile(inputFile, outputFile, key);
        else if (choice == 2)
            decryptFile(inputFile, outputFile, key);
        else
            printf("Invalid choice\n");

        printf("Continue? (1-Yes / 0-No): ");
        scanf("%d", &cont);
    }
    return 0;
}
