#include "raylib.h"
#include "Desenho.h"
#include "Structs.h"
//funções de desenhos diversas incluindo HUD e "debug"

//Mostra na tela se os controles de movimento estão funcionando
void MovimentoFunciona(bool *MovePlayer){
        if (*MovePlayer){
        DrawText("MOVENDO", 10, 10, 30, GREEN);
    } else {
        DrawText("PARADO", 10, 10, 30, RED);}

}
//Mostra o FPS dentro do jogo
void FPSAtual(void){

    DrawText(TextFormat("FPS: %d", GetFPS()), 180, 10, 30, BLACK);

}
//Posição atual do personagem
void PosicaoAtual(float PosX, float PosY){

    DrawText(TextFormat("X: %.0f Y: %.0f", PosX, PosY), 320, 10, 30, BLACK);

}

void VelocidadeAtual(float VelX, float VelY){

    DrawText(TextFormat("X: %.1f Y: %.1f", VelX, VelY), 650, 10, 30, BLACK);

}

void Setas(bool InputTeclado){

    if (InputTeclado){
    DrawText("INPUT",850, 10, 30,GREEN);
    } else {
        DrawText("INPUT",850, 10, 30,RED);}
}
