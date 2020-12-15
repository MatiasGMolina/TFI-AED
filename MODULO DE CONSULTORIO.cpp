#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

void menu();
bool buscar_vet();
void lista_espera();

struct veterinario
{	char apell_nom[60];
	int matricula, dni;
	char telefono[10];
	char contrasenia[10];
};
veterinario reg;
main()
{
	setlocale(LC_ALL, ""); // caracteres en español
	int opcion;
	bool i=false;
	do
	{
		menu();
		printf("\t\t         Seleccione una Opción: ");
		scanf("%d", &opcion);
		
		
		
			switch(opcion)
			{
			
				case 1:
					
					i=buscar_vet();
					system("\n\npause");
					break;
				case 2: 
					
					if(i==true)
					{
						lista_espera();
					}
					else 
					{
						printf("\nERROR. Primero debe iniciar sesión.\n\n");
					}
					system("\n\npause");
					break;
				case 3: 
					
					
					system("\n\npause");
					break;
				case 4:

					
					break;
				case 5:
					printf("\nGRACIAS POR UTILIZAR NUESTROS SERVICIOS\n\n");
					
					break;

				default:
					printf("\nNo corresponde a ninguna opción del MENU\n\n");system("\n\npause");
					break;
			}
	}while(opcion!=5);

	printf("\n\n");
	system("pause");
}
void menu()
{
		system("cls");
		printf("\n\n\n");
		printf("\t\t**                     Modulo de Consultorio Veterinario                **\n");
		printf("\t\t******************************************************************\n");
		printf("\t\t                                                                  \n");
		printf("\t\t         1- Iniciar Sesión.					 			          \n");
		printf("\t\t                                                                  \n");
		printf("\t\t         2- Visualizar Lista de Espera de Turnos.	              \n");
		printf("\t\t                                                                  \n");                 
		printf("\t\t         3- Registros Evolución de la mascota.                    \n");
		printf("\t\t                                                                  \n");
		printf("\t\t         4- Cerrar la Aplicación.                  	              \n");
		printf("\t\t                                                                  \n");
		printf("\t\t******************************************************************\n\n");
}


//Inicio de sesion
bool buscar_vet()
{	
	system("cls");
	FILE*arch;
	char contrasenia[10];
	int matricula;
	
	arch=fopen("veterinario.dat", "rb");
	
	if(arch==NULL)
	{
		printf("\nERROR. NO SE REGISTRO NINGUN VETERINARIO.");
	}
	else
	{
		printf("\nIngrese la matricula: ");
		scanf("%d", &matricula);
		printf("\nIngrese la contraseña: ");
		_flushall();
		gets(contrasenia);
		
		fread(&reg, sizeof(reg), 1, arch);
		
		while(!feof(arch))
		{	
			if(matricula==reg.matricula)
			{	
				if(strcmp(reg.contrasenia, contrasenia)==0)
				{
					printf("\nInició sesión correctamente.");
					printf("\n BIENVENIDO: ");
					puts(reg.apell_nom);
					fclose(arch);
					return true;
				}
				else
				{
					printf("\nERROR. Contraseña incorrecta.");
				}	
			}
			else
			{
				printf("\nERROR. Usuario incorrecto.");
			}
			fread(&reg, sizeof(reg), 1, arch);
		}
	}
	fclose(arch);
	return false;
}


//lista de espera de turnos(informe)
void lista_espera()
{
	printf("\nhoalllllllllllllllllll.");
}

