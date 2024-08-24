#include "graphdinamis.h"
#include <stdbool.h>
#include <windows.h>
#include <time.h>

//char a,b,c;

address1 alokasistasiun(){
	//Deklarasi//
	address1 stasiun;
	
	//Algoritma//
	stasiun = (address1) malloc(sizeof (graph));
	if (stasiun == Nil){
		printf("ALOKASI GAGAL");
	}else{
		return stasiun;
	}
}


address2 alokasijalur(){
	//Deklarasi//
	address2 railway; 
	
	//Algoritma//
	railway = (address2) malloc(sizeof (jalan));
	if (railway == Nil){
		printf("ALOKASI GAGAL");
	}else{
		return railway;
	}
}


address1 lastLL(address1 first){
	//Deklarasi//
	address1 cari;
	
	//Algoritma//
	cari = first;
	while(next(cari) != Nil){
		cari = next(cari);
	}
	return cari;
}

address2 lastjalur(address2 first){
	//Deklarasi//
	address2 cari;
	
	//Algoritma//
	cari = first;
	while(nextJalur(cari) != Nil){
		cari = nextJalur(cari);
	}
	return cari;
}


address1 caristasiun(char nama[], address1 first) {
    address1 cari;
	cari = first;
    while (cari != Nil) {
        if (strcmp(namaStasiun(cari), nama) == 0) {
            return cari;
        }
        cari = next(cari);
    }
    printf("Stasiun tidak ditemukan");
    return Nil;
}


void buatLL(address1 *first,char nama[]){
	//Deklarasi//
	address1 baru;
	
	//Algoritma/
	baru = alokasistasiun();
	strcpy(namaStasiun(baru),nama);
	next(baru) = Nil;
	arc(baru) = Nil;
	if(*first == Nil){
		*first = baru;
	}else{
		address1 last;
		last = lastLL(*first);
		next(last) = baru;
	}
}

void hapusLL(address1 *awal){
	address1 pencari = *awal;
	address1 akhir = lastLL(*awal);
	address1 temp;
	
	if(akhir == Nil){
		printf("Tidak ada list yang tersedia untuk dihapus");
	} else {
		if(akhir == *awal){
			free(*awal);
		}else{
			while (next(pencari) != akhir){
				pencari = next(pencari);
			}
			next(pencari) = Nil;
			free(akhir);
		}
	}
}


void buatJalur(char awal[], char akhir[], int jarak, char waktu[], address1 first) {
    address1 a;
    address1 b;
    address2 baru;
    char waktuKeberangkatan[20];
	
    a = caristasiun(awal, first);
    b = caristasiun(akhir, first);
    if (a == Nil || b == Nil) {
        printf("Maaf jalur tidak dapat dibuat dikarenakan stasiun tidak ada");
    } else {
        baru = alokasijalur();
        jarakJalur(baru) = jarak;
        strcpy(waktuKeberangkatan, waktu);
        tujuan(baru) = b;
        nextJalur(baru) = Nil;
        if (arc(a) == Nil) {
            arc(a) = baru;
        } else {
            address2 last = lastjalur(arc(a));
            nextJalur(last) = baru;
        }
    }
}

void reverseprint(address1 first){
	address1 head;
	address1 last;
	int i;
	
	i = 1;
	last = lastLL(first);
	head = first;
	printf("%d. %s\n",i ,namaStasiun(last));
	while(last != first){
		while (next(head) != last){
			head = next(head);
		}
		last = head;
		head = first;
		i++;
		printf("%d. %s\n",i, namaStasiun(last));
	}
}


void printStasiun(address1 first) {
    //Deklarasi//
    address1 sekarang = first;
	int i;
	
    //Algoritma//
    i=1;
    if (sekarang == NULL) {
        printf("Tidak ada stasiun lagi yang tersedia.\n");
        return;
    }

    printf("Stasiun Kereta Listrik di Korea Selatan:\n");
    while (sekarang != NULL) {
        printf("%d. %s\n", i,namaStasiun(sekarang));
        sekarang = next(sekarang);
        i++;
    }
}

bool cekSpasi(char *str) {
    while (*str) {
        if (*str == ' ') {
            return true; // Jika ada spasi, kembalikan true
        }
        str++;
    }
    return false; // Jika tidak ada spasi, kembalikan false
}

void registrasi(){
    akun customer;
    char b[5];
    FILE *akunC, *totalakunC;
    bool loop = true;
    int sementara;
    int a;
    
    a = 1;
    while (a == 1){
        printf("==============================================\n");
        printf("|                    Sign Up                 |\n");
        printf("==============================================\n\n");
        while (loop){
        	printf("==============================================\n");
        	printf("Masukkan Username : ");
        	scanf("%[^\n]s",customer.username);
        	if (!cekSpasi(customer.username)) {
        		loop = false;
			}else {
				printf("\n[!] ]Username tidak dapat mengandung spasi!\n");
				int c;
            	while ((c = getchar()) != '\n' && c != EOF) {}
			}
		}
        
        
        while (1) {
            printf("==============================================\n");
            printf("Masukkan Password (harus 8 karakter) : ");
            scanf("%s", customer.password);
            if (strlen(customer.password) >= 8) {
                break;
            } else {
                printf("Password minimal 8 karakter. Silakan coba lagi.\n");
            }
        }
        
        printf("-----------------------------------------------------------------------------");
        printf("\nUsername : %s \nPassword : %s\n", customer.username, customer.password);
        while (1) {
            printf("-----------------------------------------------------------------------------\n");
            printf("Apakah anda sudah yakin dengan username dan password ini ? (y/t) : ");
            scanf("%s", b);
            
            // Convert to lowercase for case-insensitive comparison
            int i;
            for(i = 0; b[i]; i++){
                b[i] = tolower(b[i]);
            }
            
            if (strcmp(b, "y") == 0 || strcmp(b, "t") == 0) {
                break;
            } else {
                printf("Input tidak valid, silakan masukkan 'y' untuk ya atau 't' untuk tidak.\n");
            }
        }
        
        if (strcmp(b, "y") == 0) {
            a = 0;
            akunC = fopen("akuncustomer.txt", "a");
            fprintf(akunC, "%s %s %d\n", customer.username, customer.password, 0);
            fclose(akunC);
            
            totalakunC = fopen("totalakuncustomer.txt", "r");
            fscanf(totalakunC, "%d", &sementara);
            fclose(totalakunC);
            
            sementara = sementara + 1;
            
            totalakunC = fopen("totalakuncustomer.txt", "w");
            fprintf(totalakunC, "%d", sementara);
            fclose(totalakunC);
            
            printf("Registrasi berhasil!\n");
        } else {
            printf("Silakan ulangi registrasi.\n");
        }
    }
}

int totalakunC(){
	FILE *totalakunC;
	int total = 0;
	totalakunC = fopen("totalakuncustomer.txt","r");
	fscanf(totalakunC,"%d",&total);
	fclose(totalakunC);
	return total;
}

bool login(char b[], char c[]) {
    int totalakun = totalakunC();
    akun customer;
    FILE *akunC;
    int i;
    
    akunC = fopen("akuncustomer.txt", "r");
    if (akunC == NULL) {
        printf("Error opening akuncustomer.txt\n");
        return false;
    }
    bool hasil = false;
    i=0;
    while (fscanf(akunC, "%s %s %d", &customer.username, &customer.password, &customer.eMoney) == 3) {
        if ((strcmp(b, customer.username) == 0) && (strcmp(c, customer.password) == 0)) {
            hasil = true;
            break;
        }
        i++;
    }
    fclose(akunC);
    return hasil;
}

void topup(char b[],char c[],int duid){
	int totalakun = totalakunC();
	akun customer[totalakun];
	FILE *akunC;
	akunC = fopen("akuncustomer.txt","r");
	int i = 0;
	while(i < totalakun){
		fscanf(akunC,"%s %s %d",customer[i].username,customer[i].password, &customer[i].eMoney);
		if (strcmp(b,customer[i].username)==0 && strcmp(c,customer[i].password)==0){
			customer[i].eMoney += duid;
		}
		i++;
	}
	fclose(akunC);
	i=0;
	akunC = fopen("akuncustomer.txt","w");
	while(i < totalakun){
		fprintf(akunC,"%s %s %d ",customer[i].username,customer[i].password, customer[i].eMoney);
		i++;
	}
	fclose(akunC);
}

int cekemoney(char b[],char c[]){
	int totalakun = totalakunC();
	akun customer;
	FILE *akunC;
	akunC = fopen("akuncustomer.txt","r");
    while (fscanf(akunC, "%s %s %d", &customer.username, &customer.password, &customer.eMoney) == 3) {
        if ((strcmp(b, customer.username) == 0) && (strcmp(c, customer.password) == 0)) {
            break;
        }
    }
	return customer.eMoney;
}

void buatFile(char nama[]) {
	FILE *baru;
	baru = fopen(nama,"r");
	if(baru==NULL){
		baru=fopen(nama,"w");
	}
	fclose(baru);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int harga(int lompatan,int jartot){
	int tiket;
	 
	tiket = lompatan * 1000;
	tiket *= jartot;
	return tiket;
}

void bayar(int biaya,char b[],char c[]){
	int totalakun = totalakunC();
	akun customer[totalakun];
	FILE *akunC;
	akunC = fopen("akuncustomer.txt","r");
	int i = 0;
	while(i < totalakun){
		fscanf(akunC,"%s %s %d",customer[i].username,customer[i].password, &customer[i].eMoney);
		if (strcmp(b,customer[i].username)==0 && strcmp(c,customer[i].password)==0){
			customer[i].eMoney -= biaya;
		}
		i++;
	}
	fclose(akunC);
	i=0;
	akunC = fopen("akuncustomer.txt","w");
	while(i < totalakun){
		fprintf(akunC,"%s %s %d ",customer[i].username,customer[i].password, customer[i].eMoney);
		i++;
	}
	fclose(akunC);
}


void pemetaan(address1 *first) {
    FILE *file;
    int kondisi, i, jarak;
    bool belok = false;
    char insert[20], insert2[20];
    char stack[5][20];
    char waktu[10];
    
	i = 0;
    file = fopen("Mapkrl.txt", "r");
    if (file == Nil) {
        printf("file tidak ada\n");
        return;
    }

    while (fscanf(file, "%s %d %s %d", insert, &kondisi, waktu, &jarak) != EOF) {
        if (kondisi != -2){
        	buatLL(first, insert);
		}

        if (next(*first) != Nil) {
            if (kondisi == -1) {
                buatJalur(stack[i-1], insert, jarak, waktu, *first);
                i--;
            } else if (kondisi == 1) {
            	strcpy(stack[i],insert);
            	i++;
                buatJalur(insert2, insert, jarak, waktu, *first);
            } else {
                buatJalur(insert2, insert, jarak, waktu, *first);
            }
        }
        strcpy(insert2, insert);
    }
    fclose(file);
}

node createNode(char stasiun[],int kilometer){
	node baru;
	baru = (node) malloc(sizeof (tercepat));
	strcpy(nama(baru),stasiun);
	jarak(baru) = kilometer;
	fs(baru) = Nil;
	nb(baru) = Nil;
	pr(baru) = Nil;
	return baru;
}

node nbakhir(node parent){
	node head = fs(parent);
	while(nb(head)!=Nil){
		head = nb(head);
	}
	return head;
}

void insert(node *root,int kilometer,char stasiun[],node *parent){
	node baru;
	node lastnb;
	baru = createNode(stasiun,kilometer);
	if(*root == Nil){
		*root = baru;
	}else{
		if(fs(*parent) == Nil){
			fs(*parent) = baru;
			pr(baru) = *parent;
		}else{
			pr(baru) = *parent;
			lastnb = nbakhir(*parent);
			nb(lastnb) = baru;
		}
	}
}

node graphToTree(address1 first, address1 awal) {
    address2 temp[5] = {NULL, NULL, NULL, NULL, NULL};
    address2 kilometer = arc(awal);
    node root;
    bool loop = true;
    bool boleh = false;
    bool pindah = false;
    int par = 0, nbro = 0;
    int i = 0, j = 0;
    int stack[10] = {0};
    int stack2[10] = {0};

    
    node parent = createNode(namaStasiun(awal), 0);
    root = parent;

    if (kilometer == NULL) {
        printf("Stasiun awal tidak dapat mencapai stasiun tujuan\n");
    } else {
        while (loop) {

            if (kilometer != NULL && arc(tujuan(kilometer)) != NULL && nextJalur(kilometer) != NULL) {
                insert(&root, jarakJalur(kilometer), namaStasiun(tujuan(kilometer)), &parent);
                temp[j] = nextJalur(kilometer);
                kilometer = arc(tujuan(kilometer));
                parent = fs(parent);
                j++;
                par = 1;
                nbro = 0;
                par = par + 1;
                stack[j] = par;
                stack2[j] = nbro+1;
                boleh = true;
            } else if (kilometer != NULL && arc(tujuan(kilometer)) != NULL && nextJalur(kilometer) == NULL) {
                insert(&root, jarakJalur(kilometer), namaStasiun(tujuan(kilometer)), &parent);
                kilometer = arc(tujuan(kilometer));
                parent = fs(parent);
                stack[j] = par++;
                stack2[j] = 0;
                if (pindah) {
                    for (i = 0; i <= stack2[j]; i++) {
                        parent = nb(parent);
                    }
                    pindah = false;
                }
            } else if (kilometer != NULL && arc(tujuan(kilometer)) == NULL && nextJalur(kilometer) != NULL) {
                insert(&root, jarakJalur(kilometer), namaStasiun(kilometer->tujuan), &parent);
                kilometer = nextJalur(kilometer);
            } else if (kilometer != NULL && arc(tujuan(kilometer)) == NULL && nextJalur(kilometer) == NULL && boleh) {
                insert(&root, jarakJalur(kilometer), namaStasiun(tujuan(kilometer)), &parent);
                for (i = 0 ; i < stack[j] ; i++) {
                    parent = pr(parent);
                }
                j--;
                kilometer = temp[j];
                if (j == 0){
                	boleh = false;
				}
                pindah = true;
            } else if (!boleh) {
                loop = false;
            }
        }
    }
    return root;
}

address1 djikstra(node root, char tujuan[], int *jartot) {
    bool boleh = true;
    int tercepat = 1000;
    int pembanding = 1001;
    node temp = NULL;
    node head = root;
    address1 first = Nil;


    while (head != NULL) {
        if (strcmp(nama(head), tujuan) == 0) {
            pembanding = jaraktotal(head, root);
            temp = head;
        }
        if (fs(head) != Nil && boleh) {
            head = fs(head);
        } else {
            if (nb(head) != Nil) {
                head = nb(head);
                boleh = true;
            } else {
                head = pr(head);
                boleh = false;
            }
            if (pembanding < tercepat) {
                tercepat = pembanding;
                *jartot = tercepat;
                if (first != Nil) {
                    hapusLL(&first);
                }
                while (temp != root) {
                    buatLL(&first, nama(temp));
                    temp = pr(temp);
                }
                buatLL(&first, nama(temp));
            }
        }
    }

    return first;
}

int jaraktotal(node tujuan,node root){
	node head;
	int total;
	
	total = 0;
	head = tujuan;
	while(head != root){
		total += jarak(head);
		head = pr(head);
	}
	total += jarak(head);
	return total;
}

int inputBener(int min, int max) {
    int num;
    char term;
    while (1) {
        if (scanf("%d%c", &num, &term) != 2 || term != '\n' || num < min || num > max) {
        	printf("----------------------------------------------------------------\n");
            printf("[!] ]Input tidak valid. Masukkan angka antara %d sampai %d: ", min, max);
            while (getchar() != '\n'); // Bersihkan buffer
        } else {
            return num;
        }
    }
}

int estimasiWaktuSampai(int jarak, char waktuKeberangkatan[]) {
    int jam, menit, kecepatanRataRata;
    sscanf(waktuKeberangkatan, "%d:%d", &jam, &menit);

    int waktuKeberangkatanDetik = jam * 3600 + menit * 60;

    time_t now;
    struct tm *local;
    time(&now);
    local = localtime(&now);

    int waktuSekarangDetik = local->tm_hour * 3600 + local->tm_min * 60 + local->tm_sec;

    double waktuTempuhDetik = (double) jarak / (double) kecepatanRataRata;
    int waktuSampaiDetik = waktuKeberangkatanDetik + waktuTempuhDetik;

	if (waktuSampaiDetik < waktuSekarangDetik) {
        waktuSampaiDetik += 24 * 3600;
    }

    int selisihDetik = waktuSampaiDetik - waktuSekarangDetik;
    int selisihMenit = selisihDetik / 60;

    return selisihMenit;
}

void menuLihatJadwal(address1 first) {
    address1 stasiun = first;
    while (stasiun != NULL) {
        address2 jalur = stasiun->arc;
        printf("Jadwal Keberangkatan dari Stasiun %s:\n", stasiun->namaStasiun);
        while (jalur != NULL) {
            printf("Tujuan: %s\nWaktu: %s\nEstimasi Waktu Sampai: %d menit\n", jalur->tujuan->namaStasiun, jalur->waktuKeberangkatan, estimasiWaktuSampai(jalur->jarakJalur, jalur->waktuKeberangkatan));
            jalur = jalur->nextJalur;
        }
        stasiun = stasiun->next;
    }
}

