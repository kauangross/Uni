#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float* readings; // Array dinâmico para armazenar leituras de temperatura.
    int size; // Número de leituras atualmente no array.
    int capacity; // Capacidade total do array, indicando quantas leituras podem ser armazenadas antes da necessidade de expansão.
    int ID_Sensor; // Tipo de sensores, seria o ID do sensor
} Sensor;

void CreateSensorData(Sensor SensorData[], int ultimo_sensor, int quant_de_sensores){
    for (int i = 0; i < quant_de_sensores; i++) 
    {
        SensorData[i].capacity = 20; // Capacidade inicial
        SensorData[i].ID_Sensor = i; 
    }
    ultimo_sensor++; // Adiciona mais um sensor
}

void addReadings(Sensor SensorData[], int *ultimo_sensor, int quant_de_sensores, int sensor_i){
    int sensor;
    printf("Qual sensor deseja adicionar leituras? ");    
    scanf("%d", &sensor);
    printf("\n%d\n", sensor);
    printf("\n%d\n", SensorData[0].ID_Sensor);
    for (int i = 0; i < quant_de_sensores; i++)
    {
        if (SensorData[i].ID_Sensor == (sensor-1))
        {
            printf("Digite a leitura: ");
            scanf("%f", &SensorData[i].readings[*ultimo_sensor]);
            SensorData[i].size++;
            *ultimo_sensor++;
            sensor_i++;
            continue;
        }
        printf("Sensor valor %f\n", SensorData[0].readings[0]);
        printf("Sensor valor %f\n", SensorData[0].readings[1]);
    }
}

int main()
{
    int quant_de_sensores = 10;
    int ultimo_sensor = 0;
    int op;
    int sensor_i = 0;
    Sensor *SensorData; // Cria o SensorData
    SensorData = malloc(sizeof(Sensor)*quant_de_sensores); // Posso criar 10 sensores 
    
    for (int i = 0; i < quant_de_sensores; i++) // zera a quantidade de leituras
    {
        SensorData[i].readings = malloc(sizeof(float)*10);
        SensorData[i].size = 0; // Não recebeu nenhuma leitura
    }
    do
    {
        printf("[0] Finalizar\n");
        printf("[1] Criar novo sensor\n");
        printf("[2] Adicionar leitura\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            CreateSensorData(SensorData, ultimo_sensor, quant_de_sensores); // Inicializa a capacidade inicial dos 10 sensores iniciais = 20
            break;
        case 2:
            addReadings(SensorData, &ultimo_sensor, quant_de_sensores, sensor_i); // Adiciona novas leituras ao sensor que o usuario quiser
            for (int i = 0; i < ultimo_sensor; i++)
            {
                for (int j = 0; j < SensorData[i].size; j++)
                {
                    printf("Sensor valor %f\n", SensorData[i].readings[j]);
                }
            }
            break;
        default:
            break;
        }
    } while (op != 0);
    
    return 0;
}
