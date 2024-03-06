preamble = "2AAF"
bytes_info = int(preamble, 16).to_bytes(4, byteorder='little')

print(bytes_info)