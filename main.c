#include <stdio.h>

struct SmartDevice {
    int deviceID;
    char deviceName[50];
    int status;
    float ratedPowerKW;
};

struct EnergySensor {
    float voltageVolts;
    float currentAmperes;
    int unoccupancyMinutes;
};

int main() {
    struct SmartDevice device;
    struct EnergySensor sensor;

    float operatingHours;
    float energyKWh;
    float electricityCost = 0.0f;

    printf("=== SMART HOME IOT - QUAN LY CUM THIET BI ===\n");

    printf("\nNhap ma thiet bi: ");
    scanf("%d", &device.deviceID);

    printf("Nhap ten thiet bi: ");
    scanf(" %49[^\n]", device.deviceName);

    printf("Nhap trang thai (1-Bat, 0-Tat): ");
    scanf("%d", &device.status);

    printf("Nhap cong suat dinh muc (kW): ");
    scanf("%f", &device.ratedPowerKW);

    printf("\n=== NHAP DU LIEU CAM BIEN ===\n");

    printf("Nhap dien ap (V): ");
    scanf("%f", &sensor.voltageVolts);

    printf("Nhap dong dien (A): ");
    scanf("%f", &sensor.currentAmperes);

    printf("Nhap thoi gian vang nguoi (phut): ");
    scanf("%d", &sensor.unoccupancyMinutes);

    printf("\nNhap so gio van hanh trong thang: ");
    scanf("%f", &operatingHours);

    if (sensor.voltageVolts < 0 ||
        sensor.currentAmperes < 0 ||
        sensor.unoccupancyMinutes < 0) {

        printf("\nLOI: Thong so cam bien khong hop le.\n");
        printf("He thong huy thao tac xu ly.\n");

        return 0;
    }

    if (operatingHours <= 0 || operatingHours > 744) {
        printf("\nLOI: So gio van hanh khong hop le.\n");
        printf("So gio phai lon hon 0 va khong vuot qua 744 gio.\n");

        return 0;
    }

    printf("\n=== KIEM SOAT AN TOAN DIEN ===\n");

    if (sensor.currentAmperes > 30.0f) {
        device.status = 0;

        printf("CANH BAO: DONG DIEN VUOT NGUONG AN TOAN!\n");
        printf("Nguy co qua tai va chay no.\n");
        printf("He thong da ngat thiet bi khan cap.\n");
    } else {
        printf("Dong dien nam trong nguong an toan.\n");
    }

    printf("\n=== TU DONG TIET KIEM NANG LUONG ===\n");

    if (device.status == 1 && sensor.unoccupancyMinutes >= 15) {
        device.status = 0;

        printf("Phong vang nguoi tu 15 phut tro len.\n");
        printf("He thong da tu dong tat thiet bi.\n");
    } else {
        printf("Khong can kich hoat che do tu dong tat.\n");
    }

    energyKWh = device.ratedPowerKW * operatingHours;

    if (energyKWh <= 50) {
        electricityCost = energyKWh * 1806;
    } else if (energyKWh <= 100) {
        electricityCost = 50 * 1806;
        electricityCost += (energyKWh - 50) * 1866;
    } else if (energyKWh <= 200) {
        electricityCost = 50 * 1806;
        electricityCost += 50 * 1866;
        electricityCost += (energyKWh - 100) * 2167;
    } else {
        electricityCost = 50 * 1806;
        electricityCost += 50 * 1866;
        electricityCost += 100 * 2167;
        electricityCost += (energyKWh - 200) * 2729;
    }

    printf("\n=== BAO CAO HE THONG ===\n");
    printf("Ma thiet bi: %d\n", device.deviceID);
    printf("Ten thiet bi: %s\n", device.deviceName);
    printf("Trang thai: %s\n", device.status == 1 ? "DANG BAT" : "DA TAT");
    printf("Cong suat dinh muc: %.2f kW\n", device.ratedPowerKW);
    printf("Dien ap: %.2f V\n", sensor.voltageVolts);
    printf("Dong dien: %.2f A\n", sensor.currentAmperes);
    printf("Thoi gian vang nguoi: %d phut\n", sensor.unoccupancyMinutes);
    printf("Thoi gian van hanh: %.2f gio\n", operatingHours);
    printf("Tong dien nang tieu thu: %.2f kWh\n", energyKWh);
    printf("Tong tien dien: %.0f VND\n", electricityCost);

    return 0;
}