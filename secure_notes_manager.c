#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTES 100
#define TITLE_LEN 100
#define CONTENT_LEN 500

typedef struct {
    char title[TITLE_LEN];
    char content[CONTENT_LEN];
} Note;

Note notes[MAX_NOTES];
int count = 0;

void addNote() {
    if (count >= MAX_NOTES) {
        printf("Note limit reached!\n");
        return;
    }

    printf("Enter title: ");
    fgets(notes[count].title, TITLE_LEN, stdin);
    notes[count].title[strcspn(notes[count].title, "\n")] = '\0';

    printf("Enter content: ");
    fgets(notes[count].content, CONTENT_LEN, stdin);
    notes[count].content[strcspn(notes[count].content, "\n")] = '\0';

    count++;
    printf("Note added successfully!\n");
}

void viewNotes() {
    if (count == 0) {
        printf("No notes available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n--- Note %d ---\n", i + 1);
        printf("Title   : %s\n", notes[i].title);
        printf("Content : %s\n", notes[i].content);
    }
}

void saveNotes() {
    FILE *fp = fopen("notes.dat", "wb");

    if (!fp) {
        printf("Error saving file.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(notes, sizeof(Note), count, fp);

    fclose(fp);
    printf("Notes saved.\n");
}

void loadNotes() {
    FILE *fp = fopen("notes.dat", "rb");

    if (!fp) {
        printf("No saved notes found.\n");
        return;
    }

    fread(&count, sizeof(int), 1, fp);
    fread(notes, sizeof(Note), count, fp);

    fclose(fp);
    printf("Notes loaded.\n");
}

void deleteNote() {
    int index;

    if (count == 0) {
        printf("No notes to delete.\n");
        return;
    }

    viewNotes();

    printf("\nEnter note number to delete: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > count) {
        printf("Invalid note number.\n");
        return;
    }

    for (int i = index - 1; i < count - 1; i++) {
        notes[i] = notes[i + 1];
    }

    count--;
    printf("Note deleted.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Notes Manager =====\n");
        printf("1. Add Note\n");
        printf("2. View Notes\n");
        printf("3. Save Notes\n");
        printf("4. Load Notes\n");
        printf("5. Delete Note\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addNote();
                break;

            case 2:
                viewNotes();
                break;

            case 3:
                saveNotes();
                break;

            case 4:
                loadNotes();
                break;

            case 5:
                deleteNote();
                break;

            case 6:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
