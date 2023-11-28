cmd_/home/oem/process_stats/process_stats.mod := printf '%s\n'   process_stats.o | awk '!x[$$0]++ { print("/home/oem/process_stats/"$$0) }' > /home/oem/process_stats/process_stats.mod
