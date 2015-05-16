def check_fermat(a, b, c, n):
    if n > 2:
        if a**n + b**n == c**n:
            return "Fermat Was Wrorng!\n"
    return "Nope, he was right"
    
def get_input():
    value = raw_input()
    return value
    
print "Enter a, b, c and n to check Fermat's last theorem"
a = get_input()
b = get_input()
c = get_input()
n = get_input()
print check_fermat(int(a), int(b), int(c), int(n))
