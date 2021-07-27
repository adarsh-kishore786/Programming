import pickle

mylist = {1: "Zack", 2: "53050", 3: "IT", 4: "38", 5: "Flipkart"}

# pickling
with open("datafile.dat", "wb") as fh:
	pickle.dump(mylist, fh)

# now unpickling the data
with open("datafile.dat", "rb") as pickle_off:
	emp = pickle.load(pickle_off)
print(emp)