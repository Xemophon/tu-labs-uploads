import sys
import subprocess
import pathlib
from time import sleep

# Mapping exe files
i = 0
SKIP_DIRS = {"bepinex", "monobleedingedge", "repo_data", "_commonredist", "platform-tools", "engine", "fsd", "pipelinecaches"}
    #change path to your cracked games directory
games = pathlib.Path("D:/PGames")
g_list = list(
    path.name
    for path in games.rglob("*.exe")
    if not any(part.lower() in SKIP_DIRS for part in path.parts)
)
counter = g_list.count("UnityCrashHandler64.exe")
while i < counter:
    g_list.remove("UnityCrashHandler64.exe")
    i += 1
g_list.remove("ModIOAuth.exe")

#Game list
for j in range(len(g_list)):
    print(f"{j+1}. " + g_list[j])

#Execution
choice = int(input("Enter number of game: "))
subprocess.Popen(["C:/Program Files (x86)/Steam/steam.exe"])
print("Launching Steam...")
chosen_game = g_list[choice - 1]
sleep(20)
print(f"Launching {chosen_game}...")
subprocess.Popen([str(path) for path in games.rglob(chosen_game) if path.name == chosen_game][0])

exit
