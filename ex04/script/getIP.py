import base64
import ipaddress
import subprocess
import sys

def isValidIP(IPstr):
    try:
        ipaddress.ip_address(IPstr)
        return True
    except ValueError:
        return False

def xorData(data, key):
    return bytes([b ^ key for b in data])

def applyDecodeRules(strings):
    results = []
    for data in strings:
        data = base64.b64decode(data)
        data = xorData(data, 170)
        data = data.decode('latin1')
        if isValidIP(data):
            results.append(data)
    return results

def isBase64(s):
    try:
        if len(s) % 4 != 0:
            return False
        base64.b64decode(s, validate=True)
        return True
    except (base64.binascii.Error):
        return False

def getStrBase64(strings):
    validStrings = [s for s in strings if isBase64(s)]
    return validStrings

def runStrings(filePath):
    result = subprocess.run(['strings', filePath], stdout=subprocess.PIPE, text=True)
    return result.stdout.splitlines()

def main():
    if len(sys.argv) != 2:
        print("Usage: python getIP.py <filepath>")
        sys.exit(1)
    output = runStrings(sys.argv[1])
    output = getStrBase64(output)
    output = applyDecodeRules(output)
    if output:
        print("Adresses IP :")
        for s in output:
            print(s)
    else:
        print("Impossible de trouver des adresses IP valides.")

if __name__ == "__main__":
    main()
