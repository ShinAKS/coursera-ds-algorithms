# python3
def balance_check(s):
    
    opening = set('([{') 
    closing=set(')]}')
    
    matches = set([ ('(',')'), ('[',']'), ('{','}') ]) 
    
    stack = []
    j=[]
    
    for i in range(len(s)):
        
        if s[i] in opening:
            stack.append(s[i])
            j.append(i)
        
        elif s[i] in closing:
            
            if len(stack) == 0:
                return i+1
            
            last_open = stack.pop()
            
            if (last_open,s[i]) not in matches:
                return i+1
            else:
                j.pop()
            
    if len(stack)==0:
        return 'Success'
    else:
        return (j[0]+1)
s=input()
print(balance_check(s))



