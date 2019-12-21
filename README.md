# October Kernel

This is a project to learn about kernels and operating systems.
The kernel will boot using GRUB/QEMU as I think writing a bootloader and a kernel would be too daunting of a task.

I named this October simply because I started the project in late October.

The target hardware for this operating system is the Raspberry Pi Zero W.

## TODO List

This list is more for myself than anything.

- Implement VGA for ARM systems
- Structure build scripts so that the architecture could be selected
- Implement keyboard input for ARM
- Implement virtual memory for ARM
- Implement a shell
- Implement memory protection for user mode
- Add libc support
- Add a filesystem
- Add ability to run simple binaries on the filesystem
