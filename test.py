import itertools
import subprocess
import time
import pyautogui
import os

def generate_permutations(base_lines, static_lines):
    permutations = itertools.permutations(base_lines)
    
    # Create a folder for the variants
    folder_name = "map_variants"
    os.makedirs(folder_name, exist_ok=True)
    
    for i, perm in enumerate(permutations):
        filename = f"{folder_name}/map_variant_{i+1}.cub"
        with open(filename, "w") as f:
            f.writelines("\n".join(perm) + "\n")
            f.writelines("\n".join(static_lines) + "\n")
        
        print(f"Executing: ./cub3d {filename}")
        process = subprocess.Popen(["./cub3d", filename])
        
        pyautogui.press("esc")  # Presionar ESC
        process.terminate()

if __name__ == "__main__":
    base_lines = [
        "WE ./sprites/test3.png",
        "NO ./sprites/test1.png",
        "SO ./sprites/test2.png",
        "F 220,100,0",
        "EA ./sprites/test4.png",
        "C 225,30,0"
    ]
    
    static_lines = [
        "",
        " 11111111111111111111111",
        "11001111111111111111001",
        "10000000000000000000001",
        "11100000000000000000011",
        "1000010000000000000111",
        "1000100000000000000111",
        "1011000N00000000000111",
        "1000000000000000000111",
        "1000000001000000000111",
        "1000001110000000000111",
        "1000000000000000000111",
        "1000000000111111100111",
        "1000000000100000100111",
        "1000000000100111100111",
        "1000000000100000000111",
        "1111111111111111111111"
    ]
    
    generate_permutations(base_lines, static_lines)