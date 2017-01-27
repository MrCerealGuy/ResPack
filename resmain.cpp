/*====================================================================

  PROJECT		: ResPack
  VERSION		: 1.0

  --------------------------------------------------------------------

  FILE			: resmain.cpp
  AUTHOR		: Andreas Zahnleiter

 =====================================================================*/

#include "respack.h"

int main(int argc, char* argv[])
{
	do
	{
		printf("-- ResPack v1.0 - Game Assets Resource Packer --\n\n");
		printf("1 - ResPack Archiv erstellen\n");
		printf("2 - Datei aus Archiv extrahieren\n");
		printf("3 - Programm beenden\n\n");
		printf("> ");

		switch(getchar())
		{
			case '1':
			{
				char list_file[256], pak_file[256];
				printf("\nDateiname der List Datei: ");
				scanf("%s", list_file);
				printf("Dateiname der Pak Datei : ");
				scanf("%s", pak_file);

				if (create_archive(list_file,pak_file) == -1)
				{
					printf("Error: create_archive() == -1\n");
					fflush(stdin); getchar();
				}
			}
			break;

			case '2':
			{
				char ex_file[256], pak_file[256], file_out[256];
				printf("\nDateiname der Pak Datei              : ");
				scanf("%s", pak_file);
				printf("Dateiname der zu extrahierenden Datei: ");
				scanf("%s", ex_file);
				printf("Dateinamen der extrahierten Datei    : ");
				scanf("%s", file_out);
				
				if (extract_file(pak_file,ex_file,file_out) == -1)
				{
					printf("Error: extract_file() == -1\n");
					fflush(stdin); getchar();
				}
			}
			break;

			case '3': return 0;

		default:
			printf("\nFalsche Eingabe!"); fflush(stdin);
			getchar(); system("cls");
		break;
		}

		fflush(stdin); getchar(); system("cls");

	} while(1);


	return 0;
}