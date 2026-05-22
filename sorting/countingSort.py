import numpy as np

# doesn't handle NEGATIVE
def countingSort(array):
    sz = len(array)
    output = [0]*sz
    pref_cnt=[0]*(max(array)+1)
    for i in range (0,sz):
        pref_cnt[array[i]]+=1
        
    for i in range (1, max(array)+1):
        pref_cnt[i]+=pref_cnt[i-1]
        
    for i in range (sz - 1, -1, -1):
        output[pref_cnt[array[i]]-1]=array[i]
        pref_cnt[array[i]]-=1
        
    
    for i in range(0,sz):
        array[i] = output[i]
        


data = np.fromstring(input(), dtype=int, sep=' ')
data = data.tolist()   # convert to list

countingSort(data)
print(data)