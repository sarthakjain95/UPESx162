# OpenGL setup on Windows (using WSL)

## How to install

1. Setup WSL with Ubuntu (20.04 LTS Recommended) [See [this](https://www.windowscentral.com/install-windows-subsystem-linux-windows-10)]
2. Setup Ubuntu
	1. Enable copy pasting in Ubuntu terminal
		1. Right click on ubuntu icon on top left corner of Ubuntu terminal window
		2. Open Properties - Options
		3. Check the option 'Use Ctrl+Shift+C/V as Copy/Paste'
	2. Run the following commands (Paste using Ctrl+Shift+V)
		1. ```sudo su``` 
		2. ```sudo apt-get update```
		3. ```sudo apt-get -y install build-essentials```
		4. ```sudo apt-get -y install libglu1-mesa-dev freeglut3-dev mesa-common-dev mesa-utils xorg openbox xauth xserver-xorg-core xserver-xorg``` 
	3. Edit ```.bashrc``` (Cheatsheet for nano [here](https://www.nano-editor.org/dist/latest/cheatsheet.html))
		1. ```nano ~/.bashrc```
		2. Go to the very end of this file
		3. Add these lines
			```bash
            export DISPLAY=localhost:0.0
            export LIBGL_ALWAYS_INDIRECT=1
            ```
        4. Save file and exit nano
3. Download and Install Xming [[here](https://sourceforge.net/projects/xming/)]
4. Restart Windows

## How to run

* Get OpenGL sample codes [here](https://www.opengl.org/archives/resources/code/samples/glut_examples/examples/examples.html)
1. Start Xming server on Windows 
2. Navigate to Windows directory in Ubuntu terminal
	* ```cd /mnt/c/Users/<USERNAME>/<FILEPATH_IN_WINDOWS>```
3. Compile and Execute code
	* ```gcc FILENAME.c -lGL -lGLU -lglut && ./a.out```