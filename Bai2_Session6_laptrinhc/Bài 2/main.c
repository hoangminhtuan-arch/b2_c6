#include <stdio.h>
#include <string.h>

int main() {
    const int MAX = 100;
    char maPhieu[100][15];
    char tenSach[100][50];
    int soNgayMuon[100];
    int tienPhat[100];
    int soLuong = 0;
    int choice;

    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat (Qua han > 14 ngay)\n");
        printf("6. Thoat chuong trinh\n");
        printf("==============================================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                } else {
                    printf("\n=== THEM LUOT MUON SACH MOI ===\n");
                    char maMoi[15];
                    printf("Nhap ma phieu muon: ");
                    scanf("%14s", maMoi);
                    while (getchar() != '\n');

                    int dup = 0;
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maMoi) == 0) {
                            dup = 1;
                            break;
                        }
                    }

                    if (dup) {
                        printf("Loi: Ma phieu %s da ton tai!\n", maMoi);
                    } else {
                        strcpy(maPhieu[soLuong], maMoi);
                        
                        printf("Nhap ten sach: ");
                        fgets(tenSach[soLuong], 50, stdin);
                        if (tenSach[soLuong][strlen(tenSach[soLuong]) - 1] == '\n') {
                            tenSach[soLuong][strlen(tenSach[soLuong]) - 1] = '\0';
                        }
                        
                        int ngay;
                        do {
                            printf("Nhap so ngay muon thuc te: ");
                            scanf("%d", &ngay);
                            while (getchar() != '\n');
                            if (ngay <= 0) printf("So ngay muon phai > 0!\n");
                        } while (ngay <= 0);

                        soNgayMuon[soLuong] = ngay;
                        tienPhat[soLuong] = (ngay > 14) ? (ngay - 14) * 5000 : 0;
                        
                        printf("\n--> Tien phat tu dong tinh: %d VND\n", tienPhat[soLuong]);
                        printf("--> Them luot muon sach thanh cong!\n");
                        soLuong++;
                    }
                }
                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                } else {
                    printf("\n================================ DANH SACH MUON SACH ================================\n");
                    printf("%-5s | %-10s | %-30s | %-10s | %-15s\n", "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");
                    printf("-------------------------------------------------------------------------------------\n");
                    long long tongPhat = 0;
                    for (int i = 0; i < soLuong; i++) {
                        printf("%-5d | %-10s | %-30s | %-10d | %-15d\n", i + 1, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                        tongPhat += tienPhat[i];
                    }
                    printf("-------------------------------------------------------------------------------------\n");
                    printf("Tong tien phat toan he thong: %lld VND\n", tongPhat);
                }
                break;

            case 3:
                {
                    char maSua[15];
                    printf("\n=== CAP NHAT SO NGAY MUON ===\n");
                    printf("Nhap ma phieu muon can cap nhat: ");
                    scanf("%14s", maSua);
                    while (getchar() != '\n');

                    int idx = -1;
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maSua) == 0) {
                            idx = i;
                            break;
                        }
                    }

                    if (idx == -1) {
                        printf("Khong tim thay phieu muon co ma: %s\n", maSua);
                    } else {
                        printf("Tim thay phieu muon cua sach: %s (So ngay hien tai: %d)\n", tenSach[idx], soNgayMuon[idx]);
                        int ngayMoi;
                        do {
                            printf("Nhap so ngay muon thuc te moi: ");
                            scanf("%d", &ngayMoi);
                            while (getchar() != '\n');
                            if (ngayMoi <= 0) printf("So ngay muon phai > 0!\n");
                        } while (ngayMoi <= 0);

                        soNgayMuon[idx] = ngayMoi;
                        tienPhat[idx] = (ngayMoi > 14) ? (ngayMoi - 14) * 5000 : 0;
                        printf("\n--> Tien phat moi: %d VND\n", tienPhat[idx]);
                        printf("--> Cap nhat so ngay muon thanh cong!\n");
                    }
                }
                break;

            case 4:
                {
                    char maXoa[15];
                    printf("\n=== XOA PHIEU MUON ===\n");
                    printf("Nhap ma phieu muon can xoa: ");
                    scanf("%14s", maXoa);
                    while (getchar() != '\n');

                    int idx = -1;
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maXoa) == 0) {
                            idx = i;
                            break;
                        }
                    }

                    if (idx == -1) {
                        printf("Khong tim thay phieu muon co ma: %s\n", maXoa);
                    } else {
                        for (int i = idx; i < soLuong - 1; i++) {
                            strcpy(maPhieu[i], maPhieu[i + 1]);
                            strcpy(tenSach[i], tenSach[i + 1]);
                            soNgayMuon[i] = soNgayMuon[i + 1];
                            tienPhat[i] = tienPhat[i + 1];
                        }
                        soLuong--;
                        printf("Xoa phieu muon thanh cong!\n");
                    }
                }
                break;

            case 5:
                {
                    int coPhat = 0;
                    printf("\n=== THONG KE PHIEU MUON QUA HAN ===\n");
                    for (int i = 0; i < soLuong; i++) {
                        if (soNgayMuon[i] > 14) {
                            if (!coPhat) {
                                printf("%-5s | %-10s | %-30s | %-10s | %-15s\n", "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");
                                printf("-------------------------------------------------------------------------------------\n");
                            }
                            printf("%-5d | %-10s | %-30s | %-10d | %-15d\n", i + 1, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                            coPhat = 1;
                        }
                    }
                    if (!coPhat) {
                        printf("Khong co luot muon nao bi qua han phat!\n");
                    } else {
                        printf("-------------------------------------------------------------------------------------\n");
                    }
                }
                break;

            case 6:
                printf("Thoat chuong trinh. Hen gap lai!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
