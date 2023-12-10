import sys

print("Arguments received {}".format(len(sys.argv)))
for arg in sys.argv:
	print("Command-line argument: {}".format(arg))
