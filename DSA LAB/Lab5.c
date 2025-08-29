#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    float coeff;
    int exp;
    struct Node *next;
} Node;

Node* createNode(float c, int e) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->coeff = c; n->exp = e; n->next = NULL;
    return n;
}

void insert(Node **poly, float c, int e) {
    Node* n = createNode(c, e);
    if (!*poly) *poly = n;
    else {
        Node* t = *poly;
        while (t->next) t = t->next;
        t->next = n;
    }
}

void printPoly(Node* p) {
    if (!p) { printf("0\n"); return; }
    while (p) {
        printf("%.1fx^%d", p->coeff, p->exp);
        if (p->next) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

Node* addPoly(Node* p1, Node* p2) {
    Node* res = NULL;
    while (p1 && p2) {
        if (p1->exp > p2->exp) { insert(&res, p1->coeff, p1->exp); p1 = p1->next; }
        else if (p2->exp > p1->exp) { insert(&res, p2->coeff, p2->exp); p2 = p2->next; }
        else { insert(&res, p1->coeff + p2->coeff, p1->exp); p1 = p1->next; p2 = p2->next; }
    }
    while (p1) { insert(&res, p1->coeff, p1->exp); p1 = p1->next; }
    while (p2) { insert(&res, p2->coeff, p2->exp); p2 = p2->next; }
    return res;
}

Node* multPoly(Node* p1, Node* p2) {
    Node* res = NULL;
    for (Node* a = p1; a; a = a->next)
        for (Node* b = p2; b; b = b->next)
            insert(&res, a->coeff * b->coeff, a->exp + b->exp);
    return res; // No combine like terms for simplicity
}

float evaluate(Node* p, float x) {
    float sum = 0;
    while (p) { sum += p->coeff * pow(x, p->exp); p = p->next; }
    return sum;
}

int main() {
    Node *P1 = NULL, *P2 = NULL, *R = NULL;
        printf("\n=== Polynomial Menu ===\n1. Insert term (choose P1 or P2)\n2. Print polynomials\n3. Add (R = P1 + P2)\n4. Multiply (R = P1 * P2)\n5. Evaluate polynomial\n0. Exit\n");
    int choice;
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int which;
                float c; int e;
                printf("Insert into which polynomial? (1=P1, 2=P2): ");
                scanf("%d", &which);
                printf("Enter coefficient and exponent: ");
                scanf("%f%d", &c, &e);
                if (which == 1) insert(&P1, c, e);
                else insert(&P2, c, e);
                break;
            }
            case 2:
                printf("P1: "); printPoly(P1);
                printf("P2: "); printPoly(P2);
              //  printf("R: ");  printPoly(R);
                break;
            case 3:
                R = addPoly(P1, P2);
                printf("Result (P1 + P2): "); printPoly(R);
                break;
            case 4:
                R = multPoly(P1, P2);
                printf("Result (P1 * P2): "); printPoly(R);
                break;
            case 5: {
                int w; float x;
                printf("Which poly? (1=P1, 2=P2, 3=R): ");
                scanf("%d", &w);
                printf("Enter x: ");
                scanf("%f", &x);
                Node* p = (w==1)?P1:(w==2)?P2:R;
                if (!p) printf("Polynomial is empty.\n");
                else printf("Value = %.2f\n", evaluate(p, x));
                break;
            }
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}
