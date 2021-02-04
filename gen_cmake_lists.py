import os
import subprocess
get_raw_cpp_list_cmd = 'forfiles /s /m *.c /c "cmd /c echo @relpath"'
get_raw_h_list_cmd   = 'forfiles /s /m *.h /c "cmd /c echo @relpath"'


def get_cmd(cmd):
	return subprocess.check_output(cmd, shell=True)

h_list = get_cmd(get_raw_h_list_cmd).replace('\\', '/')
cpp_list = get_cmd(get_raw_cpp_list_cmd).replace('\\', '/')

name = "libpng"
add_target = "add_library"
with open("CMakeLists.txt", "w") as fp:
	content = "%s(%s\n" % (add_target, name) + h_list + cpp_list + ")"
	content = '\n'.join(content.splitlines())  # remap newline char
	content += "\n"
	fp.write(content) 
