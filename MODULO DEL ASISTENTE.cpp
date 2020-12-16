#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <conio.h>


void menu();
void reg_mascota();
void reg_turnos();
bool buscar_usuario();
void atenciones();

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
struct veterinario
{	char apell_nom[60];
	int matricula, dni;
	char telefono[10];
	char contrasenia[32];
};




main()
{
	int opcion;
	bool i=false;
	setlocale(LC_ALL, ""); // caracteres en español
	system("COLOR B0"); // Para darle color de fondo y de letras
	
	
	do
	{
		menu();
		printf("\t\t         Seleccione una Opcion: ");
		scanf("%d", &opcion);
		
		
		
			switch(opcion)
			{
			
				case 1:
					i=buscar_usuario();
					system("\n\npause");
					break;
				case 2: 
					
					if(i==true)
					{
						reg_mascota();
					}
					else 
					{
						printf("\nERROR. Primero debe iniciar sesión.\n\n");
					}
					system("\n\npause");
					
					break;
				case 3: 
					
					if(i==true)
					{
						reg_turnos();
					}
					else 
					{
						printf("\nERROR. Primero debe iniciar sesión.\n\n");
					}
					system("\n\npause");
					
					
					break;
				case 4:
					if(i==true)
					{
						atenciones();
					}
					else 
					{
						printf("\nERROR. Primero debe iniciar sesión.\n\n");
					}
					
					printf("\n\n");
					system("\n\npause");
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
		printf("\t\t******************************************************************\n");
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
		printf("\t\t******************************************************************\n\n");
}


// OPCION 1 INICIAR SESION
bool buscar_usuario()
{	
	system("cls");
	FILE*arch;
	char usuario[10],contrasenia[10];
	usuarios reg;
	
	
	arch=fopen("usuario.dat", "rb");
	if(arch==NULL)
	{
		printf("\nERROR. NO SE REGISTRO NINGUN VETERINARIO.\n\n");
	}
	else
	{
		printf("\nIngrese el usuario: ");
		_flushall();
		gets(usuario);
		printf("\nIngrese la contraseña: ");
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


	system("cls");
	printf("\nRegistrar Turnos.\n");
	
	printf("\nIngrese la Matricula del veterinario: ");
	scanf("%d", &reg.Matricula_de_Veterinario);	
	
	printf("\nIngrese el DNI de Dueño: ");
	scanf("%d", &reg.DNI_Duenio);
	
	
//	fecha de turno podes hacer con un while para que pongas que la el DIA sea entre 
//	1 y 31 desues que el MES sea entre 1 y 12 y el AÑO entre 2020 y 2025 creo
	
	
		printf("\nFecha de turno:");
		do
		{	
    	printf("\nDia: ");
        scanf("%d",&reg.fecha_cargada.dia);
        if(reg.fecha_cargada.dia<1 || reg.fecha_cargada.dia>31)
        {	printf("\nEL DIA DEL MES DEBE ESTAR ENTRE 1 Y 31. REINGRESAR DIA");
		} 
   		}while(reg.fecha_cargada.dia<1 || reg.fecha_cargada.dia>31);
        do
		{	
		printf("\nMes: ");
        scanf("%d",&reg.fecha_cargada.mes);
        if(reg.fecha_cargada.mes<1 || reg.fecha_cargada.mes>12)
        {	printf("\nEL MES DEBE ESTAR ENTRE 1 Y 12. REINGRESE EL MES");
		}
    	}while(reg.fecha_cargada.mes<1 || reg.fecha_cargada.mes>12);
        do
		{
		printf("\nAnio: ");
        scanf("%d",&reg.fecha_cargada.year);
		if(reg.fecha_cargada.year<2020 || reg.fecha_cargada.year>2025)
        {	printf("\nEL ANIO DEBE ESTAR ENTRE 2020 Y 2025. REINGRESE EL ANIO");
		}
    	}while(reg.fecha_cargada.year<2020 || reg.fecha_cargada.year>2025);

        
	printf("\nIngrese los detalles de la atención: ");
	_flushall();
	gets(reg.Detalle_de_Atencion);
	
	printf("\nTurno cargado con exito.");
	
	FILE*arch1;
	arch1=fopen("Turnos.dat", "ab");
	fwrite(&reg, sizeof(reg), 1, arch1);
	fclose(arch1);
}


// OPCION NUMERO 4 informe de atenciones
void atenciones()
{
	system("cls");
	int dia,mes,year;
	Turnos reg;
	veterinario reg2;
	
	FILE*arch1,*arch2;
	arch1=fopen("Turnos.dat", "rb");
	
	
	arch2=fopen("veterinario.dat", "rb");
	
	
	
	if(arch2==NULL)
	{
		printf("\nERROR. NO SE REGISTRO NINGUN VETERINARIO.");
		fclose(arch1);
		fclose(arch2);
	}
	else 
	{
		if(arch1==NULL)
		{
			printf("\nERROR. NO SE REGISTRO NINGUN TURNO.");
		}
		else
		{
			printf("\t\t**                  LISTADO DE ATENCIOINES                          **\n");
			printf("\t\t                                                                      \n");
			printf("\t\tMATRICULA                  VETERINARIO                 FECHA DE TURNO \n");
			printf("\t\t**********************************************************************\n\n");
			printf("\t\t                                                                      \n");
			fread(&reg, sizeof(reg), 1, arch1);
			while(!feof(arch1))
			{
				
				printf("\n\t\t %d    ",reg.Matricula_de_Veterinario);
				fread(&reg2, sizeof(reg2), 1, arch2);
				while(!feof(arch1))
				{
					if(reg.Matricula_de_Veterinario==reg2.matricula)
					{
						printf("               %s",reg2.apell_nom);
						//puts(reg2.apell_nom);
						break;
					}
					fread(&reg2, sizeof(reg2), 1, arch2);
				}
				
				
				printf("\t\t            %d/%d/%d",reg.fecha_cargada.dia,reg.fecha_cargada.mes,reg.fecha_cargada.year);
				fread(&reg, sizeof(reg), 1, arch1);
			}	
		}
		fclose(arch1);
		fclose(arch2);
	}
}







