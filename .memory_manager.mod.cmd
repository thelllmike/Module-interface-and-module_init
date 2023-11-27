cmd_/home/oem/memory_manager/memory_manager.mod := printf '%s\n'   memory_manager.o | awk '!x[$$0]++ { print("/home/oem/memory_manager/"$$0) }' > /home/oem/memory_manager/memory_manager.mod
