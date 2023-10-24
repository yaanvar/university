import struct
from struct import *
import sys
class BinaryReader:
    formats = {
        'char': 'c',
        'int8': 'b ',
        'uint8': 'B',
        'int16': 'h',
        'uint16': 'H',
        'int32': 'i',
        'uint32': 'I',
        'int64': 'q',
        'uint64': 'Q',
        'double': 'd',
        'float': 'f',
    }

    C_format = '<' + formats['int16'] + formats['uint64']
    C_size = struct.calcsize(C_format)

    D_format = '<' + formats['int64'] + formats['uint32'] \
               + formats['uint16'] + formats['float'] \
               + formats['int32'] + formats['int32']
    D_size = struct.calcsize(D_format)

    B_format = '<' + formats['float'] + formats['uint32'] \
               + formats['uint32'] + formats['uint32'] \
               + formats['uint8'] + formats['uint8'] + \
               formats['uint32'] + formats['uint16'] + \
               formats['uint32']
    B_size = struct.calcsize(B_format)

    A_format = B_format + formats['uint32'] + \
               formats['uint16'] + formats['uint16'] \
               + formats['uint16'] + formats['uint32'] \
               + formats['uint16'] + D_format

    def __init__(self, sequence):
        self.data = sequence
        self.pointer = struct.calcsize(5*BinaryReader.formats['uint8'])
    def unpack_A(self):
        A_buffer = self.unpack(BinaryReader.A_format)
        self.pointer = 5
        A1 = self.unpack_B(self.pointer)
        A2 = A_buffer[7]
        A3 = A_buffer[8]
        A4 = self.unpack(A_buffer[9] * BinaryReader.formats["char"], A_buffer[10])
        A4 = self.dec_char(A4)
        A5 = self.unpack(A_buffer[11] * BinaryReader.formats["uint8"], A_buffer[12])
        self.pointer = 5
        A6 = self.unpack_D(self.pointer)
        return self.lists('A', [A1, A2, A3, A4, A5, A6])

    def unpack_B(self):
        B_buffer = self.unpack(BinaryReader.B_format)
        B1 = B_buffer[0]
        B2 = B_buffer[1]
        size, address = B_buffer[2:4]
        B3 = [i for i in struct.unpack_from(size * BinaryReader.formats['char'], self.data, address)]
        B4 = B_buffer[4]
        B5 = B_buffer[5]
        size, address = B_buffer[6:]
        B6 = [i for i in struct.unpack_from(size * BinaryReader.formats['uint32'], self.data, address)]
        return self.lists('B', [B1, B2, B3, B4, B5, B6])

    def unpack_D(self):
        D_buffer = self.unpack(BinaryReader.D_format)
        D1 = D_buffer[0]
        size, address = D_buffer[1:3]
        D2 = [i for i in struct.unpack_from(size * BinaryReader.formats['int8'], self.data, address)]
        D3 = D_buffer[2]
        D4 = D_buffer[3]
        D5 = D_buffer[4]
        return self.lists('D', [D1, D2, D3, D4, D5])
    def unpack_C(self):
        C_Buffer = self.unpack(BinaryReader.C_format)
        C1 = C_Buffer[0]
        C2 = C_Buffer[1]
        return self.lists('C', [C1, C2])

    def unpack(self, format, offset=None, address=None):
        if address is None:
            address = self.pointer
            if offset is None:
                offset = struct.calcsize(format)
            buff = struct.unpack_from(format, self.data, address)
            self.pointer += offset
            return  buff

    def dec_char(self, bytearr):
        s = ''
        for sym in bytearr:
            s += sym.decode('ascii')
        return s
    def unpack_seq(self):
        A_buffer = self.unpack(BinaryReader.A_format)
        self.pointer = 5
        A1 = self.unpack_B(self.pointer)
        A2 = A_buffer[7]
        A3 = self.unpack(A_buffer[8] * BinaryReader.formats[' char'], 0, A_buffer[9])
        A3 = self.dec_char(A3)
        A4 = self.dec_char(A_buffer[10:12])
        A5, A6, A7 = A_buffer[12:15]
        A8 = self.unpack_D(A_buffer[-1])
        return BinaryReader.lists('A', [A1, A2, A3, A4, A5, A6, A7, A8])
    @staticmethod
    def lists(letter, arr):
        l = [letter + str(i + 1) for i in range(len(arr))]
        return {k: v for k, v in zip(l, arr)}

    def unpack_B(self, address):
        B_buffer = self.unpack(BinaryReader.B_format, address = address)
        B1 = B_buffer[0]

def main(seqence):
    obj = BinaryReader(seqence)
    return obj.unpack_seq()

print(main(b'ADYR\xa9\xe6cK>F#\xab\xfd\x06\x00\x00\x00G\x00\x00\x00\x9d\xd5\x04'
 b'\x00\x00\x00u\x00\xadm\xfc@\x0e\xd4\x04\x00\x85\x00\x02\x00\x00\x00\x89'
 b'\x00\xc8h\xefmV\x9e\x0eO\x03\x00\x00\x00\x8b\x00\xf6\xd3"\xbf\xa8\x9a-\x82h'
 b'\x8ew\x00ilkaskT\xa9\xf8%\xb8.^Q\x1diDn\xaa\x82\xd3\x9b\x80\xe6\xe2'
 b'Z\xfb\xe6\t}\xe1\xd7\x8a\xbf\xcbm>\x0e\x80\xed\x01\xc8\x1b<\xfb\x02M\x00\x00'
 b'\x00W\x00\x00\x00a\x00\x00\x00k\x00\x00\x00dagy\x8b]v\xe2H'))