#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "graphdinamis.h"
#include <time.h>

int main() {
	int pilihan, i;
    int cobaLogin = 0;
    int opsi, uang, saldo, jartot;
    char input[20], pw[20];
    char namaStasiun[20], tujuan[20];
    char choice[5], nominal[20];
    bool loop1, loop2;
    address1 first = Nil;
    address1 tercepat;
    node root = Nil;
    
    
    pemetaan(&first);
    loop1 = true;
    while (loop1) {
    	setColor(11);
        printf("==============================================================\n");
        printf("|                  Selamat Datang di MEWCL!                  |\n");
        printf("|                          LOGIN                             |\n");
        printf("==============================================================\n");
        printf("==============================================================\n");
        printf("1. Sign Up \n2. Sign In");
        printf("\n==============================================================\n");
        printf("Opsi Pilihan : ");
		opsi = inputBener(1,2);

        if (opsi == 1) {
        	system("cls");
            buatFile("totalakuncustomer.txt");
            registrasi();
            printf("\n=====================================================================================================================\n");
            printf("|                        Selamat! Akun anda berhasil terdaftar! Tekan enter untuk login.                            |\n");           
            printf("=====================================================================================================================");
            getchar();
            getchar();
            system("cls");
        }
		if (opsi == 2) {
            bool loop = true;
            while (loop) {
            	system("cls");
            	printf("==============================================\n");
		        printf("|                    Sign In                 |\n");
		        printf("==============================================\n\n");
		        printf("==============================================\n");
                printf("Masukan username : ");
                scanf("%s", input);
                printf("==============================================\n");
                printf("Masukan password : ");
                scanf("%s", pw);
                if (!login(input, pw)) {
		            printf("\n[!] Username atau Password salah!");
		            getchar();
		            getchar();
		            cobaLogin++;
            	if (cobaLogin >= 3) {
                	printf("\n[!] Anda telah gagal 3 kali.\nApakah anda sudah memiliki akun? (y/t) : ");
                
                	while (1) {
                    	scanf("%s", choice);
                    
                    	int i;
                    	for (i = 0; choice[i]; i++) {
                        choice[i] = tolower(choice[i]);
                    	}

                    	if (strcmp(choice, "y") == 0 || strcmp(choice, "t") == 0) {
                        	break;
                    	} else {
                        	printf("Input tidak valid, silakan masukkan 'y' untuk ya atau 't' untuk tidak: ");
                    }
                }

                if (strcmp(choice, "t") == 0) {
                    system("cls");
                    printf("Silahkan membuat akun terlebih dahulu dengan sign up.\n");
                    loop = false;
                } else {
                    cobaLogin = 0; 
                	}
            	}
                } else {
                    printf("\nSelamat! anda berhasil login. Selamat datang.");
                    loop = false;
                    getchar();
                    getchar();
                    system("cls");
                    loop2 = true;
                    while (loop2) {
                    	saldo = cekemoney(input, pw);
                    	setColor(11);
                    	time_t now;
	    				time(&now);
	
					    // Mengonversi waktu ke dalam struktur tm
					    struct tm *local = localtime(&now);
                    	printf("\n==============================================================\n");
                    	printf("!              M   M  EEEEE  W   W  CCCC  L                  !\n");
					    printf("!              MM MM  E      W W W  C     L                  !\n");
					    printf("!              M M M  EEEE   W W W  C     L                  !\n");
					    printf("!              M   M  E      W W W  C     L                  !\n");
					    printf("!              M   M  EEEEE   W W   CCCC  LLLLL              !\n");
					    printf("==============================================================\n");
                        printf("\n==============================================================\n");
                        printf("|                  Selamat Datang di MEWCL!                  |\n");
                        printf("|          Pencarian Rute Kereta Listrik Tercepat!           |\n");
                        printf("==============================================================\n\n");
                        printf("Jam: %02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);
                        printf("Saldo anda saat ini Rp. %d\n\n", saldo);
                        printf("1. Tampilkan seluruh stasiun.\n");
                        printf("2. Lihat Jadwal dan Perkiraan\n");
                        printf("3. Pilih stasiun awal.\n");
                        printf("4. TopUp MEWpay.\n");
                        printf("5. Logout.\n");
                        printf("6. Keluar\n");
                        printf("\nPilihan anda : ");
                        pilihan = inputBener(1,5);

                        switch (pilihan) {
                        	saldo = cekemoney(input, pw);
                            case 1:
                            	system("cls");
                                printStasiun(first);
                                break;
                            case 2:
                            	menuLihatJadwal(first);
                            	break;
							case 3:
								system("cls");
                                printStasiun(first);
                                printf("Pilih stasiun awal anda : ");
                                opsi = inputBener(1, 20);
                                if (opsi < 1 || opsi > 20) {
                                	printf("\nPilihan tidak valid! Pilih angka sesuai list stasiun diatas! \n\n");
                                	getchar();
                                	system("pause");
                                	system("cls");
								} else {
	                                address1 temp;
	                                address1 awal;
	                                awal = first;
									temp = first;
									int i,nilai;
									for(i = 0; i < opsi;i++){
										temp = next(temp);
									}
									while(next(awal)!=temp){
										awal = next(awal);
									}
	                                if (caristasiun(namaStasiun(temp), first)) {
	                                	system("cls");
	                                   	printStasiun(temp);
	                                   	printf("\n\nPilih Stasiun tujuan anda : ");
	                                   	opsi = inputBener(1, 20-opsi);
	                                   	if (opsi > 19) {
	                                   		printf("\nPilihan tidak valid! Pilih angka sesuai list stasiun diatas! \n\n");
		                                	getchar();
		                                	system("pause");
		                                	system("cls");
										}
										for(i = 0; i < opsi-1;i++){
											temp = next(temp);
											}
	                                   	// Dijkstra
	                                   	system("cls");
	                                   	printf("\nJalur tercepat : \n");
	                                   	root = graphToTree(first,awal);
	                                   	tercepat = djikstra(root,namaStasiun(temp),&jartot);
	                                   	reverseprint(tercepat);
	                    				printf("\nJarak total yang ditempuh : %d Km\n", jartot);
	                    				
	                                   	// Bayar
	                                   	nilai = harga(opsi,jartot);
	                                   	printf("\nHarga tiket yang harus dibayar : Rp. %d", nilai);
	                                   	printf("\n\nSaldo anda saat ini Rp. %d\n\n", saldo);
		                                   	if(saldo < nilai){
		                                   		printf("\n[!] Harap top up terlebih dahulu saldo anda kurang...");
		                                   		getchar();
		                                   		system("cls");
	                                   		}else {
	                                   			printf("\nApakah anda ingin bayar sekarang ? (y/t) : ");
		                                		scanf("%s", choice);
											   if (strcasecmp(choice,"y") == 0){
			                                   		bayar(nilai,input,pw);
			                                   		printf("\n[!] PEMBAYARAN SUCCESS");
			                                   		printf("\n\nTekan enter untuk kembali ke main menu...");
			                                   		getchar();
			                                   		getchar();
		                                   			system("cls");
												}else if(strcasecmp(choice, "t") == 0) {
													printf("\nAnda akan kembali ke main menu...");
													getchar();
													getchar();
													system("cls");
												}
											}
									
	                                } else {
	                                    printf("Stasiun tidak ditemukan!");
	                                }
	                            }
                 			break;
                            case 4:
                                printf("\nAnda ingin TopUp Berapa?\n");
                                printf("Masukkan nominal : ");
                                
                                while (1) {
                                	scanf("%s", nominal);
							            if (sscanf(nominal, "%d", &uang) == 1) {
							            	if (uang < 0) {
							            		printf("[!] Input tidak valid!\n");
							            		printf("Masukkan nominal : ");
											} else{
												saldo += uang;
								                topup(input, pw, uang);
								                break;
											}
							            } else {
							                printf("[!] Input tidak valid.\n");
							                printf("Masukkan nominal : ");
							            }
							    }
							    printf("\nTekan enter untuk kembali ke main menu");
							    getchar();
							    getchar();
							    system("cls");
                                break;
                            case 5:
                                loop2 = false;
                                system("cls");
                                break;
                            case 6:
                                printf("Terima kasih telah menggunakan Aplikasi MEWCL!");
                                loop2 = false;
                                loop1 = false;
                                break;
                            default:
                                printf("Pilihan tidak valid! Masukkan angka 1-5\n");
                                break;
                        }
                    }
                }
            }
        } else if (opsi != 1 && opsi != 2) {
            printf("\nPilihan tidak valid (PILIH ANGKA 1-2!)\n");
        }
    }
    return 0;
}
