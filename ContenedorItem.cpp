/** 
 * @file    Cofre.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */
/*
#include "ContenedorItem.h"
#include "EmptyContainer.h"
#include <stdexcept>

ContenedorItem::ContenedorItem(int cuantosCaben)
    :_maxItems(cuantosCaben)
    ,_numItems(0) {
    
    _items=new Item*[cuantosCaben];
    for (int i = 0; i < cuantosCaben; i++) {
        _items[i]=0;
    }
}

/**Crea un Cofre vacío del mismo tamaño del original*/
/*
ContenedorItem::ContenedorItem(const ContenedorItem& orig) 
    :_maxItems(orig._maxItems)
    ,_numItems(orig._numItems) {

    _items=new Item*[_maxItems];
    for (int i = 0; i < _maxItems; i++) {
        _items[i]=0;
    }
}

ContenedorItem::~ContenedorItem() {
    delete [] _items;
}

int ContenedorItem::cuantosHay() const {
    return _numItems;
}

int ContenedorItem::cuantosCaben() {
    return _maxItems;
}

void ContenedorItem::mete(Item* item) {
    if (!item) 
        throw std::invalid_argument ("[Cofre::mete] Intento de asignar puntero 0");
    if (_numItems==_maxItems)
        throw std::out_of_range("[Cofre::mete] No caben más elementos en el cofre");
    _items[_numItems++]=item;
}

/**@param cual nº orden del elemento a consultar
 * @return Referencia al objeto indicado del cofre
   @throw std::out_of_range si el elemento no existe
   @throw EmptyContainer si el cofre está vacío*/
/*
Item& ContenedorItem::consulta(int cual) {
    if (_numItems==0) 
        throw EmptyContainer("[Cofre::consulta] El cofre está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}


/**@param cual nº orden del elemento a extraer
 * @return Extrae del cofre y devuelve el puntero al Item indicado
   @throw std::out_of_range si el elemento no existe
   @throw EmptyContainer si el cofre está vacío*/
/*
Item* ContenedorItem::saca(int cual) {
    if (_numItems==0) 
        throw EmptyContainer("[Cofre::saca] El cofre está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::mete] El elemento indicado no existe");
    Item* elemento = _items[cual-1];
    _numItems--;
    if (_numItems>0)
        _items[cual-1]=_items[_numItems];
    return elemento;
}
*/ 
