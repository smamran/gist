#!/bin/bash
# Full-featured Linux OS info script with colors
# Usage: just type 'os'

# Color codes
GREEN='\033[0;32m'
CYAN='\033[0;36m'
YELLOW='\033[1;33m'
MAGENTA='\033[0;35m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "\n${MAGENTA}===== SYSTEM INFO =====${NC}"

# OS Name & Version
if [ -f /etc/os-release ]; then
    . /etc/os-release
    echo -e "${GREEN}OS:${NC} ${CYAN}$NAME $VERSION${NC}"
else
    echo -e "${GREEN}OS:${NC} Unknown"
fi

# Kernel & Architecture
echo -e "${GREEN}Kernel:${NC} ${CYAN}$(uname -r)${NC}"
echo -e "${GREEN}Architecture:${NC} ${CYAN}$(uname -m)${NC}"

# Hostname
echo -e "${GREEN}Hostname:${NC} ${CYAN}$(hostname)${NC}"

# Uptime
echo -e "${GREEN}Uptime:${NC} ${CYAN}$(uptime -p)${NC}"

# CPU
CPU_MODEL=$(lscpu | grep 'Model name' | sed 's/Model name:[ \t]*//')
CPU_CORES=$(lscpu | grep '^CPU(s):' | awk '{print $2}')
echo -e "${GREEN}CPU:${NC} ${CYAN}$CPU_MODEL${NC} (${YELLOW}$CPU_CORES cores${NC})"

# Memory
MEM_TOTAL=$(free -h | awk '/Mem:/ {print $2}')
MEM_USED=$(free -h | awk '/Mem:/ {print $3}')
echo -e "${GREEN}Memory:${NC} ${CYAN}$MEM_USED${NC} / ${CYAN}$MEM_TOTAL${NC} used"

# Disk usage (root)
DISK_TOTAL=$(df -h / | awk 'NR==2{print $2}')
DISK_USED=$(df -h / | awk 'NR==2{print $3}')
echo -e "${GREEN}Disk ( / ):${NC} ${CYAN}$DISK_USED${NC} / ${CYAN}$DISK_TOTAL${NC} used"

# IP Address
IP=$(hostname -I | awk '{print $1}')
echo -e "${GREEN}IP:${NC} ${CYAN}${IP:-Not available}${NC}"

# VMware Tools IP (optional)
if command -v vmrun >/dev/null 2>&1; then
    VM_IP=$(vmrun getGuestIPAddress *.vmx 2>/dev/null)
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}VMware Guest IP:${NC} ${CYAN}$VM_IP${NC}"
    fi
fi

# Docker info
if command -v docker >/dev/null 2>&1; then
    DOCKER_VERSION=$(docker --version | awk '{print $3}' | sed 's/,//')
    DOCKER_RUNNING=$(docker ps -q | wc -l)
    echo -e "${GREEN}Docker:${NC} ${YELLOW}$DOCKER_VERSION${NC}, Running Containers: ${CYAN}$DOCKER_RUNNING${NC}"
fi

echo -e "${MAGENTA}========================${NC}\n"
