import subprocess as sb
import socket

try:
    hostname = socket.gethostname()
    self_ip = socket.gethostbyname(hostname)
    if len(self_ip) not in range(7, 16):
        raise Exception("Невалидна дължина на IP адрес.")
    result = sb.run(["netstat", "-n"], capture_output=True, text=True, check=True)
    rewr_input = []
    for line in result.stdout.splitlines():
        words = line.split()
        if len(words) == 4:
            foreign_ip = words[2]
            rewr_input.append(foreign_ip)     
    print("\n--- Непознати / Сървърни IP адреси ---")
    for arr in rewr_input:  
        if self_ip in arr or ":443" in arr or "127.0.0.1" in arr:
            continue
        else:
            print(arr)
            
except Exception as e:
    print(f"Command failed: {e}")