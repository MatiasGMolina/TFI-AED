#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
void menu();
void reg_mascota();
void reg_turnos();
bool buscar_usuario();

FILE *registrodemascota;
FILE *registrodeturnos;

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
struct usuarios
{
	char usuario[10];
	char contrasenia[10];
	char apell_nomb[60];	
};





main()
{
	int opcion;
	setlocale(LC_ALL, ""); // caracteres en español
	do
	{
		menu();
		printf("\t\t         Seleccione una Opcion: ");
		scanf("%d", &opcion);
		
		
		
			switch(opcion)
			{
			
				case 1:
					buscar_usuario();
					system("\n\npause");
					break;
				case 2: 
					reg_mascota();
					system("\n\npause");
					
					
					break;
				case 3: 
					reg_turnos();
					system("\n\npause");
					
					
					break;
				case 4:

					
					break;
				case 5:
					printf("\nGRACIAS POR UTILIZAR NUESTROS SERVICIOS\n\n");
					
					break;

				default:
					printf("\nNo corresponde a ninguna opcion del MENU\n\n");system("\n\npause");
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
		printf("\t\t**                     Modulo del Asistente                     **\n");
		printf("\t\t************************\n");
		printf("\t\t                                                                  \n");
		printf("\t\t         1- Iniciar Sesion.					 		        	  \n");
		printf("\t\t                                                                  \n");
		printf("\t\t         2- Registrar Mascota.	                                  \n");
		printf("\t\t                                                                  \n");                 
		printf("\t\t         3- Registrar Turno.                                      \n");
		printf("\t\t                                                                  \n");
		printf("\t\t         4- Listado de Atenciones por Veterinario y Fecha.        \n");
		printf("\t\t                                                                  \n");
		printf("\t\t         5- Cerrar la Aplicacion.                  	              \n");
		printf("\t\t                                                                  \n");
		printf("\t\t***********************\n\n");
}

bool buscar_usuario()
{	
	system("cls");
	FILE*arch;
	char usuario[10],contrasenia[10];
	usuarios reg;
	
	
	arch=fopen("usuario.dat", "rb");
	if(arch==NULL)
	{
		printf("\nERROR. NO SE REGISTRO NINGUN VETERINARIO.");
	}
	else
	{
		printf("\nIngrese el usuario: ");
		_flushall();
		gets(usuario);
		printf("\nIngrese la contraseñia: ");
		_flushall();
		gets(contrasenia);
		
		fread(&reg, sizeof(reg), 1, arch);
		
		while(!feof(arch))
		{	
			if(strcmp(reg.usuario, usuario)==0)
			{	
				if(strcmp(reg.contrasenia, contrasenia)==0)
				{
					printf("\nInició sesión correctamente.");
					printf("\n BIENVENIDO: ");
					puts(reg.apell_nomb);
				}
				fclose(arch);
				return true;
			}
			fread(&reg, sizeof(reg), 1, arch);
		}
	}
	
	fclose(arch);
	return false;
}

//OPCION NUMERO 2 REGISTRAR MASCOTA 
void reg_mascota()
{
	Mascota reg;
	int DNI_Duenio;
	float Peso;	

	system("cls");
	printf("\nRegistrar Mascota.\n");

	printf("\nIngrese el apellido y nombre a registrar: ");
	_flushall();
	gets(reg.apell_nomb);
	
	printf("\nIngrese Domicilio: ");
	_flushall();
	gets(reg.Domicilio);
	
	printf("\nIngrese el DNI de Dueño: ");
	_flushall();
	scanf("%d", &DNI_Duenio);

	
	printf("\nIngrese la Localidad: ");
	_flushall();
	gets(reg.Locaidad);
	
	
	printf("\nIngrese fecha de nacimiento: ");
        printf("\nDia: ");
        scanf("%d",&reg.fecha_nacimiento.dia);
        
        printf("\nMes: ");
        scanf("%d",&reg.fecha_nacimiento.mes);
        
        printf("\nAnio: ");
        scanf("%d",&reg.fecha_nacimiento.year);
	
	
	
	printf("\nIngrese el Peso: ");
	_flushall();  
	scanf("%f", &Peso);  


	printf("\nIngrese el Telefono: ");
	_flushall();
    gets(reg.Telefono);
    
    
    
    FILE*arch, *arch1;
	arch1=fopen("Mascota.dat", "ab");
	fwrite(&registrodemascota, sizeof(registrodemascota), 1, arch1);
	fclose(arch1);
    
    	
	
		
	
}


// OPCION NUMERO 3 REGISTRAR TURNOS
void reg_turnos()
{
	
	Turnos reg;
	int Matricula_de_Veterinario;
	int DNI_Duenio;

	system("cls");
	printf("\nRegistrar Turnos.\n");
	
	printf("\nIngrese la Matricula del veterinario: ");
	scanf("%d", &Matricula_de_Veterinario);	
	
	printf("\nIngrese el DNI de Dueño: ");
	scanf("%d", &DNI_Duenio);
	
	
	printf("\nFecha de turno:");
        printf("\nDia: ");

        scanf("%d",&reg.fecha_cargada.dia);
        
        printf("\nMes: ");
   
        scanf("%d",&reg.fecha_cargada.mes);
        
        printf("\nAnio: ");

        scanf("%d",&reg.fecha_cargada.year);
	

	FILE*arch, *arch1;
	arch1=fopen("Turnos.dat", "ab");
	fwrite(&registrodeturnos, sizeof(registrodeturnos), 1, arch1);
	fclose(arch1);
}
