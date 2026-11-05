#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "logicaMov.h"
#include "Structs.h"
#include "mapa.h"

#define TILE_LARGURA 10
#define TILE_ALTURA 25
#define COLUNAS_MAPA 120
#define LINHAS_MAPA 29
//Entradas ou inputs de direção para o personagem (com as setinhas)

//Travas na velocidade para poder implementar pulo e gravidade
void LimiteVel(float *VelX, float *VelY){

    if(*VelX > 10){
        *VelX = 10.0;
    }
    if(*VelX < -10){
        *VelX = -10.0;
    }
    if(*VelY > 50){
        *VelY = 50.0;
    }
    if(*VelY < -50){
        *VelY = -50.0;
    }
}

void Direcional(Vector2 *XY,float *VelX, float *VelY, bool *movendo, bool *InputTeclado){

    *InputTeclado = false;
    *movendo = false;
    //*VelX = 0;
    //*VelY = 0;

    if (IsKeyDown(KEY_LEFT)){
       *VelX += -6 * GetFrameTime();
        *InputTeclado = true;
    }
    if (IsKeyDown(KEY_RIGHT)){
        *VelX += 6 * GetFrameTime();
        *InputTeclado = true;
    }
    if (IsKeyDown(KEY_UP)){
       *VelY += -60 * GetFrameTime();
        *InputTeclado = true;
    }
    if (IsKeyDown(KEY_DOWN)){
       *VelY += 6 * GetFrameTime();
        *InputTeclado = true;
    }

    LimiteVel(VelX, VelY);

    XY->x += *VelX;
    XY->y += *VelY;

    if (*VelX != 0){
        *movendo = true;
        if(VelX > 0 && !*InputTeclado){
            *VelX -= *VelX/50;
        } else if(VelX < 0 && !*InputTeclado){
            *VelX += *VelX/50;
            }
    }

}

//Teste de colisão do personagem com o mapa
void Colisao(float *VelX, float *VelY, Vector2 Tamanho,Vector2 *posicaoatual,char mapa1[][COLUNAS_MAPA+1]){

    Vector2 pos = *posicaoatual;

    float FuturaPosX = pos.x + (*VelX * GetFrameTime());
    float FuturaPosY = pos.y + (*VelY * GetFrameTime());
//Colisão Laterais Esquerda e Direita
    if (*VelX < 0){
//Mudar os valores faz com que a colisão não faça o personagem agarrar no chão quando cai     \/  Na duvida mudar para 1 e o ver o que acontece ao pular enquanto se movimenta
       if(GetTile(FuturaPosX, pos.y, mapa1) == 'p' || GetTile(FuturaPosX, pos.y + Tamanho.y - 7, mapa1) == 'p'){
            int TileX = (int)(FuturaPosX / TILE_LARGURA);
            FuturaPosX = (TileX + 1) * TILE_LARGURA;
            *VelX = 0;
       }
    } else {                                                                                                      //  \/
        if(GetTile(FuturaPosX + Tamanho.x, pos.y, mapa1) == 'p' || GetTile(FuturaPosX + Tamanho.x, pos.y + Tamanho.y - 7, mapa1) == 'p'){
            int TileX = (int) ((FuturaPosX + Tamanho.x)/ TILE_LARGURA);
            FuturaPosX = (TileX * TILE_LARGURA) - Tamanho.x;
            *VelX = 0;
        }
    }
//Colisão Verticais Cima e Baixo
        if (*VelY <= 0){

       if(GetTile(FuturaPosX, FuturaPosY, mapa1) == 'p' || GetTile(FuturaPosX + Tamanho.x - 1, FuturaPosY, mapa1)  == 'p'){
            int TileY = (int) (FuturaPosY / TILE_ALTURA);
            FuturaPosY = (TileY + 1) * TILE_ALTURA;
            *VelY = 0;
       }
    } else {
        if(GetTile(FuturaPosX, FuturaPosY + Tamanho.y, mapa1) == 'p' || GetTile(FuturaPosX + Tamanho.x - 1, FuturaPosY + Tamanho.y, mapa1) == 'p'){
            int TileY = (int) ((FuturaPosY + Tamanho.y) / TILE_ALTURA);
            FuturaPosY = (TileY * TILE_ALTURA) - Tamanho.y;
            *VelY = 0;
        }

    }

    posicaoatual->x = FuturaPosX;
    posicaoatual->y = FuturaPosY;
}

