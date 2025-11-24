#include "drivers/gps.h"
#include "drivers/imu.h"
#include "drivers/dht.h"
#include "ros/ros_publisher.h"

void setup() {
    ros_init();
    gps_init();
    imu_init();
    dht_init();
}

void loop() {
    publish_gps(gps_read());
    publish_imu(imu_read());
    publish_dht(dht_read());

    ros_spin();
    delay(100);
}
