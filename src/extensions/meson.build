files += files(
	'client.cpp'
)

if get_option('opengl').enabled()
	# opengl = dependency('opengl', required : true)
	# dependencies += opengl

	files += files(
		'opengl.cpp'
	)
	compile_args += '-DXR_USE_GRAPHICS_API_OPENGL'


	if get_option('xlib').enabled()
		x11 = dependency('x11', required : true)
		glx = dependency('glx', required : true)
		dependencies += [x11, glx]
		
		compile_args += '-DXR_USE_PLATFORM_XLIB'
	endif
endif
