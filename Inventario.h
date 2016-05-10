/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventario.h
 * Author: admin
 *
 * Created on 4 de mayo de 2016, 9:15
 */

#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "ContenedorItem.h"
class Inventario: public Contenedor<Item>{
public:
    Inventario();
    Inventario(const Inventario& orig);
    virtual ~Inventario();
private:

};

#endif /* INVENTARIO_H */

