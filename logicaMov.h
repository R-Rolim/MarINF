#ifndef LOGICAMOV_H_INCLUDED
#define LOGICAMOV_H_INCLUDED

#define TILE_LARGURA 10
#define TILE_ALTURA 25
#define COLUNAS_MAPA 120
#define LINHAS_MAPA 29

void Direcional(Vector2 *XY, float *VelX, float *VelY, bool *movendo);
void Colisao(float *VelX, float *VelY, Vector2 Tamanho,Vector2 *posicaoatual,char mapa1[][COLUNAS_MAPA+1]);

#endif // LOGICAMOV_H_INCLUDED
