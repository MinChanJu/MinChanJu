import os

def print_directory_structure(dir_path, indent=0):
    try:
        for entry in os.listdir(dir_path):
            print("  " * indent + "|-- " + entry)
    except PermissionError:
        print("  " * indent + "|-- [Permission Denied]")

if __name__ == "__main__":
    current_directory = os.getcwd()
    parent_directory = os.path.dirname(current_directory)
    print(f"Directory structure for: {parent_directory}")
    print_directory_structure(parent_directory)