#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include "raylib.h"
//Auto explicativo
typedef struct JOGADOR{
    Vector2 Tamanho;
    Vector2 Pos;
    bool NoChao;
    float VelX;
    float VelY;
    bool Movendo;
    bool InputTeclado;
    bool Invencivel;

}JOGADOR;

typedef struct TARTARUGA{

    bool Existe;
    Rectangle CorpoTart;

}TARTARUGA;

#endif // STRUCTS_H_INCLUDED
