import sys
stdin = sys.stdin.read().split("\n")
stdin.pop()
rpath = ""
l = ""
for line in stdin:
    if "swift" not in line: continue
    line = line.split("=> ")[1]
    if rpath == "":
        parts = line.split("/")
        parts.pop()
        rpath = "/".join(parts)
    l += " -l" + line.split(" ")[0].split("/lib").pop().replace(".so","")
print("-L" + rpath + l, end = "")