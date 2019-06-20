def permute(s):
    out = []
    if len(s) == 1:
        out= [s]
    else:
        for i,let in enumerate(s):
            #print(" let " + s[:i] + s[i+1:])
            #print(" s[:i]  " + s[:i] )
            #print(" s[i+1:]  " + s[i+1:] )
            print(permute( s[:i] + s[i+1:]))
            for perm in permute( s[:i] + s[i+1:]):             
             #   print(" perm " + perm)
                out += [let+perm]
               # print(out)
            
    
    return out
    
#permute("abc")
print(permute("abc"))        
