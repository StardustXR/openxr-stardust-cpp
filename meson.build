project('openxr-stardust', 'cpp', default_options: ['cpp_std=c++17'], version:'0.1.0')

# add_project_arguments([
# 	'-fvisibility=hidden',
# ], language: 'cpp')

openxr = dependency('openxr')
stardust = dependency('stardustxr')
flatbuffers = dependency('flatbuffers')

files = []
dependencies = [openxr, stardust, flatbuffers]
compile_args = []

subdir('src')

mapfile = 'libopenxr.version'
version_script_flag = '-Wl,--version-script,@0@/@1@'.format(meson.current_source_dir(), mapfile)
lib = shared_library(
	'openxr_stardust',
	files,
	dependencies: dependencies,
	link_args: version_script_flag,
	c_args: compile_args,
	cpp_args: compile_args,
	install: true
)
