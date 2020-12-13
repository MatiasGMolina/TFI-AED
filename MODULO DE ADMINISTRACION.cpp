#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
void menu();
void reg_vet();
void reg_asistente();
bool buscar_usuario(char usu[10]);
bool buscar_vet(char nombre[60],int matricula);
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
	char contrasenia[10];
};
main()
{
	setlocale(LC_ALL, ""); // caracteres en español
	int opcion;
	do
	{
		menu();
		printf("\t\t         Seleccione una Opción: ");
		scanf("%d", &opcion);
		
		
		
			switch(opcion)
			{
			
				case 1:
					
					reg_vet();
					system("\n\npause");
					break;
				case 2: 
					
					reg_asistente();
					system("\n\npause");
					break;
				case 3: 
					
					
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
		printf("\t\t**                     Modulo de Administración                 **\n");
		printf("\t\t******************************************************************\n");
		printf("\t\t                                                                  \n");
		printf("\t\t         1- Registrar Veterinario.					 			  \n");
		printf("\t\t                                                                  \n");
		printf("\t\t         2- Registrar Usuario Asistente.	                      \n");
		printf("\t\t                                                                  \n");                 
		printf("\t\t         3- Atenciones por Veterinarios.                          \n");
		printf("\t\t                                                                  \n");
		printf("\t\t         4- Ranking de Veterinarios por Atención.  			      \n");
		printf("\t\t                                                                  \n");
		printf("\t\t         5- Cerrar la Aplicación.                  	              \n");
		printf("\t\t                                                                  \n");
		printf("\t\t******************************************************************\n\n");
}

bool buscar_vet(char nombre[60],int matricula)
{	
	FILE*arch;
	veterinario reg;
	arch=fopen("veterinario.dat", "a+b");
	fread(&reg, sizeof(reg), 1, arch);
	while(!feof(arch))
	{	
		if(strcmp(reg.apell_nom, nombre)==0 or (matricula==reg.matricula))
		{	
			fclose(arch);
			return true;
		}
	fread(&reg, sizeof(reg), 1, arch);
	}
	fclose(arch);
	return false;
}
void reg_vet()
{
	bool h;
	veterinario reg1;
	
	system("cls");
	printf("\n\tRegistrar Veterinario.");
	do
	{
		printf("\n\nIngrese el apellido y nombre del veterinario a registrar: ");
		_flushall();
		gets(reg1.apell_nom);
		printf("\nIngrese el numero de matricula: ");
		scanf("%d", &reg1.matricula);
		h = buscar_vet(reg1.apell_nom,reg1.matricula);
		if(h==true)
		{	
			printf("\nESTOS DATOS YA FUERON REGISTRADOS. INTENTE NUEVAMENTE.\n");
		}
	}while(h==true);
	
	
	printf("\nIngrese el DNI: ");
	scanf("%d", &reg1.dni);
	printf("\nIngrese el telefono: ");
	scanf("%d", &reg1.telefono);
	

	printf("\nIngrese la clave: ");
	_flushall();
	gets(reg1.contrasenia);
	
	FILE*arch1;
	arch1=fopen("veterinario.dat", "ab");
	fwrite(&reg1, sizeof(reg1), 1, arch1);
	fclose(arch1);
	printf("\nVETERINARIO REGISTRADO\n");
	printf("\n");
}
void reg_asistente()
{	
	bool h;
	usuarios reg;
	int band=0,i,mayuscula=0,digitos=0,caracter_invalido=0;
	
	system("cls");
	printf("\n\tRegistrar Asistente.");
	
	printf("\n\nIngrese el apellido y nombre del nuevo asistente a registrar: ");
	_flushall();
	gets(reg.apell_nomb);

	
	printf("\nIngrese el nuevo usuario.");
	printf("\nEste último debera cumplir los siguiente requisitos:");
	printf("\nA.El usuario debe tener como minimo 6 caracteres y maximo de 10, los cuales podrán ser letras, números y/o símbolos del conjunto {+,-,/,*,?,¿,!,¡}.");
	printf("\nB.Ser único para cada usuario registrado.");
	printf("\nC.Comenzar con una letra minúscula.");
	printf("\nD.Tener al menos 2 letras mayúsculas.");
	printf("\nE.Tener como máximo 3 dígitos.");
	do
	{
		printf("\n\nIngrese el usuario: ");
		_flushall();
		gets(reg.usuario);
		h= buscar_usuario(reg.usuario);
		if(h==true)
		{	
			printf("\nESTE USUARIO YA FUE INGRESADO. INTENTE NUEVAMENTE.\n");
		}
	}while(h==true);
	
	while(band==0)
	{
		if(strlen(reg.usuario)<6)
		{
			printf("\nERROR. El usuario debe tener mas de 6 caracteres.");
			band=1;
		}
		if(strlen(reg.usuario)>10)
		{
			printf("\nERROR. El usuario debe tener menos de 10 caracteres.");
			band=1;
		}
		if(!(reg.usuario[0]>='a' and reg.usuario[0]<='z'))
		{
			printf("\nERROR. El primer caracter debe ser una minuscula.");
			band=1;
		}
		for(i=0;i<10;i++)
		{
			if(reg.usuario[i]>='A' and reg.usuario[i]<='Z')
			{
				mayuscula++;	
			}
			if((reg.usuario[i]>='0' and reg.usuario[i]<='9') or (reg.usuario[i]=='+') or (reg.usuario[i]=='-') or (reg.usuario[i]=='/') or (reg.usuario[i]=='*') or (reg.usuario[i]=='?') or (reg.usuario[i]=='¿')or (reg.usuario[i]=='!')or (reg.usuario[i]=='¡'))
			{
				digitos++;
			}
			if(!((reg.usuario[i]>='0' and reg.usuario[i]<='9') or ((reg.usuario[i]>='A' and reg.usuario[i]<='Z')) or ((reg.usuario[0]>='a' and reg.usuario[0]<='z')) or (reg.usuario[i]=='+') or (reg.usuario[i]=='-') or (reg.usuario[i]=='/') or (reg.usuario[i]=='*') or (reg.usuario[i]=='?') or (reg.usuario[i]=='¿')or (reg.usuario[i]=='!')or (reg.usuario[i]=='¡')))
			{
				caracter_invalido++;
			}
		}
		if(caracter_invalido!=0)
		{
			printf("\nERROR. El usuario ingresado contiene caracteres invalidos.");
			band=1;
		}
		if(mayuscula<2)
		{
			printf("\nERROR. El usuario debe tener 2 mayusculas como minimo.");
			band=1;	
		}
		if(digitos>3)
		{
			printf("\nERROR. El usuario debe tener 3 digitos como maximo.");
			band=1;
		}
		if(band==1)
		{
			printf("\nIngrese el usuario nuevamente: ");
			_flushall();
			gets(reg.usuario);
			band=0;mayuscula=0;digitos=0;caracter_invalido=0;
		}
		else
		{
			break;
		}
	}
	
	printf("\nINGRESE LA CLAVE:");
	_flushall();
	gets(reg.contrasenia);
	
	FILE*arch;
	arch=fopen("usuario.dat", "ab");
	fwrite(&reg, sizeof(reg), 1, arch);
	fclose(arch);
	printf("\nASISTENTE REGISTRADO\n");
}
bool buscar_usuario(char usu[10])
{	
	FILE*arch;
	usuarios reg;
	arch=fopen("usuario.dat", "a+b");
	fread(&reg, sizeof(reg), 1, arch);
	while(!feof(arch))
	{	
		if(strcmp(reg.usuario, usu)==0)
		{	
			fclose(arch);
			return true;
		}
		fread(&reg, sizeof(reg), 1, arch);
	}
	fclose(arch);
	return false;
}
