project('openxr-stardust', 'cpp', default_options: ['cpp_std=c++17'], version:'0.1.0')

openxr = dependency('openxr')
stardust = dependency('stardustxr')

files = []

subdir('src')

lib = library(
	'openxr_stardust',
	files,
	dependencies: [openxr, stardust],
	install: true
)
