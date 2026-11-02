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

}JOGADOR;

#endif // STRUCTS_H_INCLUDED
