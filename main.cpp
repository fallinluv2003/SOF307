/* Header file có tên stdio.h trong Thư viện C chuẩn định nghĩa 3 kiểu biến,
 một số macro và các hàm đa dạng để thực hiện input và output.*/
#include <stdio.h>
/*Thư viện conio.h hỗ trợ các hàm giúp bạn thực hiện các thao tác input hoặc output từ màn hình console*/
#include <conio.h>
/*string.h trong C Header file có tên string.h trong Thư viện C chuẩn định nghĩa một kiểu biến,
 một macro và các hàm đa dạng để thao tác các mảng ký tự.*/
#include <string.h>
/*Khai báo số lượng lưu trữ tối đa của danh sách nhân viên là 100.*/
#define sl 100

struct Date
{
    int ngay;
    int thang;
    int nam;
};
typedef struct Date date;

struct NhanVien
{
    int msnv;
    char ho[20];
    char ten[20];
    date ngaySinh;
    char noiSinh[100];
    char diaChi[200];
    float luong;
    date ngayVao;
};
typedef struct NhanVien nhanVien;

struct DanhSach
{
    nhanVien arr[sl];
    int n;
};
typedef struct DanhSach danhSach;

void nhapNgayThang(date &ntn)
{
    do
    {
        printf("\nNhap vao ngay: ");
        scanf("%d", &ntn.ngay);
        // Điều kiện ngày nhỏ hơn 1 và lớn hơn 31 sẽ cho nhập lại
    } while (ntn.ngay < 1 || ntn.ngay > 31);
    do
    {
        printf("\nNhap vao thang: ");
        scanf("%d", &ntn.thang);
        // Điều kiện tháng nhỏ hơn 1 và lớn hơn 12 sẽ cho nhập lại
    } while (ntn.thang < 1 || ntn.thang > 12);

    do
    {
        printf("\nNhap vao nam: ");
        scanf("%d", &ntn.nam);
        // Điều kiện năm nhỏ hơn 1 và lớn hơn 2023 sẽ cho nhập lại
    } while (ntn.nam < 1 || ntn.nam > 2023);
}

void xuatNgayThang(date ntn)
{
    printf("%d-", ntn.ngay);
    printf("%d-", ntn.thang);
    printf("%d", ntn.nam);
}

// Hàm nhập nhân viên
void nhapNhanVien(nhanVien &nv)
{
    printf("\nNhap vao MSNV: ");
    scanf("%d", &nv.msnv);
    printf("\nNhap vao ho: ");
    fflush(stdin); // Xóa bộ nhớ đệm
    gets(nv.ho); // Hàm này chấp nhận chuỗi có khoảng trống
    printf("\nNhap vao ten: ");
    fflush(stdin);
    gets(nv.ten);
    printf("\nNhap vao ngay sinh: ");
    nhapNgayThang(nv.ngaySinh);
    printf("\nNhap vao noi sinh: ");
    fflush(stdin);
    gets(nv.noiSinh);
    printf("\nNhap vao dia chi: ");
    fflush(stdin);
    gets(nv.diaChi);
    printf("\nNhap vao luong: ");
    scanf("%f", &nv.luong);
    printf("\nNhap vao ngay vao: ");
    nhapNgayThang(nv.ngayVao);
}

void xuatNhanVien(nhanVien nv)
{
    printf("\nMa so nhan vien: %d", nv.msnv);
    printf("\nHo: %s", nv.ho);
    printf("\nTen: %s", nv.ten);
    printf("\nNgay sinh: ");
    xuatNgayThang(nv.ngaySinh);
    printf("\nNoi sinh: %s", nv.noiSinh);
    printf("\nDia chi: %s", nv.diaChi);
    printf("\nLuong: %9.2f", nv.luong);
    printf("\nNgay vao: ");
    xuatNgayThang(nv.ngayVao);
}

void nhapDanhSach(danhSach &ds)
{
    printf("\nNhap so luong nhan vien: ");
    scanf("%d", &ds.n);
    printf("\n\t\t\tNhap thong tin nhan vien");
    // Duyệt từ vị trí đầu đến cuối của danh sách và gọi hàm nhập nhân viên
    for (int i = 0; i < ds.n; i++)
    {
        printf("\n\t\tNhan vien thu: %d", i + 1);
        nhapNhanVien(ds.arr[i]);
    }
}

void xuatDanhSach(danhSach ds)
{
    printf("\n\t\t\tDanh sach nhan vien");
    // Duyệt từ vị trí đầu đến cuối của danh sách và gọi hàm xuất nhân viên
    for (int i = 0; i < ds.n; i++)
    {
        printf("\n\t\tNhan vien thu: %d", i + 1);
        xuatNhanVien(ds.arr[i]);
    }
}

void themNhanVien(danhSach &ds, nhanVien nv, int them)
{
    // Dịch chuyển để tạo ô trống trước khi thêm
    for (int i = ds.n; i > them; i--)
    {
        ds.arr[i] = ds.arr[i - 1];
    }
    // Chèn nhân viên tại vị trí thêm
    ds.arr[them] = nv;
    // Tăng số lượng phần từ xong khi chèn
    ds.n++;
}

// Tìm kiếm theo tên nhân viên
int timTen(danhSach ds, char *ten)
{
    // Duyệt từ vị trí đầu đến cuối của danh sách
    for (int i = 0; i < ds.n; i++)
    {
        // Sử dụng strcmp trong thư viện string.h để kiểm tra 2 tên có trùng nhau hay không
        // Sử dụng strlwr trong thư viện string.h để ép chuỗi từ chữ hoa về chữ thường
        // Nếu bằng 0 thì sẽ trả về vị trí tìm được và break để thoát vòng lặp
        if (strcmp(strlwr(ds.arr[i].ten), strlwr(ten)) == 0)
        {
            return i;
            break;
        }
    }
    // Nếu không tìm thấy trả về -1
    return -1;
}

// Tìm kiếm mã số nhân viên bằng tìm kiếm tuần tự vét cạn
int timMSNV(danhSach ds, int ma)
{
    // Duyệt từ vị trí đầu đến cuối của danh sách
    for (int i = 0; i < ds.n; i++)
    {
        // Nếu mã nhân viên bằng mã số cần tìm thì sẽ trả về vị trí tìm được
        // Break để thoát khỏi vòng lặp
        if (ds.arr[i].msnv == ma)
        {
            return i;
            break;
        }
    }
    // Nếu không tìm thấy trả về -1
    return -1;
}

// Sắp xếp nhân viên bằng Bubble Sort
void sapXep(danhSach ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        for (int j = 0; j < ds.n - 1 - i; j++)
        {
            if (ds.arr[j].luong < ds.arr[j + 1].luong)
            {
                nhanVien temp = ds.arr[j];
                ds.arr[j] = ds.arr[j + 1];
                ds.arr[j + 1] = temp;
            }
        }
    }
    xuatDanhSach(ds);
}

// Xóa nhân viên theo mã
void xoaNhanVien(danhSach ds, int ma)
{   
    int viTri = timMSNV(ds, ma);
    if (viTri == -1)
    {
        printf("\nKhong tim thay MSNV %d muon xoa", ma);
    }
    else
    {
        // Duyệt từ vị trí tìm được đến hết danh sách
        for (int i = viTri; i < ds.n; i++)
        {
            ds.arr[i] = ds.arr[i + 1];
            // Giam so luong phan tu sau khi xoa.
            ds.n--;
        }
        xuatDanhSach(ds);
    }
}

void menu()
{
    printf("\n\t\t-----------------MENU----------------");
    printf("\n\t 1. Nhap xuat danh sach nhan vien");
    printf("\n\t 2. Them nhan vien");
    printf("\n\t 3. Tim nhan vien theo ma so");
    printf("\n\t 4. Tim nhan vien theo ten");
    printf("\n\t 5. Bang luong cua nhan vien giam dan");
    printf("\n\t 6. Xoa nhan vien");
    printf("\n\t 0. Thoat");
    printf("\n\t\t*************************************");
    printf("\n\t Chon 1 trong nhung chuc nang tren: ");
}

int main()
{
    int choose;
    menu();
    int d, viTri;
    danhSach ds;
    nhanVien nv;
    while (true)
    {
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
        {
            nhapDanhSach(ds);
            xuatDanhSach(ds);
            menu();
            break;
        }

        case 2:
        {
            printf("\n\tVi tri them: ");
            scanf("%d", &viTri);
            nhapNhanVien(nv);
            themNhanVien(ds, nv, viTri);
            printf("\n\tDanh sach sau khi them: ");
            xuatDanhSach(ds);
            menu();
            break;
        }
        case 3:
        {
            int d;
            printf("\n\tNhap ma so can tim: ");
            scanf("%d", &d);
            int a = timMSNV(ds, d);
            if (a == -1)
            {
                printf("\nKhong tim thay");
            }
            else
            {
                printf("\nTim thay nhan vien thu %d", a + 1);
            }
            menu();
            break;
        }
        case 4:
        {
            char ten[20];
            printf("\n\tNhap ten can tim: ");
            fflush(stdin);
            gets(ten);
            int b = timTen(ds, ten);
            if (b == -1)
            {
                printf("\nKhong tim thay nhan vien: %s", ten);
            }
            else
            {
                printf("\nTim thay nhan vien thu: %d", b + 1);
            }
            menu();
            break;
        }
        case 5:
        {
            printf("\n\t\tDanh sach luong sau khi sap xep");
            sapXep(ds);
            menu();
            break;
        }
        case 6:
        {
            printf("\nNhap ma so can xoa: ");
            scanf("%d", &d);
            printf("\n\t\tDanh sach sau khi xoa: ");
            xoaNhanVien(ds, d);
            menu();
            break;
        }
        case 0:
        {
            printf("\nBan da thoat");
            break;
        }
        default:
            printf("Khong co chuc nang nay, moi chon lai!");
            menu();
            break;
        }
    }
    getch();
}
