#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mediana(int *vetor, int n ){
     int b =( (1+n)/2) -1;
     int c = vetor[b];
     if(n%2==0){
       c =  (vetor[b] + vetor[b+1] )/ 2;
     }
    return c;
}

float media(int *vetor, int n){
    float a=0;
    for(int i = 0; i<n;i++){
        a += vetor[i];
    }
    return a/n;
}

float variancia(int *vetor, int n){
    float a=0;
    float b = 0;
	b = media(vetor, n);
        for(int i = 0;i<n;i++){
            a = a + pow(vetor[i] - b, 2);
        }
    return a/(n -1);
}

float desviop(int *vetor, int n){
    return sqrt(variancia(vetor, n));
}

float errop(int *vetor, int n){
    float a = desviop(vetor, n);
    return a/sqrt(n);
}

float cv(int *vetor, int n){
	return (desviop(vetor, n)/ media(vetor, n)) *100;
}

float iv(int *vetor, int n){
	return (errop(vetor, n)/media(vetor, n)) *100;
}

int quartil1(int *vetor, int n){
	int a = n*0.25;
	int b= 0;
	for(int i =0 ; i<= a; i++){
		b = vetor[a];
	}
	return b;
}

int quartil3(int *vetor, int n){
	int a = n*0.75;
	int b= 0;
	for(int i =0 ; i<= a; i++){
		b = vetor[a];
	}
	return b;
}


int min(int *vetor, int n){
	int a = vetor[0];

	return a;
}

int max(int *vetor, int n){
	int a = vetor[n-1];

	return a;
}

void resumo(int *vetor, int n){
        printf("Mediana = %d \n", mediana(vetor,n) );
        printf("Primeiro Quartil = %.2f \n", quartil1(vetor, n));
        printf("Terceiro Quartil = %.2f \n", quartil3(vetor, n));
        printf("Valor minimo = %d \n", min(vetor, n));
        printf("Valor maximo = %d \n", max(vetor, n));
}


int main(){
    int *v;
    int n = 0;
    int opc =1;

while(opc != 2){
		printf("\n-----------------------------------------------\n");
        printf("insira quantos valores voce deseja no vetor: ");
        scanf("%d", &n);
        v = (int *) malloc(sizeof(int)*n);

        printf("insira os valores no vetor: ");

        for(int i = 0; i<n; i++){
            scanf("%d", &v[i]);
		}

        for(int i = 0; i < n; i++){
            for(int j = i+1; j<n; j++){
                if(v[j] < v[i]){
                    int tmp = v[i];
                    v[i] = v[j];
                    v[j] = tmp;
            }
        }
    }

    	printf("vetor ordenado: \n");
    	for(int i = 0; i<n; i++){
            printf("%d ", v[i]);
        }
        printf("\n-----------------------------------------------\n");

        printf("Media: %.2f \n", media(v, n));
        printf("Variancia: %f \n", variancia(v, n));
        printf("Desvio padrao: %f \n", desviop(v, n));
        printf("Erro padrao: %f \n", errop(v, n));
        printf("Coeficiente de Variacao em porcentagem: %f \n", cv(v, n));
        printf("Indice de Variacao em porcentagem: %f \n", iv(v, n));
        printf("\n-----------------------------------------------\n");

        printf("Resumo: \n");
        resumo(v, n);

	printf("\n-----------------------------------------------\n");
    printf("deseja calcular novamente? 1- sim / 2 - nao \n");
    scanf("%d", &opc);

}

    return 0;
}
