#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>


// thong tin cua 1 Nhan Vien
typedef struct {
	char manv[10];
	char tennv[30];
	int tuoi;
	char gt[4];
	char sdt[11];
	char diachi[100];
} NhanVien;
// thong tin cua 1 khach hang
typedef struct {
	char makh[10];
	char tenkh[30];
	int tuoi;
	char gt[4];
	char sdt[11];
	char ngaydat[20];
	char diachi[100];
} KhachHang;
// thong tin cua 1 hoa don dat
typedef struct {
	char mahd[10];
	char manv[10];
	char tennv[30];
	char makh[10];
	char tenkh[30];
	char ngaydat[20];
	char ngaygiao[20];
} HoaDonDat;
// thong tin cua 1 Bang luong
typedef struct {
	char manv[10];
	char tennv[30];
	float tglv;
	float sddg;
	float tglt;
	float lcb;
	float llt;
	float ttl;
} BangLuong;

// ========================================================= FILE ============================================================================
//=========== Ghi, Doc File Nhan Vien ======================
void GhiFile_NhanVien(NhanVien dsnv[], int slnv) {
	FILE* f;
	f = fopen("DSNV.dat", "wb");
	for (int i = 0; i < slnv; i++) {
		NhanVien nv = dsnv[i];
		fwrite(&nv, sizeof(NhanVien), 1, f);
	}
	fclose(f);
}
void DocFile_NhanVien(NhanVien dsnv[], int* slnv) {
	FILE* f;
	int i = 0;
	f = fopen("DSNV.dat", "rb");
	if (f) {
		while (!feof(f)) {
			NhanVien nv;
			fread(&nv, sizeof(NhanVien), 1, f);
			if (!feof(f))
				dsnv[i++] = nv;
		}
	}
	fclose(f);
	*slnv = i;
}
//=========== Ghi, Doc File Khach H�ng ======================
void GhiFile_KhachHang(KhachHang dskh[], int slkh) {
	FILE* f;
	f = fopen("DSKH.dat", "wb");
	for (int i = 0; i < slkh; i++) {
		KhachHang kh = dskh[i];
		fwrite(&kh, sizeof(KhachHang), 1, f);
	}
	fclose(f);
}
void DocFile_KhachHang(KhachHang dskh[], int* slkh) {
	FILE* f;
	int i = 0;
	f = fopen("DSKH.dat", "rb");
	if (f) {
		while (!feof(f)) {
			KhachHang kh;
			fread(&kh, sizeof(KhachHang), 1, f);
			if (!feof(f))
				dskh[i++] = kh;
		}
	}
	fclose(f);
	*slkh = i;
}
//=========== Ghi, Doc File Hoa Don Dat ======================
void GhiFile_HoaDon(HoaDonDat dshd[], int slhd) {
	FILE* f;
	f = fopen("DSHD.dat", "wb");
	for (int i = 0; i < slhd; i++) {
		HoaDonDat hd = dshd[i];
		fwrite(&hd, sizeof(HoaDonDat), 1, f);
	}
	fclose(f);
}
void DocFile_HoaDon(HoaDonDat dshd[], int* slhd) {
	FILE* f;
	int i = 0;
	f = fopen("DSHD.dat", "rb");
	if (f) {
		while (!feof(f)) {
			HoaDonDat hd;
			fread(&hd, sizeof(HoaDonDat), 1, f);
			if (!feof(f))
				dshd[i++] = hd;
		}
	}
	fclose(f);
	*slhd = i;
}
//=========== Ghi, Doc File Bang Luong ======================
void GhiFile_BangLuong(BangLuong dsbl[], int slbl) {
	FILE* f;
	f = fopen("DSBL.dat", "wb");
	for (int i = 0; i < slbl; i++) {
		BangLuong bl = dsbl[i];
		fwrite(&bl, sizeof(BangLuong), 1, f);
	}
	fclose(f);
}
void DocFile_BangLuong(BangLuong dsbl[], int* slbl) {
	FILE* f;
	int i = 0;
	f = fopen("DSBL.dat", "rb");
	if (f) {
		while (!feof(f)) {
			BangLuong bl;
			fread(&bl, sizeof(BangLuong), 1, f);
			if (!feof(f))
				dsbl[i++] = bl;
		}
	}
	fclose(f);
	*slbl = i;
}

void XoaDauCachThua(char str[]){ 
	if(strlen(str) == 0){
		return;
	} 
	// xoa o dau chuoi
	while(str[0] == ' '){
		for(int i = 0; i < strlen(str); i++) {
			str[i] = str[i+1];
			if(str[0] == '\0') return;
		}
	} 
	// xoa o cuoi chuoi
	int i = strlen(str)-1;
	while(str[i] == ' ') {
		str[i] = str[i+1];
		i--;
	} 
	// xoa o giua chuoi
	for(int i = 0; i < strlen(str) - 1; i++){
		if(str[i] != ' ' && str[i+1] == ' ' && str[i+2] == ' ') {
			for(int j = i+1; j < strlen(str); j++) {
				str[j] = str[j+1];
			}
			i--;
		}
	} 
} 

void XoaDauCach(char str[]){
	if(strlen(str) == 0){
		return;
	}
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == ' ') {
			for(int j = i; j < strlen(str)-1; j++) {
				str[j] = str[j+1];
			}
			i--;
		}
	} 
}

void VietHoa(char str[]){
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        if (str[i - 1] == ' ' || i == 0){
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
    }
}

void ChuanHoaChuoi(char str[]) {
	if(strlen(str)==0) return;
	XoaDauCachThua(str); VietHoa(str);
}


int KiemTraSo(char str[]){
	if(strlen(str) == 0) return 0;
    for( int i = 0; i <= strlen(str); i++){
        if (str[i] != '\0'){
        	if(str[i] < 48 || str[i] > 57){ // 0 -> 9
        		return 0;	
			}
		}
    }
    return 1;
}

int KiemTraThu(char str[]){
	if(strlen(str) == 0) return 0;
    for( int i = 0; i <= strlen(str); i++){
        if (str[i] != '\0'){
        	if(str[i] < 50 || str[i] > 55){ // 2 -> 7
        		return 0;	
			}
		}
    }
    return 1;
}

int KiemTraChu(char str[]){
	if(strlen(str) == 0) return 0;
    for(int i = 0; i <= strlen(str); i++){ 
        if(str[i] !='\0'){ 
            if((str[i]<65 || str[i] >90) && (str[i]<97 || str[i]>122) && (str[i]<32 || str[i]>32)){
            	return 0;
			}
		}
    }
    return 1;
}

// ======================= KIEM TRA NGAY ===================== 
bool KT_CauTrucNgayDung(char str[]){
	if(strlen(str)==0){
	 	return false;
	}
	else{
		if(str[10] != '\0') return false;
	}
	for (int i = 0; i < strlen(str); i++ ){
		if(i == 2 || i == 5){
			if(str[i] != '/'){
				return false;
			}
		}
		else { 
			if(48 > str[i] || str[i] > 57 ){
				return false;
			} 
		}
	}
 	return true;
}

int CheckNamNhuan(int nam){
	if(nam % 400 == 0) return 1;
  	else {
    	if(nam % 100 == 0) return 0;
    	else {
         	if(nam % 4 == 0) return 1;
         	else return 0;
    	}
 	}
} 

bool KTNgayChuan(char str[]){ 
	if(KT_CauTrucNgayDung(str) == false) return false;
	char d[3]; char m[3]; char y[5];
	d[0] = str[0]; d[1] = str[1]; d[2] = '\0'; int ngay = atoi(d);
	m[0] = str[3];  m[1] = str[4]; m[2] = '\0'; int thang = atoi(m);
	y[0] = str[6]; y[1] = str[7]; y[2] = str[8]; y[3] = str[9] ; y[4] = '\0'; int nam = atoi(d);
	if(ngay < 1 || ngay > 31 || thang < 1 || thang > 12){
		return false;
	}
    else {
        if(thang == 4 || thang == 6 || thang == 9 || thang == 11) { //thang co 30 ngay
            if(ngay == 31) return false; 
        }
        else if(thang == 2){
            if(ngay > 29)
                return false;  //thang 2 co nhieu nhat la 29 ngay
            else if(ngay == 29)
            {
                if(CheckNamNhuan(nam) == 0)
                 	return false;
            }
        }
    }
	return true;
} 

//========================================================================== HIEN THI ====================================================================

//=================================== HIEN THI THONG TIN HOC VIEN ====================
void HienThiCot_NhanVien() {
	printf("============================================================================================================================================\n");
	printf("| %-10s | %-30s | %-12s | %-10s | %-10s | %-50s|\n", "MaNV", "Ten NV", "Tuoi", "Gioi Tinh", "SDT", "Dia Chi");
	printf("============================================================================================================================================\n");
}
void HienThiTT_NhanVien(NhanVien dsnv[], int slnv) {
	HienThiCot_NhanVien();
	for (int i = 0; i < slnv; i++) {
		printf("| %-10s | %-30s | %-12d | %-10s | %-10s | %-50s|\n", dsnv[i].manv, dsnv[i].tennv, dsnv[i].tuoi, dsnv[i].gt, dsnv[i].sdt, dsnv[i].diachi);
		printf("____________________________________________________________________________________________________________________________________________\n");
	}
}


// ================================= HIEN THI THONG TIN KHACH HANG ====================
void HienThiCot_KhachHang() { 
	printf("==============================================================================================================================================================\n");
	printf("\n| %-10s | %-30s | %-10s | %-10s | %-12s | %-50s | %-50s|\n", "MaKH", "Ten KH", "Tuoi", "Gioi Tinh", "SDT", "Ngay Dat", "Dia Chi");
	printf("==============================================================================================================================================================\n");
}
void HienThiTT_KhachHang(KhachHang dskh[], int slkh) {
	HienThiCot_KhachHang();
	for (int i = 0; i < slkh; i++) {
		printf("\n| %-10s | %-30s | %-10d | %-10s | %-12s | %-50s | %-50s|\n", dskh[i].makh, dskh[i].tenkh, dskh[i].tuoi, dskh[i].gt, dskh[i].sdt, dskh[i].ngaydat, dskh[i].diachi);
		printf("______________________________________________________________________________________________________________________________________________________________\n");
	}
	printf("\n");
}
void HienThiCot_HoaDon(){
	printf("==========================================================================================================================================\n");
	printf("| %-10s | %-10s | %-30s | %-10s | %-30s | %-50s | %-50s |\n","MaHD", "MaNV","TenNV", "  MAKH", "TenKH", "Ngay Dat","Ngay Giao");
	printf("==========================================================================================================================================\n");
}
void HienThiTT_HoaDon(HoaDonDat dshd[],int slhd){
	HienThiCot_HoaDon();
	for(int i = 0; i<slhd; i++){    
		printf("| %-10s | %-10s | %-30s | %-10s | %-30s | %-50s | %-50s |\n",dshd[i].mahd, dshd[i].manv, dshd[i].tennv, dshd[i].makh, dshd[i].tenkh, dshd[i].ngaydat, dshd[i].ngaygiao);
		printf("__________________________________________________________________________________________________________________________________________\n");				
	}
}
void HienThiCot_BangLuong() {
	printf("==================================================================================================================================================================================================================\n");
	printf("| %-10s | %-30s | %-15s | %-27s | %-10s | %-25s | %-25s | %-25s \n", "MaNV", "   Ten NV", "Thoi gian lam", " So luong don da giao", "Thoi gian lam them", "Luong co ban","Luong lam them", "Tong tien luong");
	printf("==================================================================================================================================================================================================================\n");
}
void HienThiTT_BangLuong(BangLuong dsbl[], int slbl) {
	HienThiCot_BangLuong();
	for (int i = 0; i < slbl; i++) {  
			printf("| %-10s | %-30s | %-15s | %-27s | %-10s | %-25s | %-25s | %-25s \n", dsbl[i].manv, dsbl[i].tennv, dsbl[i].tglv, dsbl[i].sddg, dsbl[i].tglt, dsbl[i].lcb, dsbl[i].llt, dsbl[i].ttl);
			printf("_______________________________________________________________________________________________________________________________________________________________________________\n");
		}
}


// Hien thi 
void HienThi(NhanVien dsnv[], int slnv, KhachHang dskh[], int slkh, HoaDonDat dshd[], int slhd, BangLuong dsbl[], int slbl ){
	int chon;
	do{
		system("cls");
		printf("\n______________________ Hien Thi __________________________\n");
		printf("|                                                         |\n");
		printf("|      1.  Hien Thi Thong Tin Cua Cac Nhan Vien           |\n");
		printf("|      2.  Hien Thi Thong Tin Cua Cac Khach Hang          |\n");
		printf("|      3.  Hien Thi Thong Tin Cua Cac Hoa Don Dat         |\n");
		printf("|      4.  Hien Thi Thong Tin Bang Luong                  |\n");
 		printf("|      0.  Thoat Hien Thi                                 |\n");
		printf("|_________________________________________________________|\n");
		printf("                    Lua Chon cua Ban: ");
		scanf("%d",&chon);
		switch(chon){
			case 0:
				break;
			case 1:
				printf("\n\n\t\t\t\t\t\tTHONG TIN NHAN VIEN\n");
				HienThiTT_NhanVien(dsnv, slnv);
				system("pause");
				break;
			case 2:
				printf("\n\n\t\t\t\t\t\tTHONG TIN KHACH HANG\n");
				HienThiTT_KhachHang(dskh, slkh);
				system("pause");
				break;
			case 3:
				printf("\n\n\t\t\t\t\t\tTHONG TIN VE CAC HOA DON\n");
				HienThiTT_HoaDon(dshd, slhd );
				system("pause");
				break;
			case 4:
				printf("\n\n\t\t\t\t\t\t\tTHONG TIN BANG LUONG\n");
				HienThiTT_BangLuong(dsbl, slbl );
				system("pause");
				break;
			default: 
				printf("\nNhap sai! Moi ban nhap lai\n");
				system("pause");
				break;
		}
	}while(chon); 
	return;
}
//============================================================ QUAN LY THONG TIN ===============================================

// ================================ QUAN LY THONG TIN NHAN VIEN =========================
// ==============  Nhap Thong Tin 1 Nhan Vien ===================== 
NhanVien Nhap1TT_NhanVien(NhanVien dsnv[], int slnv) {
	NhanVien nv;
	bool check = false;
	do {
		check = true;
		printf("\nMa Nhan Vien: "); fflush(stdin); gets(nv.manv);
		XoaDauCach(nv.manv);
		if(strlen(nv.manv)==0){
			printf("\n=> Ma Nhan Vien Khong Hop Le. Moi Nhap Lai !");
			check = false;
		}
		for (int i = 0; i < slnv; i++) {
			if (strcmp(dsnv[i].manv, nv.manv) == 0) {
				printf("\n=> Ma Nhan Vien Da Ton Tai. Moi Nhap Lai !");
				check = false;
			}
		}
	} while (check == false);
	do{
 		printf("Ho Ten Nhan Vien: "); fflush(stdin); gets(nv.tennv); 
 		ChuanHoaChuoi(nv.tennv);
 		if(KiemTraChu(nv.tennv) == 1){
 			break;
		} 
		printf("\n=> Ho Ten Khong Hop Le. Moi Nhap Lai !\n"); 
	}while(true);
	
	do{ 
 		printf("Tuoi: "); fflush(stdin); scanf("%d",&nv.tuoi);  
		if(nv.tuoi > 17){
			break;
		}
		printf("\n=> Ngay Sinh Khong Hop Le. Vui Long Nhap Dung Tuoi Duoc La Dong !\n"); 
	}while(true);

 	do{
 		fflush(stdin); printf("Gioi Tinh: "); gets(nv.gt);
 		XoaDauCach(nv.gt);VietHoa(nv.gt);
 		if(strcmp(nv.gt,"Nam")==0 || strcmp(nv.gt,"Nu")==0){ 
 			break;
		} 
		printf("\n=> Gioi Tinh (Nam/Nu). Moi Nhap Lai\n"); 
	}while(true);
	
	do{
 		fflush(stdin);printf("So Dien Thoai: "); gets(nv.sdt);
 		XoaDauCach(nv.sdt);
 		if(strlen(nv.sdt)==10 && KiemTraSo(nv.sdt) == 1){
 			break;
		} 
		printf("\n=> So Dien Thoai Khong Hop Le. Moi Ban Nhap Lai!\n"); 
	}while(true); 
	
 	do{
 		fflush(stdin);printf("Dia Chi: "), gets(nv.diachi);
 		ChuanHoaChuoi(nv.diachi);
 		if(strlen(nv.diachi)!=0){ 
 			break;
		} 
		printf("\n=> Dia Chi Khong Hop Le. Moi Nhap Lai !\n"); 
	}while(true);
	
	return nv;
}
// ========================= Tim Kiem 1 Nhan Vien ==========================
int timkiem_nhanvien(NhanVien dsnv[], int slnv, char str[10]){
	int check = -1;
	for (int i = 0; i < slnv; i++) {
		if (strcmp(dsnv[i].manv, str) == 0) {
			check = i;
			printf("\n\t\t\t\t\t\tTHONG TIN NHAN VIEN CAN TIM\n");
			HienThiCot_NhanVien();
			printf("| %-10s | %-30s | %-12s | %-10s | %-10s | %-50s|\n", dsnv[i].manv, dsnv[i].tennv, dsnv[i].tuoi, dsnv[i].gt, dsnv[i].sdt, dsnv[i].diachi);
			printf("____________________________________________________________________________________________________________________________________________\n");
			break;
		}
	}
	return check;
}
void TimKiem_NhanVien(NhanVien dsnv[], int slnv) {
	printf("\n\t\t\t\t\t\tTHONG TIN HOC VIEN\n");
	HienThiTT_NhanVien(dsnv, slnv);
	char manvCanTim[10]; 
	printf("Nhap Ma Nhan Vien Can Tim: "); scanf("%s", &manvCanTim);
	int check = timkiem_nhanvien(dsnv,slnv, manvCanTim);
	if (check == -1) {
		printf("\nKhong Tim Thay Hoc Vien\n");
		return;
	}	
}
//=============== CAP NHAP THONG TIN Nhan Vien =================================
void CapNhapTT_NhanVien(NhanVien dsnv[], int slnv, BangLuong dsbl[], int slbl, HoaDonDat dshd[], int slhd) { 
	char key[5];
	do{
		printf("Nhap Phim Bat De Tiep Tuc Hoac Enter De ket Thuc: ");
		fflush(stdin); gets(key); 
		if(strcmp(key,"")==0){
			break;
		}
		system("cls");
		printf("\n\t\t\t\t\t\tDanh Sach Nhan Vien\n");
		HienThiTT_NhanVien(dsnv, slnv);
		char manvCanCapNhap[10]; 
		printf("Nhap Ma Giao Vien Can Cap Nhap: "); scanf("%s", &manvCanCapNhap);
	  	int check = timkiem_nhanvien(dsnv, slnv, manvCanCapNhap);
	  	if(check == -1){
	  		printf("\nKhong Tim Thay Nhan Vien Can Sua\n"); 
		}
		else{ 
			char key[5];
			printf("Ban Co Chac Chan Muon Sua Khong? (y): ");
			fflush(stdin); gets(key);
			if(strcmp(strlwr(key),"y")!=0){
				printf("\nThong Tin Chua Duoc Sua\n"); 
			}
			else{ 
				NhanVien nv;
				strcpy(nv.manv, manvCanCapNhap);
				do{ 
					printf("Ho Ten Nhan Vien: "); fflush(stdin); gets(nv.tennv);
					ChuanHoaChuoi(nv.tennv);
					if(KiemTraChu(nv.tennv) == 1){ 
						break;
					}
					printf("\n=> Ho Ten Nhan Vien Khong Hop Le. Moi Nhap Lai !\n");
				}while(true);
				
				do{ 
			 		printf("Tuoi: "); fflush(stdin); scanf("%d",&nv.tuoi) ;
					if(nv.tuoi >= 18){
						break;
					}
					printf("\n=> Tuoi Khong Hop Le. Vui Long Nhap Dung Tuoi > 18 !\n"); 
				}while(true);
			  
				do{
			 		printf("Gioi Tinh: "); fflush(stdin); gets(nv.gt);
			 		XoaDauCach(nv.gt);VietHoa(nv.gt);
			 		if(strcmp(nv.gt,"Nam")==0 || strcmp(nv.gt,"Nu")==0){ 
			 			break;
					} 
					printf("\n=> Gioi Tinh (Nam/Nu). Moi Nhap Lai\n");
				}while(true);
			 	
				do{
					fflush(stdin);printf("So Dien Thoai: "); gets(nv.sdt);
					XoaDauCach(nv.sdt);
					if(strlen(nv.sdt)==10 && KiemTraSo(nv.sdt) == 1){
						break;
					} 
					printf("\n=> So Dien Thoai Khong Hop Le. Moi Ban Nhap Lai!\n"); 
				}while(true);
				
				do{
			 		fflush(stdin);printf("Dia Chi: "), gets(nv.diachi);
			 		ChuanHoaChuoi(nv.diachi);
			 		if(strlen(nv.diachi)!=0){ 
			 			break;
					}
					printf("\n=> Dia Chi Khong Hop Le. Moi Nhap Lai\n");
				}while(true);
				dsnv[check] = nv; 
				for (int j = 0; j < slhd; j++) {
					if (strcmp(dshd[j].manv, dshd[check].manv) == 0) {
						strcpy(dshd[j].tennv, dsnv[check].tennv); 
					}
				}
				for (int k = 0; k < slbl; k++) {
					if (strcmp(dsbl[k].manv, dsbl[check].manv) == 0) {
						strcpy(dsbl[k].tennv, dsnv[check].tennv); 
					}
				}
				
				GhiFile_NhanVien(dsnv,slnv);
				GhiFile_HoaDon(dshd,slhd);
				GhiFile_BangLuong(dsbl,slbl);
				printf("\nCap Nhap Thanh Cong\n");
				printf("\t\t\t\t\t\tDanh Sach Giao Vien Sau Khi Sua\n");
				HienThiTT_NhanVien(dsnv, slnv); 
			}
		}
	}while(true); 
	return;
}
// ==================== Xoa thong tin nhan vien ============
void XoaTT_NhanVien(NhanVien dsnv[], int* slnv, BangLuong dsbl[], int* slbl, HoaDonDat dshd[], int* slhd){
	char key[5];
	do{
		printf("Nhap Phim Bat De Tiep Tuc Hoac Enter De ket Thuc: ");
		fflush(stdin); gets(key); 
		if(strcmp(key,"")==0){
			break;
		}
		system("cls");  
		printf("\n\t\t\t\t\t\tDanh Sach Nhan Vien\n");
		HienThiTT_NhanVien(dsnv, *slnv);
		char manvCanXoa[10]; 
		printf("Nhap MaNV Can Xoa: "); scanf("%s", &manvCanXoa);
		int check = timkiem_nhanvien(dsnv, *slnv, manvCanXoa);
		if(check == -1){
			printf("\nKhong Tim Thay Giao Vien Can Xoa\n"); 
		}
		else{  
			printf("Ban Co Chac Chan Muon Xoa Khong ? (y): ");
			fflush(stdin); gets(key);
			if(strcmp(strlwr(key),"y")!=0){
				printf("\nThong Tin Nhan Vien Chua Duoc Xoa\n");
			}
			else{
				for (int j = check; j < *slnv - 1; j++) {
					dsnv[j] = dsnv[j + 1];
				}
				*slnv = *slnv - 1;  
				for (int i = 0; i < *slhd; i++) {
					if (strcmp(dshd[i].manv, manvCanXoa) == 0) {
						for(int j= i; j<*slhd; j++)
 							dshd[j] = dshd[j + 1];
 					}
 					i--;
				}
				*slhd--;
				for (int i = 0; i < *slbl; i++) {
					if (strcmp(dsbl[i].manv, manvCanXoa) == 0) {
						for(int j= i; j<*slbl; j++)
 							dsbl[j] = dsbl[j + 1];
 					}
 					i--;
				}
				*slbl--;
				printf("\nDa Xoa Thong Tin Giao Vien\n");
				printf("\n\t\t\t\t\t\tDanh Sach Giao Vien Sau Khi Xoa\n");
				HienThiTT_NhanVien(dsnv, *slnv);
				GhiFile_NhanVien(dsnv, *slnv);
				GhiFile_HoaDon(dshd, *slhd);
				GhiFile_BangLuong(dsbl,*slbl);
				
			} 
		} 
	}while(true);
	return;
}
void QuanLyTT_NhanVien(NhanVien dsnv[], int* slnv, KhachHang dskh[], int* slkh, HoaDonDat dshd[], int* slhd, BangLuong dsbl[], int* slbl) {
	int chon;
	do {
		system("cls");
		printf("\n_____________ Quan Ly Nhan Vien ___________");
		printf("\n|                                         |");
		printf("\n|    1. Them Nhan Vien Moi                |");
		printf("\n|    2. Cap Nhap Lai Thong Tin Nhan Vien  |");
		printf("\n|    3. Xoa Thong Tin Nhan Vien           |");
		printf("\n|    0. Thoat Quan Ly Nhan Vien           |");
		printf("\n|_________________________________________|");
		printf("\n           Lua chon cua ban ");
		scanf("%d", &chon);
		switch (chon) {
		case 0:
			break;
		case 1:
		{  
			char key[5];
			do{
				printf("Nhap Phim Bat De Tiep Tuc Hoac Enter De ket Thuc: ");
				fflush(stdin); gets(key); 
				if(strcmp(key,"")==0){
					break;
				} 
				printf("\nThem Thong Tin Nhan Vien Thu %d ", *slnv + 1);
				NhanVien nv = Nhap1TT_NhanVien(dsnv, *slnv);
				dsnv[(*slnv)++] = nv;
				GhiFile_NhanVien(dsnv, *slnv);
				printf("\nThem Thanh Cong\n"); 
			}while(true); 
			break;
		}
		case 2: 
			CapNhapTT_NhanVien(dsnv, *slnv, dsbl, *slbl,dshd, *slhd);
			break; 
		case 3: 
			XoaTT_NhanVien(dsnv, &(*slnv),dsbl, &(*slbl),dshd, &(*slhd));
			break;  
		default:
			printf("\nNhap Sai Moi Ban Nhap Lai\n");
			break;
		}
	} while (chon);
	return;
}
// ================================ QUAN LY THONG TIN Khach Hang =========================
// ==============  Nhap Thong Tin 1 Khach Hang ===================== 
KhachHang Nhap1TT_KhachHang(KhachHang dskh[], int slkh) {
	KhachHang kh;
	bool check = false;
	do {
		check = true;
		printf("\nMa Khach Hang: "); fflush(stdin); gets(kh.makh);
		XoaDauCach(kh.makh);
		if(strlen(kh.makh)==0){
			printf("\n=> Ma Nhan Vien Khong Hop Le. Moi Nhap Lai !");
			check = false;
		}
		for (int i = 0; i < slkh; i++) {
			if (strcmp(dskh[i].makh, kh.makh) == 0) {
				printf("\n=> Ma Khach Hang Da Ton Tai. Moi Nhap Lai !");
				check = false;
			}
		}
	} while (check == false);
	do{
 		printf("Ho Ten Khach Hang: "); fflush(stdin); gets(kh.tenkh); 
 		ChuanHoaChuoi(kh.tenkh);
 		if(KiemTraChu(kh.tenkh) == 1){
 			break;
		} 
		printf("\n=> Ho Ten Khong Hop Le. Moi Nhap Lai !\n"); 
	}while(true);
	
	do{ 
 		printf("Tuoi: "); fflush(stdin); scanf("%d",&kh.tuoi);  
		if(kh.tuoi > 14){
			break;
		}
		printf("\n=> Tuoi Khong Hop Le. Vui Long Nhap Dung Tuoi  !\n"); 
	}while(true);

 	do{
 		fflush(stdin); printf("Gioi Tinh: "); gets(kh.gt);
 		XoaDauCach(kh.gt);VietHoa(kh.gt);
 		if(strcmp(kh.gt,"Nam")==0 || strcmp(kh.gt,"Nu")==0){ 
 			break;
		} 
		printf("\n=> Gioi Tinh (Nam/Nu). Moi Nhap Lai\n"); 
	}while(true);
	
	do{
 		fflush(stdin);printf("So Dien Thoai: "); gets(kh.sdt);
 		XoaDauCach(kh.sdt);
 		if(strlen(kh.sdt)==10 && KiemTraSo(kh.sdt) == 1){
 			break;
		} 
		printf("\n=> So Dien Thoai Khong Hop Le. Moi Ban Nhap Lai!\n"); 
	}while(true); 
	do{ 
		printf("Ngay Dat Hang(DD/MM/YYYY): "); fflush(stdin); gets(kh.ngaydat); 
		XoaDauCach(kh.ngaydat);
		if(KTNgayChuan(kh.ngaydat) == true){
				break;
		}
	printf("\n=> Ngay Dat Hang Khong Hop Le. Vui Long Nhap Dung Dinh Dang Ngay !\n"); 
	}while(true);
 	do{
 		fflush(stdin);printf("Dia Chi: "), gets(kh.diachi);
 		ChuanHoaChuoi(kh.diachi);
 		if(strlen(kh.diachi)!=0){ 
 			break;
		} 
		printf("\n=> Dia Chi Khong Hop Le. Moi Nhap Lai !\n"); 
	}while(true);
	
	return kh;
}
// ========================= Tim Kiem 1 Khach Hang ==========================
int timkiem_KhachHang(KhachHang dskh[], int slkh, char str[10]){
	int check = -1;
	for (int i = 0; i < slkh; i++) {
		if (strcmp(dskh[i].makh, str) == 0) {
			check = i;
			printf("\n\t\t\t\t\t\tTHONG TIN NHAN VIEN CAN TIM\n");
			HienThiCot_KhachHang();
			printf("| %-10s | %-30s | %-12s | %-10s | %-10s | %-50s| %-50s|\n", dskh[i].makh, dskh[i].tenkh, dskh[i].tuoi, dskh[i].gt, dskh[i].sdt,dskh[i].ngaydat, dskh[i].diachi);
			printf("_______________________________________________________________________________________________________________________________________________________________\n");
			break;
		}
	}
	return check;
}
void TimKiem_KhachHang(KhachHang dskh[], int slkh ) {
	printf("\n\t\t\t\t\t\tTHONG TIN KHACH HANG\n");
	HienThiTT_KhachHang(dskh, slkh);
	char makhCanTim[10]; 
	printf("Nhap Ma Khach Hang Can Tim: "); scanf("%s", &makhCanTim);
	int check = timkiem_KhachHang(dskh,slkh, makhCanTim);
	if (check == -1) {
		printf("\nKhong Tim Thay Khach Hang\n");
		return;
	}	
}
//=============== CAP NHAP THONG TIN KHACH HANG ==========================
void CapNhapTT_KhachHang(KhachHang dskh[], int slkh, HoaDonDat dshd[], int slhd) { 
	char key[5];
	do{
		printf("Nhap Phim Bat Ki De Tiep Tuc Hoac Enter De ket Thuc: ");
		fflush(stdin); gets(key); 
		if(strcmp(key,"")==0){
			break;
		}
		system("cls");
		printf("\n\t\t\t\t\t\tDanh Sach Khach Hang\n");
		HienThiTT_KhachHang(dskh, slkh);
		char makhCanCapNhap[10]; 
		printf("Nhap Ma Giao Vien Can Cap Nhap: "); scanf("%s", &makhCanCapNhap);
	  	int check = timkiem_KhachHang(dskh, slkh, makhCanCapNhap);
	  	if(check == -1){
	  		printf("\nKhong Tim Thay Khach Hang Can Sua\n"); 
		}
		else{ 
			char key[5];
			printf("Ban Co Chac Chan Muon Sua Khong? (y): ");
			fflush(stdin); gets(key);
			if(strcmp(strlwr(key),"y")!=0){
				printf("\nThong Tin Chua Duoc Sua\n"); 
			}
			else{ 
				KhachHang kh;
				strcpy(kh.makh, makhCanCapNhap);
				do{ 
					printf("Ho Ten Khach Hang: "); fflush(stdin); gets(kh.tenkh);
					ChuanHoaChuoi(kh.tenkh);
					if(KiemTraChu(kh.tenkh) == 1){ 
						break;
					}
					printf("\n=> Ho Ten Khach Hang Khong Hop Le. Moi Nhap Lai !\n");
				}while(true);
				
				do{ 
			 		printf("Tuoi: "); fflush(stdin); scanf("%d",kh.tuoi); 
					if(kh.tuoi >= 15){
						break;
					}
					printf("\n=>Tuoi Khong Hop Le. Vui Long Nhap Dung Tuoi > 15 !\n"); 
				}while(true);
			  
				do{
			 		printf("Gioi Tinh: "); fflush(stdin); gets(kh.gt);
			 		XoaDauCach(kh.gt);VietHoa(kh.gt);
			 		if(strcmp(kh.gt,"Nam")==0 || strcmp(kh.gt,"Nu")==0){ 
			 			break;
					} 
					printf("\n=> Gioi Tinh (Nam/Nu). Moi Nhap Lai\n");
				}while(true);
			 	
			 	do{ 
			 		printf("Ngay Dat Hang (DD/MM/YYYY): "); fflush(stdin); gets(kh.ngaydat); 
					XoaDauCach(kh.ngaydat);
					if(KTNgayChuan(kh.ngaydat) == true){
						break;
					}
					printf("\n=> Ngay Dat Hang Khong Hop Le. Vui Long Nhap Dung Dinh Dang Ngay !\n"); 
				}while(true);
				
				do{
					fflush(stdin);printf("So Dien Thoai: "); gets(kh.sdt);
					XoaDauCach(kh.sdt);
					if(strlen(kh.sdt)==10 && KiemTraSo(kh.sdt) == 1){
						break;
					} 
					printf("\n=> So Dien Thoai Khong Hop Le. Moi Ban Nhap Lai!\n"); 
				}while(true);
				
				do{
			 		fflush(stdin);printf("Dia Chi: "), gets(kh.diachi);
			 		ChuanHoaChuoi(kh.diachi);
			 		if(strlen(kh.diachi)!=0){ 
			 			break;
					}
					printf("\n=> Dia Chi Khong Hop Le. Moi Nhap Lai\n");
				}while(true);
				dskh[check] = kh; 
				for (int j = 0; j < slhd; j++) {
					if (strcmp(dshd[j].makh, dshd[check].makh) == 0) {
						strcpy(dshd[j].tenkh, dskh[check].tenkh); 
					}
				}
				for (int j = 0; j < slhd; j++) {
					if (strcmp(dshd[j].makh, dshd[check].makh) == 0) {
						strcpy(dshd[j].ngaydat, dskh[check].ngaydat); 
					}
				}
				GhiFile_KhachHang(dskh,slkh);
				GhiFile_HoaDon(dshd,slhd);
				printf("\nCap Nhap Thanh Cong\n");
				printf("\t\t\t\t\t\tDanh Sach Khach Hang Sau Khi Sua\n");
				HienThiTT_KhachHang(dskh, slkh); 
			}
		}
	}while(true); 
	return;
}
// ==================== Xoa thong tin khach hang ============
void XoaTT_KhachHang(KhachHang dskh[], int* slkh, HoaDonDat dshd[], int* slhd){
	char key[5];
	do{
		printf("Nhap Phim Bat De Tiep Tuc Hoac Enter De ket Thuc: ");
		fflush(stdin); gets(key); 
		if(strcmp(key,"")==0){
			break;
		}
		system("cls");  
		printf("\n\t\t\t\t\t\tDanh Sach Khach Hang\n");
		HienThiTT_KhachHang(dskh, *slkh);
		char makhCanXoa[10]; 
		printf("Nhap makh Can Xoa: "); scanf("%s", &makhCanXoa);
		int check = timkiem_KhachHang(dskh, *slkh, makhCanXoa);
		if(check == -1){
			printf("\nKhong Tim Thay Giao Vien Can Xoa\n"); 
		}
		else{  
			printf("Ban Co Chac Chan Muon Xoa Khong ? (y): ");
			fflush(stdin); gets(key);
			if(strcmp(strlwr(key),"y")!=0){
				printf("\nThong Tin Khach Hang Chua Duoc Xoa\n");
			}
			else{  
				for (int j = check; j < *slkh - 1; j++) {
					dskh[j] = dskh[j + 1];
				}
				*slkh = *slkh - 1;  
				for (int i = 0; i < *slhd; i++) {
					if (strcmp(dshd[i].makh, makhCanXoa) == 0) {
						for(int j= i; j<*slhd; j++)
 							dshd[j] = dshd[j + 1];
 					}
 					i--;
				}
				*slhd--;
				printf("\nDa Xoa Thong Tin Khach Hang\n");
				printf("\n\t\t\t\t\t\tDanh Sach Khach Hang Sau Khi Xoa\n");
				HienThiTT_KhachHang(dskh, *slkh);
				GhiFile_KhachHang(dskh, *slkh);
				GhiFile_HoaDon(dshd, *slhd);
				 
			} 
		} 
	}while(true);
	return;
}
void QuanLyTT_KhachHang(KhachHang dskh[], int* slkh, HoaDonDat dshd[], int* slhd) {
	int chon;
	do {
		system("cls");
		printf("\n _____________ Quan Ly Khach Hang ___________");
		printf("\n|                                            |");
		printf("\n|    1. Them Khach Hang Moi                  |");
		printf("\n|    2. Cap Nhap Lai Thong Tin Khach Hang    |");
		printf("\n|    3. Xoa Thong Tin Khach Hang             |");
		printf("\n|    0. Thoat Quan Ly Khach Hang             |");
		printf("\n|____________________________________________|");
		printf("\n           Lua chon cua ban: ");
		scanf("%d", &chon);
		switch (chon) {
		case 0:
			break;
		case 1:
		{  
			char key[5];
			do{
				printf("Nhap Phim Bat De Tiep Tuc Hoac Enter De ket Thuc: ");
				fflush(stdin); gets(key); 
				if(strcmp(key,"")==0){
					break;
				} 
				printf("\nThem Thong Tin Khach Hang Thu %d ", *slkh + 1);
				KhachHang kh = Nhap1TT_KhachHang(dskh, *slkh);
				dskh[(*slkh)++] = kh;
				GhiFile_KhachHang(dskh, *slkh);
				printf("\nThem Thanh Cong!\n"); 
			}while(true); 
			break;
		}
		case 2: 
			CapNhapTT_KhachHang(dskh, *slkh, dshd, *slhd);
			break; 
		case 3: 
			XoaTT_KhachHang(dskh, &(*slkh), dshd, &(*slhd));
			break;  
		default:
			printf("\nNhap Sai Moi Ban Nhap Lai\n");
			break;
		}
	} while (chon);
	return;
}
// ===================================== QUAN LY Hoa DON DAT HANG ====================================
// ===================   NHAP THONG TIN 1 HOA DON ========================= 
HoaDonDat Nhap1TT_HoaDon(HoaDonDat dshd[], int slhd, NhanVien dsnv[], int slnv, KhachHang dskh[], int slkh) {
	HoaDonDat hd;
	bool check = false; 
	do {
		check = false;
		printf("\nMa Hoa Don: "); fflush(stdin); gets(hd.mahd);
		XoaDauCach(hd.mahd);
 		if(strlen(hd.mahd)==0){ 
			printf("\n=> Ma Khoa Hoc Khong Hop Le. Moi Nhap Lai !");
			check = true;
		} 
		for (int i = 0; i < slkh; i++) {
			if (strcmp(dshd[i].mahd, hd.mahd) == 0) {
				printf("\nMa Hoa Don Da Ton Tai. Moi Nhap Lai !");
				check = true;
			}
		}
	} while (check == true);

	do {
		check = false; 
		printf("Ma Nhan Vien: ");fflush(stdin); gets(hd.manv);
		XoaDauCach(hd.manv);
		for (int i = 0; i < slnv; i++) {
			if (strcmp(dsnv[i].manv, hd.manv) == 0) {
				strcpy(hd.tennv, dsnv[i].tennv);
				printf("Ten Nhan Vien: %s\n", hd.tennv);
				check = true;
			}
		}
		if(check == false) printf("\n=> Ma Nhan Vien Khong Ton Tai. Moi Nhap Lai !\n");
	} while (check == false);
	
	do {
		check = false; 
		printf("Ma Khach Hang: ");fflush(stdin); gets(hd.makh);
		XoaDauCach(hd.makh);
		for (int i = 0; i < slkh; i++) {
			if (strcmp(dskh[i].makh, hd.makh) == 0) {
				strcpy(hd.tenkh, dskh[i].tenkh);
				printf("Ten Khach Hang: %s\n", hd.tenkh); 
				strcpy(hd.ngaydat, dskh[i].ngaydat);
				printf("Ngay Dat Hang: %s\n", hd.ngaydat);
				check = true;
			}
		}
		if(check == false) printf("\n=> Ma Khach Hang Khong Ton Tai. Moi Nhap Lai !\n");
	} while (check == false);
	
	do{ 
		printf("Ngay Giao Hang (DD/MM/YY): ");fflush(stdin); gets(hd.ngaygiao); 
		XoaDauCach(hd.ngaygiao);
		if(KTNgayChuan(hd.ngaygiao) == true){
			break;
		}
		printf("\n=> Thoi Gian K Hop Le. Vui Long Nhap Dung Dinh Dang Ngay !\n"); 
	}while(true);
	
	
	return hd;
}


// Tim Kiem Hoa Don
int timkiem_hoadon(HoaDonDat dshd[], int slhd, char str[10]){
	int check = -1;
	for (int i = 0; i < slhd; i++) {
		if (strcmp(dshd[i].mahd, str) == 0) {
			check = i;
			printf("\n\t\t\t\t\t\tTHONG TIN HOA DON CAN TIM\n");
			HienThiCot_HoaDon(); 
			printf("| %-10s | %-10s | %-30s | %-10s | %-30s | %-50s | %-50s |\n",dshd[i].mahd, dshd[i].manv,dshd[i].tennv, dshd[i].makh, dshd[i].tenkh, dshd[i].ngaydat, dshd[i].ngaygiao);
			printf("________________________________________________________________________________________________________________________________________\n");
			break;
		}
	} 
	return check;
}

void TimKiem_HoaDon(HoaDonDat dshd[], int slhd) {
 	printf("\n\t\t\t\t\t\tTHONG TIN HOA DON\n");
	HienThiTT_HoaDon(dshd, slhd);
	char mahdCanTim[10]; 
	printf("Nhap Ma Hoa Don Can Tim: "); scanf("%s", &mahdCanTim);
	int check = timkiem_hoadon(dshd,slhd, mahdCanTim);
	if (check == -1) {
		printf("\nKhong Tim Thay Khach Hang\n");
		return;
	}	
}
 
//================== CAP NHAP THONG TIN KHOA HOC =====================
void CapNhapTT_HoaDon(HoaDonDat dshd[], int slhd, NhanVien dsnv[], int slnv, KhachHang dskh[], int slkh) {
	char key[5];
	do{
		printf("Nhap Phim Bat De Tiep Tuc Hoac Enter De ket Thuc: ");
		fflush(stdin); gets(key); 
		if(strcmp(key,"")==0){
			break;
		}
		system("cls");
	  	printf("\n\t\t\t\t\t\tDanh Sach Cac Hoa Don\n");
		HienThiTT_HoaDon(dshd, slhd);
		char mahdCanCapNhap[10]; 
		printf("Nhap Ma Hoa Don Can Cap Nhap: "); scanf("%s", &mahdCanCapNhap);
		int check = timkiem_hoadon(dshd, slhd,mahdCanCapNhap);
		if(check == -1){
			printf("\nKhong Tim Thay Hoa Don Can Cap Nhap\n"); 
		}
		else{ 
			char key[5];
			printf("Ban Co Chac Chan Sua Khong ? (y): "); fflush(stdin); gets(key);
			if(strcmp(strlwr(key),"y")!=0){
				printf("\nThong Tin Khong Duoc Cap Nhap\n"); 
			}
			else{ 
			 	HoaDonDat hd;
				strcpy(hd.mahd, dshd[check].mahd);
				bool check1;
				do {
					check1 = false; 
					printf("\nMa Hoa Don: "); fflush(stdin); gets(hd.mahd);
					XoaDauCach(hd.mahd);
			 		if(strlen(hd.mahd)==0){ 
						printf("\n=> Ma Khoa Hoc Khong Hop Le. Moi Nhap Lai !");
						check1 = true;
					} 
					for (int i = 0; i < slkh; i++) {
						if (strcmp(dshd[i].mahd, hd.mahd) == 0) {
							printf("\nMa Hoa Don Da Ton Tai. Moi Nhap Lai !");
							check1 = true;
						}
					}
				} while (check1 == true);
			
				do {
					check1 = false; 
					printf("Ma Nhan Vien: ");fflush(stdin); gets(hd.manv);
					XoaDauCach(hd.manv);
					for (int i = 0; i < slnv; i++) {
						if (strcmp(dsnv[i].manv, hd.manv) == 0) {
							strcpy(hd.tennv, dsnv[i].tennv);
							printf("Ten Nhan Vien: %s\n", hd.tennv);
							check1 = true;
						}
					}
					if(check1 == false) printf("\n=> Ma Nhan Vien Khong Ton Tai. Moi Nhap Lai !\n");
				} while (check1 == false);
				
				do {
					check1 = false; 
					printf("Ma Khach Hang: ");fflush(stdin); gets(hd.makh);
					XoaDauCach(hd.makh);
					for (int i = 0; i < slkh; i++) {
						if (strcmp(dskh[i].makh, hd.makh) == 0) {
							strcpy(hd.tenkh, dskh[i].tenkh);
							printf("Ten Khach Hang: %s\n", hd.tenkh);
							check = true;
						}
						else if (strcmp(dskh[i].makh, hd.makh) == 0) {
							strcpy(hd.ngaydat, dskh[i].ngaydat);
							printf("Ngay Dat Hang: %s\n", hd.ngaydat);
							check = true;
						}
					}
					if(check1 == false) printf("\n=> Ma Khach Hang Khong Ton Tai. Moi Nhap Lai !\n");
				} while (check1 == false);
				
				do{ 
					printf("Ngay Giao Hang (DD/MM/YY): ");fflush(stdin); gets(hd.ngaygiao); 
					XoaDauCach(hd.ngaygiao);
					if(KTNgayChuan(hd.ngaygiao) == true){
						break;
					}
					printf("\n=> Thoi Gian K Hop Le. Vui Long Nhap Dung Dinh Dang Ngay !\n"); 
				}while(true);
				dshd[check] = hd; 
				GhiFile_HoaDon(dshd,slhd);
				printf("\nCap Nhap Thanh Cong\n");
				printf("\n\t\t\t\t\t\tDanh Sach Hoa Don Sau Khi Cap Nhap\n"); 
				HienThiTT_HoaDon(dshd, slhd );
			}
		}
	}while(true);
	return;
}

// xoa thong tin Hoa don
void XoaTT_HoaDon(HoaDonDat dshd[], int* slhd, NhanVien dsnv[], int* slnv, KhachHang dskh[], int* slkh){
	char key[5];
	do{
		printf("Nhap Phim Bat De Tiep Tuc Hoac Enter De ket Thuc: ");
		fflush(stdin); gets(key); 
		if(strcmp(key,"")==0){
			break;
		}  
		system("cls");
		printf("\n\t\t\t\t\t\tDanh Sach Hoa Don\n");
		HienThiTT_HoaDon(dshd, *slhd );
		char mahdCanXoa[10]; 
		printf("Nhap Ma Hoa Don Can Xoa: "); scanf("%s", &mahdCanXoa);
		int check = timkiem_hoadon(dshd, *slhd ,mahdCanXoa);
		if(check == -1 ){
			printf("Khong Tim Thay Hoa Don Can Xoa.\n");
		}
		else{ 
			printf("Ban Co Chan Chan Xoa Khong ? (y): ");
			fflush(stdin); gets(key);
			if(strcmp(strlwr(key),"y")!=0){
				printf("Thong Tin Hoa Don Chua Duoc Xoa.\n");
			}
			else{ 
				for (int j = check; j < *slhd - 1; j++) {
					dshd[j] = dshd[j + 1];
				}
				*slhd = *slhd - 1;  
				
				printf("\nThong Tin Hoa Don Da Duoc Xoa.\n");
				printf("\n\t\t\t\t\t\tDanh Sach Hoa Don Sau Khi Xoa\n");
				HienThiTT_HoaDon(dshd, *slhd );
				GhiFile_HoaDon(dshd, *slhd);
				
			}
		}  
	}while(true); 
	return;
}
void QuanLyTT_HoaDon(HoaDonDat dshd[], int* slhd, NhanVien dsnv[], int* slnv, KhachHang dskh[], int* slkh) {
	int chon;
	do {
		system("cls");
		printf("\n _____________ Quan Ly Hoa Don _____________");
		printf("\n|                                           |");
		printf("\n|    1. Them Thong Tin Hoa Don Moi          |");
		printf("\n|    2. Cap Nhap Lai Thong Tin Hoa Don      |");
		printf("\n|    3. Xoa Thong Tin Hoa Don               |");
		printf("\n|    0. Thoat Quan Ly Hoa Don               |");
		printf("\n|___________________________________________|");
		printf("\n           Lua chon cua ban? ");
		scanf("%d", &chon);
		switch (chon) {
		case 0:
			break;
		case 1:
		{ 	
			if(slhd == 0){
				printf("\nChua Co Thong Tin Hoa Don Day\n");
				system("pause");
				break;
			} 
			char key[5];
			do{
 				printf("Nhap Phim Bat De Tiep Tuc Hoac Enter De ket Thuc: ");
 				fflush(stdin); gets(key); 
				if(strcmp(key,"")==0){
					break;
				}
			  	printf("\nThem Thong Tin Hoa Don Thu %d ", *slhd + 1);
				HoaDonDat hd = Nhap1TT_HoaDon(dshd, *slhd, dsnv, *slnv, dskh, *slkh);
				dshd[(*slhd)++] = hd;
				GhiFile_HoaDon(dshd, *slhd);
				printf("\nThem Thanh Cong\n");
			}while(true); 
			break; 	 
		}
		case 2: 
			CapNhapTT_HoaDon(dshd, *slhd, dsnv, *slnv, dskh, *slkh); 
			break; 
		case 3: 
			XoaTT_HoaDon(dshd, &(*slhd), dsnv, &(*slnv), dskh, &(*slkh));
			break; 
		default:
			printf("\nNhap Sai Moi Ban Nhap Lai\n");
			system("pause");
			break;
		}
	} while (chon);
	return;
}
// ====================== Bang Luong Cua Nhan Vien ==========================================================
// ========= Nhap thong tin Bang Luong ==========================
BangLuong Nhap1TT_BangLuong(BangLuong dsbl[], int slbl, NhanVien dsnv[], int slnv) {
	BangLuong bl;
	bool check = false;
	
	do{
		check = false;
		printf("Nhap Ma Nhan Vien: "); fflush(stdin); gets(bl.manv);
		XoaDauCach(bl.manv);
		for (int i = 0; i < slnv; i++) {
			if (strcmp(dsnv[i].manv, bl.manv) == 0) {
				strcpy(bl.tennv, dsnv[i].tennv);
				printf("Ten Nhan Vien: %s\n", bl.tennv);
				check = true;
			}
		}
		if(check == false) printf("\n=> Ma Nhan Vien Khong Ton Tai. Moi Nhap Lai !\n");
	}while(check == false);
	do{ 
		printf("Nhap thoi gian lam viec(gio)): "); fflush(stdin); scanf("%f",&bl.tglv);
		if(bl.tglv >= 300){ 
			break;
		}
		printf("\n=> Thoi gian lam viec >=300 gio. Moi Nhap Lai !\n");
	}while(true);
	do{
		printf("Nhap so don hang da giao: "); fflush(stdin); scanf("%f",&bl.sddg);
		if(bl.sddg >= 900 ){ 
			break;
		}
		printf("\n=> So don hang da giao phai >= 900 don/thang. Moi Nhap Lai !\n");
	}while(true);

	printf("Nhap thoi gian lam them(gio): "); fflush(stdin);  scanf("%f",&bl.tglt);
	bl.lcb = bl.tglv*20000;
	bl.llt = bl.tglt*30000;
	bl.ttl = bl.lcb + bl.llt;

	return bl;
}

// tim Kiem Thong Tin Bang Luong
int timkiem_bangluong(BangLuong dsbl[], int slbl,char str[10]){
	int check = -1; 
	for(int i = 0 ; i< slbl; i++){
		if(strcmp(dsbl[i].manv, str)==0){
			check = i;
			printf("\n\t\t\t\t\t\tThong Tin Bang Luong Can Tim\n");
			HienThiCot_BangLuong(); 
			printf("| %-10s | %-30s | %-15s | %-27s | %-10s | %-25s | %-25s | %-25s \n", dsbl[i].manv, dsbl[i].tennv, dsbl[i].tglv, dsbl[i].sddg, dsbl[i].tglt, dsbl[i].lcb, dsbl[i].llt, dsbl[i].ttl);
			printf("_______________________________________________________________________________________________________________________________________________________________________\n");				
				
			break; 
		}
	} 
	return check;	
}
void TimKiem_BangLuong(BangLuong dsbl[], int slbl) {
 	printf("\n\t\t\t\t\t\tTHONG TIN BANG LUONG\n");
	HienThiTT_BangLuong(dsbl, slbl);
	char mablCanTim[10]; 
	printf("Nhap Ma Bang Luong Can Tim: "); scanf("%s", &mablCanTim);
	int check = timkiem_bangluong(dsbl,slbl, mablCanTim);
	if (check == -1) {
		printf("\nKhong Tim Thay Khach Hang\n");
		return;
	}	
}
// ======================== CAP NHAP THONG TIN BANG LUONG ===============  
void CapNhapTT_BangLuong(BangLuong dsbl[], int slbl, NhanVien dsnv[], int slnv){  
	char key[5];
 	do{ 
		printf("Nhap Phim Bat Ky De Tiep Tuc Hoac Enter De ket Thuc: ");
		fflush(stdin); gets(key); 
		if(strlen(key)==0){
			break;
		}
		system("cls");
		printf("\n\t\t\t\t\t\tThong Tin Danh Sach Bang Luong\n");
		HienThiTT_BangLuong(dsbl, slbl );
		char ManvCanCapNhap[10];
		printf("Nhap Ma Nhan Vien Can Cap Nhap: "); scanf("%s", &ManvCanCapNhap);
		int check = timkiem_bangluong(dsbl, slbl ,ManvCanCapNhap);
		if(check == -1){
			printf("\nKhong Tim Thay Thong Tin Bang Luong Can Tim.\n"); 
		}
		else{  
			printf("Ban Co Chan Chan Muon Cap Nhap Lai Khong ? (y): ");
			fflush(stdin); gets(key);
			if(strcmp(strlwr(key),"y")!=0){
				printf("\nThong Tin Lich Hoc Chua Duoc Cap Nhap.\n");
			}
			else{ 
				bool check1;
				BangLuong bl;
				strcpy(bl.manv, ManvCanCapNhap); 
				do{ 
				printf("Nhap thoi gian lam viec(gio)): "); fflush(stdin); scanf("%f",&bl.tglv);
					if(bl.tglv >= 300){ 
						break;
					}
					printf("\n=> Thoi gian lam viec >= 300 gio. Moi Nhap Lai !\n");
				}while(true);
				do{
					printf("Nhap so don hang da giao: "); fflush(stdin); scanf("%f",&bl.sddg);
					if(bl.sddg >= 900 ){ 
						break;
					}
					printf("\n=> So don hang da giao phai >= 900 don/thang. Moi Nhap Lai !\n");
				}while(true);
			
				printf("Nhap thoi gian lam them(gio): "); fflush(stdin);  scanf("%f",&bl.tglt);
				bl.lcb = bl.tglv*20000;
				bl.llt = bl.tglt*30000;
				bl.ttl = bl.lcb + bl.llt;
				
				dsbl[check] = bl;
				GhiFile_BangLuong(dsbl, slbl);
				printf("\nCap Nhap Thanh Cong\n"); 
				printf("\n\t\t\t\t\t\t\tDanh Sach Bang Luong Sau Khi Sua\n");
				HienThiTT_BangLuong(dsbl, slbl);   
			}
		}
	}while(true); 
	return;
}

// ==================== xoa thong tin dang ky hoc ================
void XoaTT_BangLuong(BangLuong dsbl[], int *slbl, NhanVien dsnv[], int slnv){
	char key[5];
 	do{ 
		printf("Nhap Phim Bat Ky De Tiep Tuc Hoac Enter De ket Thuc: ");
		fflush(stdin); gets(key); 
		if(strlen(key)==0){
			break;
		}
		system("cls"); 
		printf("\n\t\t\t\t\t\tThong Tin Danh Sach Bang Luong\n");
		HienThiTT_BangLuong(dsbl, *slbl );
		char ManvCanXoa[10];
		printf("Nhap Ma Nhan Vien Can Xoa: "); scanf("%s", &ManvCanXoa);
		int check = timkiem_bangluong(dsbl, *slbl , ManvCanXoa);
		if(check == -1){
			printf("\nKhong Tim  Thay Thong Tin Bang Luong Can Xoa.\n"); 
		}
		else{
			printf("Ban Co Chac Chan Muon Xoa Khong ? (y): ");
			fflush(stdin); gets(key); 
			if(strcmp(strlwr(key),"y")==0){
				printf("\nThong Tin Bang Luong Chua Duoc Xoa.\n");
			}
			else{
				for (int j = check; j < *slbl - 1; j++) {
					dsbl[j] = dsbl[j + 1];
				}
				*slbl = *slbl - 1;
				GhiFile_BangLuong(dsbl,*slbl);
				printf("\nXoa Thanh Cong\n"); 
			 	printf("\n\t\t\t\t\t\tDanh Sach Bang Luong Sau Khi Xoa\n");
				HienThiTT_BangLuong(dsbl, *slbl );
			}
		} 
	}while(true);
	return;
}

void QuanLyTT_BangLuong(BangLuong dsbl[], int *slbl, NhanVien dsnv[], int slnv){
	int chon;
	do {
		system("cls");
		printf("\n _____________ Quan Ly Bang Luong _____________");
		printf("\n|                                              |");
		printf("\n|    1. Them Thong Tin Bang Luong              |");
		printf("\n|    2. Cap Nhap Lai Thong Tin Bang Luong      |");
		printf("\n|    3. Xoa Thong Tin Bang Luong               |");
		printf("\n|    0. Thoat Quan Ly Bang Luong               |");
		printf("\n|______________________________________________|");
		printf("\n          Nhap lua chon cua ban: ");
		scanf("%d", &chon);
		switch (chon) {
		case 0:
			break;
		case 1:
		{   	
			if(slnv == 0 ){
				printf("\nChua Co Thong Tin Nhan Vien.\n");
				system("pause");
				break;
			}
			char key[5];
			do{  
 				printf("Nhap Phim Bat Ky De Tiep Tuc Hoac Enter De ket Thuc: ");
 				fflush(stdin); gets(key); 
				if(strlen(key)==0){
					break;
				}
				printf("\nThem Thong Tin Bang Luong Thu %d", *slbl + 1);
				BangLuong bl = Nhap1TT_BangLuong(dsbl, *slbl, dsnv, slnv);
				if(strcmp(bl.manv,"\0")==0){
					printf("\nThem Thong Tin Khong Thanh Cong\n");
				}
				else{
					dsbl[(*slbl)++] = bl;
					GhiFile_BangLuong(dsbl, *slbl);
					printf("\nThem Thong Tin Thanh Cong\n"); 
				} 
			}while(true); 
			break;
		}
		case 2: 
			CapNhapTT_BangLuong(dsbl, *slbl, dsnv, slnv); 
			break; 
		case 3: 
			XoaTT_BangLuong(dsbl, &(*slbl), dsnv, slnv);
			break;	 
		default:
			printf("\nNhap Sai! Moi Ban Nhap Lai\n");
			system("pause");
			break;
		}
	} while (chon);
	return;
}
// ============================================================= TIM KIEM THONG TIN ================================================================
// Tim Kiem
void TimKiem(NhanVien dsnv[], int slnv, KhachHang dskh[], int slkh, HoaDonDat dshd[], int slhd, BangLuong dsbl[], int slbl){
	int chon;
	do{
		system("cls");
		printf("\n_____________________________ Tim Kiem _________________________________\n");
		printf("|                                                                         |\n");
		printf("|     1. Tim Kiem Thong Tin Nhan Vien    						   	      |\n"); 
		printf("|     2. Tim Kiem Thong Tin Khach Hang      						      |\n");
		printf("|     3. Tim Kiem Thong Tin Hoa Don Dat Hang  						      |\n");
		printf("|     4. Tim Kiem Thong Tin Bang Luong cua Nhan Vien                      |\n");
		printf("|     0. Thoat Tim kiem                                                   |\n");
		printf("|_________________________________________________________________________|\n");
		printf("            Lua Chon Cua Ban? ");
		scanf("%d",&chon);
		switch(chon){
			case 0: 
				break;
			case 1:
				TimKiem_NhanVien(dsnv, slnv);
				system("pause");
				break;
			case 2:
				TimKiem_KhachHang(dskh, slkh);
				system("pause");
				break;
			case 3:
				TimKiem_HoaDon(dshd, slhd);
				system("pause");
				break;
			case 4:
				TimKiem_BangLuong(dsbl, slbl );
				system("pause");
				break;
			default:
				printf("\nNhap Sai! Moi Ban Nhap lai\n");
				system("pause");
				break;
		}
	}while(chon);
}
void main() {
	NhanVien dsnv[1000]; int slnv = 0; DocFile_NhanVien(dsnv, &slnv); 
	KhachHang dskh[100];  int slkh = 0; DocFile_KhachHang(dskh,&slkh); 
	HoaDonDat dshd[100];  int slhd = 0; DocFile_HoaDon(dshd, &slhd); 
	BangLuong dsbl[100];   int slbl = 0; DocFile_BangLuong(dsbl, &slbl); 
	 
	 
	int luachon;
	do {
		system("cls");
		printf("\n____________ Chuong Trinh Quan Ly Shipper Giao Hang Online __________\n");
		printf("|                                                                      |\n");
		printf("|          1.  Quan Ly Thong Tin Nhan Vien                             |\n");
		printf("|          2.  Quan Ly Thong Tin Khach Hang                            |\n");
		printf("|          3.  Quan Ly Thong Tin Hoa Don Dat Hang                      |\n");
		printf("|          4.  Quan Ly Thong Tin Bang Luong Cua Nhan Vien              |\n");
		printf("|          5.  Hien Thi Thong Tin                                      |\n");
		printf("|          6.  Tim Kiem Thong Tin                                      |\n");
		printf("|          0.  Thoat chuong trinh                                      |\n");
		printf("|______________________________________________________________________|");
		printf("\n               	Lua chon cua ban:  ");
		scanf("%d", &luachon);
		getchar();
		switch (luachon) {
		case 0:
			printf("\n      Da Chuong Trinh Quan Ly Shipper Giao Hang Online\n");
			break;
		case 1:
			QuanLyTT_NhanVien(dsnv, &slnv, dskh, &slkh, dshd, &slhd, dsbl, &slbl);
			break;
		case 2:
			QuanLyTT_KhachHang(dskh, &slkh, dshd, &slhd);
			break;
		case 3:
			QuanLyTT_HoaDon(dshd, &slhd, dsnv, &slnv, dskh, &slkh);
			break;
		case 4:
			QuanLyTT_BangLuong(dsbl, &slbl, dsnv, slnv);
			break;
		case 5:
			HienThi(dsnv, slnv, dskh, slkh, dshd, slhd, dsbl, slbl);
			break;
		case 6:
			TimKiem(dsnv, slnv, dskh, slkh, dshd, slhd, dsbl, slbl);
			break;
		default:
			printf("\nNhap Sai! Moi Ban Nhap lai\n");
			system("pause");
			break;
		}
	} while (luachon);
	return;
}

