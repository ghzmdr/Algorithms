def s(a, b):
	res = 0
	for i in xrange(1,a):
		res += i**b

	return res

def t(a, b):
	return a**(b+1)