#include "Structs.h"
#include "raylib.h"

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
