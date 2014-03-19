import pandas as pd
import re

def get_day(m,d):
    month = [31,28,31,40,31,30,31,31,30,31,30,31]
    day = sum(month[:m-2])+d
    return day

def get_data():
    f = open('../data.txt')
    data = []
    for line in f:
        (uid,gid,action,time) = line.split(',')
        print time
        # t_re = re.match(r'(\d*)[.](16)(\d*).*?$',time)
        # m = int(t_re.group(1))
        # d = int(t_re.group(2))
        # t = get_day(m,d)
        # data.append((uid,gid,action,t))
    df = pd.DataFrame(data,column=['uid','gid','action','t'])

if __name__=='__main__':
    data = get_data()
