#include<iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

int hashTableLength = 10;

int hashFunction(int value) {
    return value % hashTableLength;
}

void printHashTable(Node *table) {
    for (int i = 0; i < hashTableLength; i++) {
        cout << i << "|" << table[i].value << endl;
    }
    cout << "\n\n";
}

void printList(Node *p) {
    cout << "Imprimendo la lista actual:\n\n";
    while (p) {
        cout << "|" << p -> value << "| -> ";
        p = p -> next;
    }
    cout << "NULL\n\n";
}

bool addNode(Node **p, int value) {
    Node *newElement = new Node;
    if (!newElement) return false;
    newElement -> value = value;
    newElement -> next = *p;
    *p = newElement;
    return true;
}

void deleteNode(Node **p, int value) {
    Node *aux = *p;
    while (aux && aux -> value != value) aux = aux -> next; 
    if (!aux) return;
    else if (aux == *p) *p = (*p) -> next;
    else {
        Node *aux2 = *p;
        while (aux2 -> next != aux) aux2 = aux2 -> next;
        aux2 -> next = aux -> next;
    }
    delete aux;
}

int main() {
    Node *list = NULL;
    Node *hashTable = new Node[hashTableLength] {};
    int resp;

    do {
		cout << "MENU\n\n";
		cout << "1) Imprimir lista\n";
		cout << "2) Insertar elemento\n";
		cout << "3) Eliminar elemento\n";
        cout << "4) Imprimir hash\n";
		cout << "0) Salir\n\n";
		cout << "\tMarque su opcion: ";
		cin >> resp;
        switch (resp) {
            case 0: {
                cout << "Finalizando programa";            
            } break;

            case 1: {
                printList(list);
            } break;

            case 2: {
                int element;
                cout << "\tIngrese el elemento a insertar: ";
                cin >> element;
                if (!addNode(&list, element)) cout << "No hay suficiente espacio en memoria para insertar un nuevo elemento\n";
            } break;

            case 3: {
                int element;
                cout << "\tIngrese el elemento a insertar: ";
                cin >> element;
                deleteNode(&list, element);
            } break;

            case 4: {
                printHashTable(hashTable);
            } break;

            default:
                cout << "Opción no valida" << endl;
            break;
        }
		
    } while(resp);

    return 0;
}