Gem::Specification.new do |s|
	s.name        = 'fingerprint'
	s.version     = '0.0.0'
	s.date        = '2013-05-04'
	s.summary     = 'U.are.U fingerprint scanner methods.'
	s.description = 'Load and verify fingerprints scanned using a U.are.U fingerprint scanner.'
	s.authors     = ['Zachary Salzbank']
	s.email       = 'zach@keyme.net'
	s.files       = Dir.glob('ext/**/*.{c,h,rb}')
	s.extensions  = ['ext/fingerprint/extconf.rb']
	s.homepage    = 'http://github.com/keyme/fingerprint-ruby'
	s.add_dependency 'rice'
	s.requirements << 'Drivers installed from https://github.com/keyme/fingerprint-drivers'
end
