import sys
import json
import pandas as pd
import matplotlib.pyplot as plt

# Check argument
if len(sys.argv) < 2:
    print(f"Usage: {sys.argv[0]} <results.json>")
    sys.exit(1)

filename = sys.argv[1]

with open(filename) as f:
    data = json.load(f)

benchmarks = data["benchmarks"]
df = pd.DataFrame(benchmarks)

# Sort by CPU time
df = df.sort_values("cpu_time")

plt.figure()
plt.barh(df["name"], df["cpu_time"])
plt.xlabel("CPU Time (ns)")
plt.title("Google Benchmark Results")
plt.tight_layout()
plt.show()