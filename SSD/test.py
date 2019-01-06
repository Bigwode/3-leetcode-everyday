def isIsomorphic(s, t):
    print(set(zip(s, t)))
    # return len(set(zip(s, t))) == len(set(s)) and len(set(zip(t, s))) == len(set(t))


isIsomorphic('egg', 'add')