#!/usr/bin/python3

import argparse
import os
from PIL import Image
import image_processing_py

def is_valid_path (path):
    if not os.path.isdir(path):
        raise argparse.ArgumentTypeError(path + " is not a valid path")
    return path

def is_image(file_path):
    try:
        Image.open(file_path).verify()
        return True
    except (IOError, SyntaxError):
        return False
    
def manipulateFilesFromPathToPath(source, dest):
    for filename in os.listdir(source):
        full_source_path = os.path.join(source, filename)
        if is_image(full_source_path):
            full_dest_path = os.path.join(dest, filename)
            avgPixelValue = image_processing_py.saveProprietaryImageManipulationToFile(full_source_path, full_dest_path)
            print(filename + " | AvgPixelValue = " + str(avgPixelValue) + " |")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Demo")
    parser.add_argument("source_directory", type=is_valid_path)
    parser.add_argument("destination_directory", type=is_valid_path)
    args = parser.parse_args()

    manipulateFilesFromPathToPath(args.source_directory, args.destination_directory)