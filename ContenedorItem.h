/** 
 * @file    Cofre.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Item.h"
#include "EmptyContainer.h"

#ifndef CONTENEDORITEM_H
#define CONTENEDORITEM_H
#include <string>
#include <stdexcept>
template<typename T>
class Contenedor{
public:
    Contenedor<T>(int cuantosCaben=27):
    _maxItems(cuantosCaben)
    ,_numItems(0)
    {
    _items=new Item*[cuantosCaben];
    for (int i = 0; i < cuantosCaben; i++) {
        _items[i]=0;
    }
    };
    
    Contenedor<T>(const Contenedor<T>& orig):
    _maxItems(orig._maxItems)
    ,_numItems(orig._numItems)
    {
        _items=new Item*[_maxItems];
    for (int i = 0; i < _maxItems; i++) {
        _items[i]=0;
    }
    };
    
    virtual ~Contenedor<T>()
    { delete [] _items;};
    
    int cuantosCaben() { return _maxItems; };
    
    int cuantosHay() const  { return _numItems;};
    
    virtual void mete(T *item)
    {
    if (!item) 
        throw std::invalid_argument ("[Cofre::mete] Intento de asignar puntero 0");
    if (_numItems==_maxItems)
        throw std::out_of_range("[Cofre::mete] No caben más elementos en el cofre");
    _items[_numItems++]=item;
    };
    
    T& consulta(int cual)
    {
    if (_numItems==0) 
        throw EmptyContainer("[Cofre::consulta] El cofre está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::consulta] El elemento indicado no existe");
    return *_items[cual-1];
    };
    
    T* saca(int cual)
    {
    if (_numItems==0) 
        throw EmptyContainer("[Cofre::saca] El cofre está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Cofre::mete] El elemento indicado no existe");
    Item* elemento = _items[cual-1];
    _numItems--;
    if (_numItems>0)
        _items[cual-1]=_items[_numItems];
    return elemento;
    };
    
private:
    int _maxItems; ///< Tamaño del vector de punteros
    Item* *_items; ///< Vector de punteros creado dinámicamente
    int _numItems; ///< Primeras posiciones del vector ocupadas (máximo maxItems)
};

#endif /* COFRE_H */

