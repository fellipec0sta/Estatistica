#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int *v;
    int *v1;

    int temp;
    int somx = 0, somx2 = 0, somy = 0, somxy = 0 , somxpy = 0;

    int n = 0;

        printf("insira quantos valores voce deseja em x: ");
        scanf("%d", &n);
        v1 = (int *) malloc(sizeof(int)*n);

        for(int i = 0; i<n; i++){
            scanf("%d", &v[i]);
        }

        printf("insira quantos valores voce deseja em y: ");
        scanf("%d", &n);
        v2 = (int *) malloc(sizeof(int)*n);

        for(int i = 0; i<n; i++){
            scanf("%d", &v1[i]);
        }

        for(int i = 0; i<n; i++){ //vetor ?
            somx += v[i];
            somy += v1[i];
            somxpy = somx + somy;
            somxy = somx * somy;
        }

        for (int i = 0; i < n; ++i)
        {
            temp = v[i];
            somx2 =  somx2 + temp*v[i];
        }

        int M1[2][2] = {n, somx, somx, somx2};
        int M2[2][1] = {somy, somxy};

        // inversa
        //inversa * M2
        // a = y - b*x



    return 0;
}