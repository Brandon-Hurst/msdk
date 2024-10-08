## Description

This folder contains Python utilty scripts for image capturing and post-processing, including a serial console application and image conversion utilites.  The console application supports communication with the following example projects:

* ImgCapture
* CSI2

## Requirements

Python 3.9+

Then, install Python packages using the `requirements.txt` file in this folder.

Ex:

```shell
pip install -r requirements.txt
```

## Usage

### Console (console.py)

1. Ensure the latest firmware from a support example project is flashed to the host MCU and running.  Refer to the example's [README](../README.md) file for more details on this step.

2. Verify that the LED on the host MCU is flashing.  This is the signal that the firmware is searching for the host.

3. Connect the Python console to the host MCU firmware using `console.py`.  Ex:

    ```shell
    $ python console.py <COM port>
    ```

    "<COM port>" should match the port presented by the MAX78002EVKIT on CN2.

    Alternatively, use `python console.py -h` to see a list of console start-up options.

4. Verify a successful connection, which should look similar to the following:

    ```shell
    $ python console.py COM8
    Started ImgCapture console and opened COM8
    MCU: *SYNC*
    MCU: Established communications with host!
    MCU: Registered 5 total commands:
    MCU: -----
    MCU: 'help' : Print this help string
    MCU: 'reset' : Issue a soft reset to the host MCU.
    MCU: 'capture' : Perform a standard blocking capture of a single image
    MCU: 'set-reg' <register> <value> : Write a value to a camera register.
    MCU: 'get-reg' <register> : Prints the value in a camera register.
    MCU: -----
    MCU:
    MCU:
    MCU: **** MIPI CSI-2 Example ****
    MCU: This example streams the image data through the COM port
    MCU: and a script running on the host pc converts the data into
    MCU: a .png image.
    MCU:
    MCU: Go into the pc_utility folder and run the script:
    MCU: python console.py [COM#]
    MCU:
    MCU: Press PB1 (SW4) or send the 'capture' command to trigger a frame capture.
    MCU:
    MCU: Initializing camera...
    MCU: Camera ID = 5640
    MCU: Initializing SRAM...
    MCU: RAM ID:
    MCU: MFID: 0x0d
    MCU: KGD: 0x5d
    MCU: Density: 0x02
    MCU: EID: 0x588e670d
    MCU: Capturing image...
    MCU: Done! (took 73321 us)
    MCU: Sending image over serial port...
    MCU: *IMG* RGB565 153600 320 240
    Collecting 153600 bytes...
    $
    ```

5. Enter any of the registered commands to excercise the example.  Any `capture`-d or `stream`-ed images will be saved to an "Image.png" file next to the script.

### Batch Conversion (batchconvert.py)

This script is useful for converting a large set of images that have been saved to an SD card.  It will attempt to convert all of the images in the specified input directory to .png files in its output directory.

Run `-h` for help:

```shell
$ python batchconvert.py -h
```

Usage example:

```shell
$ python batchconvert.py D:/raw
Successfully converted D:\raw\img0 -> converted\img0.png
Successfully converted D:\raw\img1 -> converted\img1.png
Successfully converted D:\raw\img10 -> converted\img10.png
Successfully converted D:\raw\img11 -> converted\img11.png
Successfully converted D:\raw\img12 -> converted\img12.png
Successfully converted D:\raw\img13 -> converted\img13.png
Successfully converted D:\raw\img14 -> converted\img14.png
Successfully converted D:\raw\img15 -> converted\img15.png
Successfully converted D:\raw\img16 -> converted\img16.png
Successfully converted D:\raw\img2 -> converted\img2.png
Successfully converted D:\raw\img3 -> converted\img3.png
Successfully converted D:\raw\img4 -> converted\img4.png
Successfully converted D:\raw\img5 -> converted\img5.png
Successfully converted D:\raw\img6 -> converted\img6.png
Successfully converted D:\raw\img7 -> converted\img7.png
Successfully converted D:\raw\img8 -> converted\img8.png
Successfully converted D:\raw\img9 -> converted\img9.png
$ 
```
