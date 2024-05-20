#!/bin/bash

# Function to display system information
display_system_info() {
	echo "System Information:"
	echo "Architecture: $(uname -m)"
	echo "Kernel Version: $(uname -r)"
	echo "Number of Physical Processors: $(nproc --all)"
	echo "Number of Virtual Processors: $(nproc)"
	echo "Available RAM: $(free -h | awk '/Mem:/ {print $7}')"
	echo "RAM Utilization: $(free | awk '/Mem:/ {printf("%.2f%%", $3/$2 * 100)}')"
	echo "Available Memory: $(free -h | awk '/Mem:/ {print $4}')"
	echo "Memory Utilization: $(free | awk '/Mem:/ {printf("%.2f%%", $4/$2 * 100)}')"
	#echo "Processor Utilization: $(top -bn1 | awk '/^%Cpu/ {print $2}')%"
	echo "Processor Utilization: $(top -bn 1 | awk 'NR==3 {printf "%.2f%%", $4 + $2}')"
	echo "Last Reboot: $(who -b | awk '{print $3, $4}')"
	echo "LVM Status: $(sudo lvscan | grep ACTIVE > /dev/null && echo "Active" || echo "Inactive")"
	echo "Active Connections: $(netstat -ant | grep ESTABLISHED | wc -l)"
	echo "Number of Users: $(who | wc -l)"
	echo "IPv4 Address: $(hostname -I)"
	echo "MAC Address: $(ip link show | awk '/ether/ {print $2}' | head -n1)"
	echo "Number of sudo Commands Executed: $(cat /var/log/auth.log* | grep sudo | wc -l)"
}

display_banner() {
	echo "=== Server Monitoring ==="
}
# Main function
main() {
	display_banner
	while true; do
		wall < <(echo -e "\n[System Information]\n$(display_system_info)")
		sleep 600
	done
}

# Execute the main function
main

