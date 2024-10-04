#include <gtest/gtest.h>
#include "ex001.h"  // Arquivo com as classes Objeto, Quadrado, Circulo e função colidir
#include <cmath> // Para usar sqrt

// Teste para verificar a detecção de colisão entre o círculo e o quadrado
TEST(ColisaoTest, ColisaoQuadradoCirculo) {
    // Cenário de colisão esperado
    Quadrado quadrado({1.0f, 2.0f}, {0.0f, 0.0f}, 0.0f);  // O quadrado está parado
    Circulo circulo({1.0f, 2.0f}, {0.0f, 0.0f}, 0.0f);    // O círculo está exatamente na mesma posição que o quadrado

    // Como estão na mesma posição, deve haver colisão
    EXPECT_TRUE(colidir(quadrado, circulo));
}

// Teste para verificar a ausência de colisão quando os objetos estão distantes
TEST(ColisaoTest, SemColisao) {
    Quadrado quadrado({10.0f, 10.0f}, {0.0f, 0.0f}, 0.0f);  // Quadrado longe
    Circulo circulo({0.0f, 0.0f}, {0.0f, 0.0f}, 0.0f);      // Círculo longe do quadrado

    // Como os objetos estão distantes, não deve haver colisão
    EXPECT_FALSE(colidir(quadrado, circulo));
}

// Teste para verificar a atualização da posição do objeto
TEST(MovimentoTest, AtualizarPosicao) {
    Quadrado quadrado({1.0f, 1.0f}, {1.0f, 0.0f}, 2.0f); // O quadrado deve se mover 2 unidades no eixo X por iteração
    quadrado.posicao_tempo();
    
    // A nova posição deve ser (3, 1)
    EXPECT_FLOAT_EQ(quadrado.getPX(), 3.0f);
    EXPECT_FLOAT_EQ(quadrado.getPY(), 1.0f);
}

// Teste para verificar se a função colidir detecta colisão após movimento
TEST(ColisaoTest, ColisaoAposMovimento) {
    Quadrado quadrado({0.0f, 0.0f}, {1.0f, 0.0f}, 1.0f);  // Quadrado se move para a direita
    Circulo circulo({10.0f, 0.0f}, {-1.0f, 0.0f}, 1.0f);   // Círculo se move para a esquerda

    for (int i = 0; i < 5; ++i) {
        quadrado.posicao_tempo();
        circulo.posicao_tempo();
    }

    // Após 5 iterações, o quadrado e o círculo devem colidir
    EXPECT_TRUE(colidir(quadrado, circulo));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}