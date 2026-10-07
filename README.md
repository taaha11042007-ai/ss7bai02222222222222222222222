# BÁO CÁO THIẾT KẾ MODULE QUẢN LÝ CỤM THIẾT BỊ PHÒNG THÔNG MINH

## 1. Phân tích bài toán

### 1.1. Input

Chương trình sử dụng hai cấu trúc dữ liệu.

### SmartDevice

- `deviceID`: Mã định danh thiết bị.
- `deviceName`: Tên thiết bị.
- `status`: Trạng thái hoạt động, 1 là bật và 0 là tắt.
- `ratedPowerKW`: Công suất định mức của thiết bị, đơn vị kW.

### EnergySensor

- `voltageVolts`: Điện áp đo được, đơn vị V.
- `currentAmperes`: Dòng điện đo được, đơn vị A.
- `unoccupancyMinutes`: Thời gian phòng không có người, đơn vị phút.

### Biến phụ trợ

- `operatingHours`: Số giờ vận hành trong tháng.
- `energyKWh`: Tổng điện năng tiêu thụ.
- `electricityCost`: Tổng tiền điện chưa bao gồm VAT.

## 2. Output

Chương trình xuất:

- Trạng thái thiết bị sau khi áp dụng các quy tắc tự động.
- Cảnh báo quá tải dòng điện nếu dòng điện vượt 30A.
- Thông báo tự động tắt thiết bị khi phòng vắng người từ 15 phút trở lên.
- Tổng điện năng tiêu thụ theo kWh.
- Tổng tiền điện phải trả theo biểu giá điện bậc thang.

## 3. Thiết kế giải pháp

Chương trình sử dụng `struct` để nhóm các thông tin có liên quan.

Các thuộc tính của cấu trúc được truy cập trực tiếp bằng toán tử `.`.

Ví dụ:

```c
device.status
device.ratedPowerKW
sensor.currentAmperes
sensor.unoccupancyMinutes\
