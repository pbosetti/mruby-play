MRuby::Gem::Specification.new('mruby-play') do |spec|
  # Note that it needs WiringPI libraries (http://wiringpi.com)
  spec.license = 'MIT'
  spec.author  = 'Paolo Bosetti and Matteo Ragni, University of Trento'
  spec.summary = 'Raspberry library for IO access'
  spec.version = 0.1
  spec.description = spec.summary
  spec.homepage = "Not yet defined"
  
  if not build.kind_of? MRuby::CrossBuild then
    spec.cc.command = 'gcc' # clang does not work!
    spec.cc.flags << %w||
    spec.cc.include_paths << "/usr/local/include"
  
    spec.linker.library_paths << "/usr/local/lib"
  else
    # complete for your case scenario
  end
end
