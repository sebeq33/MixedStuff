1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
 #include <boost/bind.hpp>
 
 template <typename T>
 class Function;
 
 template <typename T, typename P1>
 class Function<T(P1)>
 {
   typedef Function<T(P1)>& retour;
   typedef T (*ptr)(P1);
 
   class Holder
   {
   public:
     virtual T  operator()(P1 const&) = 0;
    virtual ~Holder(){};
   };
 
  template <typename C>
   class PlaceHolder : public Holder
   {
     C           *_b;
 
   public:
     PlaceHolder() : _b(0)
     {}
     PlaceHolder(C const& p) : _b(new C(p))
     {}
     PlaceHolder(PlaceHolder<C> const& f) : _b(f._b)
     {}
     PlaceHolder(PlaceHolder<T(P1)> const& f) : _b(f._b)
     {}
 
     T                   operator()(P1 const& p)
    {
       if (_b)
         return _b->operator()(p);
       return T(p);
     }
     virtual ~PlaceHolder()
    {delete _b;}
   };
 
   template <typename PTR, typename A1>
   class PlaceHolder<PTR(A1)> : public Holder
  {
     ptr         _o;
 
   public:
     PlaceHolder() : _o(0)
     {}
 
     PlaceHolder(ptr p) : _o(p)
     {}
 
     PlaceHolder(PlaceHolder<T(P1)> const& f) : _o(f._o)
     {}
 
    T                   operator()(P1 const& p)
     { return _o(p); }
     virtual ~PlaceHolder() {}
   };
 
 public:
  Function() : _hold(0)
  {}
 
 template <typename C>
  Function(C const& p) : _hold(new PlaceHolder<C>(p))
  {}
 
   Function(ptr p) : _hold(new PlaceHolder<T(P1)>(p))
   { }
 
   Function(Function<T(P1)> const& f) : _hold(f._hold)
   {
   }
 
   T                     operator()(P1 const& p)
   {
     if (_hold)
       return _hold->operator()(p);
     return T();
   }
   retour                operator=(ptr p)
   {
     delete _hold;
     _hold = new PlaceHolder<T(P1)>(p);
     return *this;
   }
 
   template <typename B>
   retour                operator=(B const&b)
   {
     delete _hold;
   _hold = new PlaceHolder<B>(b);
     return *this;
   }
   
 private:
  Holder *      _hold;
 };