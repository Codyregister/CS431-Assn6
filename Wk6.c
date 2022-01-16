/*
 * CS431 - Wk6 - Cody Register - 20211126
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <linux/hdreg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int fd = open("/dev/pts/0", O_RDONLY);
    struct winsize sz, sz2;

    //Get virtual terminal attributes
    ioctl(fd, TIOCGWINSZ, &sz);
    printf("Screen Width: %i Screen Height: %i\n", sz.ws_col, sz.ws_row);
    printf("Horizontal Pixels: %i Vertical Pixels: %i\n", sz.ws_xpixel, sz.ws_ypixel);

    //Change the virtual terminal attributes
    sz.ws_col += 20;
    sz.ws_row += 30;
    ioctl(fd, TIOCSWINSZ, &sz);

    //Check whether the changes were successful
    ioctl(fd, TIOCGWINSZ, &sz2);
    printf("Screen Width: %i Screen Height: %i\n", sz2.ws_col, sz2.ws_row);
    printf("Horizontal Pixels: %i Vertical Pixels: %i\n", sz2.ws_xpixel, sz2.ws_ypixel);


    /* EXTRA CREDIT SECTION
     * Disregard, I could not get this section functional.
     * Every attempt ended with "Inappropriate ioctl for device.
     * I would appreciate an explanation regarding why HDIO_GET_IDENTITY and 
     * HDIO_GETGEO do not work on any of the hard drives in /dev/.
     
     
    int drive;
    if (drive = open("/dev/sda2", O_RDONLY | O_NONBLOCK) < 0) {
        fprintf(stderr, "Could not open drive: %s\n", strerror(errno));
        exit(-1);
    }
    struct hd_driveid hd;
    if (ioctl(drive, HDIO_GET_IDENTITY, &hd) < 0) {
        fprintf(stderr, "Could not get HDIO_GET_IDENTITY: %s\n", strerror(errno));
        //exit(-1);
    }
    printf("Model: %22.10s\n", hd.model);

    struct hd_geometry geom;
    if (ioctl(drive, HDIO_GETGEO, &geom) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        //exit(-1);
    }
    printf("Heads: %i, Sectors: %i, Cylinders: %i\n", geom.heads, geom.sectors, geom.cylinders);

    close(drive);
     */

}
