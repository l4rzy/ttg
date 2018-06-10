project('ttg', 'c',
  version: '0.0.1',
  meson_version: '>=0.43',
  default_options: 'c_std=c99'
)

version_array = meson.project_version().split('.')

cc = meson.get_compiler('c')

## libs
tdjson = cc.find_library('tdjson')
pthread = dependency('threads')
ncurses = dependency('ncurses')
build_dependencies = [tdjson, ncurses, pthread]

## flags
flags = [
  '-Wall',
  '-Wextra'
]

## defines
defines = [
  '-DDEBUG_ON',
  '-DVERSION_MAJOR=@0@'.format(version_array[0]),
  '-DVERSION_MINOR=@0@'.format(version_array[1]),
  '-DVERSION_PATCH=@0@'.format(version_array[2])
]

flags = cc.get_supported_arguments(flags)

sources = files(
  'src/text.c',
  'src/ui.c',
  'src/ttg.c',
  'src/key.c'
)

executable('ttg', 
  sources,
  dependencies: build_dependencies,
  c_args: defines + flags)

