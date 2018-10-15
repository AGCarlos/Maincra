/** [ Solución PR10 y punto de partida PR11 ]
 * @file   main.cpp
 * @author jrbalsas
 *
 * @date 15 de abril de 2016
 */

#include <cstdlib>
#include <iostream>

#include "ContenedorItem.h"
#include "Item.h"
#include "Bloque.h"
#include "Espada.h"
#include "Filete.h"
#include "Inventario.h"
#include "Cofre.h"
#include "EmptyContainer.h"
#include "ItemApilable.h"
using namespace std;

/**Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a 0
 * @return número de posiciones del vector con items creados*/
int inicializaItems(Contenedor<Item> &v) {
    v.mete(new Filete);
    return 1;
}

/**Libera los items del vector creados en memoria dinámica*/
void liberaItems(Contenedor<Item> &v) {
    for (int i = 0; i < v.cuantosHay(); i++) {
        delete v.saca(1);


    }

}

void visualiza(Contenedor<Item> &c) {
    std::cout << "CONTENIDO DEL COFRE" << std::endl
            << "===================" << std::endl;
    for (int i = 1; i <= c.cuantosHay(); i++) {
        std::cout << i << ".- "
                << c.consulta(i).getDescripcion() << std::endl;
    }

}

/**@brief Probando los Cofres
 * 
 */
int main(int argc, char** argv) {
    try {
        /* Creo un inventario y un cofre */
        Inventario inventory;
        Cofre* c=new Cofre; // Víctor: Te faltaba crear el Cofre
        
        /* Creo un filete para meterlo en el cofre y
         *  meto el cofre en el inventario */

        Filete* depollo = new Filete;
        c->mete(depollo);
        
        inventory.mete(c);
        /* Visualizo el cofre */

        visualiza(*c);

        /* Saco el cofre para comprobar que es un cofre y 
         * mostrarlo por pantalla */

        Item* buscado = (&inventory.consulta(1)); /* Saco el cofre y lo trasformo en un puntero */
        if (dynamic_cast<Cofre*> (buscado) != 0) /* Compruebo que es un cofre */

            visualiza(dynamic_cast<Cofre&> (*buscado)); /* Transformo el puntero en un referancia para poder usar visualiza */

    } catch (std::invalid_argument &e) {
        cerr << e.what()<<endl;
    } catch ( std::exception &e ){
        cerr << e.what()<<endl;
    } catch (...) {
        cerr << "Error chungo"<<endl;
    }

    return 0;
}

