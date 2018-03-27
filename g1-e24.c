#include <stdio.h>
#include <stdlib.h>

#define MAX_DIAS 366
#define MIN_DIAS 1
#define SEMANA_DIAS 7
#define DOMINGO "Domingo"
#define LUNES "LUNES"
#define MARTES "Martes"
#define MIERCOLES "Miercoles"
#define JUEVES "Jueves"
#define VIERNES "Viernes"
#define SABADO "Sabado"

#define INGRESO_MSG "Ingrese el dia del año para calcular el dia de la semana correspondiente(El programa tiene en cuenta que el año empezo un dia domingo):	"
#define DIA_SEMANA_MSG "El dia de la semana es:	"
#define ERR_MSG "(1) Error: el valor ingresado es incorrecto"

int main(void){
	
	int dia=0;

	printf("%s", INGRESO_MSG);
	scanf("%d", &dia);

	if(dia<MIN_DIAS || dia>MAX_DIAS){
		puts(ERR_MSG);
		return EXIT_FAILURE;
	}

	switch(dia%SEMANA_DIAS){
		
		case 1:	
			printf("%s%s\n",DIA_SEMANA_MSG, DOMINGO);
			break;

		case 2:	
			printf("%s%s\n",DIA_SEMANA_MSG, LUNES);
			break;

		case 3:	
			printf("%s%s\n",DIA_SEMANA_MSG, MARTES);
			break;

		case 4:	
			printf("%s%s\n",DIA_SEMANA_MSG, MIERCOLES);
			break;

		case 5:	
			printf("%s%s\n",DIA_SEMANA_MSG, JUEVES);
			break;

		case 6:	
			printf("%s%s\n",DIA_SEMANA_MSG, VIERNES);
			break;

		case 0:	
			printf("%s%s\n",DIA_SEMANA_MSG, SABADO);
			break;

}

	return EXIT_SUCCESS;
}

	

	