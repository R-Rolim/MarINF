#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#define TILE_LARGURA 10
#define TILE_ALTURA 25
#define COLUNAS_MAPA 120
#define LINHAS_MAPA 29

void Desenha_mapa(char mapa1[][COLUNAS_MAPA+1]);
Vector2 PosicaoInicPlayer(char mapa1[][COLUNAS_MAPA+1]);
char GetTile(int x, int y, char mapa1[][COLUNAS_MAPA+1]);

#endif // MAPA_H_INCLUDED
