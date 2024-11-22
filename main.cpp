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

bool addNode(Node **p, int value) {
    Node *newElement = new Node;
    if (!newElement) return false;
    newElement -> value = value;
    newElement -> next = *p;
    *p = newElement;
    return true;
}

int main() {
    Node *list;
    Node hashTable[hashTableLength] = {};
    int resp;

    do {
		cout << "MENU\n\n";
		cout << "1) Imprimir lista\n";
		cout << "2) Insertar elemento\n";
		cout << "4) Eliminar elemento\n";
        cout << "4) Imprimir hash";
		cout << "0) Salir\n\n";
		cout << "\tMarque su opcion: ";
		cin >> resp;
        switch (resp) {
            case 0: {
                cout << "Finalizando programa";            
            } break;


            case 1: {
                
            } break;

            case 2: {
                int element;
                cout << "\tIngrese el elemento a insertar: ";
                cin >> element;
                if (!addNode(&list, element)) cout << "No hay suficiente espacio en memoria para insertar un nuevo elemento\n";
            } break;

            case 3: {
                
            } break;

            case 4: {
                
            } break;

            default:
                cout << "Opción no valida" << endl;
            break;
        }
		
    } while(resp);

    return 0;
}