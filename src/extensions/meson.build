GL = dependency('GL', required : get_option('opengl'))

files += files(
	'client.cpp'
)

if get_option('opengl').enabled() and GL.found()
	files += files(
		'opengl.cpp'
	)
	compile_args += '-DXR_USE_GRAPHICS_API_OPENGL'
endif