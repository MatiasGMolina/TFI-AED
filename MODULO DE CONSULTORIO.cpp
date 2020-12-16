#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

void menu();
bool buscar_vet();
void lista_espera();
void evolucion();

struct veterinario
{	char apell_nom[60];
	int matricula, dni;
	char telefono[10];
	char contrasenia[32];
};
struct Fecha
{
    int dia;
    int mes;
    int year; 
};
struct Mascota
{
	char apell_nomb[60];
	char Domicilio[60];
	int DNI_Duenio;
	char Locaidad[60];
    Fecha fecha_nacimiento;
	float Peso;	
	char Telefono[25];	
};
struct Turnos
{
	int Matricula_de_Veterinario;
	Fecha fecha_cargada;
	int DNI_Duenio;
	char Detalle_de_Atencion[380];
	
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
						evolucion();
					
					system("\n\npause");
					break;
				case 4:
					printf("\nGRACIAS POR UTILIZAR NUESTROS SERVICIOS\n\n");
					
					break;

				default:
					printf("\nNo corresponde a ninguna opción del MENU\n\n");system("\n\npause");
					break;
			}
	}while(opcion!=4);

	printf("\n\n");
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
	Fecha hoy;
	Turnos reg;
	FILE*arch;
	printf("\nINFORME DE TURNOS DIARIOS\n");
	printf("INGRESE EL DIA DEL TURNO:");
	scanf("%d", &hoy.dia);
	printf("\nINGRESE EL MES DEL TURNO:");
	scanf("%d", &hoy.mes);
	printf("\nINGRESE EL AÑO:");
	scanf("%d", &hoy.year);
	arch=fopen("Turnos.dat", "rb");
	fread(&reg, sizeof(reg),1, arch);
	while(!feof(arch))
	{	if(reg.fecha_cargada.dia==hoy.dia && reg.fecha_cargada.mes==hoy.mes &&reg.fecha_cargada.year==hoy.year)
		{
				printf("\nMATRICULA VETERINARIO:%d", reg.Matricula_de_Veterinario);
				printf("\nFECHA DE ATENCION:%d/%d/%d", hoy.dia, hoy.mes, hoy.year);
				printf("\nDNI DEL DUENIO:%d", reg.DNI_Duenio); 
				printf("\nDETELLE ATENCION:%s\n", reg.Detalle_de_Atencion);
		}
		fread(&reg, sizeof(reg),1, arch);
	}
	fclose(arch);
}
void evolucion()
{	Fecha hoy;
	Turnos reg;
	FILE*arch;
	long posi;
	bool h=false;
	int dni;
	printf("\nINFORME DE TURNOS DIARIOS\n");
	printf("INGRESE EL DIA DEL TURNO:");
	scanf("%d", &hoy.dia);
	printf("\nINGRESE EL MES DEL TURNO:");
	scanf("%d", &hoy.mes);
	printf("\nINGRESE EL AÑO:");
	scanf("%d", &hoy.year);
	printf("\nINGRESE EL DNI DEL DUEÑO:");
	scanf("%d", &dni); 
	arch=fopen("Turnos.dat", "r+b");
	fread(&reg, sizeof(reg),1, arch);
	while(!feof(arch)&&h==false)
	{	if(reg.fecha_cargada.dia==hoy.dia && reg.fecha_cargada.mes==hoy.mes &&reg.fecha_cargada.year==hoy.year && reg.DNI_Duenio)
		{
				h=true;
				printf("\nDATOS DEL TURNO:");
				printf("\nMATRICULA VETERINARIO:%d", reg.Matricula_de_Veterinario);
				printf("\nFECHA DE ATENCION:%d/%d/%d", hoy.dia, hoy.mes, hoy.year);
				printf("\nDNI DEL DUENIO:%d", reg.DNI_Duenio); 
				printf("\nDETELLE ATENCION:%s\n", reg.Detalle_de_Atencion);
				posi=ftell(arch)-sizeof(reg);
		} else 
		fread(&reg, sizeof(reg),1, arch);
	}
	if(h==false)
	{	printf("\nMASCOTA NO HALLADA");
	} else 
	{	char texto[100];
		printf("\nINGRESE LA EVOLUCION:");
		fflush(stdin);
		gets(texto);
		strcat(reg.Detalle_de_Atencion, "\n");
		strcat(reg.Detalle_de_Atencion, texto);
		fseek(arch, posi, SEEK_SET);
		fwrite(&reg, sizeof(reg), 1, arch);
		printf("\nEVOLUCION REGISTRADA SATISFACTORIAMENTE");
	}
	fclose(arch);
}
