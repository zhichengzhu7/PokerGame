Hello, sir. to let the programe run need to reset path for SFML.  I have already demo it to you during in the lab section and it can run for sure.

the SFML2.5.1 Folder is under 测试 folder.

1. project properties >> C/C++ >>general >> Additional Include Directories
	
   add the path to SFML2.5.1 Folder and SFML2.5.1 Folder/include

2. project properties >> Linker >>general >> Additional Library Directories
	
  add the path to SFML2.5.1 Folder and SFML2.5.1 Folder/include

3. project properties >> Linker >>input >> Additional Dependencies

  add these files name to addtional dependencies, you can just copy them

sfml-graphics-d.lib
sfml-audio-d.lib
sfml-window-d.lib
sfml-system-d.lib
sfml-graphics.lib
sfml-window.lib
sfml-system.lib
