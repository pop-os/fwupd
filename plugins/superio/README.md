---
title: Plugin: SuperIO
---

## Introduction

This plugin enumerates the various ITE85* SuperIO embedded controller ICs found
in many laptops. Vendors wanting to expose the SuperIO functionality will need
to add a HwId quirk entry to `superio.quirk`.

See [the Wikipedia page](https://en.wikipedia.org/wiki/Super_I/O) for more
details about SuperIO and what the EC actually does.

Other useful links:

* <https://raw.githubusercontent.com/system76/ecflash/master/ec.py>
* <https://github.com/system76/firmware-update/tree/master/src>
* <https://github.com/coreboot/coreboot/blob/master/util/superiotool/superiotool.h>
* <https://github.com/flashrom/flashrom/blob/master/it85spi.c>
* <http://wiki.laptop.org/go/Ec_specification>

## GUID Generation

These devices use a custom GUID generated using the SuperIO chipset name:

* `SuperIO-$(chipset)`, for example `SuperIO-IT8512`

## Update Behavior

The firmware is deployed when the device is in normal runtime mode, but it is
only activated on machine reboot. The firmware write is normally scheduled to be
done very early in the boot process to minimize the chance the EC chip locking
up if the user is actually using the keyboard controller.

## Vendor ID Security

The vendor ID is set from the baseboard vendor, for example `DMI:Star Labs`

## Quirk Use

This plugin uses the following plugin-specific quirks:

### SuperioControlPort

Control (status/command) port number, e.g. `0x66`

Since: 1.6.2

### SuperioDataPort

Data port number, e.g. `0x62`

Since: 1.6.2

### SuperioAutoloadAction

Autoload action, specified by ITE: `none`, `disable`, `on`, `off`

Since: 1.6.2

### SuperioTimeout

Maximum wait time in ms (default value is `250`)

Since: 1.6.2

## External Interface Access

This plugin requires access to raw system memory via `inb`/`outb`.

## Version Considerations

This plugin has been available since fwupd version `1.1.2`.
