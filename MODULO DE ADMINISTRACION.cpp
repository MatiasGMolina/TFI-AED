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
void validar_contrasenia(char cadena[32]);
bool letras_consecutivas(char contrasenia[32]);
bool numeros_consecutivos(char contrasenia[32]);

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
					
					//atenciones_vet();
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

//*****************************************************************************************************//

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



//*****************************************************************************************************//


void reg_vet()
{
	bool h;
	veterinario reg1;
	int i,n=0,band=0,letra_minuscula=0,letra_mayuscula=0,caracter_numerico=0,caracter_invalido1=0;
	
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
	
	printf("\nCondiciones para el ingreso de la contrasenia: \n");
	printf("\nA. Debera contener al menos una letra mayuscula, una letra minuscula y un numero. ");
	printf("\nB. No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. ");
	printf("solo caracteres alfanumericos. ");
	printf("\nC. Debera tener entre 6 y 32 caracteres.");
	printf("\nD. No debe tener mas de 3 caracteres numericos consecutivos. ");
	printf("\nE. No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente).");
	printf("Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas.");
	
	printf("\n\nIngrese la clave: ");
	_flushall();
	gets(reg1.contrasenia);
	
	validar_contrasenia(reg1.contrasenia);

	
	FILE*arch1;
	arch1=fopen("veterinario.dat", "ab");
	fwrite(&reg1, sizeof(reg1), 1, arch1);
	fclose(arch1);
	printf("\nVETERINARIO REGISTRADO\n");
	printf("\n");
	
	
}



//*****************************************************************************************************//



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
	
	printf("\nCondiciones para el ingreso de la contrasenia: \n");
	printf("\nA. Debera contener al menos una letra mayuscula, una letra minuscula y un numero. ");
	printf("\nB. No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. ");
	printf("solo caracteres alfanumericos. ");
	printf("\nC. Debera tener entre 6 y 32 caracteres.");
	printf("\nD. No debe tener mas de 3 caracteres numericos consecutivos. ");
	printf("\nE. No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente).");
	printf("Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas.");
	
	printf("\n\nIngrese la clave: ");
	_flushall();
	gets(reg.contrasenia);
	
	validar_contrasenia(reg.contrasenia);

	FILE*arch;
	arch=fopen("usuario.dat", "ab");
	fwrite(&reg, sizeof(reg), 1, arch);
	fclose(arch);
	printf("\nASISTENTE REGISTRADO\n");
	
}


//*****************************************************************************************************//


//void atenciones_vet()
//{
//	int mes;
//	FILE*archvet,*archturnos,*archvet;
//	
//	
//	printf("\nIngrese el número de mes a listar: ");
//	scanf("%d",&mes);
//	
//	
//	
//	
//	
//	
//	
//}

//*****************************************************************************************************//
//*****************************************************************************************************//
//***************                           FUNCTIONS                            **********************//
//*****************************************************************************************************//
//*****************************************************************************************************//


//Retorna verdadero si el nombre del veterinario y la matricula ya existen 
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


//Retorna verdadero si el nombre del usuario ya existe
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


//validar contrasenia
void validar_contrasenia(char cadena[32])
{
	int i,n=0,band=0,letra_minuscula=0,letra_mayuscula=0,caracter_numerico=0,caracter_invalido1=0;
	
	while(band==0)
	{
		n=strlen(cadena);
		for(i=0;i<n;i++)
		{
			if(cadena[i] >= 'a' and cadena[i] <=  'z')
			{
				letra_minuscula++;
			}
			
			if(cadena[i] >= 'A' and cadena[i] <= 'Z')
			{
				letra_mayuscula++;
			}
			
			if(cadena[i] >= '0' and cadena[i] <= '9')
			{
				caracter_numerico++;
			}
			
			if((cadena[i] == '+') or (cadena[i] == ',') or (cadena[i] == ';') or (cadena[i] == ':') or (cadena[i] == '""') 
		 	or (cadena[i] == '[]') or (cadena[i] == '{}') or (cadena[i] == '()') or (cadena[i] == '?') 
			or (cadena[i] == '¿') or (cadena[i] == '-') or (cadena[i] == '_') or (cadena[i] == '!') or (cadena[i] == '¡') 
			or (cadena[i] == ' '))
			{
				caracter_invalido1++;
			}	
		}
		
		if(letra_minuscula < 1)
		{
			printf("\nERROR. La contrasenia debe contener al menos una letra minuscula.");
			band=1;
		}
		if(letra_mayuscula < 1)
		{
			printf("\nERROR. La contrasenia debe contener al menos una letra mayuscula.");
			band=1;
		}
		if(caracter_numerico < 1)
		{
			printf("\nERROR. La contrasenia debe contener al menos un numero.");
			band=1;
		}
		if(caracter_invalido1 != 0)
		{
			printf("\nERROR. La contrasenia no debe contener caracteres de puntuacion, acentos, ni espacios.");
			band=1;
		}
		if(strlen(cadena) < 6)
		{
			printf("\nERROR. La contrasenia debe tener mas de 6 caracteres.");
			band=1;
		}
		if(strlen(cadena) > 32)
		{
			printf("\nERROR. La contrasenia debe tener menos de 32 caracteres.");
			band=1;
		}
		if(numeros_consecutivos(cadena))
		{
			printf("\nERROR. La contrasenia no debe poseer mas de 3 caracteres numericos consecutivos. ");
			band=1;
		}
		if(letras_consecutivas(cadena))
		{
			printf("\nERROR. La contrasenia no debe poseer letras alfabeticamente consecutivas. ");
			band=1;
		}
		if(band==1)
		{
			_flushall();
			printf("\n\nIngrese el contrasenia nuevamente: ");
			gets(cadena);
			band=0;letra_minuscula=0;letra_mayuscula=0;caracter_numerico=0;caracter_invalido1=0;
	
		}
		else
		{
			break;
		}
	}
}


//retorna verdadero si hay letras consecutivas 
bool letras_consecutivas(char contrasenia[32])
{
	
	int n=0,i=0, ascii=0,ascii1=0;
	char letra, letra1,contrasenia2[32];
	
	contrasenia2[32]=contrasenia[32];
	
	n=strlen(contrasenia2);
	strlwr(contrasenia2);
	
	while(i<n-1)
	{
		
		letra=contrasenia2[i];
		
		//validacion de letras	
		if(letra >= 'a' and letra <=  'z')
		{
			ascii=letra;
			letra1=contrasenia2[i+1];
			ascii1=letra1;
		
			if(ascii+1==ascii1)
			{
				return true;
			}
		}
		
		i++;
	}
	
	return false;	
}


//retorna verdadero si hay numeros consecutivos 
bool numeros_consecutivos(char contrasenia[32])
{
	
	int n=0,i=0, caracter_numerico=0;
	
	n=strlen(contrasenia);
	
	while(i<n-1)
	{
		if( contrasenia[i]>= '0' and contrasenia[i] <= '9')
		{
			caracter_numerico++;
		}
		
		if(caracter_numerico>3)
		{
			return true;
		}
		
		i++;
	}
	
	return false;	
}
