test = int(input ());

for kase in range (1 , test + 1):
	cats,dogs,legs = input ().split ();
	cats = int (cats);
	dogs = int (dogs);
	legs = int (legs);
	
	maxlegs = (cats + dogs) * 4;
	minlegs = dogs * 4;
	if dogs * 2 < cats:
		minlegs += (cats - dogs * 2) * 4;

	if (legs % 4 != 0 or legs > (cats + dogs) * 4):
		print ('no');
	elif (legs >= minlegs and legs <= maxlegs):
		print ('yes');
	else:
		print ('no');