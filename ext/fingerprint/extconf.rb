require 'mkmf-rice'

$CPPFLAGS += ' -std=c++0x'
$INCFLAGS += " -I/opt/DigitalPersona/UareUSDK/Include"

dir_config('', 'compare', 'compare')

have_library('dpfj')
have_library('dpfpdd')

$objs = ['fingerprint.o', 'compare/compare.o']

create_makefile('keyme/fingerprint')
