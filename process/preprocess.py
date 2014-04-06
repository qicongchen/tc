import pandas as pd
from pandas import Series
import re
import sys


# def get_day(m,d):
#     month = [31,28,31,40,31,30,31,31,30,31,30,31]
#     day = sum(month[:m-2])+d
#     return day

# def get_data():
#     f = open('../data.txt')
#     data = []
#     for line in f:
#         (uid,gid,action,time) = line.split(',')
#         print time
#         t_re = re.match(r'(\d*)[.](16)(\d*).*?$',time)
#         m = int(t_re.group(1))
#         d = int(t_re.group(2))
#         t = get_day(m,d)
#         data.append((uid,gid,action,t))
#     df = pd.DataFrame(data,column=['uid','gid','action','t'])
#     return df


def get_data():
    df1 = pd.read_csv('../test/test.qids',names=['qid'])
    df2 = pd.read_csv('../test/test.labels',names=['test.labels'])
    df3 = pd.read_csv('../test/predicted.labels',names=['predicted.labels'])
    df4 = pd.read_csv('../test/test.allids',sep='\t',names=['eid','g_key','u_key'])
    df4['predicted.labels'] = df3['predicted.labels']
    df4['test.labels'] = df2['test.labels']
    df4['qid'] = df1['qid']
    return df4

def get_train():
    df1 = pd.read_csv('../test/train.qids',names=['qid'])
    df2 = pd.read_csv('../test/train.labels',names=['train.labels'])
    df3 = pd.read_csv('../test/train.labels',names=['train.labels'])
    df4 = pd.read_csv('../test/train.allids',sep='\t',names=['eid','g_key','u_key'])
    df4['train.labels'] = df3['train.labels']
    df4['train.labels'] = df2['train.labels']
    df4['qid'] = df1['qid']
    return df4

def sortt(df):
    sort = df.sort(['qid','train.labels'],ascending=[True,False])
    return sort

def sort(df):
    sort = df.sort(['qid','predicted.labels'],ascending=[True,False])
    return sort

# def f_or_t(row):
#     p = row['predicted.labels']
#     t = row['test.labels']
#     if p<0 and t<0:
#         return 0
#     elif p>0 and t>0:
#         return 1
#     elif p>0 and t<0:
#         return 2
#     elif p<0 and t>0:
#         return 3

def compute_all(groups,n):
    all_p = []
    all_r = []
    all_f = []
    f = open('p_r_f.txt','a+')
    for i in range(0,883):
        t = groups.get_group(i)['test.labels'].tolist()
        if n!= 0:
            # print 'tp',tp,t.count
            n_ = n
            tp = t[:n].count(1)
            pass
        else:
            n_ = len(t)
            tp = t.count(1)
        # else:
        #     pass
        # tn = t.count(0)
        # print 'tn',tn
        # tp = t.count(1)
        # print 'tp',tp
        # fp = t.count(2)
        # print 'fp',fp
        # fn = t.count(3)
        # print 'fn',fn



        if t.count(1)==0:
            pass
        else:
            p = float(tp)/n_
            r = float(tp)/t.count(1)
            print 'tp',tp,t.count(1)
            if p+r!=0:
                f1 = 2*p*r/(p+r)
            else:
                f1=0
            all_p.append(p)
            all_r.append(r)
            all_f.append(f1)

        # for x in all_p:
        #     print x
        # for x in all_r:
        #     print x
        # for x in all_f:
        #     print x
    if n==0:
        num = 'all'
    else:
        num = str(n)
    f.write('get top n ('+num+'):\n'+'average precision: '+str(sum(all_p)/len(all_p))+'\n')
    f.write('average recall: '+str(sum(all_r)/len(all_r))+'\n')
    f.write('average f1 score: '+str(sum(all_f)/len(all_f))+'\n\n')
    f.close

def get_output(sort):
    groups = sort.groupby('qid')
    f = open('2_9_5-10_3gf.txt','w')
    for i in range(0,884):
        u = groups.get_group(i)['u_key'].tolist()[0]
        gs = groups.get_group(i)['g_key'].tolist()
        l = int(len(gs)*0.1)

        if l>10:
            l=10
        if l<5:
            l=5
        gs = gs[:l]

        g_str = ','.join(str(g) for g in gs)
        # if l>0:
        f.write(str(u)+'\t'+g_str+'\n')

def get_output1(s1,s2):
    groups1 = s1.groupby('qid')
    groups2 = s2.groupby('qid')
    f = open('2_9_5_7f_new.txt','w')
    os = 0
    for i in range(0,884):
        try:
            print i
            u1 = groups1.get_group(i)['u_key'].tolist()[0]
            u2 = groups2.get_group(i)['u_key'].tolist()[0]
            j = i

            while u1 != u2:
                j += 1
                u2 = groups2.get_group(j)['u_key'].tolist()[0]

            print (u1==u2)
            gs1 = groups1.get_group(i)['g_key'].tolist()[:5]
            label = groups2.get_group(j)['train.labels'].tolist()
            gs2 = groups2.get_group(j)['g_key'].tolist()

            gs = []
            for idx,l in enumerate(label):
                if l>0:
                    gs.append(gs2[idx])
                else:
                    break
            for s in gs1:
                gs.append(s)
            gs = list(set(gs))
            l = int(len(gs)*0.1)
        except:
            pass

        # if l>10:
        #     l=10
        # if l<3:
        #     l=3
        # gs = gs[:l]
        # g_str = ''
        g_str = ','.join(str(g) for g in gs)
        # if l>0:
        f.write(str(u1)+'\t'+g_str+'\n')

def process_label(sort):
    s = sort.groupby('eid')
    # size = s.size().tolist()[0]
    f = open('1_all.txt','a+')
    for i in range(0,8906):
        g = s.get_group(i)['g_key'].tolist()[0]
        l = s.get_group(i)['test.labels'].tolist()
        len_1 = l.count(1)
        len_all = len(l)
        print 'qwe'
        f.write(str(g)+'\t'+str(len_1)+'\t'+str(l)+'\n')

if __name__=='__main__':
    agr = sys.argv[1]
    nlist= [3,5,10,0]
    data = get_data()
    s = sort(data)
    # s['t/f'] = s.apply(f_or_t,axis=1)
    f = open('p_r_f.txt','a+')
    f.write('\n=='+agr+'==\n')
    f.close()
    groups = s.groupby('qid')
    for n in nlist:
        compute_all(groups,n)






