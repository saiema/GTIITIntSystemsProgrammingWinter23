for i in range(1000):
	for j in range(1000):
		print("{} has ref {}; {} has ref {}; {} * {} has ref {}".format(i, id(i), j, id(j), i, j, id(i*j)))
		print("{} has ref {}; {} has ref {}; {} * {} has ref {}".format(i, id(i), j, id(j), i, j, id(i*j)))
