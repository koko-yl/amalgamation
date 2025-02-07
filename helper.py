import os
from sys import argv;
paths = []
for i in os.listdir(): 
    if os.path.isdir(i): 
        if "Makefile" in os.listdir(i):
            paths += [i]

objs = []
for path in paths:
    objs += [path + "/" + open(path+"/Makefile").read().split("all: ")[1].split(" ")[0]]

srcs = []
for path in paths:
    source = ""
    for f in os.listdir(path):
        if f.startswith("source"):
            source = f
            break
    srcs += [path + "/" + source]
libs = list(map(lambda x: x + "/libs.txt", paths))

if argv[1] == "targets":
    for i in range(len(objs)):
        print(f"{objs[i]}: {srcs[i]}\n\tmake -C {paths[i]}")
    
if argv[1] == "sources":
    print(" ".join(srcs))

if argv[1] == "objects":
    print(" ".join(objs))

if argv[1] == "clean":
    print(" ".join(objs), " ".join(libs))

if argv[1] == "libs":
    print(" ".join(list(map(lambda x: open(x, "r").read(), libs))))