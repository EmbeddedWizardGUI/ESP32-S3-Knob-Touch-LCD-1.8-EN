"""Generate a LittleFS image from a directory, compatible with ESP-IDF esp_littlefs."""
import sys
import os
from littlefs import LittleFS

def main():
    if len(sys.argv) < 4:
        print(f"Usage: {sys.argv[0]} <image_size> <source_dir> <output_file>")
        print("  image_size: partition size in bytes (decimal or 0xHEX)")
        sys.exit(1)

    image_size = int(sys.argv[1], 0)
    source_dir = sys.argv[2]
    output_file = sys.argv[3]

    block_size = 4096
    block_count = image_size // block_size

    fs = LittleFS(block_size=block_size, block_count=block_count)

    file_count = 0
    total_bytes = 0

    for filename in os.listdir(source_dir):
        filepath = os.path.join(source_dir, filename)
        if os.path.isfile(filepath):
            with open(filepath, "rb") as f:
                data = f.read()
            with fs.open("/" + filename, "wb") as f:
                f.write(data)
            file_count += 1
            total_bytes += len(data)
            print(f"  Added: {filename} ({len(data)} bytes)")

    with open(output_file, "wb") as f:
        f.write(fs.context.buffer)

    print(f"\nLittleFS image created: {output_file}")
    print(f"  Files: {file_count}, Data: {total_bytes} bytes")
    print(f"  Image size: {image_size} bytes ({image_size // 1024} KB)")

if __name__ == "__main__":
    main()
