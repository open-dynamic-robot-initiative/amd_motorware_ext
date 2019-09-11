AMD MotorWare Extensions
========================

This repository contains some modules that extend the Texas Instruments
MotorWare library as well as a patch file to apply some required modifications
on the original MotorWare library itself.


MotorWare Patch
---------------

Our software is based on Texas Instruments' MotorWare library which is freely
available on the [TI website](http://www.ti.com/tool/MOTORWARE).  We made some
modifications to the original MotorWare which are needed to build our software.
These changes are included in the file `motorware_1_01_00_18_patch1` in this
repository.  Use the following steps to set up your workspace so you are able to
build the software:

1. Download MotorWare v1.01.00.18 from the [TI
   website](http://www.ti.com/tool/MOTORWARE).
2. Install it to extract the source.  For Linux users: Unfortunately TI only
   provides a Windows installer.  There is not really an installation required,
   you only need the source files.  You can get them by either installing on a
   Windows machine or using an emulator like Wine on Linux and then copy the
   files from the installation directory.
   Search for the directory containing the `sw` directory and copy that into
   a directory called `motorware` in your workspace.  The structure should be
   like this:

       workspace
       ├── amd_motorware_ext
       ├── motorware
       │   ├── docs
       │   ├── eclipse
       │   ├── mw_explorer
       │   └── sw
       ├── mw_dual_motor_torque_ctrl
       ├── user_config_f28069m_drv8305
       └── ...


Now go into the `motorware` directory and apply the patch file:

    patch -p1 < ../amd_motorware_ext/motorware_patch/motorware_1_01_00_18_patch1


Now you should be able to build the `mw_dual_motor_torque_ctrl` project using
[Code Composer Studio](http://www.ti.com/tool/CCSTUDIO-C2000).


License
-------

BSD 3-Clause License

Copyright (c) 2019, Max Planck Gesellschaft, New York University
