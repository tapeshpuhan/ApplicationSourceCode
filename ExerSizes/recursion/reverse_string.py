def reverse(s):
    if len(s) <= 1:
        return s
    print(s[1:])
    return s[1:] + s[0]
    
print(reverse("tapesh"))
