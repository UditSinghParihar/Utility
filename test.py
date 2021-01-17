def maxset(A):
        st, end, tot, maxi, maxSt, maxEnd = 0, 0, 0, -0.5, 0, 0
        
        for i in range(len(A)):
            if(A[i] < 0):
                st = i+1
                end = i+1
                tot = -1 
                
            elif(A[i] >= 0):
                end = i
                tot = sum(A[st:end+1])
                
            if(tot > maxi):
                maxi = tot
                maxSt = st
                maxEnd = end
            elif(tot == maxi and (st != end)):
                maxi = tot
                maxSt = st
                maxEnd = end 
        print(A[maxSt:maxEnd+1], maxSt, maxEnd)      
         
        if(maxSt == maxEnd == 0 and A[0]<0):
            return []
        return A[maxSt:maxEnd+1]

res = maxset([-1,-1,-1,-1,-1])
print(res)

res = maxset([0,0,-1,0])
print(res)

res=maxset([ 137806862, -982906996, -511702305, -1937477084 ])
print(res)
