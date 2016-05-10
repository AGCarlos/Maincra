/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cofre.h
 * Author: admin
 *
 * Created on 4 de mayo de 2016, 9:06
 */

#ifndef COFRE_H
#define COFRE_H

#include "ContenedorItem.h" 
class Cofre: public Contenedor<Item>, public Item {
public:
    Cofre();
    Cofre(const Cofre& orig);
    virtual ~Cofre();
    virtual void mete(Item *item);
    virtual std::string getDescripcion() const;
private:
    int _maxItems; ///< Tamaño del vector de punteros
    Item* *_items; ///< Vector de punteros creado dinámicamente
    int _numItems; ///< Primeras posiciones del vector ocupadas (máximo maxItems)
};

#endif /* COFRE_H */

