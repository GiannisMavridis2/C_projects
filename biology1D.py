import matplotlib.pyplot as plt
import random

def gameOfLife(A,propability,index,liveFlag):
    temp=random.randint(0,100)
    if temp<=propability*100:
        A[index]=liveFlag

N=30000 #the cells
p=0.05 #produce death
q=0.1 #give life
A=[]

#fill A
for i in range(0,N):
    temp=random.randint(0,100)
    if temp<=50:
        A.append(1)
    else:
        A.append(0)
        
#a cell kills neigbors with propability p
gameOfLife(A,p,1,0) #cell_0 may kill its neighbor in element 1
for i in range(1,N-1):
    #cell i may kill its left neighbor
    gameOfLife(A,p,i-1,0)
    #cell i may kill its right neighbor
    gameOfLife(A,p,i+1,0)
#cell N-1 may kill cell N-2    
gameOfLife(A,p,N-2,0)

#a cell gives life to neigbors with propability q
gameOfLife(A,q,1,1) #cell_0 may give life to its neighbor in element 1
for i in range(1,N-1):
    #cell i may give life to its left neighbor
    gameOfLife(A,q,i-1,1)
    #cell i may give life to its right neighbor
    gameOfLife(A,q,i+1,1)
#cell N-1 may give life to cell N-2    
gameOfLife(A,q,N-2,1)

#initialize smini
smini=[]
for i in range(0,N):
    smini.append(0)
#compute smini[]
#for example, smini[5]=10 means that:
#there are 10 5-ades me synexomenoys assoys    
i=0
while i<len(smini)-1 :
    temp_plithos=0
    if A[i]==1:
        while A[i]==1:
            i=i+1
            temp_plithos=temp_plithos+1
        smini[temp_plithos]=smini[temp_plithos]+1          
    else:
        i=i+1

#plot data
plt.plot(smini[1:20])
plt.ylabel("smini")
plt.show()        


































