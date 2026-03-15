# GF(2^m) Modular Inverse

Chương trình tìm **nghịch đảo modular** của phần tử trong trường hữu hạn **GF(2^m)** sử dụng thuật toán **Extended Euclidean Algorithm** (Euclid mở rộng) trên đa thức nhị phân.

## Mô tả

Trong mật mã học và an toàn thông tin, phép tính nghịch đảo trên trường hữu hạn GF(2^m) là thao tác cơ bản được sử dụng rộng rãi trong các thuật toán mã hóa như **AES**, **ECC (Elliptic Curve Cryptography)**, và các hệ mã dựa trên đường cong elliptic.

Chương trình thực hiện các phép toán sau trên đa thức nhị phân:

| Hàm | Chức năng |
|---|---|
| `bac_da_thuc(x)` | Tính bậc của đa thức (biểu diễn dưới dạng số nguyên) |
| `nhan_da_thuc(a, b)` | Nhân hai đa thức trong GF(2) bằng phương pháp shift-and-XOR |
| `chia_da_thuc(A, B, Q, R)` | Chia đa thức A cho B, trả về thương Q và dư R |
| `tim_nghich_dao(a, m)` | Tìm nghịch đảo của đa thức a modulo m bằng Extended Euclidean Algorithm |

## Tham số mặc định

- **Đa thức bất khả quy (modulus):** `m = 1033` → tương ứng `x^10 + x^3 + 1`
- **Phần tử a:** `523` → tương ứng `x^9 + x^3 + x + 1`
- **Phần tử b:** `1015` → tương ứng `x^9 + x^8 + x^7 + x^6 + x^4 + x^2 + x + 1`

## Cách biểu diễn đa thức

Các đa thức được biểu diễn dưới dạng **số nguyên** sử dụng biểu diễn nhị phân. Mỗi bit tương ứng với hệ số của một bậc:

```
Ví dụ: 1033 = 10000001001 (nhị phân)
       = 1·x^10 + 0·x^9 + ... + 1·x^3 + 0·x^2 + 0·x + 1
       = x^10 + x^3 + 1
```

## Yêu cầu hệ thống

- **Trình biên dịch C++:** GCC (g++) phiên bản 7.0 trở lên hoặc tương đương
- **Hệ điều hành:** Windows / Linux / macOS

## Biên dịch và chạy

### Trên Linux / macOS

```bash
g++ -o gf2m_modular_inverse gf2m_modular_inverse.cpp
./gf2m_modular_inverse
```

### Trên Windows (MinGW)

```cmd
g++ -o gf2m_modular_inverse.exe gf2m_modular_inverse.cpp
gf2m_modular_inverse.exe
```

## Kết quả mẫu

```
--- Tim nghich dao cua 523 ---
Phep chia r: 1033 / 523 duoc thuong q = 2, so du r = 13
Phep nhan: q * t2 = 2 * 1 = 2
Tinh t moi: t1 ^ (q * t2) = 0 ^ 2 = 2

Phep chia r: 523 / 13 duoc thuong q = 42, so du r = 5
Phep nhan: q * t2 = 42 * 2 = 84
...

--- Tim nghich dao cua 1015 ---
...
```

## Cơ sở lý thuyết

### Extended Euclidean Algorithm trên GF(2^m)

Thuật toán sử dụng phép chia Euclid mở rộng để tìm nghịch đảo:

Cho đa thức `a(x)` và đa thức bất khả quy `m(x)`, tìm `a⁻¹(x)` sao cho:

```
a(x) · a⁻¹(x) ≡ 1 (mod m(x))
```

**Các bước:**
1. Khởi tạo: `r₁ = m`, `r₂ = a`, `t₁ = 0`, `t₂ = 1`
2. Lặp cho đến khi `r₂ = 0`:
   - Tính `q, r` sao cho `r₁ = q · r₂ + r` (phép chia đa thức)
   - Cập nhật: `t = t₁ ⊕ (q · t₂)`
   - Gán: `r₁ ← r₂`, `r₂ ← r`, `t₁ ← t₂`, `t₂ ← t`
3. Kết quả: `a⁻¹ = t₁`

> **Lưu ý:** Phép cộng và trừ trên GF(2) đều là phép XOR (⊕).

## Cấu trúc project

```
gf2m-modular-inverse/
├── gf2m_modular_inverse.cpp   # Mã nguồn chính
├── .gitignore                 # Danh sách file bị bỏ qua bởi Git
├── LICENSE                    # Giấy phép MIT
└── README.md                  # Tài liệu hướng dẫn (file này)
```

## Tác giả

- **Họ tên:** thuanvd378
- **Trường:** Đại học Bách khoa Hà Nội (HUST)
- **Môn học:** An toàn thông tin

## Giấy phép

Project này được phân phối theo giấy phép [MIT](LICENSE).
