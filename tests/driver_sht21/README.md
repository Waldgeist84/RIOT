# About
This is a test application for the Sensirion sht21 temperature and humidity sensor
# Usage
Just enter the `make BOARD=??? flash` command in the `tests/driver_sht21/` folder.
# Results
The sensor will be measuring using the highest resolution. First the temperature and humidity will be returned. Then the settings byte will be read and returned. After that the chip heater will be enabled. The settings register will be read again. The byte should have changed since the heater is enabled now. The temperature and humidity will be measured and printed out to the console every 5s. The temperature should increase while the humidity decreases, as the heater is enabled now.
