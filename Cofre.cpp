/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cofre.cpp
 * Author: admin
 * 
 * Created on 4 de mayo de 2016, 9:06
 */

#include "Cofre.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
Cofre::Cofre() {
}

Cofre::Cofre(const Cofre& orig) {
}

Cofre::~Cofre() {
}

void Cofre::mete(Item* item){
    Cofre *cofre=dynamic_cast<Cofre*>(item);
    if(cofre!=0)
        throw std::invalid_argument("[ERROR]: Item no permitido");
        this->Contenedor<Item>::mete(item); 
    
}

std::string Cofre::getDescripcion() const{
    std::stringstream ss;
    
    ss<<"Cofre con"<<this->cuantosHay()<<" elementos";
    return ss.str();
}