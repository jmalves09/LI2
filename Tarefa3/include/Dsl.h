/* include/dsl.h */

#ifndef DSL_H
#define DSL_H

void adicionaJogo(const char *nome);
void adicionaBaralhos(int n);

void adicionaTipo(const char *tipo, const char *flags);

void adicionaInit(const char *tipo, int n);

void adicionaMovimento(const char *origem,
                       const char *destino,
                       const char *flags);

void adicionaAuto(const char *origem,
                  const char *destino,
                  const char *flags);

void adicionaWin(const char *tipo, int n);

#endif