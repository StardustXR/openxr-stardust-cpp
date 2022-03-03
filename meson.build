project('openxr-stardust', 'cpp', default_options: ['cpp_std=c++17'], version:'0.1.0')

# add_project_arguments([
# 	'-fvisibility=hidden',
# ], language: 'cpp')

openxr = dependency('openxr')
stardust = dependency('stardustxr')

files = []

subdir('src')

mapfile = 'libopenxr.version'
version_script_flag = '-Wl,--version-script,@0@/@1@'.format(meson.current_source_dir(), mapfile)
lib = shared_library(
	'openxr_stardust',
	files,
	# gnu_symbol_visibility : 'hidden',
	dependencies: [openxr, stardust],
	link_args: version_script_flag,
	install: true
)
