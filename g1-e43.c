

	/*Javier Roberto Torrico-Padron:96840*/
/*gcc -ansi -pedantic -Wall 43.c -0 43.o*/
#include <stdio.h>
#include <stdlib.h>

#define INGRESO_KMS "Ingrese los kilometros recorridos(-1 para terminar):	"
#define INGRESO_PRECIO_LTS "Ingrese el precio del combustible por litro:	"
#define INGRESO_MONTO_TOTAL "Ingrese el monto total utilizado en esta compra:	"
#define RTO_MSG "Rendimiento (l/100km) de este tanque >>			"
#define RTO_PROM_MSG "Rendimiento promedio (l/100km) >>		"
#define MEJOR_RTO_MSG "Mejor rendimiento (l/100km) >>		"
#define PEOR_RTO_MSG "Peor rendimiento (l/100km) >>		"
#define DIST_TOTAL_MSG "Distancia total recorrida (km) >>	"
#define CTBLE_TOTAL_MSG "Combustible total consumidos (l) >>	"
#define COSTO_TOTAL_MSG "Costo total de su vehiculo ($) >>	" 
#define CTE_RTO 100 /*Factor de escala para calcular el rendimiento*/ 
#define ERR_MSG "ERROR: (1)El valor ingresado es incorrecto"
int main(void){
	
	float error=-2;/*Defino la constante dentro del main, debido a que si lo hago fuera esta se crea como entero*/
	float rto, precio_lts=0, mto_total=0, kms_rdos=0, salir=-1;
	float rto_total=0;
	float mejor_rto=1000, peor_rto=0;/*Uso casos extremos para comparar*/
	float dist_total=0, ctble_total=0, costo_total=0;
	int i=0;
	while(kms_rdos != salir){
		kms_rdos=error;
		printf("%s",INGRESO_KMS);
		scanf("%f", &kms_rdos);
		if(kms_rdos==salir){
			break;
		}
	
		if(kms_rdos==error){
			puts(ERR_MSG);
			return EXIT_FAILURE;					
		}
		if(kms_rdos<0){
			puts(ERR_MSG);
			return EXIT_FAILURE;					
		}

		precio_lts=error;
		printf("%s",INGRESO_PRECIO_LTS);
		scanf("%f", &precio_lts);
		if(precio_lts==error){
			puts(ERR_MSG);
			return EXIT_FAILURE;					
		}
		if(precio_lts<0){
			puts(ERR_MSG);
			return EXIT_FAILURE;					
		}

		mto_total=error;
		printf("%s",INGRESO_MONTO_TOTAL);
		scanf("%f", &mto_total);
		if(mto_total==error){
			puts(ERR_MSG);
			return EXIT_FAILURE;					
		}
		if(mto_total<0){
			puts(ERR_MSG);
			return EXIT_FAILURE;					
		}

		rto= (mto_total/precio_lts)/(kms_rdos/CTE_RTO);
		printf("%s%.02f\n",RTO_MSG, rto);

		rto_total=rto_total+rto;

		if(mejor_rto>rto)mejor_rto=rto;

		if(peor_rto<rto)peor_rto=rto;
		
		dist_total=dist_total+kms_rdos;

		ctble_total=ctble_total + (mto_total/precio_lts);

		costo_total=costo_total +mto_total;		
		
		
		
		i++;		
		
	
	}

	printf("%s%.04f\n",RTO_PROM_MSG, rto_total/i);
	printf("%s%.02f\n",MEJOR_RTO_MSG, mejor_rto);
	printf("%s%.02f\n",PEOR_RTO_MSG, peor_rto);
	printf("%s%.00f\n",DIST_TOTAL_MSG, dist_total);
	printf("%s%.02f\n",CTBLE_TOTAL_MSG, ctble_total);
	printf("%s%.02f\n",COSTO_TOTAL_MSG, costo_total);
		 
		
	return EXIT_SUCCESS;
}