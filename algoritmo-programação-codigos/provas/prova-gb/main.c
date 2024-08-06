#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Sensores
typedef struct {
    int cod;
    char nome[30];
    int capacity;
    int size;
    float *readings;
} SensorData;

void createSensorData(SensorData *S, int *cod, char name[]){
    S->capacity = 20;
    S->size = 0;
    S->readings = malloc(sizeof(float) * S->capacity);
    strcpy(S->nome, name);
    S->nome[strcspn(S->nome, "\n")] = '\0';
    (*cod)++;
    S->cod = *cod;
}

void addReading(SensorData *S, float valor){
    if(S->size == S->capacity){
        S->capacity = S->capacity * 1.5;
        S->readings = (float *)realloc(S->readings, S->capacity * sizeof(float));
    }
    S->readings[S->size] = valor;
    S->size++;

    printf("Valor adicionado com sucesso!\n\n");
}

void freeSensorData(SensorData *S){
    free(S->readings);
}

int menu(){
    int resp;
    while(resp < 0 || resp > 4){
        printf("MENU\n\n");
        printf("[1] Criar um novo sensor\n");
        printf("[2] Mostrar os sensores\n");
        printf("[3] Adicionar leitura\n");
        printf("[4] Liberar espaco de um sensor\n");
        printf("[5] Fechar o programa\n");
        scanf("%d", &resp);
        while (getchar() != '\n');
        printf("\n\n");
    }
    return resp;
}

void mostrarSensorData(SensorData Sensor[], int size){
    if(size != 0){
        for(int i = 0; i < size; i++){
            printf("ID: %d; Nome: %s; Capacidade: %d\n", Sensor[i].cod, Sensor[i].nome, Sensor[i].capacity);
            printf("Valores: \n");
            for(int j = 0; j < Sensor[i].size; j++){
                printf("%.2f\n", Sensor[i].readings[j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Nenhum sensor registrado.\n");
    }
    printf("\n");
}

int main(){
    int cod = 0;
    char nome[30];
    SensorData sensorData[20];
    SensorData novo_Sensor;
    int a;
    float v;
    int resp = -1;

    while(resp != 0){
        a = -1;
        resp = menu();

        switch (resp)
        {
        case 1:
            printf("Digite o tipo do sensor:\n");
            fgets(nome, sizeof(nome), stdin);
            printf("\n");
            createSensorData(&novo_Sensor, &cod, nome);
            sensorData[novo_Sensor.cod - 1] = novo_Sensor;
            break;
        case 2:
            mostrarSensorData(sensorData, cod);
            break;
        case 3:
            while(a < 1 || a > cod){
                printf("Digite o ID do Sensor desejado:\n\n");
                mostrarSensorData(sensorData, cod);
                scanf("%d", &a);
            }
            printf("Digite o valor que deseja adicionar:\n");
            scanf("%f", &v);
            printf("\n");
            addReading(&sensorData[a-1], v);
            break;
        case 4:
            while(a < 1 || a > cod){
                printf("Digite o ID do Sensor desejado:\n\n");
                mostrarSensorData(sensorData, cod);
                scanf("%d", &a);
            }
            freeSensorData(&sensorData[a - 1]);
            break;
        case 0:
            printf("Finalizando...\n\n");
            break;
        }
    }

return 0;
}