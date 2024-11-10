#include <iostream>
#include <string>
using namespace std;

class Dongvat {
private:
    string Tendongvat;
    string Loaidongvat;
    float Cannang;
    string Thetrang;
    int Soluong;
    string Masodongvat;

public:
    void nhap() {
        cout << "Nhap ten dong vat: ";
        getline(cin, Tendongvat);
        cout << "Nhap loai dong vat: ";
        getline(cin, Loaidongvat);
        cout << "Nhap can nang: ";
        cin >> Cannang;
        cin.ignore();
        cout << "Nhap the trang: ";
        getline(cin, Thetrang);
        cout << "Nhap so luong: ";
        cin >> Soluong;
        cin.ignore();
        cout << "Nhap ma so dong vat: ";
        getline(cin, Masodongvat);
    }

    void xuat() const {
        cout << "Ten: " << Tendongvat << endl;
        cout << "Loai: " << Loaidongvat << endl;
        cout << "Can nang: " << Cannang << " kg" << endl;
        cout << "The trang: " << Thetrang << endl;
        cout << "So luong: " << Soluong << endl;
        cout << "Ma so: " << Masodongvat << endl;
    }
    string getTendongvat(){
        return Tendongvat;
    }
    int getSoluong(){
        return Soluong;
    }
    float getCannang(){
        return Cannang;
    }
    friend istream& operator>>(istream& is, Dongvat& dv) {
        dv.nhap();
        return is;
    }

    friend ostream& operator<<(ostream& os, const Dongvat& dv) {
        dv.xuat();
        return os;
    }
};

struct Node {
    Dongvat data;
    Node* next;

    Node(const Dongvat& dv){
        data = dv;
        next = NULL;
    }
};
class Danhsachdongvat {
private:
    Node* head;
    Node* tail;

public:
    Danhsachdongvat() : head(nullptr), tail(nullptr) {}

    ~Danhsachdongvat() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Thêm vào cuối danh sách
    void themLast() {
        Dongvat dv;
        cout << "Nhap thong tin dong vat:\n";
        cin >> dv;
        Node* tmp = new Node(dv);

        if (tail == nullptr) { // Danh sách rỗng
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
        cout << "Da them dong vat vao cuoi danh sach.\n";
    }

    // Thêm vào đầu danh sách
    void themFirst() {
        Dongvat dv;
        cout << "Nhap thong tin dong vat:\n";
        cin >> dv;
        Node* tmp = new Node(dv);

        if (head == nullptr) { // Danh sách rỗng
            head = tail = tmp;
        } else {
            tmp->next = head;
            head = tmp;
        }
        cout << "Da them dong vat vao dau danh sach.\n";
    }
    //Xóa động vật
    void deleteDv(int pos){
        if (head == nullptr) {
            cout << "Danh sach rong.\n";
            return;
        }
        // Xóa nút đầu tiên
        if (pos == 0) { 
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) tail = nullptr; // Nếu danh sách giờ rỗng
            return;
        }
        
        Node* current = head;
        Node* tmp = nullptr;
        int count = 0;
        
        while (current != nullptr && count < pos) {
            tmp = current;
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Vi tri khong ton tai trong danh sach.\n";
            return;
        }
        tmp->next = current->next;
        // Nếu xóa nút cuối
        if (current->next == nullptr) { 
            tail = tmp;
        }
        delete current;
    }
    // tìm kiếm động vật
    void searchDv(const string &ten){
        Node *tmp=head;
        bool ktra=false;
        while(tmp != NULL){
            if(tmp->data.getTendongvat() == ten){
                cout << "\nThong tin dong vat vua tim:";
                tmp->data.xuat();
                ktra=true;
            }
            tmp = tmp->next;
        }
        if(!ktra){
            cout << "\nKhong tim thay ten vua tim!";
        }
    }
    //tìm động vật có số lượng lớn nhất
    void timMax(){
        if(head==NULL){
            cout << "\nDanh sach rong!";
            return;
        }
        Node *max=head;
        Node *tmp = head->next;
        while(tmp != NULL){
            if(max->data.getSoluong() < tmp->data.getSoluong()){
                max = tmp;
            }
            tmp=tmp->next;
        }
        cout << "Dong vat co so luong nhieu nhat la:\n";
        max->data.xuat();
    }
    //sắp xếp động vật giảm dần theo cân nặng
    void sapxep(){
        if(head==NULL){
            cout << "\nDanh sach rong!";
            return;
        }
        for(Node *i=head; i != NULL; i=i->next){
            for(Node *j=i->next; j != NULL;j=j->next){
                if(i->data.getCannang() < j->data.getCannang()){
                    Dongvat tmp = i->data;
                    i->data = j->data;
                    j->data = tmp;
                }
            }
        }
        cout << "Danh sach theo thu tu giam dan theo can nang:\n";
        xuatDanhSach();
    }
    // in danh sách ra màn hình
    void xuatDanhSach() const {
        cout << "\nDanh sach dong vat:\n";
        Node* current = head;
        
        while (current != nullptr) {
            current->data.xuat();
            cout << "----------------------" << endl;
            current = current->next;
        }
    }
};

class App {
public:
    void run() {
        Danhsachdongvat danhSach;
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Them dong vat vao cuoi danh sach\n";
            cout << "2. Them dong vat vao dau danh sach\n";
            cout << "3. Xoa dong vat\n";
            cout << "4. Tim kiem dong vat\n";
            cout << "5. Dong vat co so luong nhieu nhat\n";
            cout << "6. Sap xep dong vat theo thu tu giam dan cua can nang\n";
            cout << "7. Xuat danh sach dong vat\n";
            cout << "0. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1:
                    danhSach.themLast();
                    break;
                case 2:
                    danhSach.themFirst();
                    break;
                case 3:
                    int pos;cout << "Nhap vi tri can xoa: ";cin >> pos;
                    danhSach.deleteDv(pos);
                    break;
                case 4:{
                    string ten;cout << "Nhap ten can tim: "; getline(cin,ten);
                    danhSach.searchDv(ten);
                    break;
                }
                case 5:
                    danhSach.timMax();
                    break;
                case 6:
                    danhSach.sapxep();
                    break;
                case 7:
                    danhSach.xuatDanhSach();
                    break;
                case 0:
                    break;
                default:
                    cout << "Lua chon khong hop le.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    App app;
    app.run();
    return 0;
}
