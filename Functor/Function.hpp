
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
