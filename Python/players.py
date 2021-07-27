N = int(input("Enter the number of participants: "))

m = 0
name = []


for i in range(N):
	name.append(input("Enter name of partcipant: "))
	m = int(input("Enter number of events participated: "))
	temp = []
	for j in range(m):
		temp.append(input("Enter sports name: "));
	name.append(temp)
	print()

events = []

for ev in name:
	if not isinstance(ev, str):
		for e in ev:
			if e not in events:
				events.append(e)

for e in sorted(events):
	print(e)
	name_by_event = []
	for i in range(len(name)):
		if isinstance(name[i], str) and e in name[i + 1]:
			name_by_event.append(name[i])
	print(sorted(name_by_event)) 
