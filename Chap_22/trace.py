from random import randrange

# 5 for loops that we can decide which trace we want
for a in range(1, 6):
    trace = []
    # generate 10 random traces
    for _ in range(0, 10):
        trace.append(randrange(10))

    print("Trace " + str(a) + ": Unsorted" + str(trace))
    # sort the traces to get spartial locality
    trace.sort()
    print("Trace " + str(a) + ": Sorted" + str(trace) + "\n")