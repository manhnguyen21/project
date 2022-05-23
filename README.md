#Bắn_tàu
Game bắn tàu chiến lược mô phỏng tàu chiến lấy bối cảnh giả tưởng đại chiến thế giới, build với thư viện [SDL 2](https://www.libsdl.org/)

## Mục lục

1.  [Hướng dẫn cài đặt](#hướng-dẫn-cài-đặt)
2.  [Mô tả chung](#mô-tả-chung)
3.  [Chức năng đã cài đặt](#chức-năng-đã-cài-đặt)
4.  [Kĩ thuật sử dụng](#kĩ-thuật-sử-dụng)
5.  [Hướng phát triển](#hướng-phát-triển)
6.  [Kết luận](#kết-luận)

---

# Nội dung

## Hướng dẫn cài đặt

Project sử dụng codeblock trên windows

### Yêu cầu

- Cài đặt [SDL2], [SDL2_image](SDL2_image-devel-2.0.5-mingw.tar.gz), [SDL2_ttf] và [SDL2_mixer]

### Tải và chạy game

Tải project (Download as zip) về máy hoặc dùng git

```
git clone https://github.com/manhnguyen21/project.git
```

## Mô tả chung

    Trò chơi được lấy ý tưởng chính từ tựa game có tên Battleship.
    -  Nhiệm vụ của trò chơi là tiêu diệt tất cả các tàu chiến của đối thủ. Nếu bạn có thể tiêu diệt tất cả các tàu trước đối thủ của bạn, bạn có thể giành chiến thắng.
    -  Để chiến thắng được đối thủ trước tiên bạn phải sắp xếp tàu chiến của mình không theo 1 cấu trúc nào cả để tránh ăn những viên đạn của đối thủ sau đó hãy nhanh trí chọn những vị trí mà bạn nghi ngờ có tàu chiến của đối thủ và nã pháo vào.

## Chức năng đã cài đặt

> Demo
> [link video demo](https://www.youtube.com/watch?v=S9pZrQA2jFU)

    - Tạo menu game :
        + Có nút PLAY: Khi người chơi click chuột trái vào nút PLAY thì trò chơi sẽ bắt đầu.
        + Có nút QUIT: Khi người chơi click chuột trái vào nút QUIT thì trò chơi sẽ đóng lại.
    - Các chức năng khi chơi game:
        + Chức năng đặt tàu : Di chuyển toàn bộ con tàu vào map bên phải. Click chuột trái để đặt tàu
        + Chức năng xoay tàu: Sủ dụng phím SPACE để xoay tàu 1 góc 90 độ
        + Sinh random map của bot team : Khi người chơi đặt xong thì bot tự động random và đặt 5 con tàu vào vị trí bất kì bên map trái
        + Tạo thuật toán cho bot bắn tàu : Khi người chơi bắn 1 phát thì bot cũng bắn 1 phát.
        + Tạo phần chơi lại game mới
    - Các hiệu ứng âm thanh :
        + Nhạc nền trò chơi
        + Âm thanh khi click chuột
        + Âm thanh khi bắn
        + Âm thanh khi bắn trúng
        + Am thanh khi nổ tàu

## Kĩ thuật sử dụng

- Đồ họa với thư viện SDL:
  - Xử lí hiệu ứng animation
  - Xử lí các hình ảnh, icon
  - Xử lí sự kiện từ chuột và bàn phím
  - Kĩ thuật render chữ
  - Xử lí âm thanh
  - Vẽ đồ họa game
- Các kĩ thuật lập trình
  - Kỹ thuật lập trình hướng đối tượng: Trò chơi được chia thành nhiều đối tượng khác nhau để dễ dàng quản lý và sử dụng. Có tận dụng tất cả tính năng của lập trình hướng đối tượng bao gồm tính kế thừa, tính đóng gói, tính đa hình.
  - Kĩ thuật chia tách file: Các Class được khai báo trong các file .h và việc định nghĩa chi tiết các phương thức của class được đưa vào trong các file .cpp
  - Sử dụng cấu trúc Struct: Trong khi các đối tượng có độ phức tạp cao (nhiều thuộc tính, nhiều phương thức) được quản lý thông qua các Class thì các đối tượng ít phức tạp (như đối tượng vị trí chỉ gồm toạ độ x và y) được quản lý thông qua struct.
  - Sử dụng cấu trúc mảng: Trong dự án có sử dụng container vector C++ để lưu trữ các đối tượng.
- Âm thanh với thư viện SDL:
  - Kỹ thuật load âm thanh
  - Kỹ thuật phát file.wav
- Kỹ thuật clean code.

## Kết luận, hướng phát triển và kinh nghiệm rút ra

- Kết luận:
  - Dự án có ứng dụng nhiều kỹ thuật lập trình từ các nguồn khác nhau.
  - Dự án tạo ra một trò chơi có âm thanh, đồ hoạ và có tiềm năng phát triển tiếp.
- Hướng phát triển tiếp theo:
  - Thêm hiệu ứng đạn bay từ tàu bắn sang tàu địch
  - Thêm mức độ của mỗi lần chơi
  - Hiệu ứng animation đẹp, đọc đáo hơn.
