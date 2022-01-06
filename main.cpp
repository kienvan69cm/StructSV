#include <iostream>
using namespace std;
struct SinhVien
{
    string id;
    string hoTen;
    string ngaySinh;
    string Khoa;
    float Mon1;
    float Mon2;
    float diemTB;
    string xepLoai;
};
SinhVien nhapSV()
{
    SinhVien SV;
    cin.ignore();
    cout << "Nhap so thu tu: ";
    getline(cin, SV.id);
    cout << "Nhap ho ten: ";
    getline(cin, SV.hoTen);
    cout << "Nhap ngay sinh: ";
    getline(cin, SV.ngaySinh);
    cout << "Nhap khoa: ";
    getline(cin, SV.Khoa);
    cout << "Nhap diem mon 1: ";
    cin >> SV.Mon1;
    cout << "Nhap diem mon 2: ";
    cin >> SV.Mon2;
    SV.diemTB = (SV.Mon1 + SV.Mon2) / 2;
    return SV;
}
void xuatSV(SinhVien SV)
{
    cout << "ID: " << SV.id << endl;
    cout << "Ho ten: " << SV.hoTen << endl;
    cout << "Ngay sinh: " << SV.ngaySinh << endl;
    cout << "Khoa: " << SV.Khoa << endl;
    cout << "Diem mon 1: " << SV.Mon1 << endl;
    cout << "Diem mon 2: " << SV.Mon2 << endl;
}
void chenSV(SinhVien SV[], int &n)
{
    int k;
    SinhVien newSV;
    cout << "Nhap vi tri SV can chen: ";
    cin >> k;
    cout << "Nhap thong tin SV can chen: " << endl;
    newSV = nhapSV();
    for (int i = n; i > k; i--)
    {
        SV[i] = SV[i - 1];
    };
    SV[k] = newSV;
    n++;
    for (int i = 0; i < n; i++)
    {
        xuatSV(SV[i]);
    }
}
void xoaSV(SinhVien SV[], int &n)
{
    int k;
    cout << "Nhap vi tri SV can xoa: ";
    cin >> k;
    for (int i = k; i < n - 1; i++)
    {
        SV[i] = SV[i + 1];
    };
    n--;
    for (int i = 0; i < n; i++)
    {
        xuatSV(SV[i]);
    }
}
void timSV(SinhVien SV[], int n)
{
    string name;
    bool found = false;
    cin.ignore();
    cout << "Nhap ten SV can tim: ";
    getline(cin, name);
    for (int i = 0; i < n; i++)
    {
        if (SV[i].hoTen == name)
        {
            xuatSV(SV[i]);
            found = true;
        }
    }
    if (found == false)
        cout << "Khong tim thay sinh vien co ten" << name << endl;
}
void sapxepSV(SinhVien SV[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (SV[i].diemTB > SV[j].diemTB)
            {
                SinhVien tmp = SV[i];
                SV[i] = SV[j];
                SV[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        xuatSV(SV[i]);
    }
}
void xeploaiSV(SinhVien SV[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (SV[i].diemTB >= 8)
            SV[i].xepLoai = "Gioi";
        else if (SV[i].diemTB >= 6.5)
            SV[i].xepLoai = "Kha";
        else if (SV[i].diemTB >= 5)
            SV[i].xepLoai = "Trung Binh";
        else
            SV[i].xepLoai = "Yeu";
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Ho ten: " << SV[i].hoTen << endl;
        cout << "Xep loai: " << SV[i].xepLoai << endl;
    }
}
int main()
{
    SinhVien SV[30];
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        SV[i] = nhapSV();
    }
    for (int i = 0; i < n; i++)
    {
        xuatSV(SV[i]);
    }
    cout << "Chen Sinh Vien: " << endl;
    chenSV(SV, n);
    cout << "Xoa Sinh Vien: " << endl;
    xoaSV(SV, n);
    cout << "Tim Sinh Vien: " << endl;
    timSV(SV, n);
    cout << "Sap Xep Sinh Vien: " << endl;
    sapxepSV(SV, n);
    cout << "Xep Loai Sinh Vien: " << endl;
    xeploaiSV(SV, n);
    return 0;
}