#if !defined(ITERATOR)
#define ITERATOR
// to be continue
class IIter{
    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual void currentItem() = 0;
};

#endif // ITERATOR
