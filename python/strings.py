s = "Hola Mundo"
s.lower(), s.upper(), s.swapcase(), s.title(), s.capitalize()
s.isdigit(), s.isalpha(), s.isalnum(), s.isspace(), s.islower(), s.isupper()
s.find("o"), s.rfind("o")      # indice o -1
s.index("o")                   # como find pero lanza ValueError
s.count("o")                   # ocurrencias sin traslape
s.startswith("Ho"), s.endswith("do")
s.replace("o", "0")            # replace(a, b, k): solo las primeras k
s.split()                      # por espacios, ignora espacios repetidos
"a,b,,c".split(",")            # ['a', 'b', '', 'c']
s.rsplit(" ", 1)               # corta desde la derecha, max 1 vez
s.partition(" ")               # ('Hola', ' ', 'Mundo')
" x ".strip(), " x ".lstrip(), " x ".rstrip()   # strip("ab") quita esos chars
" ".join(["a", "b", "c"])      # 'a b c'
s[::-1]                        # reverso
s[2:5], s[-3:]                 # slicing [l, r)
"7".zfill(3), "ab".ljust(4, "."), "ab".rjust(4), "ab".center(6, "*")
ord("a"), chr(97)              # 97, 'a'
int("ff", 16), int("101", 2)   # 255, 5 (string en base b a int)
bin(5)[2:], hex(255)[2:], oct(8)[2:], format(5, "08b")   # '101', 'ff', '10', '00000101'
f"{3.14159:.2f}", f"{42:>5}", f"{7:03d}"                 # '3.14', '   42', '007'
sorted(s), "".join(sorted(s))  # lista de chars ordenada
list(s), set(s)
from collections import Counter
Counter("banana").most_common(1)   # [('a', 3)]
import string
string.ascii_lowercase, string.ascii_uppercase, string.digits
s.translate(str.maketrans("aeiou", "AEIOU"))   # reemplazo char a char
# Leer rapido toda la entrada
import sys
data = sys.stdin.buffer.read().split()   # tokens en bytes, usar int(x)
