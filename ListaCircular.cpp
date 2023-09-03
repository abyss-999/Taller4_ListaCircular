#include <iostream>
#include <conio.h>
using namespace std;

struct Elmto {
    int num;
    Elmto* siguiente;
};

Elmto* pi = nullptr;

typedef struct Elmto* Tlista;
///////////////////////////////////////////////////////////
void insertar_dato(int dato) {
    Elmto* nuevo = new Elmto;
    nuevo->num = dato;

    if (pi == nullptr) {
        pi = nuevo;
        nuevo->siguiente = pi;
    } else {
        Elmto* temp = pi;
        while (temp->siguiente != pi) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        nuevo->siguiente = pi;
    }
}
///////////////////////////////////////////////////////////
void BuscarElemento(Elmto* lista, int valor) {
    Tlista q = lista;
    int i = 0, band = 0;

    do {
        if (q->num == valor) {
            cout << endl << "Encontrado en la posicion: " << i << endl;
            band = 1;
        }
        q = q->siguiente;
        i++;
    } while (q != lista);

    if (band == 0)
        cout << "\n\nNumero no encontrado" << endl;
}
///////////////////////////////////////////////////////////
void EliminarDato(Elmto*& lista, int valor) {
    if (lista != nullptr) {
        Elmto* aux_borrar = lista;
        Elmto* anterior = nullptr;

        do {
            if (aux_borrar->num == valor) {
                if (anterior == nullptr) {
                    Elmto* ultimo = lista;
                    while (ultimo->siguiente != lista) {
                        ultimo = ultimo->siguiente;
                    }
                    lista = lista->siguiente;
                    ultimo->siguiente = lista;
                } else {
                    anterior->siguiente = aux_borrar->siguiente;
                }
                delete aux_borrar;
                return;
            }
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        } while (aux_borrar != lista);

        cout << "\n\nNumero no encontrado" << endl;
    }
}
///////////////////////////////////////////////////////////
int ActualizarLista(int valor, int valor_actualizar) {
    Tlista temp = pi;
    int encontrado = 0;

    do {
        if (temp->num == valor) {
            temp->num = valor_actualizar;
            encontrado = 1;
        }
        temp = temp->siguiente;
    } while (temp != pi);

    return encontrado;
}
///////////////////////////////////////////////////////////
void mostrar_lista() {
    int i = 0, band = 0;
    Elmto* temp = pi;

    if (temp != nullptr) {
        do {
            cout << "elemento " << i << ": " << temp->num << endl << endl;
            temp = temp->siguiente;
            i++;
        } while (temp != pi);
    }
}
///////////////////////////////////////////////////////////
int main() {
    int dato, valor_actualizar;
    char respuesta;

    do {
        cout << endl << "***************";
        cout << endl << "Ingrese un dato: ";
        cin >> dato;
        insertar_dato(dato);
        cout << endl << "Seguir ingresando datos? (s/n)"<<endl;
        respuesta = getch();
    } while (respuesta == 's');

    mostrar_lista();

    do {
        cout << endl << "***************";
        cout << endl << "Deseas buscar elementos? (s/n): ";
        respuesta = getch();
        if (respuesta == 's') {
            cout << "\nDigite el numero que quieres buscar: ";
            cin >> dato;
            BuscarElemento(pi, dato);
        }
    } while (respuesta == 's');

    do {
        cout << endl << "***************";
        cout << endl << "Desea actualizar elementos? (s/n)";
        respuesta = getch();
        if (respuesta == 's') {
            cout << "\nDigite el numero que quieres actualizar: ";
            cin >> dato;
            cout << "\nValor a modificar: ";
            cin >> valor_actualizar;
            if (ActualizarLista(dato, valor_actualizar) == 1) {
                cout << "El valor se actualizo" << endl;
                mostrar_lista();
            } else {
                cout << "El valor no se encontro en la lista" << endl;
            }
        }
    } while (respuesta == 's');

    do {
        cout << endl << "***************";
        cout << endl << "Desea eliminar elementos? (s/n)";
        respuesta = getch();
        if (respuesta == 's') {
            cout << "\nDigite el numero que quieres eliminar: "<<endl;
            cin >> dato;
            EliminarDato(pi, dato);
            mostrar_lista();
        }
    } while (respuesta == 's');
    return 0;
}