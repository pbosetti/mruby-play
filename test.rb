
puts "Daemonizing PID #{$PID} child of #{$PPID}..."
status = daemon(true, true) # nochdir, noclose
puts <<-EOL
This is daemon PID #{$PID} child of #{$PPID}:
  Status:       #{status[0] == 0 ? 'success' : 'FAILURE'}
  Current path: #{status[1]}
EOL

10.times do |i|
  puts i
  sleep 0.5
end

puts "Done."
