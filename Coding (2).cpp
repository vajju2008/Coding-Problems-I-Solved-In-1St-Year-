#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;
};

struct paragraph {
    struct sentence* data;
    int sentence_count;
};

struct document {
    struct paragraph* data;
    int paragraph_count;
};

struct document get_document(char* text) {
    struct document doc;
    doc.paragraph_count = 0;

    char* temp = strdup(text);
    char* para = strtok(temp, "\n");
    while (para) {
        doc.paragraph_count++;
        para = strtok(NULL, "\n");
    }

    doc.data = malloc(doc.paragraph_count * sizeof(struct paragraph));

    strcpy(temp, text);
    para = strtok(temp, "\n");
    int pi = 0;

    while (para) {
        struct paragraph p;
        p.sentence_count = 0;

        char* temp2 = strdup(para);
        char* sen = strtok(temp2, ".");
        while (sen) {
            p.sentence_count++;
            sen = strtok(NULL, ".");
        }

        p.data = malloc(p.sentence_count * sizeof(struct sentence));

        strcpy(temp2, para);
        sen = strtok(temp2, ".");
        int si = 0;

        while (sen) {
            struct sentence s;
            s.word_count = 0;

            char* temp3 = strdup(sen);
            char* word = strtok(temp3, " ");
            while (word) {
                s.word_count++;
                word = strtok(NULL, " ");
            }

            s.data = malloc(s.word_count * sizeof(struct word));

            strcpy(temp3, sen);
            word = strtok(temp3, " ");
            int wi = 0;

            while (word) {
                s.data[wi].data = strdup(word);
                wi++;
                word = strtok(NULL, " ");
            }

            p.data[si++] = s;
            sen = strtok(NULL, ".");
        }

        doc.data[pi++] = p;
        para = strtok(NULL, "\n");
    }

    return doc;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1];
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();

    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = malloc(strlen(doc) + 1);
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() {
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }
        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }
        else {
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
    return 0;
}

