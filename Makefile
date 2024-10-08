MCU = atmega328p
F_CPU = 16000000UL 
BAUD = 9600
AVRDUDE_PORT = /dev/cu.usbserial-110 # Update this for your system
AVRDUDE_PROGRAMMER = arduino
AVRDUDE_BAUDRATE = 115200

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

SRC_DIR = src
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
TARGET = main

CFLAGS = -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
LDFLAGS = -mmcu=$(MCU)

$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY: all clean flash

all: $(BUILD_DIR)/$(TARGET).hex

flash: $(BUILD_DIR)/$(TARGET).hex
	$(AVRDUDE) -v -p $(MCU) -c $(AVRDUDE_PROGRAMMER) -P $(AVRDUDE_PORT) -b $(AVRDUDE_BAUDRATE) -D -U flash:w:$(BUILD_DIR)/$(TARGET).hex:i

clean:
	rm -rf $(BUILD_DIR)/*

