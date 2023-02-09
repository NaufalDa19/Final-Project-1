#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f_user,*f_user2,*f_admin,*f_admin2; 

struct masuk{
	char nama[100],almt[200],user[100],pass[50],hp[50];
}b,d[100];
struct obat{
	char uname[100],kategori[100];
	double dosis,harga;
}data[100],temp;
struct va{
	char name[50];
	int va,rekening;
}a[100];
char cari[100],pl;
int pil,i,n,j,x=0,y=0,c;

void registmember();
void loginadmin(int);
void loginmember(int);
void datamember();
void admin();
void member();
void menuobat();
void pembayaran();
void tambah();
void tambahobat();
void kategoripenyakit();
void menutambah();
void info();
void infoobat();
void infomember();
void hapusobat();
void updatekode();
void hapusakun();
void pemilihanobat();
void tambahkode();
void transfer();
void edit();
void pilihan();
void plh();

int main () //Menu Utama
{
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==D'Medicine==             ==\n");
	printf("==                                        ==\n");
	printf("============================================\n");
	printf("\nAkun : \n\n [1]Admin\n [2]Member\n [3]Exit\n\nPilihan : ");
	scanf("%d", &pil);
	getchar();
	switch(pil){
		case 1: loginadmin(3);break;
		case 2: datamember();break;
		case 3: system("exit");printf("\n:):):):)Terima Kasih:):):):)\n\n");system("pause");break;
		default: printf("Menu Tidak Tersedia Dalam Pilihan!\nTekan enter untuk kembali ke menu awal:)");getchar();system("cls");main();break;
	}
}

void loginadmin(int kesempatan) //Fungsi Untuk Login Admin
{
	system("cls");
	if(kesempatan>0){
		printf("============================================\n");
		printf("==                                        ==\n");
		printf("==             ==D'Medicine==             ==\n");
		printf("==                                        ==\n");
		printf("============================================");
		printf("\n\n              ==Login Admin==            \n");
		printf("\nKesempatan Anda %d Lagi \n", kesempatan);
		printf("\nUsername : ");
		gets(b.user);
		printf("Password : ");
		gets(b.pass);
		if(strcmp(b.user,"admin")==0 && strcmp(b.pass,"admin")==0){
			printf("\nLogin Successful!!!");getchar();admin();
		}
		else{
			printf("\nLogin Failed!!!");getchar();
			loginadmin(kesempatan-1);
		}
		
	}
	else{
		printf("\nMaaf kesempatan anda sudah habis!!!\nTekan enter untuk kembali ke menu awal");system("cls");loginadmin(kesempatan);
		getchar();
	}
	
}
void loginmember(int kesempatan) //Fungsi Untuk Login member
{
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==D'Medicine==             ==\n");
	printf("==                                        ==\n");
	printf("============================================");
	printf("\n\n              ==Login Member==            \n");
    printf("\nUsername\t: "); 
	gets(b.user);
    printf("Password\t: "); 
	gets(b.pass);
    i=0;
    f_user=fopen("Registrasi.dat","rb");                                                         
	while(fread(&d[i],sizeof(d[i]),1,f_user)==1)
	{
        if(strcmp(b.user,d[i].user)==0 && strcmp(b.pass,d[i].pass)==0)
		{
			i=1;
            break;
        }
    }
    fclose(f_user);
    if(i==1){
        printf("\nLogin Successful!!!");
        getchar();
        system("cls");member();
    }
	else{
        printf("\nLOGIN FAILED,\nTersisa %d kesempatan",kesempatan-1);
        getchar();
        system("cls");
        kesempatan--;
        if(kesempatan>0) {
        	loginmember(kesempatan);
		}
        else {
        	printf("============================================\n");
			printf("==                                        ==\n");
			printf("==             ==D'Medicine==             ==\n");
			printf("==                                        ==\n");
			printf("============================================\n");
            printf("\nMaaf kesempatan anda sudah habis,\nTekan enter untuk kembali ke menu awal"); 
            getchar();
            system("cls");
			datamember();
        }
    system("cls");
    }
}
void registmember() // Fungsi Untuk Menregister member
{
	char tempa[100];
	system("cls");
	f_user=fopen("Registrasi.dat","ab");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==D'Medicine==             ==\n");
	printf("==                                        ==\n");
	printf("============================================");
	printf("\n\n               ==Registrasi==             \n");
	printf("\nNama : ");
	gets(d[i].nama);
	printf("No HP : ");
	gets(d[i].hp);
	printf("Alamat : ");
	gets(d[i].almt);
	printf("Username : ");
	gets(d[i].user);
	printf("Password : ");
	gets(d[i].pass);
	printf("Confirm Password : ");
	gets(tempa);
	if(strcmp(tempa,d[i].pass)==0){
		fwrite(&d[i],sizeof(d[i]),1,f_user);
		printf("\nRegistrasi Berhasil");
		fclose(f_user);
	}
	else{
		printf("\nPassword tidak sama");
		getchar();
		registmember();
	}
	getchar();
	system("cls");
	datamember();
	
}

void datamember() //Menu untuk Member
{
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==D'Medicine==             ==\n");
	printf("==                                        ==\n");
	printf("============================================\n");
	printf("\nMenu :\n\n [1]Register\n [2]Login\n [3]Menu Awal\n");
	printf("\nPilihan : ");
	scanf("%d", &pil);
	getchar();
	switch(pil){
		case 1: registmember();break;
		case 2: loginmember(3);break;
		case 3: main();break;
		default: printf("Menu Tidak Tersedia Dalam Pilihan!\nTekan enter untuk kembali ke menu awal:)");getchar();system("cls");datamember();break;
	}
}
void admin()// Menu Admin
{
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==D'Medicine==             ==\n");
	printf("==                                        ==\n");
	printf("============================================\n\n");
	printf("Menu\n\n [1]Tambah Data\n [2]Informasi Data\n [3]Menghapus Data Obat\n [4]Update Kode VR\n [5]Update Akun Member\n [6]Menghapus Akun Member\n [7]Menu Awal\n\nPilihan : ");
	scanf("%d", &pil);
	switch(pil){
		case 1:tambah();break;
		case 2:info();break;
		case 3:pilihan();break;
		case 4:updatekode();break;
		case 5:edit();break;
		case 6:plh();break;
		case 7:main();break;
		default:printf("Pilihan Tidak Ada!!!!!\n\n");system("pause");admin();break;
	}
}
void infomember()// Menu untuk Melihat data Member
{
	system("cls");
	f_user=fopen("Registrasi.dat","rb");
	printf("==============================================\n");
	printf("==                                          ==\n");
	printf("==              ==Data Member==             ==\n");
	printf("==                                          ==\n");
	printf("==============================================\n\n");
	i=0;
	while(fread(&d[i],sizeof(d[i]),1,f_user)==1){
		printf("%d.\tNama\t : %s ", i+1,d[i].nama);
		printf("\n\tNo Hp\t : %s ", d[i].hp);
		printf("\n\tAlamat\t : %s ", d[i].almt);
		printf("\n\n");
		i++;
	}
	fclose(f_user);system("pause");
	info();
}

void kategoripenyakit() //Fungsi Untuk menambah kategori obat
{
	system("cls");
	printf("==========================================================\n");
	printf("==                                                      ==\n");
	printf("==              ==Penambahan Data Obat==                ==\n");
	printf("==                                                      ==\n");
	printf("==========================================================\n\n");
	f_admin=fopen("tambahan.dat","rb");
	printf("Kategori Penyakit :\n\n");
	i=0;
	while(fread(&data[i],sizeof(data[i]),1,f_admin)==1){
		printf(" [%d]%s\n",i+1,data[i].kategori);
		i++;
	}
	fclose(f_admin);
	printf("Berapa data yang akan ditambahkan : ");
	scanf("%d", &n);
	system("cls");
	printf("\n\n==========================================================\n");
	printf("==                                                      ==\n");
	printf("==            ==Penambahan Kategori Penyakit==          ==\n");
	printf("==                                                      ==\n");
	printf("==========================================================\n\n");
	f_admin=fopen("tambahan.dat","ab");
	for(i=1;i<=n;i++){
		printf("%d. Kategori Penyakit : ", i);
		fflush(stdin);
		gets(data[i].kategori);
		strcpy(data[i].uname,"-");
		data[i].dosis=0;
		data[i].harga=0;
		fwrite(&data[i],sizeof(data[i]),1,f_admin);
	}
	printf("\nData telah ditambahkan");
	fclose(f_admin);getchar();
	admin();
}
void tambah() //Menu untuk menambah data obat
{
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==D'Medicine==             ==\n");
	printf("==                                        ==\n");
	printf("============================================\n\n");
	printf("Menu :\n\n [1]Kategori Penyakit\n [2]Obat\n [3]Kembali\n\nPilihan : ");
	scanf("%d", &pil);
	switch(pil){
		case 1: kategoripenyakit();break;
		case 2: menutambah();break;
		case 3: admin();break;
		default: printf("Pilihan Tidak Ada!!!!!");tambah();break;
	}
	
	
}
void menutambah() //Menu untuk memilih kategori obat yang akan ditambah
{
	system("cls");
	printf("==========================================================\n");
	printf("==                                                      ==\n");
	printf("==              ==Penambahan Data Obat==                ==\n");
	printf("==                                                      ==\n");
	printf("==========================================================\n\n");
	printf("Kategori Penyakit :\n\n");
	i=0;
	f_admin=fopen("tambahan.dat","rb");
	while(fread(&data[i],sizeof(data[i]),1,f_admin)==1){
		printf(" [%d]%s\n",i+1,data[i].kategori);
		i++;
	}
	fclose(f_admin);
	f_admin=fopen("tambahan.dat","rb+");
	printf("\nNama data yang akan dicari : ");
	fflush(stdin);
	gets(cari);
	i=0;
	while(fread(&data[i],sizeof(data[i]),1,f_admin)==1){
		if(strcmp(cari,data[i].kategori)==0){
			tambahobat();
		}
		i++;
	}
	printf("Data tidak ditemukan");
	fclose(f_admin);
}

void tambahobat() // Menu untuk menambah Obat
{
	f_admin=fopen("Obat.dat","ab");
	printf("Berapa data yang ditambahkan : ");
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		printf("Nama Penyakit : ");
		fflush(stdin);
		gets(data[i].kategori);
		printf("%d.	Nama Obat\t\t : ", i);
		gets(data[i].uname);
		printf("	Dosis (mg)\t\t : ");
		scanf("%lf", &data[i].dosis);
		printf("	Harga\t\t\t : ");
		scanf("%lf", &data[i].harga);
		fwrite(&data[i],sizeof(data[i]),1,f_admin);
	}
	fclose(f_admin);
	admin();
}

void info() //Menu untuk melihat Info obat,member
{
	system("cls");
	printf("==============================================\n");
	printf("==                                          ==\n");
	printf("==              ==Bagian Informasi==        ==\n");
	printf("==                                          ==\n");
	printf("==============================================\n");
	printf("\nMenu :\n\n [1]Member\n [2]Obat\n [3]Kembali\n\nPilihan : ");
	scanf("%d", &pil);
	switch(pil){
		case 1: infomember();break;
		case 2: infoobat();break;
		case 3: admin();break;
		default: printf("Pilihan Tidak Ada!!!!!");tambah();break;
	}
}

void infoobat() //menampilkan obat yang sudah di inputkan
{
	system("cls");
	printf("==============================================\n");
	printf("==                                          ==\n");
	printf("==                =Data Obat==              ==\n");
	printf("==                                          ==\n");
	printf("==============================================\n\n");
	f_user=fopen("tambahan.dat","rb");
	i=0;
	printf("Daftar Penyakit : \n\n");
	while(fread(&data[i],sizeof(data[i]),1,f_user)==1){
		printf(" [%d]%s\n",i+1,data[i].kategori);
		i++;
	}
	fclose(f_user);
	f_admin=fopen("Obat.dat","rb");
	printf("\nNama Penyakit : ");
	fflush(stdin);
	gets(cari);
	i=0;
	x=0;
	while(fread(&data[i],sizeof(data[i]),1,f_admin)==1){
		if(strcmp(data[i].kategori,cari)==0){
			printf("%d.\tNama obat\t\t : %s ", x+1,data[i].uname);
			printf("\n\tDosis (mg)\t\t : %.0f ", data[i].dosis);
			printf("\n\tHarga\t\t\t : %.0f", data[i].harga);
			printf("\n\n");
			x++;
		}
		i++;
	}
	fclose(f_admin);getchar();
	admin();
}
void pilihan() //Pilihan untuk masuk ke menu hapus obat
{
	printf("Apakah anda ingin menghapus data?[y/n]\npilih : ");
	scanf("%s", &pl);
	if(pl=='y' || pl=='Y'){
		hapusobat();
	}
	else if(pl=='n' || pl=='N'){
		admin();
	}
}
void hapusobat() //Fungsi untuk Menghapus Obat
{
	system("cls");
	printf("==============================================\n");
	printf("==                                          ==\n");
	printf("==        ==Penghapusan Data Obat==         ==\n");
	printf("==                                          ==\n");
	printf("==============================================\n\n");
	f_user=fopen("tambahan.dat","rb");
	i=0;
	printf("Penyakit yang diderita : \n\n");
	while(fread(&data[i],sizeof(data[i]),1,f_user)==1){
		printf(" [%d]%s\n",i+1,data[i].kategori);
		i++;
	}
	fclose(f_user);
	f_admin=fopen("Obat.dat","rb");
	printf("\nNama Penyakit : ");
	fflush(stdin);
	gets(cari);
	i=0;
	x=0;
	while(fread(&data[i],sizeof(data[i]),1,f_admin)==1){
		if(strcmp(data[i].kategori,cari)==0){
			printf("%d.\tNama obat\t\t : %s ", x+1,data[i].uname);
			printf("\n\tDosis (mg)\t\t : %.0f ", data[i].dosis);
			printf("\n\tHarga\t\t\t : %.0f", data[i].harga);
			printf("\n\n");
			x++;
		}
		i++;
	}
	fclose(f_admin);
	f_admin=fopen("Obat.dat","rb");
	f_admin2=fopen("Obat2.dat","wb");
	printf("Nama obat yang akan di hapus : ");
	fflush(stdin);
	gets(cari);
	while(fread(&data[i],sizeof(data[i]),1,f_admin)==1){
		if(strcmp(data[i].uname,cari)!=0){
			fwrite(&data[i],sizeof(data[i]),1,f_admin2);
		}
	}
	fclose(f_admin);
	fclose(f_admin2);
	printf("Data Terhapus");
	getchar();
	remove("Obat.dat");
	rename("Obat2.dat","Obat.dat");
	admin();
}
void plh() //Pilihan untuk masuk ke menu hapus akun
{
	printf("Apakah anda ingin menghapus data?[y/n]\npilih : ");
	scanf("%s", &pl);
	if(pl=='y' || pl=='Y'){
		hapusakun();
	}
	else if(pl=='n' || pl=='N'){
		admin();
	}
}
void hapusakun() //Fungsi Untuk menghapu akun
{
	system("cls");
	f_user=fopen("Registrasi.dat","rb");
	printf("==============================================\n");
	printf("==                                          ==\n");
	printf("==       ==Penghapusan Data Member==        ==\n");
	printf("==                                          ==\n");
	printf("==============================================\n\n");
	i=0;
	while(fread(&d[i],sizeof(d[i]),1,f_user)==1){
		printf("%d.\tNama\t : %s ", i+1,d[i].nama);
		printf("\n\tAlamat\t : %s ", d[i].almt);
		printf("\n\n");
		i++;
	}
	fclose(f_user);
	f_user=fopen("Registrasi.dat","rb");
	f_user2=fopen("Registrasi2.dat","wb");
	printf("Akun member yang akan dihapus : ");
	fflush(stdin);
	gets(cari);
	while(fread(&d[i],sizeof(d[i]),1,f_user)==1){
		if(strcmp(d[i].nama,cari)!=0){
			fwrite(&d[i],sizeof(d[i]),1,f_user2);
		}
	}
	fclose(f_user);
	fclose(f_user2);
	printf("Data Member Terhapus");
	getchar();
	remove("Registrasi.dat");
	rename("Registrasi2.dat","Registrasi.dat");
	admin();
}
void member() //Menu Untuk member memilih kategori Obat
{
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==D'Medicine==             ==\n");
	printf("==                                        ==\n");
	printf("============================================\n\n");
	f_user=fopen("tambahan.dat","rb");
	i=0;
	printf("Penyakit yang diderita : \n\n");
	while(fread(&data[i],sizeof(data[i]),1,f_user)==1){
		printf(" [%d]%s\n",i+1,data[i].kategori);
		i++;
	}
	fclose(f_user);
	f_admin=fopen("Obat.dat","rb");
	printf("\nTulis Nama Penyakit : ");
	gets(cari);
	i=0;
	while(fread(&data[i],sizeof(data[i]),1,f_user)==1){
		fclose(f_user);menuobat();
		i++;
	}
	fclose(f_user);
	pemilihanobat();
}
void menuobat()//Fungsi untuk mengurutkan obat di bagian member
{
	f_admin=fopen("Obat.dat","rb");
	i=1; c=1;
	while(fread(&data[i],sizeof(data[i]),1,f_admin)==1){
		data[i];
		i++;
		c++;
	}
	fclose(f_admin);
	for(i=1;i<=c;i++){
        for(j=1;j<=c-i;j++){
           	if(strcmp(data[j].uname,data[j+1].uname)>0){
               	temp=data[j];
               	data[j]=data[j+1];
               	data[j+1]=temp;
            }
        }
    }
    x=0;
	for(i=1;i<=c;i++){
		if(strcmp(data[i].kategori,cari)==0){
		printf("%d.\tNama obat\t\t : %s ", x+1,data[i].uname);
		printf("\n\tDosis (mg)\t\t : %.0f ", data[i].dosis);
		printf("\n\tHarga\t\t\t : %.0f", data[i].harga);
		printf("\n\n");
		x++;
		}
	}
}
void pemilihanobat()//Menu untuk member memilih obat
{
	f_user=fopen("Obat.dat","rb");
	i=0;
	printf("Tulis Nama Obat : ");
	gets(cari);
	while(fread(&data[i],sizeof(data[i]),1,f_user)==1){
		if(strcmp(data[i].uname,cari)==0){
			pembayaran();
		}
		i++;
	}
	fclose(f_user);
	
}
void pembayaran() //menu untuk member memilih pembayaran yang diinginkan
{
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==Pembayaran==             ==\n");
	printf("==                                        ==\n");
	printf("============================================\n\n");
	printf("Metode Pembayaran :\n\n [1]COD\n [2]Transfer Bank\n\nPilih Pembayaran : ");
	scanf("%d", &pil);
	switch(pil){
		case 1:printf("\n\nPesanan %s akan segeran dikirim\nTerima kasih sudah berbelanja di toko obat kami:):):):):)!!!!!\n", data[i].uname);system("pause");break;
		case 2:transfer();break;
		default: printf("Pilihan Tidak Ada!!!!!");system("pause");pembayaran();
	}	
}
void updatekode() //fungsi untuk mengupdate kode bank dalam admin
{
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==Update Kode==            ==\n");
	printf("==                                        ==\n");
	printf("============================================\n\n");
	printf("Menu :\n\n [1]Lihat Kode\n [2]Tambah Kode\n [3]Hapus Kode\n [4]Kembali\n\nPilihan : ");
	scanf("%d", &pil);
	switch(pil){
		case 1:
			system("cls");
			printf("============================================\n");
			printf("==                                        ==\n");
			printf("==             ==Update Kode==            ==\n");
			printf("==                                        ==\n");
			printf("============================================\n\n");
			f_admin=fopen("Rekening.dat","rb");
			printf("Daftar Kode : \n\n");
			i=0;
			while(fread(&a[i],sizeof(a[i]),1,f_admin)==1){
				printf(" [%d]\tNama Bank\t : %s \n",i+1,a[i].name);
				printf("\tKode Bank\t : %d \n",a[i].va);
				printf("\tNomor Rekening\t : %d ",a[i].rekening);
				printf("\n\n");
				i++;
			}
			fclose(f_admin);
			system("pause");
			updatekode();
			break;
		case 2:tambahkode();break;
		case 3:
			system("cls");
			printf("============================================\n");
			printf("==                                        ==\n");
			printf("==             ==Update Kode==            ==\n");
			printf("==                                        ==\n");
			printf("============================================\n\n");
			f_admin=fopen("Rekening.dat","rb");
			printf("Daftar Kode : \n\n");
			i=0;
			while(fread(&a[i],sizeof(a[i]),1,f_admin)==1){
				printf(" [%d]\tNama Bank\t : %s \n",i+1,a[i].name);
				printf("\tKode Bank\t : %d \n",a[i].va);
				printf("\tNomor Rekening\t : %d ",a[i].rekening);
				printf("\n\n");
				i++;
			}
			fclose(f_admin);
			f_admin=fopen("Rekening.dat","rb");
			f_admin2=fopen("Rekening2.dat","wb");
			printf("Nomor kode yang akan di hapus : ");
			fflush(stdin);
			gets(cari);
			while(fread(&a[i],sizeof(a[i]),1,f_admin)==1){
				if(strcmp(a[i].name,cari)!=0){
					fwrite(&a[i],sizeof(a[i]),1,f_admin2);
				}
			}
			printf("Data Terhapus");
			fclose(f_admin);
			fclose(f_admin2);
			remove("Rekening.dat");
			rename("Rekening2.dat","Rekening.dat");system("pause");updatekode();
			break;
		case 4:admin();break;
		default:printf("\nPilihan Tidak Ada!!!!!\n\n");system("pause");updatekode();
	}
}
void tambahkode()//Fungsi untuk menambah kode bank
{
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==             ==Update Kode==            ==\n");
	printf("==                                        ==\n");
	printf("============================================\n\n");
	f_admin=fopen("Rekening.dat","ab");
	printf("Berapa data yang ingin ditambah : ");
	scanf("%d", &n);
	getchar();
	for(i=1;i<=n;i++){
		printf("%d.\tNama Bank\t : ");
		fflush(stdin);
		gets(a[i].name);
		printf("\tKode Bank\t : ");
		scanf("%d", &a[i].va);
		printf("\tNomor Rekening\t : ");
		scanf("%d", &a[i].rekening);
		fwrite(&a[i],sizeof(a[i]),1,f_admin);
		printf("\n\n");
	}
	fclose(f_admin);
	printf("Nomor VA telah ditamabahkan\n\n");system("pause");
	updatekode();
}
void transfer()//Fungsi untuk member memilih bank yang akan di transfer
{
	char tempa[50];
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==         ==Pembayaran Transfer==        ==\n");
	printf("==                                        ==\n");
	printf("============================================\n\n");
	f_user=fopen("Rekening.dat","rb");
	printf("Daftar Kode : \n\n");
	i=0;
	while(fread(&a[i],sizeof(a[i]),1,f_user)==1){
		printf(" [%d]\tNama Bank\t : %s \n",i+1,a[i].name);
		printf("\tKode Bank\t : %d \n",a[i].va);
		printf("\tNomor Rekening\t : %d ",a[i].rekening);
		printf("\n\n");
		i++;
	}
	fclose(f_user);
	f_user=fopen("Rekening.dat","rb");
	printf("Nama bank yang ingin dituju : ");
	fflush(stdin);
	gets(cari);
	
	i=0;
	while(fread(&a[i],sizeof(a[i]),1,f_user)==1){
		if(strcmp(a[i].name,cari)==0){
			printf("\nMasukan No Anda yang dapat dihubungi : ");
			gets(tempa);
			printf("\nPesanan %s dengan No. Rekening (%d %d) No. Telepone (%s) akan segera dikirim\n",data[i].uname,a[i].va,a[i].rekening,tempa);
		}
		i++;
	}
	fclose(f_user);
	system("pause");
	system("exit");
}
void edit() //Fungsi untuk mengedit data member dalam admin
{
	system("cls");
	printf("============================================\n");
	printf("==                                        ==\n");
	printf("==           ==Pengeditan Akun==          ==\n");
	printf("==                                        ==\n");
	printf("============================================\n\n");
	f_user=fopen("Registrasi.dat","rb");
	i=0;
	while(fread(&d[i],sizeof(d[i]),1,f_user)==1){
		printf("%d.\tNama\t : %s ", i+1,d[i].nama);
		printf("\n\tNo Hp\t : 0%d ", d[i].hp);
		printf("\n\tAlamat\t : %s ", d[i].almt);
		printf("\n\n");
		i++;
	}
	fclose(f_user);
	
	printf("Masukkan nama yang akan diedit : ");fflush(stdin);gets(cari);
	
	f_user=fopen("Registrasi.dat","rb+");
	while(fread(&d[i],sizeof(d[i]),1,f_user)==1){
		if(strcmp(d[i].nama,cari)==0){
			fseek(f_user,-sizeof(d[i]),SEEK_CUR);
			printf("Masukkan nama baru\t : ");gets(d[i].nama);
			printf("Masukkan no baru\t : ");scanf("%d", &d[i].hp);
			printf("Masukan alamat baru\t : ");fflush(stdin);gets(d[i].almt);
			fwrite(&d[i],sizeof(d[i]),1,f_user);
			break;
		}
	}
	fclose(f_user);
	system("pause");
	admin();
}