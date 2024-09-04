import datetime
import pefile
import sys

def printCompileTime(filepath):
    try:
        pe = pefile.PE(filepath)
        timestamp = pe.FILE_HEADER.TimeDateStamp
        print("Date de compilation:", datetime.datetime.utcfromtimestamp(timestamp).strftime('%Y-%m-%d %H:%M:%S'))
    except FileNotFoundError:
        print(f"Erreur: '{filepath}' introuvable.")
    except pefile.PEFormatError:
        print(f"Erreur: '{filepath}' n'est pas un fichier PE.")

def main():
    if len(sys.argv) != 2:
        print("Usage: python getCompilationTime.py <filepath>")
        sys.exit(1)
    printCompileTime(sys.argv[1])

if __name__ == "__main__":
    main()