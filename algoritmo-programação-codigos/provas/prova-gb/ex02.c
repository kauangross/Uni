#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funcoes.c"

int main(){
    int id = 0;
    char name[30];
    SensorData sensorData[20];
    SensorData newSensor;
    int a;
    float v;
    int ans = -1;

    while(ans != 0){
        a = -1;
        ans = menu();

        switch (ans)
        {
        case 1:
            printf("Digite um nome para identificar o sensor:\n");
            fgets(name, sizeof(name), stdin);
            printf("\n");
            createSensorData(&newSensor, &id, name);
            sensorData[newSensor.id - 1] = newSensor;
            break;
        case 2:
            listSensorData(sensorData, id);
            break;
        case 3:
            while(a < 1 || a > id){
                printf("Digite o ID do Sensor desejado:\n\n");
                listSensorData(sensorData, id);
                scanf("%d", &a);
            }
            printf("Digite o valor que deseja adicionar:\n");
            scanf("%f", &v);
            printf("\n");
            addReading(&sensorData[a-1], v);
            break;
        case 4:
            while(a < 1 || a > id){
                printf("Digite o ID do Sensor desejado:\n\n");
                listSensorData(sensorData, id);
                scanf("%d", &a);
            }
            freeSensorData(&sensorData[a - 1]);
            break;
        case 0:
            printf("Finalizando programa...\n\n");
            break;
        }
    }

    return 0;
}
