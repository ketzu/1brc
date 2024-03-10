from collections import defaultdict

# I hardcoded the path to the measurements
# As I am really really lazy.

def lines():
    with open('D:\\dev\\1brc\\measurements.txt', 'r', encoding='utf8') as f:
        for line in f:
            yield line


class Measurement:
    def __init__(self):
        self.count = 0
        self.total = 0
        self.min = float('inf')
        self.max = float('-inf')

    def add(self, value):
        self.count += 1
        self.total += value
        self.min = min(self.min, value)
        self.max = max(self.max, value)


results = defaultdict(Measurement)

for line in lines():
    location, measurement = line.split(";")
    measurement = float(measurement)
    results[location].add(measurement)

# To fix: This breaks for encoding reasons
for location, measurement in results.items():
    print(
        f"'{location}'='{measurement.min:.1f}/{(measurement.total / measurement.count) if measurement.count != 0 else 0:.1f}/{measurement.max:.1f}'",
        end="\n",
    )
