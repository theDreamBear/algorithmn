#include <iostream>
#include <utility>
#include <string>

#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

#include <algorithm>
#include <boost/type_index.hpp>

/*
1. typelist
2. front
3. popfront
4. pushront
5. pushback
6. reverse
7. popback
8. size
9. nth_element
10. IsEmpty;
*/

using namespace std;

template<typename ...Types>
struct TypeList {
};

template<typename List>
struct FrontTypeT;

template<typename Front, typename ...Rest>
struct FrontTypeT<TypeList<Front, Rest...>> {
    using type = Front;
};

template<typename List>
using FrontType = typename FrontTypeT<List>::type;

template<typename List>
struct PopFrontT;

template<typename Head, typename ...Rest>
struct PopFrontT<TypeList<Head, Rest...>> {
    using type = TypeList<Rest...>;
};

template<typename List>
using PopFront = typename PopFrontT<List>::type;

template<typename List, typename NewElem>
struct PushFrontT;

template<typename ...Types, typename NewElem>
struct PushFrontT<TypeList<Types...>, NewElem> {
    using type = TypeList<NewElem, Types...>;
};

template<typename List, typename NewElement>
using PushFront = typename PushFrontT<List, NewElement>::type;

template<typename List, typename NewElem>
struct PushBackT;

template<typename ...Types, typename NewElem>
struct PushBackT<TypeList<Types...>, NewElem> {
    using type = TypeList<Types..., NewElem>;
};

template<typename List, typename NewElement>
using PushBack = typename PushBackT<List, NewElement>::type;


template<typename List>
struct TypeListSize;

template<typename List>
struct TypeListSize {
    constexpr static auto value = 1 + TypeListSize<PopFront<List>>::value;
};

template<typename List, unsigned N, auto b = (N < TypeListSize<List>::value)>
struct NthElementT;

template<typename List, unsigned N>
struct NthElementT<List, N, true> : public NthElementT<PopFront<List>, N - 1> {
};

template<typename List, unsigned N>
struct NthElementT<List, N, false> : public exception {
};

template<typename List>
struct NthElementT<List, 0, true> : public FrontTypeT<List> {
};

template<typename List, unsigned N>
using NthElement = typename NthElementT<List, N>::type;

template<>
struct TypeListSize<TypeList<>> {
    constexpr static auto value = 0;
};

template<typename List>
struct IsEmpty {
    constexpr static auto value = false;
};

template<>
struct IsEmpty<TypeList<>> {
    constexpr static auto value = true;
};

template<typename List, bool = IsEmpty<List>::value>
struct ReverseT;

template<typename List>
struct ReverseT<List, false> {
    using Front = FrontType<List>;
    using Tail = typename ReverseT<PopFront<List>>::type;
    using type = PushBack<Tail, Front>;
};

template<>
struct ReverseT<TypeList<>, true> {
    using type = TypeList<>;
};

template<typename List>
using Reverse = typename ReverseT<List>::type;

// 继承实现
//template<typename List, bool = IsEmpty<List>::value>
//struct ReverseT2;
//
//template<typename List>
//using Reverse2 = typename ReverseT2<List>::type;
//
//
//template<typename List>
//struct ReverseT2<List, false> : public PushBackT<
//        Reverse2<PopFront<List>>,
//        FrontType<List>> {
//};
//template<>
//struct ReverseT2<TypeList<>, true> {
//    using type = TypeList<>;
//};


template<typename List>
struct PopBackT : public ReverseT<PopFront<Reverse<List>>> {
};

template<typename List>
using PopBack = typename PopBackT<List>::type;
